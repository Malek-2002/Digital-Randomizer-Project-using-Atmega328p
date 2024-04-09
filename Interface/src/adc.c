#include "adc.h"

void ADC_init()
{
    // ADMUX = 0;

    // ADCSRA |= (1 << ADEN) | (ADPS1) | (1 << ADPS0); // enable

    ADMUX = 0;
    ADMUX |= (1 << REFS0); // vcc
    ADMUX |= (1 << MUX0);
    ADCSRA |= (1 << ADEN) | (1 << ADIE) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

void ADC_startConvertion()
{
    ADCSRA |= (1 << ADSC); // start conversion
}

uint16 ADC_getConversionValue()
{
    while ((ADCSRA & (1 << ADSC)))
        ; // check end of conversion

    uint16 data = ADC; // put the value of adc in variable x

    return data;
}
