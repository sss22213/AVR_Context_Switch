/*
 * core.c
 *
 * Created: 2016/08/30 下午 02:35:56
 *  Author: bohung
 */ 
#include "core.h"
uint8_t allocate_space() {
	if(!pTCB->count)
	{
		asm("lds r18,(pTCB)+2 ");
		asm("push r18");
		pTCB->count++;
		return 1;
	}
	return 0;
}
