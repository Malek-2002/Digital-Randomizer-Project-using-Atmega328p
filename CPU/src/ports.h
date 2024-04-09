 /******************************************************************************
 *
 * Module: PORTS
 *
 * File Name: ports.h
 *
 * Description: Header file for the AVR ports driver
 *
 * Author: Malek Hossam
 *
 *******************************************************************************/

#ifndef PORTS_
#define PORTS_

#include "std_types.h"


// port D configurations

#define PORTD (*(volatile uint8*)0x2B)

#define DDRD (*(volatile uint8*)0x2A)

#define PIND (*(volatile uint8*)0x29)

// port C configurations

#define PORTC (*(volatile uint8*)0x28)

#define DDRC (*(volatile uint8*)0x27)

#define PINC (*(volatile uint8*)0x26)

// port B configurations

#define PORTB (*(volatile uint8*)0x25)

#define DDRB (*(volatile uint8*)0x24)

#define PINB (*(volatile uint8*)0x23)

#endif