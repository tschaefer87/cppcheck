// auto generated tests from cfg/gnu.cfg
//
// Generated by command:
// ./generate_cfg_tests cfg/gnu.cfg > generated-cfg-tests-gnu.cpp
//
// Recommended cppcheck command line:
// $ cppcheck --enable=warning,information --inline-suppr --platform=unix64 generated-cfg-tests-gnu.cpp
// => 'unmatched suppression' warnings are false negatives.
//

void test__accept__noreturn() {
  int x = 1;
  if (cond) { x=100; accept(arg1, arg2, arg3, arg4); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__accept__leakignore() {
  char *p = malloc(10); *p=0;
  accept(p, arg2, arg3, arg4);
  // cppcheck-suppress memleak
}

void test__accept__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  accept(x, arg2, arg3, arg4);
}

void test__accept__arg2__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  accept(arg1, x, arg3, arg4);
}

void test__accept__arg3__notnull() {
  // cppcheck-suppress nullPointer
  accept(arg1, arg2, NULL, arg4);
}

void test__accept__arg3__notuninit() {
  int x[10];
  // cppcheck-suppress uninitvar
  accept(arg1, arg2, x, arg4);
}

void test__accept__arg4__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  accept(arg1, arg2, arg3, x);
}

void test__atoq__noreturn() {
  int x = 1;
  if (cond) { x=100; result = atoq(arg1); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__atoq__useretval() {
  // cppcheck-suppress ignoredReturnValue
  atoq(arg1);
}

void test__atoq__arg1__notnull() {
  // cppcheck-suppress nullPointer
  result = atoq(NULL);
}

void test__atoq__arg1__notuninit() {
  int x[10];
  // cppcheck-suppress uninitvar
  result = atoq(x);
}

void test__strndupa__noreturn() {
  int x = 1;
  if (cond) { x=100; result = strndupa(arg1, arg2); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__strndupa__useretval() {
  // cppcheck-suppress ignoredReturnValue
  strndupa(arg1, arg2);
}

void test__strndupa__arg1__notnull() {
  // cppcheck-suppress nullPointer
  result = strndupa(NULL, arg2);
}

void test__strndupa__arg1__notuninit() {
  int x[10];
  // cppcheck-suppress uninitvar
  result = strndupa(x, arg2);
}

void test__strndupa__arg2__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  result = strndupa(arg1, x);
}

void test__strsep__noreturn() {
  int x = 1;
  if (cond) { x=100; result = strsep(arg1, arg2); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__strsep__useretval() {
  // cppcheck-suppress ignoredReturnValue
  strsep(arg1, arg2);
}

void test__strsep__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  result = strsep(x, arg2);
}

void test__strsep__arg2__notnull() {
  // cppcheck-suppress nullPointer
  result = strsep(arg1, NULL);
}

void test__strsep__arg2__notuninit() {
  int x[10];
  // cppcheck-suppress uninitvar
  result = strsep(arg1, x);
}

void test__strdupa__noreturn() {
  int x = 1;
  if (cond) { x=100; result = strdupa(arg1); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__strdupa__useretval() {
  // cppcheck-suppress ignoredReturnValue
  strdupa(arg1);
}

void test__strdupa__arg1__notnull() {
  // cppcheck-suppress nullPointer
  result = strdupa(NULL);
}

void test__strdupa__arg1__notuninit() {
  int x[10];
  // cppcheck-suppress uninitvar
  result = strdupa(x);
}

void test__backtrace__noreturn() {
  int x = 1;
  if (cond) { x=100; backtrace(arg1, arg2); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__backtrace__arg1__notnull() {
  // cppcheck-suppress nullPointer
  backtrace(NULL, arg2);
}

void test__backtrace__arg2__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  backtrace(arg1, x);
}

void test__backtrace_symbols__noreturn() {
  int x = 1;
  if (cond) { x=100; result = backtrace_symbols(arg1, arg2); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__backtrace_symbols__useretval() {
  // cppcheck-suppress ignoredReturnValue
  backtrace_symbols(arg1, arg2);
}

void test__backtrace_symbols__arg1__notnull() {
  // cppcheck-suppress nullPointer
  result = backtrace_symbols(NULL, arg2);
}

void test__backtrace_symbols__arg1__notuninit() {
  int x[10];
  // cppcheck-suppress uninitvar
  result = backtrace_symbols(x, arg2);
}

void test__backtrace_symbols__arg2__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  result = backtrace_symbols(arg1, x);
}

void test__backtrace_symbols_fd__noreturn() {
  int x = 1;
  if (cond) { x=100; backtrace_symbols_fd(arg1, arg2, arg3); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__backtrace_symbols_fd__arg1__notnull() {
  // cppcheck-suppress nullPointer
  backtrace_symbols_fd(NULL, arg2, arg3);
}

void test__backtrace_symbols_fd__arg1__notuninit() {
  int x[10];
  // cppcheck-suppress uninitvar
  backtrace_symbols_fd(x, arg2, arg3);
}

void test__backtrace_symbols_fd__arg2__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  backtrace_symbols_fd(arg1, x, arg3);
}

void test__backtrace_symbols_fd__arg3__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  backtrace_symbols_fd(arg1, arg2, x);
}

void test__ecvt__noreturn() {
  int x = 1;
  if (cond) { x=100; ecvt(arg1, arg2, arg3, arg4); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__ecvt__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  ecvt(x, arg2, arg3, arg4);
}

void test__ecvt__arg2__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  ecvt(arg1, x, arg3, arg4);
}

void test__ecvt__arg3__notnull() {
  // cppcheck-suppress nullPointer
  ecvt(arg1, arg2, NULL, arg4);
}

void test__ecvt__arg4__notnull() {
  // cppcheck-suppress nullPointer
  ecvt(arg1, arg2, arg3, NULL);
}

void test__qfcvt__noreturn() {
  int x = 1;
  if (cond) { x=100; qfcvt(arg1, arg2, arg3, arg4); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__qfcvt__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  qfcvt(x, arg2, arg3, arg4);
}

void test__qfcvt__arg2__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  qfcvt(arg1, x, arg3, arg4);
}

void test__qfcvt__arg3__notnull() {
  // cppcheck-suppress nullPointer
  qfcvt(arg1, arg2, NULL, arg4);
}

void test__qfcvt__arg4__notnull() {
  // cppcheck-suppress nullPointer
  qfcvt(arg1, arg2, arg3, NULL);
}

void test__qgcvt__noreturn() {
  int x = 1;
  if (cond) { x=100; qgcvt(arg1, arg2, arg3); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__qgcvt__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  qgcvt(x, arg2, arg3);
}

void test__qgcvt__arg2__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  qgcvt(arg1, x, arg3);
}

void test__qgcvt__arg3__notnull() {
  // cppcheck-suppress nullPointer
  qgcvt(arg1, arg2, NULL);
}

void test__ecvt_r__noreturn() {
  int x = 1;
  if (cond) { x=100; ecvt_r(arg1, arg2, arg3, arg4, arg5, arg6); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__ecvt_r__pure(int arg1,int arg2,int arg3,int arg4,int arg5,int arg6) {
  // cppcheck-suppress incorrectLogicOperator
  if ((ecvt_r(arg1, arg2, arg3, arg4, arg5, arg6) > 10) || (ecvt_r(arg1, arg2, arg3, arg4, arg5, arg6) < 100)) {}
}

void test__ecvt_r__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  ecvt_r(x, arg2, arg3, arg4, arg5, arg6);
}

void test__ecvt_r__arg2__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  ecvt_r(arg1, x, arg3, arg4, arg5, arg6);
}

void test__ecvt_r__arg3__notnull() {
  // cppcheck-suppress nullPointer
  ecvt_r(arg1, arg2, NULL, arg4, arg5, arg6);
}

void test__ecvt_r__arg4__notnull() {
  // cppcheck-suppress nullPointer
  ecvt_r(arg1, arg2, arg3, NULL, arg5, arg6);
}

void test__ecvt_r__arg5__notnull() {
  // cppcheck-suppress nullPointer
  ecvt_r(arg1, arg2, arg3, arg4, NULL, arg6);
}

void test__ecvt_r__arg6__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  ecvt_r(arg1, arg2, arg3, arg4, arg5, x);
}

void test__fcvt_r__noreturn() {
  int x = 1;
  if (cond) { x=100; fcvt_r(arg1, arg2, arg3, arg4, arg5, arg6); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__fcvt_r__pure(int arg1,int arg2,int arg3,int arg4,int arg5,int arg6) {
  // cppcheck-suppress incorrectLogicOperator
  if ((fcvt_r(arg1, arg2, arg3, arg4, arg5, arg6) > 10) || (fcvt_r(arg1, arg2, arg3, arg4, arg5, arg6) < 100)) {}
}

void test__fcvt_r__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  fcvt_r(x, arg2, arg3, arg4, arg5, arg6);
}

void test__fcvt_r__arg2__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  fcvt_r(arg1, x, arg3, arg4, arg5, arg6);
}

void test__fcvt_r__arg3__notnull() {
  // cppcheck-suppress nullPointer
  fcvt_r(arg1, arg2, NULL, arg4, arg5, arg6);
}

void test__fcvt_r__arg4__notnull() {
  // cppcheck-suppress nullPointer
  fcvt_r(arg1, arg2, arg3, NULL, arg5, arg6);
}

void test__fcvt_r__arg5__notnull() {
  // cppcheck-suppress nullPointer
  fcvt_r(arg1, arg2, arg3, arg4, NULL, arg6);
}

void test__fcvt_r__arg6__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  fcvt_r(arg1, arg2, arg3, arg4, arg5, x);
}

void test__qecvt_r__noreturn() {
  int x = 1;
  if (cond) { x=100; qecvt_r(arg1, arg2, arg3, arg4, arg5, arg6); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__qecvt_r__pure(int arg1,int arg2,int arg3,int arg4,int arg5,int arg6) {
  // cppcheck-suppress incorrectLogicOperator
  if ((qecvt_r(arg1, arg2, arg3, arg4, arg5, arg6) > 10) || (qecvt_r(arg1, arg2, arg3, arg4, arg5, arg6) < 100)) {}
}

void test__qecvt_r__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  qecvt_r(x, arg2, arg3, arg4, arg5, arg6);
}

void test__qecvt_r__arg2__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  qecvt_r(arg1, x, arg3, arg4, arg5, arg6);
}

void test__qecvt_r__arg3__notnull() {
  // cppcheck-suppress nullPointer
  qecvt_r(arg1, arg2, NULL, arg4, arg5, arg6);
}

void test__qecvt_r__arg4__notnull() {
  // cppcheck-suppress nullPointer
  qecvt_r(arg1, arg2, arg3, NULL, arg5, arg6);
}

void test__qecvt_r__arg5__notnull() {
  // cppcheck-suppress nullPointer
  qecvt_r(arg1, arg2, arg3, arg4, NULL, arg6);
}

void test__qecvt_r__arg6__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  qecvt_r(arg1, arg2, arg3, arg4, arg5, x);
}

void test__qfcvt_r__noreturn() {
  int x = 1;
  if (cond) { x=100; qfcvt_r(arg1, arg2, arg3, arg4, arg5, arg6); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__qfcvt_r__pure(int arg1,int arg2,int arg3,int arg4,int arg5,int arg6) {
  // cppcheck-suppress incorrectLogicOperator
  if ((qfcvt_r(arg1, arg2, arg3, arg4, arg5, arg6) > 10) || (qfcvt_r(arg1, arg2, arg3, arg4, arg5, arg6) < 100)) {}
}

void test__qfcvt_r__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  qfcvt_r(x, arg2, arg3, arg4, arg5, arg6);
}

void test__qfcvt_r__arg2__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  qfcvt_r(arg1, x, arg3, arg4, arg5, arg6);
}

void test__qfcvt_r__arg3__notnull() {
  // cppcheck-suppress nullPointer
  qfcvt_r(arg1, arg2, NULL, arg4, arg5, arg6);
}

void test__qfcvt_r__arg4__notnull() {
  // cppcheck-suppress nullPointer
  qfcvt_r(arg1, arg2, arg3, NULL, arg5, arg6);
}

void test__qfcvt_r__arg5__notnull() {
  // cppcheck-suppress nullPointer
  qfcvt_r(arg1, arg2, arg3, arg4, NULL, arg6);
}

void test__qfcvt_r__arg6__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  qfcvt_r(arg1, arg2, arg3, arg4, arg5, x);
}

void test__strcasestr__noreturn() {
  int x = 1;
  if (cond) { x=100; result = strcasestr(arg1, arg2); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__strcasestr__useretval() {
  // cppcheck-suppress ignoredReturnValue
  strcasestr(arg1, arg2);
}

void test__strcasestr__pure(int arg1,int arg2) {
  // cppcheck-suppress incorrectLogicOperator
  if ((strcasestr(arg1, arg2) > 10) || (strcasestr(arg1, arg2) < 100)) {}
}

void test__strcasestr__leakignore() {
  char *p = malloc(10); *p=0;
  result = strcasestr(p, arg2);
  // cppcheck-suppress memleak
}

void test__strcasestr__arg1__notnull() {
  // cppcheck-suppress nullPointer
  result = strcasestr(NULL, arg2);
}

void test__strcasestr__arg1__notuninit() {
  int x[10];
  // cppcheck-suppress uninitvar
  result = strcasestr(x, arg2);
}

void test__strcasestr__arg2__notnull() {
  // cppcheck-suppress nullPointer
  result = strcasestr(arg1, NULL);
}

void test__strcasestr__arg2__notuninit() {
  int x[10];
  // cppcheck-suppress uninitvar
  result = strcasestr(arg1, x);
}

void test__getresuid__noreturn() {
  int x = 1;
  if (cond) { x=100; getresuid(arg1, arg2, arg3); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__getresuid__pure(int arg1,int arg2,int arg3) {
  // cppcheck-suppress incorrectLogicOperator
  if ((getresuid(arg1, arg2, arg3) > 10) || (getresuid(arg1, arg2, arg3) < 100)) {}
}

void test__getresuid__leakignore() {
  char *p = malloc(10); *p=0;
  getresuid(p, arg2, arg3);
  // cppcheck-suppress memleak
}

void test__getresuid__arg1__notnull() {
  // cppcheck-suppress nullPointer
  getresuid(NULL, arg2, arg3);
}

void test__getresuid__arg2__notnull() {
  // cppcheck-suppress nullPointer
  getresuid(arg1, NULL, arg3);
}

void test__getresuid__arg3__notnull() {
  // cppcheck-suppress nullPointer
  getresuid(arg1, arg2, NULL);
}

void test__getresgid__noreturn() {
  int x = 1;
  if (cond) { x=100; getresgid(arg1, arg2, arg3); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__getresgid__pure(int arg1,int arg2,int arg3) {
  // cppcheck-suppress incorrectLogicOperator
  if ((getresgid(arg1, arg2, arg3) > 10) || (getresgid(arg1, arg2, arg3) < 100)) {}
}

void test__getresgid__leakignore() {
  char *p = malloc(10); *p=0;
  getresgid(p, arg2, arg3);
  // cppcheck-suppress memleak
}

void test__getresgid__arg1__notnull() {
  // cppcheck-suppress nullPointer
  getresgid(NULL, arg2, arg3);
}

void test__getresgid__arg2__notnull() {
  // cppcheck-suppress nullPointer
  getresgid(arg1, NULL, arg3);
}

void test__getresgid__arg3__notnull() {
  // cppcheck-suppress nullPointer
  getresgid(arg1, arg2, NULL);
}

void test__setresuid__noreturn() {
  int x = 1;
  if (cond) { x=100; setresuid(arg1, arg2, arg3); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__setresuid__leakignore() {
  char *p = malloc(10); *p=0;
  setresuid(p, arg2, arg3);
  // cppcheck-suppress memleak
}

void test__setresuid__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  setresuid(x, arg2, arg3);
}

void test__setresuid__arg2__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  setresuid(arg1, x, arg3);
}

void test__setresuid__arg3__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  setresuid(arg1, arg2, x);
}

void test__setresgid__noreturn() {
  int x = 1;
  if (cond) { x=100; setresgid(arg1, arg2, arg3); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__setresgid__leakignore() {
  char *p = malloc(10); *p=0;
  setresgid(p, arg2, arg3);
  // cppcheck-suppress memleak
}

void test__setresgid__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  setresgid(x, arg2, arg3);
}

void test__setresgid__arg2__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  setresgid(arg1, x, arg3);
}

void test__setresgid__arg3__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  setresgid(arg1, arg2, x);
}

void test__inet_aton__noreturn() {
  int x = 1;
  if (cond) { x=100; inet_aton(arg1, arg2); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__inet_aton__leakignore() {
  char *p = malloc(10); *p=0;
  inet_aton(p, arg2);
  // cppcheck-suppress memleak
}

void test__inet_aton__arg1__notnull() {
  // cppcheck-suppress nullPointer
  inet_aton(NULL, arg2);
}

void test__inet_aton__arg1__notuninit() {
  int x[10];
  // cppcheck-suppress uninitvar
  inet_aton(x, arg2);
}

void test__inet_aton__arg2__notnull() {
  // cppcheck-suppress nullPointer
  inet_aton(arg1, NULL);
}

void test__inet_addr__noreturn() {
  int x = 1;
  if (cond) { x=100; inet_addr(arg1); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__inet_addr__leakignore() {
  char *p = malloc(10); *p=0;
  inet_addr(p);
  // cppcheck-suppress memleak
}

void test__inet_addr__arg1__notnull() {
  // cppcheck-suppress nullPointer
  inet_addr(NULL);
}

void test__inet_addr__arg1__notuninit() {
  int x[10];
  // cppcheck-suppress uninitvar
  inet_addr(x);
}

void test__inet_network__noreturn() {
  int x = 1;
  if (cond) { x=100; inet_network(arg1); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__inet_network__leakignore() {
  char *p = malloc(10); *p=0;
  inet_network(p);
  // cppcheck-suppress memleak
}

void test__inet_network__arg1__notnull() {
  // cppcheck-suppress nullPointer
  inet_network(NULL);
}

void test__inet_network__arg1__notuninit() {
  int x[10];
  // cppcheck-suppress uninitvar
  inet_network(x);
}

void test__inet_ntoa__noreturn() {
  int x = 1;
  if (cond) { x=100; inet_ntoa(arg1); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__inet_ntoa__leakignore() {
  char *p = malloc(10); *p=0;
  inet_ntoa(p);
  // cppcheck-suppress memleak
}

void test__inet_ntoa__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  inet_ntoa(x);
}

void test__inet_makeaddr__noreturn() {
  int x = 1;
  if (cond) { x=100; inet_makeaddr(arg1, arg2); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__inet_makeaddr__leakignore() {
  char *p = malloc(10); *p=0;
  inet_makeaddr(p, arg2);
  // cppcheck-suppress memleak
}

void test__inet_makeaddr__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  inet_makeaddr(x, arg2);
}

void test__inet_makeaddr__arg2__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  inet_makeaddr(arg1, x);
}

void test__inet_lnaof__noreturn() {
  int x = 1;
  if (cond) { x=100; inet_lnaof(arg1); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__inet_lnaof__leakignore() {
  char *p = malloc(10); *p=0;
  inet_lnaof(p);
  // cppcheck-suppress memleak
}

void test__inet_lnaof__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  inet_lnaof(x);
}

void test__inet_netof__noreturn() {
  int x = 1;
  if (cond) { x=100; inet_netof(arg1); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__inet_netof__leakignore() {
  char *p = malloc(10); *p=0;
  inet_netof(p);
  // cppcheck-suppress memleak
}

void test__inet_netof__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  inet_netof(x);
}

void test__inet_pton__noreturn() {
  int x = 1;
  if (cond) { x=100; inet_pton(arg1, arg2, arg3); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__inet_pton__leakignore() {
  char *p = malloc(10); *p=0;
  inet_pton(p, arg2, arg3);
  // cppcheck-suppress memleak
}

void test__inet_pton__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  inet_pton(x, arg2, arg3);
}

void test__inet_pton__arg2__notnull() {
  // cppcheck-suppress nullPointer
  inet_pton(arg1, NULL, arg3);
}

void test__inet_pton__arg2__notuninit() {
  int x[10];
  // cppcheck-suppress uninitvar
  inet_pton(arg1, x, arg3);
}

void test__inet_pton__arg3__notnull() {
  // cppcheck-suppress nullPointer
  inet_pton(arg1, arg2, NULL);
}

void test__inet_ntop__noreturn() {
  int x = 1;
  if (cond) { x=100; inet_ntop(arg1, arg2, arg3, arg4); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__inet_ntop__leakignore() {
  char *p = malloc(10); *p=0;
  inet_ntop(p, arg2, arg3, arg4);
  // cppcheck-suppress memleak
}

void test__inet_ntop__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  inet_ntop(x, arg2, arg3, arg4);
}

void test__inet_ntop__arg2__notnull() {
  // cppcheck-suppress nullPointer
  inet_ntop(arg1, NULL, arg3, arg4);
}

void test__inet_ntop__arg2__notuninit() {
  int x[10];
  // cppcheck-suppress uninitvar
  inet_ntop(arg1, x, arg3, arg4);
}

void test__inet_ntop__arg3__notnull() {
  // cppcheck-suppress nullPointer
  inet_ntop(arg1, arg2, NULL, arg4);
}

void test__inet_ntop__arg4__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  inet_ntop(arg1, arg2, arg3, x);
}

void test__canonicalize_file_name__noreturn() {
  int x = 1;
  if (cond) { x=100; result = canonicalize_file_name(arg1); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__canonicalize_file_name__useretval() {
  // cppcheck-suppress ignoredReturnValue
  canonicalize_file_name(arg1);
}

void test__canonicalize_file_name__leakignore() {
  char *p = malloc(10); *p=0;
  result = canonicalize_file_name(p);
  // cppcheck-suppress memleak
}

void test__canonicalize_file_name__arg1__notnull() {
  // cppcheck-suppress nullPointer
  result = canonicalize_file_name(NULL);
}

void test__execvpe__noreturn() {
  int x = 1;
  if (cond) { x=100; execvpe(arg1, arg2, arg3); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__execvpe__leakignore() {
  char *p = malloc(10); *p=0;
  execvpe(p, arg2, arg3);
  // cppcheck-suppress memleak
}

void test__execvpe__arg1__notnull() {
  // cppcheck-suppress nullPointer
  execvpe(NULL, arg2, arg3);
}

void test__execvpe__arg1__notuninit() {
  int x[10];
  // cppcheck-suppress uninitvar
  execvpe(x, arg2, arg3);
}

void test__execvpe__arg2__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  execvpe(arg1, x, arg3);
}

void test__execvpe__arg3__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  execvpe(arg1, arg2, x);
}

void test__mkostemp__noreturn() {
  int x = 1;
  if (cond) { x=100; mkostemp(arg1, arg2); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__mkostemp__leakignore() {
  char *p = malloc(10); *p=0;
  mkostemp(p, arg2);
  // cppcheck-suppress memleak
}

void test__mkostemp__arg1__notnull() {
  // cppcheck-suppress nullPointer
  mkostemp(NULL, arg2);
}

void test__mkostemp__arg1__notuninit() {
  int x[10];
  // cppcheck-suppress uninitvar
  mkostemp(x, arg2);
}

void test__mkostemp__arg2__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  mkostemp(arg1, x);
}

void test__mkstemps__noreturn() {
  int x = 1;
  if (cond) { x=100; mkstemps(arg1, arg2); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__mkstemps__leakignore() {
  char *p = malloc(10); *p=0;
  mkstemps(p, arg2);
  // cppcheck-suppress memleak
}

void test__mkstemps__arg1__notnull() {
  // cppcheck-suppress nullPointer
  mkstemps(NULL, arg2);
}

void test__mkstemps__arg1__notuninit() {
  int x[10];
  // cppcheck-suppress uninitvar
  mkstemps(x, arg2);
}

void test__mkstemps__arg2__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  mkstemps(arg1, x);
}

void test__mkostemps__noreturn() {
  int x = 1;
  if (cond) { x=100; mkostemps(arg1, arg2, arg3); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__mkostemps__leakignore() {
  char *p = malloc(10); *p=0;
  mkostemps(p, arg2, arg3);
  // cppcheck-suppress memleak
}

void test__mkostemps__arg1__notnull() {
  // cppcheck-suppress nullPointer
  mkostemps(NULL, arg2, arg3);
}

void test__mkostemps__arg1__notuninit() {
  int x[10];
  // cppcheck-suppress uninitvar
  mkostemps(x, arg2, arg3);
}

void test__mkostemps__arg2__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  mkostemps(arg1, x, arg3);
}

void test__mkostemps__arg3__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  mkostemps(arg1, arg2, x);
}

void test__memmem__noreturn() {
  int x = 1;
  if (cond) { x=100; result = memmem(arg1, arg2, arg3, arg4); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__memmem__useretval() {
  // cppcheck-suppress ignoredReturnValue
  memmem(arg1, arg2, arg3, arg4);
}

void test__memmem__leakignore() {
  char *p = malloc(10); *p=0;
  result = memmem(p, arg2, arg3, arg4);
  // cppcheck-suppress memleak
}

void test__memmem__arg1__notnull() {
  // cppcheck-suppress nullPointer
  result = memmem(NULL, arg2, arg3, arg4);
}

void test__memmem__arg1__notuninit() {
  int x[10];
  // cppcheck-suppress uninitvar
  result = memmem(x, arg2, arg3, arg4);
}

void test__memmem__arg2__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  result = memmem(arg1, x, arg3, arg4);
}

void test__memmem__arg3__notnull() {
  // cppcheck-suppress nullPointer
  result = memmem(arg1, arg2, NULL, arg4);
}

void test__memmem__arg3__notuninit() {
  int x[10];
  // cppcheck-suppress uninitvar
  result = memmem(arg1, arg2, x, arg4);
}

void test__memmem__arg4__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  result = memmem(arg1, arg2, arg3, x);
}

void test__memrchr__noreturn() {
  int x = 1;
  if (cond) { x=100; memrchr(arg1, arg2, arg3); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__memrchr__leakignore() {
  char *p = malloc(10); *p=0;
  memrchr(p, arg2, arg3);
  // cppcheck-suppress memleak
}

void test__memrchr__arg1__notnull() {
  // cppcheck-suppress nullPointer
  memrchr(NULL, arg2, arg3);
}

void test__memrchr__arg1__notuninit() {
  int x[10];
  // cppcheck-suppress uninitvar
  memrchr(x, arg2, arg3);
}

void test__memrchr__arg2__notbool() {
  // cppcheck-suppress invalidFunctionArgBool
  memrchr(arg1, !x, arg3);
}

void test__memrchr__arg2__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  memrchr(arg1, x, arg3);
}

void test__memrchr__arg3__notbool() {
  // cppcheck-suppress invalidFunctionArgBool
  memrchr(arg1, arg2, !x);
}

void test__rawmemchr__noreturn() {
  int x = 1;
  if (cond) { x=100; rawmemchr(arg1, arg2); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__rawmemchr__leakignore() {
  char *p = malloc(10); *p=0;
  rawmemchr(p, arg2);
  // cppcheck-suppress memleak
}

void test__rawmemchr__arg1__notnull() {
  // cppcheck-suppress nullPointer
  rawmemchr(NULL, arg2);
}

void test__rawmemchr__arg1__notuninit() {
  int x[10];
  // cppcheck-suppress uninitvar
  rawmemchr(x, arg2);
}

void test__rawmemchr__arg2__notbool() {
  // cppcheck-suppress invalidFunctionArgBool
  rawmemchr(arg1, !x);
}

void test__rawmemchr__arg2__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  rawmemchr(arg1, x);
}

void test__ffsl__noreturn() {
  int x = 1;
  if (cond) { x=100; result = ffsl(arg1); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__ffsl__useretval() {
  // cppcheck-suppress ignoredReturnValue
  ffsl(arg1);
}

void test__ffsl__leakignore() {
  char *p = malloc(10); *p=0;
  result = ffsl(p);
  // cppcheck-suppress memleak
}

void test__ffsl__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  result = ffsl(x);
}

void test__ffsll__noreturn() {
  int x = 1;
  if (cond) { x=100; result = ffsll(arg1); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__ffsll__useretval() {
  // cppcheck-suppress ignoredReturnValue
  ffsll(arg1);
}

void test__ffsll__leakignore() {
  char *p = malloc(10); *p=0;
  result = ffsll(p);
  // cppcheck-suppress memleak
}

void test__ffsll__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  result = ffsll(x);
}

void test__strchrnul__noreturn() {
  int x = 1;
  if (cond) { x=100; result = strchrnul(arg1, arg2); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__strchrnul__useretval() {
  // cppcheck-suppress ignoredReturnValue
  strchrnul(arg1, arg2);
}

void test__strchrnul__leakignore() {
  char *p = malloc(10); *p=0;
  result = strchrnul(p, arg2);
  // cppcheck-suppress memleak
}

void test__strchrnul__arg1__notnull() {
  // cppcheck-suppress nullPointer
  result = strchrnul(NULL, arg2);
}

void test__strchrnul__arg1__notuninit() {
  int x[10];
  // cppcheck-suppress uninitvar
  result = strchrnul(x, arg2);
}

void test__strchrnul__arg2__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  result = strchrnul(arg1, x);
}

void test__prlimit__noreturn() {
  int x = 1;
  if (cond) { x=100; prlimit(arg1, arg2, arg3, arg4); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__prlimit__leakignore() {
  char *p = malloc(10); *p=0;
  prlimit(p, arg2, arg3, arg4);
  // cppcheck-suppress memleak
}

void test__prlimit__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  prlimit(x, arg2, arg3, arg4);
}

void test__prlimit__arg2__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  prlimit(arg1, x, arg3, arg4);
}

void test__prlimit__arg3__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  prlimit(arg1, arg2, x, arg4);
}

void test__epoll_create__noreturn() {
  int x = 1;
  if (cond) { x=100; epoll_create(arg1); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__epoll_create__arg1__notbool() {
  // cppcheck-suppress invalidFunctionArgBool
  epoll_create(!x);
}

void test__epoll_create__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  epoll_create(x);
}

void test__epoll_create1__noreturn() {
  int x = 1;
  if (cond) { x=100; epoll_create1(arg1); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__epoll_create1__arg1__notbool() {
  // cppcheck-suppress invalidFunctionArgBool
  epoll_create1(!x);
}

void test__epoll_create1__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  epoll_create1(x);
}

void test__epoll_ctl__noreturn() {
  int x = 1;
  if (cond) { x=100; epoll_ctl(arg1, arg2, arg3, arg4); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__epoll_ctl__arg1__notbool() {
  // cppcheck-suppress invalidFunctionArgBool
  epoll_ctl(!x, arg2, arg3, arg4);
}

void test__epoll_ctl__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  epoll_ctl(x, arg2, arg3, arg4);
}

void test__epoll_ctl__arg2__notbool() {
  // cppcheck-suppress invalidFunctionArgBool
  epoll_ctl(arg1, !x, arg3, arg4);
}

void test__epoll_ctl__arg2__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  epoll_ctl(arg1, x, arg3, arg4);
}

void test__epoll_ctl__arg3__notbool() {
  // cppcheck-suppress invalidFunctionArgBool
  epoll_ctl(arg1, arg2, !x, arg4);
}

void test__epoll_ctl__arg3__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  epoll_ctl(arg1, arg2, x, arg4);
}

void test__epoll_ctl__arg4__notbool() {
  // cppcheck-suppress invalidFunctionArgBool
  epoll_ctl(arg1, arg2, arg3, !x);
}

void test__epoll_ctl__arg4__notnull() {
  // cppcheck-suppress nullPointer
  epoll_ctl(arg1, arg2, arg3, NULL);
}

void test__epoll_wait__noreturn() {
  int x = 1;
  if (cond) { x=100; epoll_wait(arg1, arg2, arg3, arg4); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__epoll_wait__arg1__notbool() {
  // cppcheck-suppress invalidFunctionArgBool
  epoll_wait(!x, arg2, arg3, arg4);
}

void test__epoll_wait__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  epoll_wait(x, arg2, arg3, arg4);
}

void test__epoll_wait__arg2__notbool() {
  // cppcheck-suppress invalidFunctionArgBool
  epoll_wait(arg1, !x, arg3, arg4);
}

void test__epoll_wait__arg2__notnull() {
  // cppcheck-suppress nullPointer
  epoll_wait(arg1, NULL, arg3, arg4);
}

void test__epoll_wait__arg3__notbool() {
  // cppcheck-suppress invalidFunctionArgBool
  epoll_wait(arg1, arg2, !x, arg4);
}

void test__epoll_wait__arg3__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  epoll_wait(arg1, arg2, x, arg4);
}

void test__epoll_wait__arg4__notbool() {
  // cppcheck-suppress invalidFunctionArgBool
  epoll_wait(arg1, arg2, arg3, !x);
}

void test__epoll_wait__arg4__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  epoll_wait(arg1, arg2, arg3, x);
}

void test__epoll_pwait__noreturn() {
  int x = 1;
  if (cond) { x=100; epoll_pwait(arg1, arg2, arg3, arg4, arg5); }
  // cppcheck-suppress shiftTooManyBits
  x = 1 << x;
}

void test__epoll_pwait__arg1__notbool() {
  // cppcheck-suppress invalidFunctionArgBool
  epoll_pwait(!x, arg2, arg3, arg4, arg5);
}

void test__epoll_pwait__arg1__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  epoll_pwait(x, arg2, arg3, arg4, arg5);
}

void test__epoll_pwait__arg2__notbool() {
  // cppcheck-suppress invalidFunctionArgBool
  epoll_pwait(arg1, !x, arg3, arg4, arg5);
}

void test__epoll_pwait__arg2__notnull() {
  // cppcheck-suppress nullPointer
  epoll_pwait(arg1, NULL, arg3, arg4, arg5);
}

void test__epoll_pwait__arg3__notbool() {
  // cppcheck-suppress invalidFunctionArgBool
  epoll_pwait(arg1, arg2, !x, arg4, arg5);
}

void test__epoll_pwait__arg3__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  epoll_pwait(arg1, arg2, x, arg4, arg5);
}

void test__epoll_pwait__arg4__notbool() {
  // cppcheck-suppress invalidFunctionArgBool
  epoll_pwait(arg1, arg2, arg3, !x, arg5);
}

void test__epoll_pwait__arg4__notuninit() {
  int x;
  // cppcheck-suppress uninitvar
  epoll_pwait(arg1, arg2, arg3, x, arg5);
}

void test__epoll_pwait__arg5__notbool() {
  // cppcheck-suppress invalidFunctionArgBool
  epoll_pwait(arg1, arg2, arg3, arg4, !x);
}

void test__epoll_pwait__arg5__notnull() {
  // cppcheck-suppress nullPointer
  epoll_pwait(arg1, arg2, arg3, arg4, NULL);
}

void test__epoll_pwait__arg5__notuninit() {
  int x[10];
  // cppcheck-suppress uninitvar
  epoll_pwait(arg1, arg2, arg3, arg4, x);
}

