#include "v_common.h" 
#include "fastonebigheader.h"

double (*v_cos)( double arg );

F_ONE(cos, 0, double, double, cos)
F_ONE(cos, 1, double, double, cosf)
F_ONE(cos, 2, double, double, fastcos)
F_ONE(cos, 3, double, double, fastercos)

double (*__v_cos[])(double arg) = {__var__cos0, __var__cos1, __var__cos2, __var__cos3};

LEVELS(cos, 3)
LIB_INIT(cos, "cos")
