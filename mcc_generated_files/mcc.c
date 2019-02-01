/**
  @Generated PIC24 / dsPIC33 / PIC32MM MCUs Source File

  @Company:
    Microchip Technology Inc.

  @File Name:
    mcc.c

  @Summary:
    This is the mcc.c file generated using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.85
        Device            :  PIC24FJ128GA202
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.35
        MPLAB             :  MPLAB X v5.05
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/


// Configuration bits: selected in the GUI

// CONFIG4
#pragma config DSWDTPS = DSWDTPS1F    //Deep Sleep Watchdog Timer Postscale Select bits->1:68719476736 (25.7 Days)
#pragma config DSWDTOSC = LPRC    //DSWDT Reference Clock Select->DSWDT uses LPRC as reference clock
#pragma config DSBOREN = ON    //Deep Sleep BOR Enable bit->DSBOR Enabled
#pragma config DSWDTEN = ON    //Deep Sleep Watchdog Timer Enable->DSWDT Enabled
#pragma config DSSWEN = ON    //DSEN Bit Enable->Deep Sleep is controlled by the register bit DSEN
#pragma config PLLDIV = PLL4X    //USB 96 MHz PLL Prescaler Select bits->4x PLL selected
#pragma config I2C1SEL = DISABLE    //Alternate I2C1 enable bit->I2C1 uses SCL1 and SDA1 pins
#pragma config IOL1WAY = ON    //PPS IOLOCK Set Only Once Enable bit->Once set, the IOLOCK bit cannot be cleared

// CONFIG3
#pragma config WPFP = WPFP127    //Write Protection Flash Page Segment Boundary->Page 127 (0x1FC00)
#pragma config SOSCSEL = OFF    //SOSC Selection bits->Digital (SCLKI) mode
#pragma config WDTWIN = PS25_0    //Window Mode Watchdog Timer Window Width Select->Watch Dog Timer Window Width is 25 percent
#pragma config PLLSS = PLL_FRC    //PLL Secondary Selection Configuration bit->PLL is fed by the on-chip Fast RC (FRC) oscillator
#pragma config BOREN = ON    //Brown-out Reset Enable->Brown-out Reset Enable
#pragma config WPDIS = WPDIS    //Segment Write Protection Disable->Disabled
#pragma config WPCFG = WPCFGDIS    //Write Protect Configuration Page Select->Disabled
#pragma config WPEND = WPENDMEM    //Segment Write Protection End Page Select->Write Protect from WPFP to the last page of memory

// CONFIG2
#pragma config POSCMD = NONE    //Primary Oscillator Select->Primary Oscillator Disabled
#pragma config WDTCLK = LPRC    //WDT Clock Source Select bits->WDT uses LPRC
#pragma config OSCIOFCN = OFF    //OSCO Pin Configuration->OSCO/CLKO/RA3 functions as CLKO (FOSC/2)
#pragma config FCKSM = CSECMD    //Clock Switching and Fail-Safe Clock Monitor Configuration bits->Clock switching is enabled, Fail-Safe Clock Monitor is disabled
#pragma config FNOSC = FRC    //Initial Oscillator Select->FRC
#pragma config ALTCMPI = CxINC_RB    //Alternate Comparator Input bit->C1INC is on RB13, C2INC is on RB9 and C3INC is on RA0
#pragma config WDTCMX = WDTCLK    //WDT Clock Source Select bits->WDT clock source is determined by the WDTCLK Configuration bits
#pragma config IESO = ON    //Internal External Switchover->Enabled

// CONFIG1
#pragma config WDTPS = PS32768    //Watchdog Timer Postscaler Select->1:32768
#pragma config FWPSA = PR128    //WDT Prescaler Ratio Select->1:128
#pragma config WINDIS = OFF    //Windowed WDT Disable->Standard Watchdog Timer
#pragma config FWDTEN = OFF    //Watchdog Timer Enable->WDT disabled in hardware; SWDTEN bit disabled
#pragma config ICS = PGx1    //Emulator Pin Placement Select bits->Emulator functions are shared with PGEC1/PGED1
#pragma config LPCFG = OFF    //Low power regulator control->Disabled - regardless of RETEN
#pragma config GWRP = OFF    //General Segment Write Protect->Write to program memory allowed
#pragma config GCP = OFF    //General Segment Code Protect->Code protection is disabled
#pragma config JTAGEN = OFF    //JTAG Port Enable->Disabled

#include "mcc.h"
#include "clock.h"


void OSCILLATOR_Initialize(void)
{
    CLOCK_Initialize();
}

/**
 End of File
*/