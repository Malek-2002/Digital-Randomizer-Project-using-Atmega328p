
#ifndef PROJECT_
#define PROJECT_

#include "gpio.h"
#include "UART.h"
#include "timers.h"
#include "interrupts.h"
#include "adc.h"

#define NUM_OF_TASKS 4

#define READY 0
#define SUSPENDED 1
#define STOPPED 2
#define RUNNIBG 3

#define NUM_OF_TASKS 4

#define DEFAULT_STATE READY

typedef struct Task
{
    void (*task_func)(void);
    uint16 task_cnt;
    uint16 task_time;
    uint8 task_state;
} Task;

Task task_arr[NUM_OF_TASKS];

typedef void (*callback_func)(void);


void startOperationTask();

void getConvertionValueTask();

void sendConvertionValueTask();

void endOperationTask();

void setupConfigurations();

void executeTasks();

void initTasks();

uint16 pseudoRandomNumGenerator(unsigned int seed);

void operation();

#endif