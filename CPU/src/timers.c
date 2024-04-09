#include "timers.h"
void TIMER0_init()
{
    TCCR0B |= (1 << CS00) | (1 << CS02);
    TIMSK0 |= (1 << TOIE0);
}

void TIMER1_init()
{
    SET_BIT(TCCR1A, WGM11);
    SET_BIT(TCCR1A, COM1A1);
    SET_BIT(TCCR1B, WGM12);
    SET_BIT(TCCR1B, WGM13);
    // SET_BIT(TCCR1B, CS12);
    SET_BIT(TCCR1B, CS10);
    ICR1 = 150;
    OCR1A = 40;
    // TCCR1B |= (1 << WGM12);  // CTC mode
    // OCR1A = 62500;           // Compare match value for 1Hz interrupt frequency (16MHz clock, prescaler = 256)
    // TIMSK1 |= (1 << OCIE1A); // Enable timer compare interrupt
    // TCCR1B |= (1 << CS12);   // Start timer with prescaler = 256
}

void TIMER2_init()
{
}

void TIMER0_deInit()
{
    ClEAR_REG(TCCR0A);
    ClEAR_REG(TCCR0B);
    ClEAR_REG(TCNT0);
    ClEAR_REG(TIMSK0);
}

void TIMER1_deInit()
{
    ClEAR_REG(TCCR1A);
    ClEAR_REG(TCCR2B);
    ClEAR_REG(TCNT1);
    ClEAR_REG(ICR1);
}

void TIMER2_deInit()
{
}
