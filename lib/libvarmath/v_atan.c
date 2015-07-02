#include "v_common.h" 
#include "fastonebigheader.h"

double (*v_atan)( double arg );

F_ONE(atan, 0, double, double, atan)
F_ONE(atan, 1, double, double, atanf)

double (*__v_atan[])(double arg) = {__var__atan0, __var__atan1};

LEVELS(atan, 1)
LIB_INIT(atan, "atan")
