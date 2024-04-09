# Digital-Randomizer-Project-using-Atmega328p
Digital Randomizer Project

This project builds a digital device using two ATmega328P microcontrollers (think Arduino UNO) to generate random integer numbers.

Project Goals:

    Create a digital randomizer.
    Implement a custom random number generation algorithm (no built-in functions for fairness).
    Visually display the random number using a 7-segment display and 5 LEDs.
    Provide audible feedback with a buzzer sound based on a potentiometer reading.
    Design user-friendly controls with 3 push buttons.
    Optimize for low power consumption to extend battery life.

Deliverables:

    Simulation
    Video showcasing simulation and various functionalities
    Code

Components:

    2 ATmega328P microcontrollers (Arduino UNO)
    5 LEDs for number display
    3 LEDs for processing MCU status
    Buzzer for audio feedback
    Servo motor for additional feedback
    3 Push buttons for controlling the randomizer

Functionality:

    User presses "Generate" button.
    HMI MCU sends a request to the processing MCU to generate a random number.
    Processing MCU acknowledges the request with LEDs (1 second intervals).
    Processing MCU generates a random number, sends it back to HMI MCU, and turns on a third LED (1 second). All LEDs turn off after another second. If communication fails, processing MCU's LEDs toggle for 5 seconds (500ms interval).
    HMI MCU receives the number, displays it digit by digit on the 5 LEDs (each digit for 1 second).
        The buzzer plays a sound with a duty cycle based on the digit value (value / 10).
        After displaying all digits, the buzzer plays a sound with a duty cycle based on the entire random number (number / 65535).
    The servo motor moves to a position determined by the random number modulo 180 (over 5 seconds).
    "Next" and "Previous" buttons allow users to navigate through displayed digits quickly.
    Pressing "Generate" during an ongoing process cancels the current task and starts a new generation.
    System state (generated number, current digit, etc.) is saved in EEPROM for resuming from the last state after power cycles.

Utilizing Resources:

This project utilizes various functionalities of the ATmega328P microcontroller:

    ADC (Analog-to-Digital Converter)
    Timers
    UART (Universal Asynchronous Receiver/Transmitter) - for communication between MCUs (optional, can be replaced with other methods)
    I2C (Inter-Integrated Circuit) - for communication between MCUs (optional, can be replaced with other methods)
    External interrupts

Conclusion:

The Digital Randomizer offers an entertaining and engaging experience, simulating a traditional randomizer in a digital format. The project leverages the capabilities of the ATmega328P microcontroller and various components to provide a unique user experience with communication protocol synchronization and state persistence.
