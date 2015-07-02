#include "v_common.h" 
#include "fastonebigheader.h"

double (*v_nothing)( double arg );

F_ONE(nothing, 0, double, double, exp)
F_ONE(nothing, 1, double, double, exp)

double (*__v_nothing[])(double arg) = {__var__nothing0, __var__nothing1};

LEVELS(nothing, 1)
LIB_INIT(nothing, "nothing")
