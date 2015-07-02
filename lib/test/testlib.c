#include <stdio.h>
#include <signal.h>
#include "testlib.h"

void __attribute__ ((constructor)) libinit(void);
void __attribute__ ((destructor)) libdestroy(void);


void sighandler(int signal) {
	if (f == fa) 
		f = fb;
	else
		f = fa;
}

void libinit(void) {
	printf("init\n");
	f = fb;
	signal(SIGUSR1,sighandler);
}

void libdestroy(void) {
	printf("destructor\n");
}

int fa(int param) {
	printf("fa(%d)\n", param);
	return param;
}

int fb(int param) {
        printf("fb(%d)\n", param);
        return param;
}
