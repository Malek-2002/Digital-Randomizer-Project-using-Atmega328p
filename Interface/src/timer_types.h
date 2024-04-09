


#ifndef TIMERS_DEFS_
#define TIMERS_DEFS_

#define NUM_OF_OVERFLOWS_PER_SECOND

#define NUM_OF_OVERFLOWS_PER__HALF_SECOND

typedef enum{
    Timer_F_CLK_NO_Clk        ,
    Timer_F_CLK_F_CPU_1       ,
    Timer_F_CLK_F_CPU_8       , 
    Timer_F_CLK_F_CPU_64      , 
    Timer_F_CLK_F_CPU_256     ,
    Timer_F_CLK_F_CPU_1024    ,
} Timer_F_CLK;

typedef enum{
    Timer_Mode_NORMAL        ,
    Timer_Mode_OVERFLOW      ,
    Timer_Mode_CTC           ,
    Timer_Mode_FAST_PWM      ,
} Timer_Mode;

typedef enum{
    PROCCES_MODE_POLLING       ,
    PROCCES_MODE_INTERRUPT     , 
} PROCCES_MODE;

typedef enum{
    COM_Mode_NORMAL        ,
    COM_Mode_DISCONNECT    , 
    COM_Mode_TOGGLE        ,
    COM_Mode_CLEAR         ,
    COM_Mode_SET         ,
    COM_Mode_NON_INVERTING ,
    COM_Mode_INVERTING     ,
} COM_Mode;

#endif