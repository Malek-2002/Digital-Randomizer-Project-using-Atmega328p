#include "project.h"

static callback_func callback_arr[NUM_OF_TASKS] = {task0, task1, task2, task3, task4, task5};
static uint8 curr_number_to_display_digits_arr[NUM_OF_DIGITS] = {0};
static uint16 curr_num = 0;
static uint16 ticks = 0;
static uint8 curr_task = -1;

void task0()
{
    PORTC = curr_number_to_display_digits_arr[0];

    uint8 remainder = (curr_num % 180);
    uint8 div = remainder / 5;
    OCR1A = 15.5 + (div / 180.00 * 17); // OC1A in pin 9

    OCR2A = (curr_number_to_display_digits_arr[0] / 10.00) * 255;

    if (curr_num % 180 == 0)
        SET_BIT(PORTC, 5);

    curr_task++;
}

void task1()
{
    PORTC = curr_number_to_display_digits_arr[1];

    uint8 remainder = (curr_num % 180);
    uint8 div = remainder / 4;
    OCR1A = 15.5 + (div / 180.00 * 17); // OC1A in pin 9

    OCR2A = (curr_number_to_display_digits_arr[1] / 10.00) * 255;

    curr_task++;
}

void task2()
{
    PORTC = curr_number_to_display_digits_arr[2];

    uint8 remainder = (curr_num % 180);
    uint8 div = remainder / 3;
    OCR1A = 15.5 + (div / 180.00 * 17); // OC1A in pin 9

    OCR2A = (curr_number_to_display_digits_arr[2] / 10.00) * 255;

    curr_task++;
}

void task3()
{
    PORTC = curr_number_to_display_digits_arr[3];

    uint8 remainder = (curr_num % 180);
    uint8 div = remainder / 2;
    OCR1A = 15.5 + (div / 180.00 * 17); // OC1A in pin 9

    OCR2A = (curr_number_to_display_digits_arr[3] / 10.00) * 255;

    curr_task++;
}

void task4()
{
    PORTC = curr_number_to_display_digits_arr[4];

    uint8 remainder = (curr_num % 180);
    uint8 div = remainder / 1;
    OCR1A = 15.5 + (div / 180.00 * 17); // OC1A in pin 9

    OCR2A = (curr_number_to_display_digits_arr[4] / 10.00) * 255;

    curr_task++;
}

void task5()
{
    PORTC = 15;
    TIMER0_deInit();
    TIMER1_deInit();
    TIMER2_deInit();
}

void extractDigits(uint16 generatedNumber)
{
    for (int i = 0; i < NUM_OF_DIGITS; i++)
    {
        curr_number_to_display_digits_arr[i] = generatedNumber % 10;
        generatedNumber /= 10;
    }
}

void setupConfigurations()
{
    UART_vInit();

    DDRC = 0xFF;
    DDRB = 0xFF;
    PORTB = 0b00001111;
    PORTC = 15;
    SREG |= (1 << 7);
    PORTB = 0;
    SET_BIT(EICRA, ISC01);
    SET_BIT(EICRA, ISC00);
    SET_BIT(EIMSK, INT0);

    SET_BIT(EICRA, ISC11);
    SET_BIT(EICRA, ISC10);
    SET_BIT(EIMSK, INT1);

    Clear_BIT(PORTB, 0);
    PCICR |= (1 << PCIE0);
    PCMSK0 |= (1 << PCINT0);

    SREG |= (1 << 7);
}

static void createTask(uint16 task_time, void (*a_ptr)(void), uint8 task_num)
{
    task_arr[task_num].task_func = *a_ptr;
    task_arr[task_num].task_time = task_time;
    task_arr[task_num].task_state = DEFAULT_STATE;
    task_arr[task_num].task_cnt = 0;
}

void initTasks()
{
    for (int i = 0; i < NUM_OF_TASKS; i++)
    {
        createTask(61 * i, callback_arr[i], i);
    }
}

void executeTasks()
{
    for (uint8 i = 0; i < NUM_OF_TASKS; i++)
    {
        if (task_arr[i].task_state != STOPPED)
        {
            if (task_arr[i].task_time <= task_arr[i].task_cnt)
            {
                task_arr[i].task_func();
                task_arr[i].task_cnt = 0;
                task_arr[i].task_state = STOPPED;
            }
            else
            {
                task_arr[i].task_cnt++;
            }
        }
    }
}

void shiftTaskRight()
{
    for (int i = curr_task + 1; i < NUM_OF_TASKS; i++)
    {
        task_arr[i].task_time = ticks + 61 * (i - (curr_task + 1));
    }
}

void shiftTaskLeft()
{
    if (curr_task - 1 < 0)
        return;

    curr_task--;
    for (int i = curr_task; i < NUM_OF_TASKS; i++)
    {
        task_arr[i].task_time = ticks + 61 * (i - (curr_task));
        task_arr[i].task_cnt = ticks;
        task_arr[i].task_state = READY;
    }
    curr_task--;
}

void startOperation(uint16 generatedNumber)
{
    extractDigits(generatedNumber);
    initTasks();
    TIMER0_init();
    TIMER1_init();
    TIMER2_init();
    curr_num = generatedNumber;
    ticks = 0;
    curr_task = -1;
}

ISR(TIMER0_OVF_vect)
{
    executeTasks();
    ticks++;
}

ISR(USART_RX_vect)
{
    uint8 low_data = UDR0;

    while (IS_BIT_LOW(UCSR0A, RXC0))
        ;

    uint8 high_data = UDR0;

    uint16 number = high_data;
    number = (number << 8);
    number += low_data;

    startOperation(number);
}

ISR(INT0_vect)
{
    shiftTaskLeft();
}

ISR(INT1_vect)
{
    shiftTaskRight();
}

ISR(PCINT0_vect)
{
    task5();
    UART_vTransmit(1);
}