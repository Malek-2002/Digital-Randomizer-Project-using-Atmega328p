#include "gpio.h"

/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction)
{
    if (port_num >= NUM_OF_PORTS || pin_num >= NUM_OF_PINS_PER_PORT)
    {
        /* do nothing */
    }
    else
    {
        switch (port_num)
        {
        case PORTB_ID:

            if (direction == PIN_OUTPUT)
            {
                SET_BIT(DDRB, pin_num);
            }
            else
            {
                Clear_BIT(DDRB, pin_num);
            }

            break;
        case PORTC_ID:
            if (direction == PIN_OUTPUT)
            {
                SET_BIT(DDRC, pin_num);
            }
            else
            {
                Clear_BIT(DDRC, pin_num);
            }
            break;
        case PORTD_ID:
            if (direction == PIN_OUTPUT)
            {
                SET_BIT(DDRD, pin_num);
            }
            else
            {
                Clear_BIT(DDRD, pin_num);
            }
            break;
        }
    }
}

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value)
{
    if (port_num >= NUM_OF_PORTS || pin_num >= NUM_OF_PINS_PER_PORT)
    {
        /* do nothing */
    }
    else
    {
        switch (port_num)
        {
        case PORTB_ID:

            if (IS_BIT_LOW(DDRB, pin_num))
            {
                /* nothing */
            }
            else if (value == HIGH)
            {
                SET_BIT(PORTB, pin_num);
            }
            else
            {
                Clear_BIT(PORTB, pin_num);
            }

            break;
        case PORTC_ID:

            if (IS_BIT_LOW(DDRC, pin_num))
            {
                /* nothing */
            }
            else if (value == HIGH)
            {
                SET_BIT(PORTC, pin_num);
            }
            else
            {
                Clear_BIT(PORTC, pin_num);
            }
            break;
        case PORTD_ID:
            if (IS_BIT_LOW(DDRD, pin_num))
            {
                /* nothing */
            }
            else if (value == HIGH)
            {
                SET_BIT(PORTD, pin_num);
            }
            else
            {
                Clear_BIT(PORTD, pin_num);
            }
            break;
        }
    }
}

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
uint8 GPIO_readPin(uint8 port_num, uint8 pin_num)
{

    uint8 ret_val = LOW;

    if (port_num >= NUM_OF_PORTS || pin_num >= NUM_OF_PINS_PER_PORT)
    {
        /* do nothing */
    }
    else
    {
        switch (port_num)
        {
        case PORTB_ID:

            if (IS_BIT_HIGH(PINB, pin_num))
            {
                ret_val = HIGH;
            }
            else
            {
                ret_val = LOW;
            }

            break;
        case PORTC_ID:
            if (IS_BIT_HIGH(PINC, pin_num))
            {
                ret_val = HIGH;
            }
            else
            {
                ret_val = LOW;
            }
            break;
        case PORTD_ID:
            if (IS_BIT_HIGH(PIND, pin_num))
            {
                ret_val = HIGH;
            }
            else
            {
                ret_val = LOW;
            }
            break;
        }
    }

    return ret_val;
}

/*
 * Description :
 * Setup the direction of the required port all pins input/output.
 * If the direction value is PORT_INPUT all pins in this port should be input pins.
 * If the direction value is PORT_OUTPUT all pins in this port should be output pins.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_setupPortDirection(uint8 port_num, uint8 direction)
{
    if (port_num >= NUM_OF_PORTS)
    {
        /* do nothing */
    }
    else
    {
        switch (port_num)
        {
        case PORTB_ID:

            if (direction == PORT_OUTPUT)
            {
                SET_REG(DDRB);
            }
            else
            {
                ClEAR_REG(DDRB);
            }

            break;
        case PORTC_ID:
            if (direction == PORT_OUTPUT)
            {
                SET_REG(DDRC);
            }
            else
            {
                ClEAR_REG(DDRC);
            }
            break;
        case PORTD_ID:

            if (direction == PORT_OUTPUT)
            {
                SET_REG(DDRD);
            }
            else
            {
                ClEAR_REG(DDRD);
            }

            break;
        }
    }
}

/*
 * Description :
 * Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_writePort(uint8 port_num, uint8 value)
{
    if (port_num >= NUM_OF_PORTS)
    {
        /* do nothing */
    }
    else
    {
        switch (port_num)
        {
        case PORTB_ID:

            if (IS_REG_LOW(DDRB))
            {
                /* nothing */
            }
            else if (value == PORT_OUTPUT)
            {
                SET_REG(PORTB);
            }
            else
            {
                ClEAR_REG(PORTB);
            }

            break;
        case PORTC_ID:

            if (IS_REG_LOW(DDRC))
            {
                /* nothing */
            }
            else if (value == PIN_OUTPUT)
            {
                SET_REG(PORTC);
            }
            else
            {
                ClEAR_REG(PORTC);
            }
            break;
        case PORTD_ID:
            if (IS_REG_LOW(DDRD))
            {
                /* nothing */
            }
            else if (value == PIN_OUTPUT)
            {
                SET_REG(PORTD);
            }
            else
            {
                ClEAR_REG(PORTD);
            }
            break;
        }
    }
}

/*
 * Description :
 * Read and return the value of the required port.
 * If the input port number is not correct, The function will return ZERO value.
 */
uint8 GPIO_readPort(uint8 port_num)
{
    uint8 ret_val = PORT_OUTPUT;

    if (port_num >= NUM_OF_PORTS)
    {
        /* do nothing */
    }
    else
    {
        switch (port_num)
        {
        case PORTB_ID:

            if (IS_REG_HIGH(PINB))
            {
                ret_val = REG_HIGH;
            }
            else
            {
                ret_val = REG_LOW;
            }

            break;
        case PORTC_ID:
            if (IS_REG_HIGH(PINC))
            {
                ret_val = REG_HIGH;
            }
            else
            {
                ret_val = REG_LOW;
            }
            break;
        case PORTD_ID:
            if (IS_REG_HIGH(PIND))
            {
                ret_val = REG_HIGH;
            }
            else
            {
                ret_val = REG_LOW;
            }
            break;
        }
    }
    return ret_val;
}
