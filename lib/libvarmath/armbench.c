#include <stdio.h>

//sin,0,temperature,60,100,2,4

extern double a = 1.1f;
extern double b = 1.12f;
extern double c = 1.13f;
extern double d = 1.14f;


int main() {
	
	a = exp(a);
	//b = exp(b);
	
	
	printf("%f %f\n", a, b);
	
	return 0;
	
}


void __attribute__ ((constructor)) someinit(void);

void someinit(void) 
{
	a = b;
}
