/*
 * main.h
 *
 * Created: 2016/08/31 上午 09:47:57
 *  Author: bohome
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 16000000
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include "core.h"
uint8_t count=0;
extern TCB TASK[2];

#endif /* MAIN_H_ */