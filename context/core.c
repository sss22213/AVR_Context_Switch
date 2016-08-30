/*
 * core.c
 *
 * Created: 2016/08/30 下午 02:35:56
 *  Author: bohung
 */ 
#include "core.h"
void allocate_space(TCB* TASK)
{
	//first
	TASK->pTASK();
	
}

inline void restore_switch(TCB* TASK)
{
	uint8_t *pSPH=&TASK->SP_Hi;
	uint8_t *pSPL=&TASK->SP_Lo;
	/*asm volatile (
	"sts __SPL__,r18\n\t"
	"sts __SPH__,r17\n\t"
	"pop r31\n\t"
	"pop r30\n\t"
	"pop r29\n\t"
	"pop r28\n\t"
	"pop r27\n\t"
	"pop r26\n\t"
	"pop r25\n\t"
	"pop r24\n\t"
	"pop r23\n\t"
	"pop r22\n\t"
	"pop r21\n\t"
	"pop r20\n\t"
	"pop r19\n\t"
	"pop r18\n\t"
	"pop r17\n\t"
	"pop r16\n\t"
	"pop r15\n\t"
	"pop r14\n\t"
	"pop r13\n\t"
	"pop r12\n\t"
	"pop r11\n\t"
	"pop r10\n\t"
	"pop r9\n\t"
	"pop r8\n\t"
	"pop r7\n\t"
	"pop r6\n\t"
	"pop r5\n\t"
	"pop r4\n\t"
	"pop r3\n\t"
	"pop r2\n\t"
	"pop r1\n\t"
	"pop __SREG__\n\t"
	"pop r0\n\t"
	);*/
}