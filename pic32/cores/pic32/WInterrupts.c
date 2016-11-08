//************************************************************************
//*	WInterrupts.c
//*	
//*	Arduino core files for PIC32
//*		Copyright (c) 2010, 2011 by Mark Sproul
//*	
//*	
//************************************************************************
//*	this code is based on code Copyright (c) 2004-05 Hernando Barragan
//*	
//*	This library is free software; you can redistribute it and/or
//*	modify it under the terms of the GNU Lesser General Public
//*	License as published by the Free Software Foundation; either
//*	version 2.1 of the License, or (at your option) any later version.
//*	
//*	This library is distributed in the hope that it will be useful,
//*	but WITHOUT ANY WARRANTY; without even the implied warranty of
//*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.//*	See the GNU
//*	Lesser General Public License for more details.
//*	
//*	You should have received a copy of the GNU Lesser General
//*	Public License along with this library; if not, write to the
//*	Free Software Foundation, Inc., 59 Temple Place, Suite 330,
//*	Boston, MA  02111-1307  USA
//*	
//*	
//************************************************************************
//*	Edit History
//************************************************************************
//*	Oct 15,	2010	<MLS> Started on WInterrupts.c for Pic32
//* Aug  8, 2011	<GeneApperson> completely rewritten (issue #75)
//* Aug 30, 2011    <GeneApperson> clear interrupt flag after return from
//*                     user interrupt function (issue #109)
//*	Jul 26, 2012	<GeneApperson> Added PPS support for PIC32MX1xx/MX2xx devices
//	Feb  6, 2012	<GeneApperson> Removed dependencies on the Microchip plib library
//************************************************************************

#include <p32xxxx.h>
#include <sys/attribs.h>

#include <inttypes.h>
#include <stdio.h>

#define	OPT_SYSTEM_INTERNAL
#define OPT_BOARD_INTERNAL	//pull in internal symbol definitons
#include "p32_defs.h"
#include "pins_arduino.h"

#include "WConstants.h"
#include "wiring_private.h"

// forward reference to the ISRs
void __attribute__((interrupt(),nomips16)) ExtInt0Handler(void);
void __attribute__((interrupt(),nomips16)) ExtInt1Handler(void);
void __attribute__((interrupt(),nomips16)) ExtInt2Handler(void);
void __attribute__((interrupt(),nomips16)) ExtInt3Handler(void);
void __attribute__((interrupt(),nomips16)) ExtInt4Handler(void);

static volatile voidFuncPtr intFunc[NUM_EXTERNAL_INTERRUPTS];
static volatile int intmode[NUM_EXTERNAL_INTERRUPTS];
//************************************************************************
// PIC32 devices only support rising and falling edge triggered interrupts
// on the external interrupt pins. Only the RISING and FALLING modes are
// supported.
//************************************************************************
void attachInterrupt(uint8_t interruptNum, void (*userFunc)(void), int mode)
{
    int		edge;

    if ((interruptNum < NUM_EXTERNAL_INTERRUPTS) && (mode != CHANGE))
    {
        intFunc[interruptNum]	=	userFunc;
        intmode[interruptNum] 	=	mode;

#if defined(__PIC32_PPS__)
        /* For devices with peripheral pin select (PPS), it is necessary to
        ** map the input function to the pin. This is done by loading the
        ** PPS input select register for the specific interrupt with the value
        ** to select the pin that the interrupt is mapped to as defined by the
        ** board variant file.
        */
        volatile uint32_t *	pps;
        uint8_t		pin;
        uint8_t		sel;

        if ((sel = externalIntToInputSelect(interruptNum)) != NOT_PPS_PIN)
        {
            pin = externalIntToDigitalPin(interruptNum);
            pps = ppsInputRegister(sel);
            *pps = ppsInputSelect(pin);
        }
#endif

        // The active edge is selected via the INTxEP bits in the INTCON register.
        // A '0' bit selects falling edge, and a '1' bit select rising edge.
        if (mode == FALLING || mode == LOW)
        {
            edge	=	0;
        }
        else
        {
            edge	=	1;
        }

#if defined(__PIC32MZXX__)

        // Select the active edge, set the privilege and sub-privilege levels,
        // and enable the interrupt.
        switch (interruptNum)
        {
#ifdef PIN_INT0
            case EXT_INT0:
                setIntVector(_EXTERNAL_0_VECTOR, (isrFunc) ExtInt0Handler);
                IEC0bits.INT0IE     =	0;
                IFS0bits.INT0IF     =	0;
                INTCONbits.INT0EP   =	edge;
                IPC0bits.INT0IP     =	_INT0_IPL_IPC;
                IPC0bits.INT0IS     =	_INT0_SPL_IPC;
                IEC0bits.INT0IE     =	1;
                break;
#endif
#ifdef PIN_INT1
            case EXT_INT1:
                setIntVector(_EXTERNAL_1_VECTOR, (isrFunc) ExtInt1Handler);
                IEC0bits.INT1IE		=	0;
                IFS0bits.INT1IF		=	0;
                INTCONbits.INT1EP	=	edge;
                IPC2bits.INT1IP		=	_INT1_IPL_IPC;
                IPC2bits.INT1IS		=	_INT1_SPL_IPC;
                IEC0bits.INT1IE		=	1;
                break;
#endif
#ifdef PIN_INT2
            case EXT_INT2:
                setIntVector(_EXTERNAL_2_VECTOR, (isrFunc) ExtInt2Handler);
                IEC0bits.INT2IE		=	0;
                IFS0bits.INT2IF		=	0;
                INTCONbits.INT2EP	=	edge;
                IPC3bits.INT2IP		=	_INT2_IPL_IPC;
                IPC3bits.INT2IS		=	_INT2_SPL_IPC;
                IEC0bits.INT2IE		=	1;
                break;
#endif
#ifdef PIN_INT3
            case EXT_INT3:
                setIntVector(_EXTERNAL_3_VECTOR, (isrFunc) ExtInt3Handler);
                IEC0bits.INT3IE		=	0;
                IFS0bits.INT3IF		=	0;
                INTCONbits.INT3EP	=	edge;
                IPC4bits.INT3IP		=	_INT3_IPL_IPC;
                IPC4bits.INT3IS		=	_INT3_SPL_IPC;
                IEC0bits.INT3IE		=	1;
                break;
#endif
#ifdef PIN_INT4
            case EXT_INT4:
                setIntVector(_EXTERNAL_4_VECTOR, (isrFunc) ExtInt4Handler);
                IEC0bits.INT4IE		=	0;
                IFS0bits.INT4IF		=	0;
                INTCONbits.INT4EP	=	edge;
                IPC5bits.INT4IP		=	_INT4_IPL_IPC;
                IPC5bits.INT4IS		=	_INT4_SPL_IPC;
                IEC0bits.INT4IE		=	1;
                break;
#endif
        }

#else

        // Select the active edge, set the privilege and sub-privilege levels,
        // and enable the interrupt.
        switch (interruptNum)
        {
#ifdef PIN_INT0
            case EXT_INT0:
                setIntVector(_EXTERNAL_0_VECTOR, (isrFunc) ExtInt0Handler);
                IEC0bits.INT0IE     =	0;
                IFS0bits.INT0IF     =	0;
                INTCONbits.INT0EP   =	edge;
                IPC0bits.INT0IP     =	_INT0_IPL_IPC;
                IPC0bits.INT0IS     =	_INT0_SPL_IPC;
                IEC0bits.INT0IE     =	1;
                break;
#endif
#ifdef PIN_INT1
            case EXT_INT1:
                setIntVector(_EXTERNAL_1_VECTOR, (isrFunc) ExtInt1Handler);
                IEC0bits.INT1IE		=	0;
                IFS0bits.INT1IF		=	0;
                INTCONbits.INT1EP	=	edge;
                IPC1bits.INT1IP		=	_INT1_IPL_IPC;
                IPC1bits.INT1IS		=	_INT1_SPL_IPC;
                IEC0bits.INT1IE		=	1;
                break;
#endif
#ifdef PIN_INT2
            case EXT_INT2:
                setIntVector(_EXTERNAL_2_VECTOR, (isrFunc) ExtInt2Handler);
                IEC0bits.INT2IE		=	0;
                IFS0bits.INT2IF		=	0;
                INTCONbits.INT2EP	=	edge;
                IPC2bits.INT2IP		=	_INT2_IPL_IPC;
                IPC2bits.INT2IS		=	_INT2_SPL_IPC;
                IEC0bits.INT2IE		=	1;
                break;
#endif
#ifdef PIN_INT3
            case EXT_INT3:
                setIntVector(_EXTERNAL_3_VECTOR, (isrFunc) ExtInt3Handler);
                IEC0bits.INT3IE		=	0;
                IFS0bits.INT3IF		=	0;
                INTCONbits.INT3EP	=	edge;
                IPC3bits.INT3IP		=	_INT3_IPL_IPC;
                IPC3bits.INT3IS		=	_INT3_SPL_IPC;
                IEC0bits.INT3IE		=	1;
                break;
#endif
#ifdef PIN_INT4
            case EXT_INT4:
                setIntVector(_EXTERNAL_4_VECTOR, (isrFunc) ExtInt4Handler);
                IEC0bits.INT4IE		=	0;
                IFS0bits.INT4IF		=	0;
                INTCONbits.INT4EP	=	edge;
                IPC4bits.INT4IP		=	_INT4_IPL_IPC;
                IPC4bits.INT4IS		=	_INT4_SPL_IPC;
                IEC0bits.INT4IE		=	1;
                break;
#endif
        }
#endif
    }
}

//************************************************************************
void detachInterrupt(uint8_t interruptNum)
{
    if (interruptNum < EXTERNAL_NUM_INTERRUPTS)
    {
        switch (interruptNum)
        {
#ifdef PIN_INT0
            case EXT_INT0:
                IEC0bits.INT0IE	=	0;
                clearIntVector(_EXTERNAL_0_VECTOR);
                break;
#endif
#ifdef PIN_INT1
            case EXT_INT1:
                IEC0bits.INT1IE	=	0;
                clearIntVector(_EXTERNAL_1_VECTOR);
                break;
#endif
#ifdef PIN_INT2
            case EXT_INT2:
                IEC0bits.INT2IE	=	0;
                clearIntVector(_EXTERNAL_2_VECTOR);
                break;
#endif
#ifdef PIN_INT3
            case EXT_INT3:
                IEC0bits.INT3IE	=	0;
                clearIntVector(_EXTERNAL_3_VECTOR);
                break;
#endif
#ifdef PIN_INT4
            case EXT_INT4:
                IEC0bits.INT4IE	=	0;
                clearIntVector(_EXTERNAL_4_VECTOR);
               break;
#endif
        }

        intFunc[interruptNum]	=	0;
    }
}

#define VEC_ENT_CODE(I,B,P) int c = intmode[I]; IFS0bits.B=0; if (intFunc[I] != 0) (*intFunc[I])(); if(c < CHANGE && c == digitalRead(P)) { IFS0bits.B=1; }

#ifdef PIN_INT0
//************************************************************************
// INT0 ISR
#if defined(__PIC32MZXX__)
void __attribute__((nomips16,at_vector(_EXTERNAL_0_VECTOR),interrupt(IPL4SRS))) ExtInt0Handler(void)
#else
void __attribute__((interrupt(),nomips16)) ExtInt0Handler(void)
#endif
{
	VEC_ENT_CODE(EXT_INT0,INT0IF,PIN_INT0);
/*
	int c = intmode[EXT_INT0];
	if (intFunc[EXT_INT0] != 0)
	{
		(*intFunc[EXT_INT0])();
	}
	
	if(c < CHANGE) {
		if(c == digitalRead(PIN_INT0)) {
			IFS0bits.INT0IF = 1;
		} else {
			IFS0bits.INT0IF = 0;
		}
	} else IFS0bits.INT0IF = 0;
*/
}
#endif

#ifdef PIN_INT1
//************************************************************************
// INT1 ISR
#if defined(__PIC32MZXX__)
void __attribute__((nomips16,at_vector(_EXTERNAL_1_VECTOR),interrupt(IPL4SRS))) ExtInt1Handler(void)
#else
void __attribute__((interrupt(),nomips16)) ExtInt1Handler(void)
#endif
{
	VEC_ENT_CODE(EXT_INT1,INT1IF,PIN_INT1);
/*
	int c = intmode[EXT_INT1];
	if (intFunc[EXT_INT1] != 0)
	{
		(*intFunc[EXT_INT1])();
	}
	
	if(c < CHANGE) {
		if(c == digitalRead(PIN_INT1)) {
			IFS0bits.INT1IF = 1;
		} else {
			IFS0bits.INT1IF = 0;
		}
	} else IFS0bits.INT1IF = 0;
*/
}
#endif

#ifdef PIN_INT2
//************************************************************************
// INT2 ISR
#if defined(__PIC32MZXX__)
void __attribute__((nomips16,at_vector(_EXTERNAL_2_VECTOR),interrupt(IPL4SRS))) ExtInt2Handler(void)
#else
void __attribute__((interrupt(),nomips16)) ExtInt2Handler(void)
#endif
{
	VEC_ENT_CODE(EXT_INT2,INT2IF,PIN_INT2);
/*
	int c = intmode[EXT_INT2];
	if (intFunc[EXT_INT2] != 0)
	{
		(*intFunc[EXT_INT2])();
	}
	
	if(c < CHANGE) {
		if(c == digitalRead(PIN_INT2)) {
			IFS0bits.INT2IF = 1;
		} else {
			IFS0bits.INT2IF = 0;
		}
	} else IFS0bits.INT2IF = 0;
*/
}
#endif

#ifdef PIN_INT3
//************************************************************************
// INT3 ISR
#if defined(__PIC32MZXX__)
void __attribute__((nomips16,at_vector(_EXTERNAL_3_VECTOR),interrupt(IPL4SRS))) ExtInt3Handler(void)
#else
void __attribute__((interrupt(),nomips16)) ExtInt3Handler(void)
#endif
{
	VEC_ENT_CODE(EXT_INT3,INT3IF,PIN_INT3);
/*
	int c = intmode[EXT_INT3];
	if (intFunc[EXT_INT3] != 0)
	{
		(*intFunc[EXT_INT3])();
	}
	
	if(c < CHANGE) {
		if(c == digitalRead(PIN_INT3)) {
			IFS0bits.INT3IF = 1;
		} else {
			IFS0bits.INT3IF = 0;
		}
	} else IFS0bits.INT3IF = 0;
*/
}
#endif

#ifdef PIN_INT4
//************************************************************************
// INT4 ISR
#if defined(__PIC32MZXX__)
void __attribute__((nomips16,at_vector(_EXTERNAL_4_VECTOR),interrupt(IPL4SRS))) ExtInt4Handler(void)
#else
void __attribute__((interrupt(),nomips16)) ExtInt4Handler(void)
#endif
{
	VEC_ENT_CODE(EXT_INT4,INT4IF,PIN_INT4);
/*
	int c = intmode[EXT_INT4];
	if (intFunc[EXT_INT4] != 0)
	{
		(*intFunc[EXT_INT4])();
	}
	
	if(c < CHANGE) {
		if(c == digitalRead(PIN_INT4)) {
			IFS0bits.INT4IF = 1;
		} else {
			IFS0bits.INT4IF = 0;
		}
	} else IFS0bits.INT4IF = 0;
*/
}
#endif

//************************************************************************

