#include "v_common.h" 
#include "fastonebigheader.h"


double (*v_exp)( double arg );

F_ONE(exp, 0, double, double, exp)
F_ONE(exp, 1, double, double, expf)
F_ONE(exp, 2, double, double, fastexp)
F_ONE(exp, 3, double, double, fasterexp)

double (*__v_exp[])(double arg) = {__var__exp0, __var__exp1, __var__exp2, __var__exp3};

LEVELS(exp, 3)
LIB_INIT(exp, "exp")
