
#ifndef ADC_REGS_
#define ADC_REGS_

#include "std_types.h"

//(0x7C) ADMUX REFS1 REFS0 ADLAR – MUX3 MUX2 MUX1 MUX0 262
//(0x7A) ADCSRA ADEN ADSC ADATE ADIF ADIE ADPS2 ADPS1 ADPS0 263
//(0x79) ADCH ADC Data Register High byte 265
//(0x78) ADCL ADC Data Register Low byte 265

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




// ADMUX = 0;
// ADMUX |= (1 << REFS0); // vcc

// ADCSRA |= (1 << ADEN) | (ADPS1) | (1 << ADPS0); // enable

#endif