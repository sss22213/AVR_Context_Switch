/*
 * context.c
 *
 * Created: 2016/08/30 下午 02:34:07
 * Author : bohung
 */ 

#include "main.h"
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
	//if(!allocate_space())
	//{	
		cli();
		pTCB_SWP(count%2);
		save_switch();
		pTCB_SWP(!(count%2));
		restore_switch();
		count++;
		sei();
	//}
}

