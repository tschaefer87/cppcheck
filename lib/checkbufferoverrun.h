/*
 * Cppcheck - A tool for static C/C++ code analysis
 * Copyright (C) 2007-2018 Cppcheck team.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


//---------------------------------------------------------------------------
#ifndef checkbufferoverrunH
#define checkbufferoverrunH
//---------------------------------------------------------------------------

#include "check.h"
#include "config.h"
#include "errorlogger.h"
#include "mathlib.h"
#include "tokenize.h"

#include <cstddef>
#include <list>
#include <map>
#include <string>
#include <vector>

class Settings;
class SymbolDatabase;
class Token;
namespace ValueFlow {
    class Value;
}  // namespace ValueFlow
namespace tinyxml2 {
    class XMLElement;
}  // namespace tinyxml2

// CWE ids used
static const struct CWE CWE119(119U); // Improper Restriction of Operations within the Bounds of a Memory Buffer

class Variable;

/// @addtogroup Checks
/// @{

/**
 * @brief buffer overruns and array index out of bounds
 *
 * Buffer overrun and array index out of bounds are pretty much the same.
 * But I generally use 'array index' if the code contains []. And the given
 * index is out of bounds.
 * I generally use 'buffer overrun' if you for example call a strcpy or
 * other function and pass a buffer and reads or writes too much data.
 */
class CPPCHECKLIB CheckBufferOverrun : public Check {
public:

    /** This constructor is used when registering the CheckClass */
    CheckBufferOverrun() : Check(myName()), symbolDatabase(nullptr) {
    }

    /** This constructor is used when running checks. */
    CheckBufferOverrun(const Tokenizer *tokenizer, const Settings *settings, ErrorLogger *errorLogger)
        : Check(myName(), tokenizer, settings, errorLogger)
        , symbolDatabase(tokenizer?tokenizer->getSymbolDatabase():nullptr) {
    }

    void runSimplifiedChecks(const Tokenizer *tokenizer, const Settings *settings, ErrorLogger *errorLogger) {
        CheckBufferOverrun checkBufferOverrun(tokenizer, settings, errorLogger);
        checkBufferOverrun.checkGlobalAndLocalVariable();
        if (tokenizer && tokenizer->isMaxTime())
            return;
        checkBufferOverrun.checkStructVariable();
        checkBufferOverrun.checkBufferAllocatedWithStrlen();
        checkBufferOverrun.checkInsecureCmdLineArgs();
        checkBufferOverrun.arrayIndexThenCheck();
        checkBufferOverrun.negativeArraySize();
    }

    void runChecks(const Tokenizer *tokenizer, const Settings *settings, ErrorLogger *errorLogger) {
        CheckBufferOverrun checkBufferOverrun(tokenizer, settings, errorLogger);
        checkBufferOverrun.bufferOverrun();
        checkBufferOverrun.checkStringArgument();
    }

    /** @brief %Check for buffer overruns (single pass, use ast and valueflow) */
    void bufferOverrun();

    /** @brief Using array index before bounds check */
    void arrayIndexThenCheck();

    /** @brief negative size for array */
    void negativeArraySize();

    /**
     * @brief Get minimum length of format string result
     * @param input_string format string
     * @param parameters given parameters to sprintf
     * @return minimum length of resulting string
     */
    static MathLib::biguint countSprintfLength(const std::string &input_string, const std::list<const Token*> &parameters);

    /** Check for buffer overruns - locate struct variables and check them with the .._CheckScope function */
    void checkStructVariable();

    /** Check for buffer overruns - locate global variables and local function variables and check them with the checkScope function */
    void checkGlobalAndLocalVariable();

    /** Check for buffer overruns due to allocating strlen(src) bytes instead of (strlen(src)+1) bytes before copying a string */
    void checkBufferAllocatedWithStrlen();

    /** Check string argument buffer overruns */
    void checkStringArgument();

    /** Check for buffer overruns due to copying command-line args to fixed-sized buffers without bounds checking */
    void checkInsecureCmdLineArgs();

    /** Information about N-dimensional array */
    class CPPCHECKLIB ArrayInfo {
    private:
        /** number of elements of array */
        std::vector<MathLib::bigint> _num;

        /** full name of variable as pattern */
        std::string _varname;

        /** size of each element in array */
        MathLib::bigint _element_size;

        /** declaration id */
        unsigned int _declarationId;

    public:
        ArrayInfo();
        ArrayInfo(const Variable *var, const SymbolDatabase *symbolDatabase, const unsigned int forcedeclid = 0);

        /**
         * Create array info with specified data
         * The intention is that this is only a temporary solution.. all
         * checking should be based on ArrayInfo from the start and then
         * this will not be needed as the declare can be used instead.
         */
        ArrayInfo(unsigned int id, const std::string &name, MathLib::bigint size1, MathLib::bigint n);

        /** Create a copy ArrayInfo where the number of elements have been limited by a value */
        ArrayInfo limit(MathLib::bigint value) const;

        /** array sizes */
        const std::vector<MathLib::bigint> &num() const {
            return _num;
        }

        /** array size */
        MathLib::bigint num(std::size_t index) const {
            return _num[index];
        }
        void num(std::size_t index, MathLib::bigint number) {
            _num[index] = number;
        }

        /** size of each element */
        MathLib::bigint element_size() const {
            return _element_size;
        }

        /** Variable name */
        unsigned int declarationId() const {
            return _declarationId;
        }
        void declarationId(unsigned int id) {
            _declarationId = id;
        }

        /** Variable name */
        const std::string &varname() const {
            return _varname;
        }
        void varname(const std::string &name) {
            _varname = name;
        }

        MathLib::bigint numberOfElements() const;
        MathLib::bigint totalIndex(const std::vector<ValueFlow::Value> &indexes) const;
    };

    /** Check for buffer overruns (based on ArrayInfo) */
    void checkScope(const Token *tok, const ArrayInfo &arrayInfo);
    void checkScope(const Token *tok, std::map<unsigned int, ArrayInfo> arrayInfos);
    void checkScope_inner(const Token *tok, const ArrayInfo &arrayInfo);

    /** Check for buffer overruns */
    void checkScope(const Token *tok, const std::vector<const std::string*> &varname, const ArrayInfo &arrayInfo);

    /**
     * Helper function for checkFunctionCall - check a function parameter
     * \param ftok token for the function name
     * \param paramIndex on what parameter is the array used
     * \param arrayInfo the array information
     * \param callstack call stack. This is used to prevent recursion and to provide better error messages. Pass a empty list from checkScope etc.
     */
    void checkFunctionParameter(const Token &ftok, const unsigned int paramIndex, const ArrayInfo &arrayInfo, const std::list<const Token *>& callstack);

    /**
     * Helper function that checks if the array is used and if so calls the checkFunctionCall
     * @param tok token that matches "%name% ("
     * @param arrayInfo the array information
     * \param callstack call stack. This is used to prevent recursion and to provide better error messages. Pass a empty list from checkScope etc.
     */
    void checkFunctionCall(const Token *tok, const ArrayInfo &arrayInfo, std::list<const Token *> callstack);

    void arrayIndexOutOfBoundsError(const Token *tok, const ArrayInfo &arrayInfo, const std::vector<MathLib::bigint> &index);
    void arrayIndexOutOfBoundsError(const Token *tok, const ArrayInfo &arrayInfo, const std::vector<ValueFlow::Value> &index);

    /* data for multifile checking */
    class MyFileInfo : public Check::FileInfo {
    public:
        std::string toString() const;

        struct ArrayUsage {
            MathLib::bigint   index;
            std::string       fileName;
            unsigned int      linenr;
        };

        /* key:arrayName */
        std::map<std::string, ArrayUsage> arrayUsage;

        /* key:arrayName, data:arraySize */
        std::map<std::string, MathLib::bigint>  arraySize;
    };

    /** @brief Parse current TU and extract file info */
    Check::FileInfo *getFileInfo(const Tokenizer *tokenizer, const Settings *settings) const;

    Check::FileInfo * loadFileInfoFromXml(const tinyxml2::XMLElement *xmlElement) const;

    /** @brief Analyse all file infos for all TU */
    bool analyseWholeProgram(const std::list<Check::FileInfo*> &fileInfo, const Settings& settings, ErrorLogger &errorLogger);

    /**
     * Calculates sizeof value for given type.
     * @param type Token which will contain e.g. "int", "*", or string.
     * @return sizeof for given type, or 0 if it can't be calculated.
     */
    unsigned int sizeOfType(const Token *type) const;

private:
    const SymbolDatabase *symbolDatabase;

    static bool isArrayOfStruct(const Token* tok, int &position);
    void arrayIndexOutOfBoundsError(const std::list<const Token *> &callstack, const ArrayInfo &arrayInfo, const std::vector<MathLib::bigint> &index);
    void bufferOverrunError(const Token *tok, const std::string &varnames = emptyString);
    void bufferOverrunError(const std::list<const Token *> &callstack, const std::string &varnames = emptyString);
    void strncatUsageError(const Token *tok);
    void negativeMemoryAllocationSizeError(const Token *tok); // provide a negative value to memory allocation function
    void negativeArraySizeError(const Token *tok);
    void outOfBoundsError(const Token *tok, const std::string &what, const bool show_size_info, const MathLib::bigint &supplied_size, const MathLib::bigint &actual_size);
    void sizeArgumentAsCharError(const Token *tok);
    void terminateStrncpyError(const Token *tok, const std::string &varname);
    void bufferNotZeroTerminatedError(const Token *tok, const std::string &varname, const std::string &function);
    void negativeIndexError(const Token *tok, MathLib::bigint index);
    void negativeIndexError(const Token *tok, const ValueFlow::Value &index);
    void cmdLineArgsError(const Token *tok);
    void pointerOutOfBoundsError(const Token *tok, const Token *index=nullptr, const MathLib::bigint indexvalue=0);
    void arrayIndexThenCheckError(const Token *tok, const std::string &indexName);
    void possibleBufferOverrunError(const Token *tok, const std::string &src, const std::string &dst, bool cat);
    void argumentSizeError(const Token *tok, const std::string &functionName, const std::string &varname);

    void valueFlowCheckArrayIndex(const Token * const tok, const ArrayInfo &arrayInfo);

public:
    void getErrorMessages(ErrorLogger *errorLogger, const Settings *settings) const {
        CheckBufferOverrun c(nullptr, settings, errorLogger);
        const std::vector<MathLib::bigint> indexes(2, 1);
        c.arrayIndexOutOfBoundsError(nullptr, ArrayInfo(0, "array", 1, 2), indexes);
        c.bufferOverrunError(nullptr, std::string("buffer"));
        c.strncatUsageError(nullptr);
        c.outOfBoundsError(nullptr, "index", true, 2, 1);
        c.sizeArgumentAsCharError(nullptr);
        c.terminateStrncpyError(nullptr, "buffer");
        c.bufferNotZeroTerminatedError(nullptr, "buffer", "strncpy");
        c.negativeIndexError(nullptr, -1);
        c.cmdLineArgsError(nullptr);
        c.pointerOutOfBoundsError(nullptr, nullptr, 0);
        c.arrayIndexThenCheckError(nullptr, "index");
        c.possibleBufferOverrunError(nullptr, "source", "destination", false);
        c.argumentSizeError(nullptr, "function", "array");
        c.negativeMemoryAllocationSizeError(nullptr);
        c.negativeArraySizeError(nullptr);
        c.reportError(nullptr, Severity::warning, "arrayIndexOutOfBoundsCond", "Array 'x[10]' accessed at index 20, which is out of bounds. Otherwise condition 'y==20' is redundant.", CWE119, false);
    }
private:

    static std::string myName() {
        return "Bounds checking";
    }

    std::string classInfo() const {
        return "Out of bounds checking:\n"
               "- Array index out of bounds detection by value flow analysis\n"
               "- Dangerous usage of strncat()\n"
               "- char constant passed as size to function like memset()\n"
               "- strncpy() leaving string unterminated\n"
               "- Accessing array with negative index\n"
               "- Unsafe usage of main(argv, argc) arguments\n"
               "- Accessing array with index variable before checking its value\n"
               "- Check for large enough arrays being passed to functions\n"
               "- Allocating memory with a negative size\n";
    }
};
/// @}
//---------------------------------------------------------------------------
#endif // checkbufferoverrunH
