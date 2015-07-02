#include <stdio.h>
#include <signal.h>
#include "vemu.h"

void __attribute__ ((destructor)) libdestroy(void);

vemu_regs proc;

void libdestroy(void) {
	vemu_read(READ_PROC, &proc);	
	printf("\nvaremu cycles: %llu\te: %llu\n", proc.total_cycles, proc.total_act_energy);
}
