/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC16F15345
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.05 and above
        MPLAB 	          :  MPLAB X 5.20	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set TARGET_15 aliases
#define TARGET_15_TRIS                 TRISAbits.TRISA0
#define TARGET_15_LAT                  LATAbits.LATA0
#define TARGET_15_PORT                 PORTAbits.RA0
#define TARGET_15_WPU                  WPUAbits.WPUA0
#define TARGET_15_OD                   ODCONAbits.ODCA0
#define TARGET_15_ANS                  ANSELAbits.ANSA0
#define TARGET_15_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define TARGET_15_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define TARGET_15_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define TARGET_15_GetValue()           PORTAbits.RA0
#define TARGET_15_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define TARGET_15_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define TARGET_15_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define TARGET_15_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define TARGET_15_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define TARGET_15_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define TARGET_15_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define TARGET_15_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set TARGET_14 aliases
#define TARGET_14_TRIS                 TRISAbits.TRISA1
#define TARGET_14_LAT                  LATAbits.LATA1
#define TARGET_14_PORT                 PORTAbits.RA1
#define TARGET_14_WPU                  WPUAbits.WPUA1
#define TARGET_14_OD                   ODCONAbits.ODCA1
#define TARGET_14_ANS                  ANSELAbits.ANSA1
#define TARGET_14_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define TARGET_14_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define TARGET_14_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define TARGET_14_GetValue()           PORTAbits.RA1
#define TARGET_14_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define TARGET_14_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define TARGET_14_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define TARGET_14_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define TARGET_14_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define TARGET_14_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define TARGET_14_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define TARGET_14_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set TARGET_13 aliases
#define TARGET_13_TRIS                 TRISAbits.TRISA2
#define TARGET_13_LAT                  LATAbits.LATA2
#define TARGET_13_PORT                 PORTAbits.RA2
#define TARGET_13_WPU                  WPUAbits.WPUA2
#define TARGET_13_OD                   ODCONAbits.ODCA2
#define TARGET_13_ANS                  ANSELAbits.ANSA2
#define TARGET_13_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define TARGET_13_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define TARGET_13_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define TARGET_13_GetValue()           PORTAbits.RA2
#define TARGET_13_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define TARGET_13_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define TARGET_13_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define TARGET_13_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define TARGET_13_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define TARGET_13_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define TARGET_13_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define TARGET_13_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set SCAN aliases
#define SCAN_PORT                 PORTAbits.RA3
#define SCAN_WPU                  WPUAbits.WPUA3
#define SCAN_GetValue()           PORTAbits.RA3
#define SCAN_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define SCAN_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)

// get/set ENDSCAN aliases
#define ENDSCAN_TRIS                 TRISAbits.TRISA4
#define ENDSCAN_LAT                  LATAbits.LATA4
#define ENDSCAN_PORT                 PORTAbits.RA4
#define ENDSCAN_WPU                  WPUAbits.WPUA4
#define ENDSCAN_OD                   ODCONAbits.ODCA4
#define ENDSCAN_ANS                  ANSELAbits.ANSA4
#define ENDSCAN_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define ENDSCAN_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define ENDSCAN_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define ENDSCAN_GetValue()           PORTAbits.RA4
#define ENDSCAN_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define ENDSCAN_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define ENDSCAN_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define ENDSCAN_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define ENDSCAN_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define ENDSCAN_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define ENDSCAN_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define ENDSCAN_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set ENABLESCORE aliases
#define ENABLESCORE_TRIS                 TRISAbits.TRISA5
#define ENABLESCORE_LAT                  LATAbits.LATA5
#define ENABLESCORE_PORT                 PORTAbits.RA5
#define ENABLESCORE_WPU                  WPUAbits.WPUA5
#define ENABLESCORE_OD                   ODCONAbits.ODCA5
#define ENABLESCORE_ANS                  ANSELAbits.ANSA5
#define ENABLESCORE_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define ENABLESCORE_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define ENABLESCORE_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define ENABLESCORE_GetValue()           PORTAbits.RA5
#define ENABLESCORE_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define ENABLESCORE_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define ENABLESCORE_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define ENABLESCORE_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define ENABLESCORE_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define ENABLESCORE_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define ENABLESCORE_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define ENABLESCORE_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set TARGET_10 aliases
#define TARGET_10_TRIS                 TRISBbits.TRISB4
#define TARGET_10_LAT                  LATBbits.LATB4
#define TARGET_10_PORT                 PORTBbits.RB4
#define TARGET_10_WPU                  WPUBbits.WPUB4
#define TARGET_10_OD                   ODCONBbits.ODCB4
#define TARGET_10_ANS                  ANSELBbits.ANSB4
#define TARGET_10_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define TARGET_10_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define TARGET_10_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define TARGET_10_GetValue()           PORTBbits.RB4
#define TARGET_10_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define TARGET_10_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define TARGET_10_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define TARGET_10_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define TARGET_10_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define TARGET_10_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define TARGET_10_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define TARGET_10_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set TARGET_11 aliases
#define TARGET_11_TRIS                 TRISBbits.TRISB5
#define TARGET_11_LAT                  LATBbits.LATB5
#define TARGET_11_PORT                 PORTBbits.RB5
#define TARGET_11_WPU                  WPUBbits.WPUB5
#define TARGET_11_OD                   ODCONBbits.ODCB5
#define TARGET_11_ANS                  ANSELBbits.ANSB5
#define TARGET_11_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define TARGET_11_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define TARGET_11_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define TARGET_11_GetValue()           PORTBbits.RB5
#define TARGET_11_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define TARGET_11_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define TARGET_11_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define TARGET_11_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define TARGET_11_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define TARGET_11_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define TARGET_11_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define TARGET_11_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set TARGET_12 aliases
#define TARGET_12_TRIS                 TRISBbits.TRISB6
#define TARGET_12_LAT                  LATBbits.LATB6
#define TARGET_12_PORT                 PORTBbits.RB6
#define TARGET_12_WPU                  WPUBbits.WPUB6
#define TARGET_12_OD                   ODCONBbits.ODCB6
#define TARGET_12_ANS                  ANSELBbits.ANSB6
#define TARGET_12_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define TARGET_12_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define TARGET_12_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define TARGET_12_GetValue()           PORTBbits.RB6
#define TARGET_12_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define TARGET_12_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define TARGET_12_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define TARGET_12_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define TARGET_12_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define TARGET_12_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define TARGET_12_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define TARGET_12_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set TARGET_6 aliases
#define TARGET_6_TRIS                 TRISBbits.TRISB7
#define TARGET_6_LAT                  LATBbits.LATB7
#define TARGET_6_PORT                 PORTBbits.RB7
#define TARGET_6_WPU                  WPUBbits.WPUB7
#define TARGET_6_OD                   ODCONBbits.ODCB7
#define TARGET_6_ANS                  ANSELBbits.ANSB7
#define TARGET_6_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define TARGET_6_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define TARGET_6_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define TARGET_6_GetValue()           PORTBbits.RB7
#define TARGET_6_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define TARGET_6_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define TARGET_6_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define TARGET_6_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define TARGET_6_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define TARGET_6_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define TARGET_6_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define TARGET_6_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set TARGET_7 aliases
#define TARGET_7_TRIS                 TRISCbits.TRISC0
#define TARGET_7_LAT                  LATCbits.LATC0
#define TARGET_7_PORT                 PORTCbits.RC0
#define TARGET_7_WPU                  WPUCbits.WPUC0
#define TARGET_7_OD                   ODCONCbits.ODCC0
#define TARGET_7_ANS                  ANSELCbits.ANSC0
#define TARGET_7_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define TARGET_7_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define TARGET_7_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define TARGET_7_GetValue()           PORTCbits.RC0
#define TARGET_7_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define TARGET_7_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define TARGET_7_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define TARGET_7_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define TARGET_7_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define TARGET_7_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define TARGET_7_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define TARGET_7_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set TARGET_8 aliases
#define TARGET_8_TRIS                 TRISCbits.TRISC1
#define TARGET_8_LAT                  LATCbits.LATC1
#define TARGET_8_PORT                 PORTCbits.RC1
#define TARGET_8_WPU                  WPUCbits.WPUC1
#define TARGET_8_OD                   ODCONCbits.ODCC1
#define TARGET_8_ANS                  ANSELCbits.ANSC1
#define TARGET_8_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define TARGET_8_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define TARGET_8_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define TARGET_8_GetValue()           PORTCbits.RC1
#define TARGET_8_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define TARGET_8_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define TARGET_8_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define TARGET_8_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define TARGET_8_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define TARGET_8_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define TARGET_8_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define TARGET_8_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set TARGET_9 aliases
#define TARGET_9_TRIS                 TRISCbits.TRISC2
#define TARGET_9_LAT                  LATCbits.LATC2
#define TARGET_9_PORT                 PORTCbits.RC2
#define TARGET_9_WPU                  WPUCbits.WPUC2
#define TARGET_9_OD                   ODCONCbits.ODCC2
#define TARGET_9_ANS                  ANSELCbits.ANSC2
#define TARGET_9_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define TARGET_9_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define TARGET_9_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define TARGET_9_GetValue()           PORTCbits.RC2
#define TARGET_9_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define TARGET_9_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define TARGET_9_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define TARGET_9_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define TARGET_9_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define TARGET_9_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define TARGET_9_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define TARGET_9_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set TARGET_3 aliases
#define TARGET_3_TRIS                 TRISCbits.TRISC3
#define TARGET_3_LAT                  LATCbits.LATC3
#define TARGET_3_PORT                 PORTCbits.RC3
#define TARGET_3_WPU                  WPUCbits.WPUC3
#define TARGET_3_OD                   ODCONCbits.ODCC3
#define TARGET_3_ANS                  ANSELCbits.ANSC3
#define TARGET_3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define TARGET_3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define TARGET_3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define TARGET_3_GetValue()           PORTCbits.RC3
#define TARGET_3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define TARGET_3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define TARGET_3_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define TARGET_3_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define TARGET_3_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define TARGET_3_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define TARGET_3_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define TARGET_3_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set TARGET_2 aliases
#define TARGET_2_TRIS                 TRISCbits.TRISC4
#define TARGET_2_LAT                  LATCbits.LATC4
#define TARGET_2_PORT                 PORTCbits.RC4
#define TARGET_2_WPU                  WPUCbits.WPUC4
#define TARGET_2_OD                   ODCONCbits.ODCC4
#define TARGET_2_ANS                  ANSELCbits.ANSC4
#define TARGET_2_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define TARGET_2_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define TARGET_2_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define TARGET_2_GetValue()           PORTCbits.RC4
#define TARGET_2_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define TARGET_2_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define TARGET_2_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define TARGET_2_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define TARGET_2_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define TARGET_2_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define TARGET_2_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define TARGET_2_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set TARGET_1 aliases
#define TARGET_1_TRIS                 TRISCbits.TRISC5
#define TARGET_1_LAT                  LATCbits.LATC5
#define TARGET_1_PORT                 PORTCbits.RC5
#define TARGET_1_WPU                  WPUCbits.WPUC5
#define TARGET_1_OD                   ODCONCbits.ODCC5
#define TARGET_1_ANS                  ANSELCbits.ANSC5
#define TARGET_1_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define TARGET_1_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define TARGET_1_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define TARGET_1_GetValue()           PORTCbits.RC5
#define TARGET_1_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define TARGET_1_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define TARGET_1_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define TARGET_1_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define TARGET_1_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define TARGET_1_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define TARGET_1_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define TARGET_1_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set TARGET_4 aliases
#define TARGET_4_TRIS                 TRISCbits.TRISC6
#define TARGET_4_LAT                  LATCbits.LATC6
#define TARGET_4_PORT                 PORTCbits.RC6
#define TARGET_4_WPU                  WPUCbits.WPUC6
#define TARGET_4_OD                   ODCONCbits.ODCC6
#define TARGET_4_ANS                  ANSELCbits.ANSC6
#define TARGET_4_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define TARGET_4_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define TARGET_4_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define TARGET_4_GetValue()           PORTCbits.RC6
#define TARGET_4_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define TARGET_4_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define TARGET_4_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define TARGET_4_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define TARGET_4_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define TARGET_4_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define TARGET_4_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define TARGET_4_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set TARGET_5 aliases
#define TARGET_5_TRIS                 TRISCbits.TRISC7
#define TARGET_5_LAT                  LATCbits.LATC7
#define TARGET_5_PORT                 PORTCbits.RC7
#define TARGET_5_WPU                  WPUCbits.WPUC7
#define TARGET_5_OD                   ODCONCbits.ODCC7
#define TARGET_5_ANS                  ANSELCbits.ANSC7
#define TARGET_5_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define TARGET_5_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define TARGET_5_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define TARGET_5_GetValue()           PORTCbits.RC7
#define TARGET_5_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define TARGET_5_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define TARGET_5_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define TARGET_5_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define TARGET_5_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define TARGET_5_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define TARGET_5_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define TARGET_5_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/