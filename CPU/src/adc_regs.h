
#ifndef ADC_REGS_
#define ADC_REGS_

#include "std_types.h"

#define ADMUX (*(volatile uint8 *)0x7C)
#define ADCSRA (*(volatile uint8 *)0x7A)
#define ADCH (*(volatile uint8 *)0x79)
#define ADCL (*(volatile uint8 *)0x78)
#define ADC (*(volatile uint16 *)0x78)

typedef enum
{
    MUX0,
    MUX1,
    MUX2,
    MUX3,
    N_D,
    ADLAR,
    REFS0,
    REFS1,
} ADMUX_BITS;

typedef enum
{
    ADPS0,
    ADPS1,
    ADPS2,
    ADIE,
    ADIF,
    ADATE,
    ADSC,
    ADEN,
} ADCSRA_BITS;

#endif