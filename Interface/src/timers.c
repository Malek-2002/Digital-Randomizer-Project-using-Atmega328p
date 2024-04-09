#include "timers.h"
void TIMER0_init()
{
    TCCR0A = 0;
    TCCR0B |= (1 << CS00) | (1 << CS02);
    TIMSK0 |= (1 << TOIE0);
}

void TIMER1_init()
{
    SET_BIT(TCCR1A, WGM11);
    SET_BIT(TCCR1A, COM1A1);
    SET_BIT(TCCR1B, WGM12);
    SET_BIT(TCCR1B, WGM13);
    SET_BIT(TCCR1B, CS12);
    SET_BIT(TCCR1B, CS10);
    ICR1 = 311;
    OCR1A = 15;
}

void TIMER2_init()
{
    // Set the timer prescaler to 1024
    TCCR2B = (1 << CS20) | (1 << CS21) | (1 << CS22);

    // Set the output compare mode to non-inverting fast PWM
    TCCR2A = (1 << COM2A1) | (1 << WGM21) | (1 << WGM20);
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
    ClEAR_REG(TCCR2A);
    ClEAR_REG(TCCR2B);
    ClEAR_REG(TCNT2);
    ClEAR_REG(TIMSK2);
}
