
#ifndef ADC_
#define ADC_

#include "adc_regs.h"

void ADC_init();

void ADC_startConvertion();

uint16 ADC_getConversionValue();

#endif