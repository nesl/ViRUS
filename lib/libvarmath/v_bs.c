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



double (*v_cos1)( double arg );

F_ONE(cos1, 0, double, double, cos)
F_ONE(cos1, 1, double, double, cosf)
F_ONE(cos1, 2, double, double, fastcos)
F_ONE(cos1, 3, double, double, fastercos)

double (*__v_cos1[])(double arg) = {__var__cos10, __var__cos11, __var__cos12, __var__cos13};

LEVELS(cos1, 3)
LIB_INIT(cos1, "cos1")


double (*v_cos2)( double arg );

F_ONE(cos2, 0, double, double, cos)
F_ONE(cos2, 1, double, double, cosf)
F_ONE(cos2, 2, double, double, fastcos)
F_ONE(cos2, 3, double, double, fastercos)

double (*__v_cos2[])(double arg) = {__var__cos20, __var__cos21, __var__cos22, __var__cos23};

LEVELS(cos2, 3)
LIB_INIT(cos2, "cos2")



double (*v_cos3)( double arg );

F_ONE(cos3, 0, double, double, cos)
F_ONE(cos3, 1, double, double, cosf)
F_ONE(cos3, 2, double, double, fastcos)
F_ONE(cos3, 3, double, double, fastercos)

double (*__v_cos3[])(double arg) = {__var__cos30, __var__cos31, __var__cos32, __var__cos33};

LEVELS(cos3, 3)
LIB_INIT(cos3, "cos3")





double (*v_cos4)( double arg );

F_ONE(cos4, 0, double, double, cos)
F_ONE(cos4, 1, double, double, cosf)
F_ONE(cos4, 2, double, double, fastcos)
F_ONE(cos4, 3, double, double, fastercos)

double (*__v_cos4[])(double arg) = {__var__cos40, __var__cos41, __var__cos42, __var__cos43};

LEVELS(cos4, 3)
LIB_INIT(cos4, "cos4")



double (*v_cos5)( double arg );

F_ONE(cos5, 0, double, double, cos)
F_ONE(cos5, 1, double, double, cosf)
F_ONE(cos5, 2, double, double, fastcos)
F_ONE(cos5, 3, double, double, fastercos)

double (*__v_cos5[])(double arg) = {__var__cos50, __var__cos51, __var__cos52, __var__cos53};

LEVELS(cos5, 3)
LIB_INIT(cos5, "cos5")



double (*v_cos6)( double arg );

F_ONE(cos6, 0, double, double, cos)
F_ONE(cos6, 1, double, double, cosf)
F_ONE(cos6, 2, double, double, fastcos)
F_ONE(cos6, 3, double, double, fastercos)

double (*__v_cos6[])(double arg) = {__var__cos60, __var__cos61, __var__cos62, __var__cos63};

LEVELS(cos6, 3)
LIB_INIT(cos6, "cos6")


double (*v_cos7)( double arg );

F_ONE(cos7, 0, double, double, cos)
F_ONE(cos7, 1, double, double, cosf)
F_ONE(cos7, 2, double, double, fastcos)
F_ONE(cos7, 3, double, double, fastercos)

double (*__v_cos7[])(double arg) = {__var__cos70, __var__cos71, __var__cos72, __var__cos73};

LEVELS(cos7, 3)
LIB_INIT(cos7, "cos7")


double (*v_cos8)( double arg );

F_ONE(cos8, 0, double, double, cos)
F_ONE(cos8, 1, double, double, cosf)
F_ONE(cos8, 2, double, double, fastcos)
F_ONE(cos8, 3, double, double, fastercos)

double (*__v_cos8[])(double arg) = {__var__cos80, __var__cos81, __var__cos82, __var__cos83};

LEVELS(cos8, 3)
LIB_INIT(cos8, "cos8")


double (*v_cos9)( double arg );

F_ONE(cos9, 0, double, double, cos)
F_ONE(cos9, 1, double, double, cosf)
F_ONE(cos9, 2, double, double, fastcos)
F_ONE(cos9, 3, double, double, fastercos)

double (*__v_cos9[])(double arg) = {__var__cos90, __var__cos91, __var__cos92, __var__cos93};

LEVELS(cos9, 3)
LIB_INIT(cos9, "cos9")


