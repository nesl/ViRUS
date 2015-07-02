#ifndef V_COMMON_H
#define V_COMMON_H

#include "virus.h"

#define F_ONE( name, level, rettype, argtype, f ) \
rettype __var__ ##name ##level (argtype arg) { return f(arg); }


#define F_DECLARATIONS_ONE( name, rettype, argtype ) \
extern rettype (*v_##name)( argtype arg ); \
void v_ ##name ## _set_qlevel(int lvl); \
int v_ ##name ## _get_qlevel(void); \
int v_ ##name ## _avl_qlevel(void); 


#define LEVELS( name, max_level) \
int __v_ ##name ## _curr_level = 0; \
void v_ ##name ## _set_qlevel(int lvl) \
{ \
	if (lvl < 0) { \
		lvl = 0; \
	}; \
	if (lvl > max_level) { \
		lvl = max_level; \
	}; \
	__v_ ##name ## _curr_level = lvl; \
	v_ ##name =__v_##name[lvl]; \
} \
int v_ ##name ## _get_qlevel(void) { return __v_ ##name ## _curr_level;} \
int v_ ##name ## _avl_qlevel(void) { return max_level; }

#define LIB_INIT( name, strname ) \
void __attribute__ ((constructor)) __var__ ##name ## _init(void); \
void __var__ ##name ## _init(void) { \
	__v_ ##name ## _curr_level = 0; \
	v_ ##name =__v_##name[0]; \
	v_register_knob(strname, v_ ##name ## _set_qlevel, v_ ##name ## _get_qlevel, v_ ##name ## _avl_qlevel); \
} 

#endif
