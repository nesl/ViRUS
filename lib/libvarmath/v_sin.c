#include "v_common.h" 
#include "fastonebigheader.h"

double (*v_sin)( double arg );

F_ONE(sin, 0, double, double, sin)
F_ONE(sin, 1, double, double, sinf)
F_ONE(sin, 2, double, double, fastsin)
F_ONE(sin, 3, double, double, fastersin)

double (*__v_sin[])(double arg) = {__var__sin0, __var__sin1, __var__sin2, __var__sin3};

LEVELS(sin, 3)
LIB_INIT(sin, "sin")
