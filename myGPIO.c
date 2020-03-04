/*
 * GPIO.c
 *
 *  Created on: 3/4/2020
 *      Author: Ajay Kamalakannan
 */

// For the code you place here, you may use your code that uses register references.
// However, I encourage you to start using the Driver Library as soon as possible.
#define BUFFER_SIZE 5
#define LAUNCHPAD_L1 BIT1
#define LAUNCHPAD_L2 BIT4
#define LAUNCHPAD_LED1 BIT0
#define LAUNCHPAD_LED2_RED BIT0
#define LAUNCHPAD_LED2_GREEN BIT1
#define LAUNCHPAD_LED2_BLUE BIT2
#define BOOSTERPACK_B1 BIT1
#define BOOSTERPACK_B2 BIT5
#define BOOSTERPACK_LED_RED BIT6
#define BOOSTERPACK_LED_GREEN BIT4
#define BOOSTERPACK_LED_BLUE BIT6
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myGPIO.h"

// TODO: Create a function to initialize the GPIO.
// Even though this assignment does not use all of the pushbuttons, you should write one function that does a complete GPIO init.
void initGPIO()
{
    // Launchpad S1
        P1DIR = P1DIR & ~LAUNCHPAD_L1;
        P1REN = P1REN | LAUNCHPAD_L1;
        P1OUT = P1OUT | LAUNCHPAD_L1;
    // Launchpad S2
        P1DIR = P1DIR & ~LAUNCHPAD_L2;
        P1REN = P1REN | LAUNCHPAD_L2;
        P1OUT = P1OUT | LAUNCHPAD_L2;
    // Boosterpack S1
        P5DIR = P5DIR & ~BOOSTERPACK_B1;
        P5REN = P5REN | BOOSTERPACK_B1;
        P5OUT = P5OUT | BOOSTERPACK_B1;
    // Boosterpack S2
        P3DIR = P3DIR & ~BOOSTERPACK_B2;
        P5REN = P3REN | BOOSTERPACK_B2;
        P3OUT = P3OUT | BOOSTERPACK_B2;
    // Launchpad LED1
        P1DIR = P1DIR | LAUNCHPAD_LED1;
        P1OUT = P1OUT | LAUNCHPAD_LED1;
    // Launchpad LED2 Red
        P2DIR = P2DIR | LAUNCHPAD_LED2_RED;
        P2OUT = P2OUT | LAUNCHPAD_LED2_RED;
    // Launchpad LED2 Green
        P2DIR = P2DIR | LAUNCHPAD_LED2_GREEN;
        P2OUT = P2OUT | LAUNCHPAD_LED2_GREEN;
    // Launchpad LED2 Blue
        P2DIR = P2DIR | LAUNCHPAD_LED2_BLUE;
        P2OUT = P2OUT | LAUNCHPAD_LED2_BLUE;
    // Boosterpack LED Red
        P2DIR = P2DIR | BOOSTERPACK_LED_RED;
        P2OUT = P2OUT | BOOSTERPACK_LED_RED;
    // Boosterpack LED Green
        P2DIR = P2DIR | BOOSTERPACK_LED_GREEN;
        P2OUT = P2OUT | BOOSTERPACK_LED_GREEN;
    // Boosterpack LED Blue
        P5DIR = P5DIR | BOOSTERPACK_LED_BLUE;
        P5OUT = P5OUT | BOOSTERPACK_LED_BLUE;

    // Turn off all LEDs at the start.
    turnOff_LaunchpadLED1();
    turnOff_LaunchpadLED2Red();
    turnOff_LaunchpadLED2Green();
    turnOff_LaunchpadLED2Blue();
    turnOff_BoosterpackLEDRed();
    turnOff_BoosterpackLEDGreen();
    turnOff_BoosterpackLEDBlue();
}

// TODO: Create a function to return the status of Launchpad Pushbutton S1
unsigned char checkStatus_LaunchpadS1()
{
    return ((P1IN & LAUNCHPAD_L1 ) != 0);
}

// TODO: Create a function to return the status of Launchpad Pushbutton S2
unsigned char checkStatus_LaunchpadS2()
{
    return ((P1IN & LAUNCHPAD_L2 ) != 0);
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S1
unsigned char checkStatus_BoosterpackS1()
{
    return ((P5IN & BOOSTERPACK_B1 ) != 0);
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S2
unsigned char checkStatus_BoosterpackS2()
{
    return ((P3IN & BOOSTERPACK_B2 ) != 0);
}

// TODO: Create a function to turn on Launchpad LED1.
void turnOn_LaunchpadLED1()
{
    P1OUT = P1OUT | LAUNCHPAD_LED1;
}

// TODO: Create a function to turn off Launchpad LED1.
void turnOff_LaunchpadLED1()
{
    P1OUT = P1OUT & ~LAUNCHPAD_LED1;
}

// TODO: Create a function to turn on the Red Launchpad LED2.
void turnOn_LaunchpadLED2Red()
{
    P2OUT = P2OUT | LAUNCHPAD_LED2_RED;
}

// TODO: Create a function to turn off the Red Launchpad LED2.
void turnOff_LaunchpadLED2Red()
{
    P2OUT = P2OUT & ~LAUNCHPAD_LED2_RED;
}

// TODO: Create a function to turn on the Green Launchpad LED2.
void turnOn_LaunchpadLED2Green()
{
    P2OUT = P2OUT | LAUNCHPAD_LED2_GREEN;
}

// TODO: Create a function to turn off the Green Launchpad LED2.
void turnOff_LaunchpadLED2Green()
{
    P2OUT = P2OUT & ~LAUNCHPAD_LED2_GREEN;
}

// TODO: Create a function to turn on the Blue Launchpad LED2.
void turnOn_LaunchpadLED2Blue()
{
    P2OUT = P2OUT | LAUNCHPAD_LED2_BLUE;
}

// TODO: Create a function to turn off the Blue Launchpad LED2.
void turnOff_LaunchpadLED2Blue()
{
    P2OUT = P2OUT & ~LAUNCHPAD_LED2_BLUE;
}

// TODO: Create a function to turn on the Red Boosterpack LED2.
void turnOn_BoosterpackLEDRed()
{
    P2OUT = P2OUT | BOOSTERPACK_LED_RED;
}

// TODO: Create a function to turn off the Red Boosterpack LED2.
void turnOff_BoosterpackLEDRed()
{
    P2OUT = P2OUT & ~BOOSTERPACK_LED_RED;
}

// TODO: Create a function to turn on the Green Boosterpack LED2.
void turnOn_BoosterpackLEDGreen()
{
    P2OUT = P2OUT | BOOSTERPACK_LED_GREEN;
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDGreen()
{
    P2OUT = P2OUT & ~BOOSTERPACK_LED_GREEN;
}

// TODO: Create a function to turn on the Blue Boosterpack LED2.
void turnOn_BoosterpackLEDBlue()
{
    P5OUT = P5OUT | BOOSTERPACK_LED_BLUE;
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDBlue()
{
    P5OUT = P5OUT & ~BOOSTERPACK_LED_BLUE;
}
