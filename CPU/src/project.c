#include "project.h"

static callback_func callback_arr[NUM_OF_TASKS] =
    {startOperationTask,
     getConvertionValueTask,
     sendConvertionValueTask,
     endOperationTask};

static uint16 generatedNumber = 0;

void startOperationTask()
{
    SET_BIT(PORTC, 0);
    ADC_startConvertion();
    generatedNumber = ADC_getConversionValue();
}

void getConvertionValueTask()
{
    SET_BIT(PORTC, 1);

    unsigned int a = 115245;
    unsigned int c = 12345;
    unsigned int m = 65536; // 2^31
    uint16 generatedNumber = 0;
    
    generatedNumber = (a * generatedNumber + c) % m;
}

void sendConvertionValueTask()
{

    uint8 data_low = (uint8)generatedNumber;         // Lower 8 bits
    uint8 data_high = (uint8)(generatedNumber >> 8); // Upper 8 bits

    UART_vTransmit(data_low);
    UART_vTransmit(data_high);
    SET_BIT(PORTC, 2);
}

void endOperationTask()
{

    TIMER0_deInit();
    // TIMER1_deInit();

    Clear_BIT(PORTC, 2);
    Clear_BIT(PORTC, 1);
    Clear_BIT(PORTC, 0);
}

void setupConfigurations()
{
    ADC_init();
    UART_vInit();
    // TIMER1_init();

    Clear_BIT(DDRC, 5);
    SET_BIT(DDRC, 4);
    SET_BIT(DDRC, 3);
    SET_BIT(DDRC, 2);
    SET_BIT(DDRC, 1);
    SET_BIT(DDRC, 0);
    SET_REG(DDRB);

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
    for (int i = 0; i < NUM_OF_TASKS; i++)
    {
        if (task_arr[i].task_state != STOPPED)
        {
            if (task_arr[i].task_time <= task_arr[i].task_cnt)
            {
                task_arr[i].task_cnt = 0;
                task_arr[i].task_func();
                task_arr[i].task_state = STOPPED;
            }
            else
            {
                task_arr[i].task_cnt++;
            }
        }
    }
}

uint16 pseudoRandomNumGenerator(unsigned int seed)
{
    unsigned int a = 115245;
    unsigned int c = 12345;
    unsigned int m = 65536; // 2^31
    uint16 state = 0;

    if (seed != 0)
    {
        state = seed;
    }

    state = (a * state + c) % m;
    return state;
}

void operation()
{
    endOperationTask();
    initTasks();
    TIMER0_init();
}

ISR(TIMER0_OVF_vect)
{
    executeTasks();
}

ISR(USART_RX_vect)
{
    uint8 command = UDR0;
    operation();
}
