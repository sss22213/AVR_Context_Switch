/*
 * core.h
 *
 * Created: 2016/08/30 下午 02:36:08
 *  Author: bohung
 */ 
#ifndef CORE_H_
#define CORE_H_
#include <stdint.h>
#include <avr/io.h>
typedef struct _TCB TCB;
typedef struct _TCB 
{
	uint8_t PID;	
	uint8_t SP_Hi;
	uint8_t SP_Lo;
	uint8_t count;
	void (*pTASK)(void);
}TCB;

extern TCB* pTCB; 
extern TCB TASK[2];

#define save_switch()\
	asm volatile (\
	"push  r0\n\t"\
	"in r0,__SREG__\n\t"\
	"push  r0\n\t"\
	"push  r1\n\t"\
	"push  r2\n\t"\
	"push  r3\n\t"\
	"push  r4\n\t"\
	"push  r5\n\t"\
	"push  r6\n\t"\
	"push  r7\n\t"\
	"push  r8\n\t"\
	"push  r9\n\t"\
	"push  r10\n\t"\
	"push  r11\n\t"\
	"push  r12\n\t"\
	"push  r13\n\t"\
	"push  r14\n\t"\
	"push  r15\n\t"\
	"push  r16\n\t"\
	"push  r17\n\t"\
	"push  r18\n\t"\
	"push  r19\n\t"\
	"push  r20\n\t"\
	"push  r21\n\t"\
	"push  r22\n\t"\
	"push  r23\n\t"\
	"push  r24\n\t"\
	"push  r25\n\t"\
	"push  r26\n\t"\
	"push  r27\n\t"\
	"push  r28\n\t"\
	"push  r29\n\t"\
	"push  r30\n\t"\
	"push  r31\n\t"\
	"in r17,0x3d\n\t"\
	"in r18,0x3e\n\t"\
	"lds r26,pTCB\n\t"\
	"lds r27,pTCB+1\n\t"\
	"st x+,r17\n\t"\
	"st x+,r18\n\t"\
);
#define restore_switch()\
	asm volatile (\
	"sts pTCB,r26\n\t"\
	"sts pTCB+1,r27\n\t"\
	"ld r17,x+\n\t"\
	"ld r18,x+\n\t"\
	"out 0x3d,r17\n\t"\
	"out 0x3e,r18\n\t"\
	"pop r31\n\t"\
	"pop r30\n\t"\
	"pop r29\n\t"\
	"pop r28\n\t"\
	"pop r27\n\t"\
	"pop r26\n\t"\
	"pop r25\n\t"\
	"pop r24\n\t"\
	"pop r23\n\t"\
	"pop r22\n\t"\
	"pop r21\n\t"\
	"pop r20\n\t"\
	"pop r19\n\t"\
	"pop r18\n\t"\
	"pop r17\n\t"\
	"pop r16\n\t"\
	"pop r15\n\t"\
	"pop r14\n\t"\
	"pop r13\n\t"\
	"pop r12\n\t"\
	"pop r11\n\t"\
	"pop r10\n\t"\
	"pop r9\n\t"\
	"pop r8\n\t"\
	"pop r7\n\t"\
	"pop r6\n\t"\
	"pop r5\n\t"\
	"pop r4\n\t"\
	"pop r3\n\t"\
	"pop r2\n\t"\
	"pop r1\n\t"\
	"pop r0\n\t"\
	"out __SREG__,r0\n\t"\
	"pop r0\n\t"\
	);
uint8_t allocate_space();

#endif /* CORE_H_ */