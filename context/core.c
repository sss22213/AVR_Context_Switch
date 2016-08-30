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
void save_switch(TCB* TASK)
{
	uint8_t *pSPH=&TASK->SP_Hi;
	uint8_t *pSPL=&TASK->SP_Lo;
	asm volatile (
	"push  r0\n\t"
	"in r0,__SREG__\n\t"
	"push  r0\n\t"
	"push  r1\n\t"
	"push  r2\n\t"
	"push  r3\n\t"
	"push  r4\n\t"
	"push  r5\n\t"
	"push  r6\n\t"
	"push  r7\n\t"
	"push  r8\n\t"
	"push  r9\n\t"
	"push  r10\n\t"
	"push  r11\n\t"
	"push  r12\n\t"
	"push  r13\n\t"
	"push  r14\n\t"
	"push  r15\n\t"
	"push  r16\n\t"
	"push  r17\n\t"
	"push  r18\n\t"
	"push  r19\n\t"
	"push  r20\n\t"
	"push  r21\n\t"
	"push  r22\n\t"
	"push  r23\n\t"
	"push  r24\n\t"
	"push  r25\n\t"
	"push  r26\n\t"
	"push  r27\n\t"
	"push  r28\n\t"
	"push  r29\n\t"
	"push  r30\n\t"
	"push  r31\n\t"
	"lds r17,__SPH__\n\t"
	"lds r18,__SPL__\n\t"
	"sts pSPH,r17\n\t"
	"sts pSPL,r18\n\t"
	);

}