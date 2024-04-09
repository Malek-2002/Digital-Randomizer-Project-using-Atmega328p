

#ifndef TIMERS_REGS_
#define TIMERS_REGS_

#include "std_types.h"

//0x3F (0x5F)
// TIMER2 REGS

#define TCCR2A (*(volatile uint8 *)0xB0)

#define TCCR2B (*(volatile uint8 *)0xB1)

#define TCNT2 (*(volatile uint8 *)0xB2)

#define OCR2A (*(volatile uint8 *)0xB3)

#define OCR2B (*(volatile uint8 *)0xB4)

#define TIMSK2 (*(volatile uint8 *)0x70)

#define TIFR2 (*(volatile uint8 *)0x37)


// TIMER1 REGS

#define TCCR1A (*(volatile uint8 *)0x80)

#define TCCR1B (*(volatile uint8 *)0x81)

#define TCCR1C (*(volatile uint8 *)0x82)

#define TCNT1L (*(volatile uint8 *)0x84)

#define TCNT1H (*(volatile uint8 *)0x85)

#define TCNT1 (*(volatile uint16 *)0x84)

#define ICR1L (*(volatile uint8 *)0x86)

#define ICR1H (*(volatile uint8 *)0x87)

#define ICR1 (*(volatile uint16 *)0x86)

#define OCR1AL (*(volatile uint8 *)0x88)

#define OCR1AH (*(volatile uint8 *)0x89)

#define OCR1A (*(volatile uint16 *)0x88)

#define OCR1BL (*(volatile uint8 *)0x8A)

#define OCR1BH (*(volatile uint8 *)0x8B)

#define TIMSK1 (*(volatile uint8 *)0x6F)

#define TIFR1 (*(volatile uint8 *)0x36)

// TIMER0 REGS

#define TCCR0A (*(volatile uint8 *)0x44)

#define TCCR0B (*(volatile uint8 *)0x45)

#define TCNT0 (*(volatile uint8 *)0x46)

#define OCR0A (*(volatile uint8 *)0x47)

#define OCR0B (*(volatile uint8 *)0x48)

#define TIMSK0 (*(volatile uint8 *)0x6E)

#define TIFR0 (*(volatile uint8 *)0x35)

// REGS BITS DEFS

// TIMER0 REGS BITS DEFS

typedef enum
{
    WGM00 = 0,
    WGM01 = 1,
    COM0B0 = 4,
    COM0B1 = 5,
    COM0A0 = 6,
    COM0A1 = 7
} TCCR0A_BITS;

typedef enum
{
    CS00 = 0,
    CS01 = 1,
    CS02 = 2,
    WGM02 = 3,
    FOC0B = 6,
    FOC0A = 7
} TCCR0B_BITS;

typedef enum
{
    TOIE0,
    OCIE0A,
    OCIE0B,
} TIMSK0_BITS;

typedef enum
{
    TOV0,
    OCF0A,
    OCF0B,
} TIFR0_BITS;

// TIMER1 REGS BITS DEFS

typedef enum
{
    WGM10 = 0,
    WGM11 = 1,
    COM1B0 = 4,
    COM1B1 = 5,
    COM1A0 = 6,
    COM1A1 = 7,
} TCCR1A_BITS;

typedef enum
{
    CS10 = 0,
    CS11 = 1,
    CS12 = 2,
    WGM12 = 3,
    WGM13 = 4,
    ICES1 = 6,
    ICNC1 = 7,
} TCCR1B_BITS;

typedef enum
{
    FOC1B = 6,
    FOC1A = 7
} TCCR1C_BITS;

typedef enum
{
    TOIE1,
    OCIE1A,
    OCIE1B,
    ICIE1 = 5,
} TIMSK1_BITS;

typedef enum
{
    TOV1,
    OCF1A,
    OCF1B,
    ICF1 = 5,
} TIFR1_BITS;


// TIMER2 REGS BITS DEFS

typedef enum
{
    WGM20 = 0,
    WGM21 = 1,
    COM2B0 = 4,
    COM2B1 = 5,
    COM2A0 = 6,
    COM2A1 = 7
} TCCR2A_BITS;

typedef enum
{
    CS20 = 0,
    CS21 = 1,
    CS22 = 2,
    WGM22 = 3,
    FOC2B = 6,
    FOC2A = 7
} TCCR2B_BITS;

typedef enum
{
    TOIE2,
    OCIE2A,
    OCIE2B,
} TIMSK2_BITS;

typedef enum
{
    TOV2,
    OCF2A,
    OCF2B,
} TIFR2_BITS;


#endif
