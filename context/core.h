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
	void (*pTASK)(void);
}TCB;

void save_switch(TCB*);
void allocate_space(TCB*);

#endif /* CORE_H_ */