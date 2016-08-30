/*
 * context.c
 *
 * Created: 2016/08/30 下午 02:34:07
 * Author : bohung
 */ 
#define F_CPU 16000000
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include "core.h"
uint8_t count=0;
TCB TASK[2];
void TASK1()
{
	while(1)asm("ldi r16,0xFC");
}
void TASK2()
{
	while(1)asm("ldi r17,0xCF");
}
int main(void)
{
	
	TASK[0].PID=0;
	TASK[1].PID=1;
	TASK[0].pTASK=TASK1;
	TASK[1].pTASK=TASK2;
	OCR1A = 0x0010; 
	TCCR1B |= (1 << WGM12); 
	TIMSK1 |= (1 << OCIE1A); 
	TCCR1B |= (1 << CS12) | (1 << CS10);
	sei();
    /* Replace with your application code */
	TASK[0].pTASK();
    while (1) 
    {
    }
}
ISR (TIMER1_COMPA_vect) {
	cli();
	save_switch(&(TASK[0]));
	restore_switch(&(TASK[1]));
	count++;
	sei();
}

