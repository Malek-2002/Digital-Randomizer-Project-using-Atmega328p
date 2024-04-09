

#ifndef UART_REGS_
#define UART_REGS_

#include "std_types.h"

#define UDR0 (*(volatile uint8 *)0xC6)

#define UBRR0H (*(volatile uint8 *)0xC5)

#define UBRR0L (*(volatile uint8 *)0xC4)

#define UCSR0C (*(volatile uint8 *)0xC2)

#define UCSR0B (*(volatile uint8 *)0xC1)

#define UCSR0A (*(volatile uint8 *)0xC0)

typedef enum
{
    MPCM0,
    U2X0,
    UPE0,
    DOR0,
    FE0,
    UDRE0,
    TXC0,
    RXC0
} UCSR0A_BITS;

typedef enum
{
    TXB80,
    RXB80,
    UCSZ02,
    TXEN0,
    RXEN0,
    UDRIE0,
    TXCIE0,
    RXCIE0
} UCSR0B_BITS;

typedef enum
{
    UCPOLn,
    UCSZn0,
    UCSZn1,
    USBSn,
    UPMn0,
    UPMn1,
    UMSELn0,
    UMSELn1
} UCSR0C_BITS;

#endif