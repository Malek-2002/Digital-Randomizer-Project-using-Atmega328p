

#ifndef TIMERS_
#define TIMERS_

#include "timer_regs.h"
#include "timer_types.h"
#include "gpio.h"



#define F_CPU 16000000UL


void TIMER0_init();

void TIMER1_init();

void TIMER2_init();

void TIMER0_deInit();

void TIMER1_deInit();

void TIMER2_deInit();


#endif