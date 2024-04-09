
#include "UART.h"

void UART_vInit()
{
    // bud rate 9600
    UBRR0L = 103;

    // Asynchronous
    Clear_BIT(UCSR0C, UMSELn0);
    Clear_BIT(UCSR0C, UMSELn1);

    // enable RX, TX
    SET_BIT(UCSR0B, TXEN0);
    SET_BIT(UCSR0B, RXEN0);

    // 8 bit communication
    SET_BIT(UCSR0C, UCSZn0);
    SET_BIT(UCSR0C, UCSZn1);
    Clear_BIT(UCSR0C, UCSZn0);

    // parity disabled
    Clear_BIT(UCSR0C, UPMn0);
    Clear_BIT(UCSR0C, UPMn0);

    // 1 stop bit
    Clear_BIT(UCSR0C, USBSn);

    // enable recieve inrerrupt
    SET_BIT(UCSR0B, RXCIE0);
}

void UART_vTransmit(uint8 data)
{
    while (IS_BIT_LOW(UCSR0A, UDRE0));

    UDR0 = data;
}

uint8 UART_vRecieve()
{
    while (IS_BIT_LOW(UCSR0A, RXC0));

    uint8 data = UDR0;

    return data;
}

void UART_vDeinit()
{
    ClEAR_REG(UBRR0L);
    ClEAR_REG(UCSR0C);
    ClEAR_REG(UCSR0B);
}