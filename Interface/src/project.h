
#ifndef PROJECT_
#define PROJECT_

#include "gpio.h"
#include "UART.h"
#include "timers.h"
#include "interrupts.h"
#include "adc.h"

#define READY 0
#define SUSPENDED 1
#define STOPPED 2
#define RUNNIBG 3

#define NUM_OF_TASKS 6

#define NUM_OF_DIGITS 5

#define MAX_GENERATED_NUMBERS 50

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

void task0();

void task1();

void task2();

void task3();

void task4();

void task5();

void extractDigits(uint16);

void setupConfigurations();

void executeTasks();

void initTasks();

void startOperation(uint16);

#endif