#ifndef VARMATH_H
#define VARMATH_H



// v_* functions match standard API
#ifdef __cplusplus
extern "C" {
#endif
	extern double (*v_exp)( double arg );
	void v_exp_set_qlevel(int lvl);
	int v_exp_get_qlevel(void);
	int v_exp_avl_qlevel(void);
	
	extern double (*v_log)( double arg );
	void v_log_set_qlevel(int lvl);
	int v_log_get_qlevel(void);
	int v_log_avl_qlevel(void);	
	
	
	
#ifdef __cplusplus
}
#endif




#endif
