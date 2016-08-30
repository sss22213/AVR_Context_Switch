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
typedef struct _Stack Stack;
typedef struct _Stack 
{
	uint8_t SP_Hi;
	uint8_t SP_Lo;
}Stack;
typedef struct _TCB 
{
	uint8_t PID;	
	uint8_t SP_Hi;
	uint8_t SP_Lo;
	void (*pTASK)(void);
}TCB;
#define save_switch(pTCB)\
	asm volatile ("push  r0\n\t"\
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
	"sts (pTCB)+1,r17\n\t"\
	"sts (pTCB)+2,r18\n\t"\
);

void allocate_space(TCB*);
extern inline void restore_switch(TCB*);

#endif /* CORE_H_ */