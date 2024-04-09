
/*
 * UART.c
 * Created 9/10/2023
 *      Auther: Malel
*/

#ifndef UART_
#define UART_

#include "gpio.h"
#include "UART_REGS.h"


void UART_vInit();

void UART_vTransmit(uint8);

uint8 UART_vRecieve();

void UART_vDeinit();

#endif