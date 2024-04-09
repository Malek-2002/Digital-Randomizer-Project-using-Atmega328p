#include "adc.h"

void ADC_init()
{
    ADMUX = 0;

    ADCSRA |= (1 << ADEN) | (ADPS1) | (1 << ADPS0); // enable

    ADMUX |= (1 << REFS0); // Set reference voltage to AVCC
    ADMUX |= (1 << MUX2) | (1 << MUX0);
    ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Set ADC prescaler to 128
    ADCSRA |= (1 << ADEN); // Enable ADC
}

void ADC_startConvertion()
{
    ADCSRA |= (1 << ADSC); // start conversion
}

uint16 ADC_getConversionValue()
{
    while ((ADCSRA & (1 << ADSC))); // check end of conversion

    uint16 data = ADC; // put the value of adc in variable x

    return data;
}
