/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC16F15345
        Driver Version    :  2.00
 */

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
 */

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */

typedef enum
{
    SCAN_INPUT_IDLE = 0, 
    SCAN_INPUT_DEBOUNCE, 
    SCAN_INPUT_ASSERTED
} eSCAN_INPUT_STATE_t;

typedef enum targetState
{
    TARGET_IDLE = 0,
    TARGET_ACTIVE,
    TARGET_ASSERT_15TH_POSITION,
    TARGET_WAIT_15TH_POSITION
} eTARGET_STATE_t;

typedef struct
{
    uint8_t count;
    uint16_t timeout;
    eSCAN_INPUT_STATE_t state;
    unsigned tick : 1;
    unsigned risingEdge : 1;
    unsigned fallingEdge : 1;
} SCAN_INPUT_t;

typedef struct
{
    uint16_t count;
    uint16_t stuckCount;
    uint16_t dwellCount;
    eTARGET_STATE_t state;
} TARGET_t;

SCAN_INPUT_t scan;
TARGET_t target;

// The asserted state of the scan input needs to account for the dropouts that happen because
// of the half-wave rectification of the input signal.  This timeout allows 15ms of dropout time,
// which is almost a full AC line cycle at 60Hz.  Probably would also work at 50Hz.
#define SCAN_DWELL_TIME 15

// END_SCAN_DWELL_COUNT:  defines the amount of time the 15th position relay is energized in milliseconds.
#define END_SCAN_DWELL_COUNT 1000u

// STUCK_STATE_TIMEOUT:  amount of time with no activity after which a state is considered "stuck"
// Needs to account for the last ball when the scan pulses come in at half the normal rate.
#define STUCK_STATE_TIMEOUT 500u

//#define DEBUG_UART 1

void setState(eTARGET_STATE_t s);
inline void resetEdges(void);
void countTargets(void);
void scanInput(void);
#ifdef DEBUG_UART
void printStatus(void);
#endif

void isr_1ms(void)
{
    scan.tick = 1;
    scanInput();

    if (scan.timeout > 0)
    {
        scan.timeout--;
    }
    if (scan.count > 0)
    {
        scan.count--;
    }
}

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    TMR2_SetInterruptHandler(isr_1ms);
    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    scan.count = 0;
    scan.state = SCAN_INPUT_IDLE;
    scan.timeout = 0;
    setState(TARGET_IDLE);
    
    while (1)
    {
        if (scan.tick)
        {
            scan.tick = 0;
#ifndef DEBUG_UART
            TARGET_13_TRIS = 1;
            RC1STA = 0x0;
            TX1STA = 0x0;
#else
            printStatus();
#endif
            switch (target.state)
            {
                case TARGET_IDLE:
                    ENDSCAN_SetLow();
                    ENABLESCORE_SetLow();
                    if (scan.risingEdge)
                    {
                        resetEdges();
                        if (target.count > 0)
                        {
                            setState(TARGET_ACTIVE);
                            scan.timeout = 30;
                        }
                        else    // no targets down, so skip the active state
                        {
                            setState(TARGET_ASSERT_15TH_POSITION);
                        }
                    }
                    else
                    {
                        countTargets();
                    }
                    break;

                case TARGET_ACTIVE:
                    if (scan.risingEdge)
                    {
                        resetEdges();
                        ENABLESCORE_SetHigh();
                        --target.count;
                    }
                    
                    if (scan.fallingEdge)
                    {
                        resetEdges();
                        if (target.count == 0)
                        {
                            ENABLESCORE_SetLow();
                            setState(TARGET_ASSERT_15TH_POSITION);
                        }
                    }
                    
                    // if, for some reason, activity ceases while in this state, the
                    // following code provides a way out.
                    ++target.stuckCount;
                    if (target.stuckCount > STUCK_STATE_TIMEOUT)  setState(TARGET_IDLE);
                    break;
                    
                case TARGET_ASSERT_15TH_POSITION:
                    if (scan.risingEdge)
                    {
                        resetEdges();
                        ENDSCAN_SetHigh();
                        target.dwellCount = END_SCAN_DWELL_COUNT;
                        setState(TARGET_WAIT_15TH_POSITION);
                    }

                    // if, for some reason, activity ceases while in this state, the
                    // following code provides a way out.
                    ++target.stuckCount;
                    if (target.stuckCount > STUCK_STATE_TIMEOUT)  setState(TARGET_IDLE);                    
                    break;
                    
                case TARGET_WAIT_15TH_POSITION:
                    if (--target.dwellCount == 0)
                    {
                        ENDSCAN_SetLow();
                        setState(TARGET_IDLE);
                    }
                    break;
                    
                default:
                    setState(TARGET_IDLE);
                    break;
            }
        }
    }
}

const char stateTable[] = { 'i', 'A', 'a', 'W' };

void setState(eTARGET_STATE_t s)
{
    target.state = s;
    resetEdges();
#ifdef DEBUG_UART    
    EUSART1_Write(stateTable[s]);
#endif
}   /* setState */

inline void resetEdges(void)
{
    target.stuckCount = 0;
    scan.risingEdge = 0;
    scan.fallingEdge = 0;
}   /* resetEdges */

void scanInput(void)
{
    switch (scan.state)
    {
    case SCAN_INPUT_IDLE:
        if (SCAN_GetValue() == 1)
        {
            scan.count = 4;
            scan.state = SCAN_INPUT_DEBOUNCE;
        }
        break;
        
    case SCAN_INPUT_DEBOUNCE:
        if (SCAN_GetValue() == 1)
        {
            if (scan.count == 0)
            {
                scan.risingEdge = 1;
                scan.state = SCAN_INPUT_ASSERTED;
                scan.count = SCAN_DWELL_TIME;
            }
        }
        else
        {
            scan.state = SCAN_INPUT_IDLE;
        }
        break;
        
    case SCAN_INPUT_ASSERTED:
        if (SCAN_GetValue() == 0)
        {
            if (scan.count == 0)
            {
                scan.fallingEdge = 1;
                scan.state = SCAN_INPUT_IDLE;
            }
        }
        else
        {
            scan.count = SCAN_DWELL_TIME;
        }
    }
    
}   /* scanInput */

void countTargets(void)
{
    target.count = 0;
    if (TARGET_1_GetValue() == 0)
    {
       target.count++;
    }
    if (TARGET_2_GetValue() == 0)
    {
       target.count++;
    }
    if (TARGET_3_GetValue() == 0)
    {
       target.count++;
    }
    if (TARGET_4_GetValue() == 0)
    {
       target.count++;
    }
    if (TARGET_5_GetValue() == 0)
    {
       target.count++;
    }
    if (TARGET_6_GetValue() == 0)
    {
       target.count++;
    }
    if (TARGET_7_GetValue() == 0)
    {
       target.count++;
    }
    if (TARGET_8_GetValue() == 0)
    {
       target.count++;
    }
    if (TARGET_9_GetValue() == 0)
    {
       target.count++;
    }
    if (TARGET_10_GetValue() == 0)
    {
       target.count++;
    }
    if (TARGET_11_GetValue() == 0)
    {
       target.count++;
    }
    if (TARGET_12_GetValue() == 0)
    {
       target.count++;
    }
#ifndef DEBUG_UART
    if (TARGET_13_GetValue() == 0)
    {
       target.count++;
    }
#endif
    if (TARGET_14_GetValue() == 0)
    {
       target.count++;
    }
    if (TARGET_15_GetValue() == 0)
    {
       target.count++;
    }
}   /* countTargets */

#ifdef DEBUG_UART

void printStatus(void)
{
    printf("C=%2d S=%d SC=%4d SS=%2d ", target.count, target.state, scan.count, scan.state);
    if (TARGET_1_GetValue() == 0)
    {
        printf("1 ");
    }
    if (TARGET_2_GetValue() == 0)
    {
        printf("2 ");
    }
    if (TARGET_3_GetValue() == 0)
    {
        printf("3 ");
    }
    if (TARGET_4_GetValue() == 0)
    {
        printf("4 ");
    }
    if (TARGET_5_GetValue() == 0)
    {
        printf("5 ");
    }
    if (TARGET_6_GetValue() == 0)
    {
        printf("6 ");
    }
    if (TARGET_7_GetValue() == 0)
    {
        printf("7 ");
    }
    if (TARGET_8_GetValue() == 0)
    {
        printf("8 ");
    }
    if (TARGET_9_GetValue() == 0)
    {
        printf("9 ");
    }
    if (TARGET_10_GetValue() == 0)
    {
        printf("10 ");
    }
    if (TARGET_11_GetValue() == 0)
    {
        printf("11 ");
    }
    if (TARGET_12_GetValue() == 0)
    {
        printf("12 ");
    }
    if (TARGET_13_GetValue() == 0)
    {
        printf("13 ");
    }
    if (TARGET_14_GetValue() == 0)
    {
        printf("14 ");
    }
    if (TARGET_15_GetValue() == 0)
    {
        printf("15 ");
    }
    printf("\r\n");
}
#endif




/**
 End of File
 */