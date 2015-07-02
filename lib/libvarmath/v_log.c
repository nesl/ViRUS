#include "v_common.h" 
#include "fastonebigheader.h"


double (*v_log)( double arg );

F_ONE(log, 0, double, double, log)
F_ONE(log, 1, double, double, logf)
F_ONE(log, 2, double, double, fastlog)
F_ONE(log, 3, double, double, fasterlog)

double (*__v_log[])(double arg) = {__var__log0, __var__log1, __var__log2, __var__log3};

LEVELS(log, 3)
LIB_INIT(log, "log")
