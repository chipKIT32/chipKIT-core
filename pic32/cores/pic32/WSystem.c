/************************************************************************/
/*																		*/
/*	WSystem.c -- Low Level System Management Functions					*/
/*																		*/
/************************************************************************/
/*	Author: Gene Apperson												*/
/*	Copyright 2012, Digilent. All rights reserved						*/
/************************************************************************/
/*  Module Description: 												*/
/*																		*/
/*	This module contains functions for low level system control and		*/
/*	management of the processor. This includes things like interrupt	*/
/*	management and processor configuration.								*/
/*																		*/
/************************************************************************/
//*	This module is free software; you can redistribute it and/or
//*	modify it under the terms of the GNU Lesser General Public
//*	License as published by the Free Software Foundation; either
//*	version 2.1 of the License, or (at your option) any later version.
//*	
//*	This library is distributed in the hope that it will be useful,
//*	but WITHOUT ANY WARRANTY; without even the implied warranty of
//*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//*	Lesser General Public License for more details.
//*	
//*	You should have received a copy of the GNU Lesser General
//*	Public License along with this library; if not, write to the
//*	Free Software Foundation, Inc., 59 Temple Place, Suite 330,
//*	Boston, MA  02111-1307  USA
/************************************************************************/
/*  Revision History:													*/
/*																		*/
/*	08/23/2012(GeneApperson): Created									*/
/*	06/18/2013(Keith Vogel): Finished the interrupt vector handler		*/
/*																		*/
/************************************************************************/


/* ------------------------------------------------------------ */
/*				Include File Definitions						*/
/* ------------------------------------------------------------ */

#include	<p32xxxx.h>

#define	OPT_SYSTEM_INTERNAL
#include	<System_Defs.h>
#include	<p32_defs.h>

#include	"wiring.h"
#include    "Board_Defs.h"

/* ------------------------------------------------------------ */
/*				Local Type Definitions							*/
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/*				Global Variables								*/
/* ------------------------------------------------------------ */

//************************************************************************
//* Interrupt vector dispatch table
//* This table contains pointers to the dynamically installed interrupt service routines.
//* The interrupt vectors in program flash memory have been populated with dispatch
//* functions that indirect to the ISR specified by this table.
extern const uint32_t _GEN_EXCPT_ADDR;
void (*volatile _isr_primary_install[NUM_INT_VECTOR]) (void) = {[0 ... NUM_INT_VECTOR-1] = (isrFunc) &_GEN_EXCPT_ADDR}; /* Initialize all 64*/

/* ------------------------------------------------------------ */
/*				Local Variables									*/
/* ------------------------------------------------------------ */


/* ------------------------------------------------------------ */
/*				Forward Declarations							*/
/* ------------------------------------------------------------ */


/* ------------------------------------------------------------ */
/*				Public Interface Functions						*/
/* ------------------------------------------------------------ */
/*			Interrupt Vector Management Functions				*/
/* ------------------------------------------------------------ */
#if defined(__PIC32MZXX__)

/***	initIntVector
**
**	Parameters:
**
**	Return Value:
**		none
**
**	Errors:
**		none
**
**	Description:
**		Initializes the RAM IntVector table to
**		all of the compiler generated interrupt vectors
**		This will provide backwards compatibility should
**		someone not set their interrupt vector by calling
**		setIntVector; but by not setting the IntVector
**      your vector may be maked by a conflicting peripheral
*/
void initIntVector(void)
{
    return;
}

/* ------------------------------------------------------------ */
/***	getIntVector
**
**	Parameters:
**		vec		- interrupt vector number
**
**	Return Value:
**              The current ISR function
**
**	Errors:
**              NULL if vector is out of range
**
**	Description:
**          Returns the currently assigned ISR function without
**          changeing anything.
**
*/
isrFunc getIntVector(int vec)
{
    uint32_t isrAddr = ((uint32_t *) &OFF000)[vec] + (uint32_t) &_ebase_address;
    return((isrFunc) isrAddr);
}

/***	setIntVector
**
**	Parameters:
**		vec		- interrupt vector number
**		func	- interrupt service routine to install
**
**	Return Value:
**		Returns pointer to previous interrupt service routine for the vector
**              This may return the compiler installed routine if the compiler set one.
**              It will return the address of the general exception handler if no previous ISR was set.
**              It will return 0/NULL if the vector requested is out of range of the processor
**
**	Errors:
**		None as this is used in begin() methods that have no error returns.
**
**	Description:
**		Dynamically install an interrupt service routine for the specified
**		interrupt vector; This will blast over exiting ones without an error
**      because many Arduino begin methods return no errors and just expect this to
**      work. However, this may overwrite a previeously installed ISR.
**
**      This does not change the priority level of the interrupt routine
*/
isrFunc setIntVector(int vec, isrFunc func)
{
    isrFunc isrAddr = getIntVector(vec);
 
    ((uint32_t *) &OFF000)[vec] = (uint32_t) func - (uint32_t) &_ebase_address;

    return(isrAddr);
}

/* ------------------------------------------------------------ */
/***	clearIntVector
**
**	Parameters:
**		vec		- interrupt vector number
**
**	Return Value:
**      Returns the currently set ISR before clearing it
**
**	Errors:
**		Returns NULL if the vector number specified is out of range
**
**	Description:
**		Sets the priority to 0 thus disabling the ISR, and sets the 
**      pointer to the general exception handler.
*/
isrFunc clearIntVector(int vec)
{
    isrFunc isrAddr = getIntVector(vec);
 
    ((uint32_t *) &OFF000)[vec] = (uint32_t) &_GEN_EXCPT_ADDR - (uint32_t) &_ebase_address;

    return(isrAddr);
}

#else
/***	initIntVector
**
**	Parameters:
**
**	Return Value:
**		none
**
**	Errors:
**		none
**
**	Description:
**		Initializes the RAM IntVector table to
**		all of the compiler generated interrupt vectors
**		This will provide backwards compatibility should
**		someone not set their interrupt vector by calling
**		setIntVector; but by not setting the IntVector
**      your vector may be maked by a conflicting peripheral
*/
void initIntVector(void)
{
    const IMAGE_HEADER_INFO * pImageHeader = getImageHeaderInfoStructure();
    int i = 0;
    void * pvOrgIntVec = (void *)pImageHeader->pOrgVector0;

    for(i=0; i<NUM_INT_VECTOR; i++)
    {
        // If a compiler installed interrupt handler exits, pre-load it with the original handler
        // However, if a class construtor has already loaded a value in the table, don't replace it
        // There is now a default ISR handler so this replacement almost always occurs
        if(*((uint32_t *) pvOrgIntVec) != 0xFFFFFFFF  && _isr_primary_install[i] == (isrFunc) &_GEN_EXCPT_ADDR)
        {
            _isr_primary_install[i] = (isrFunc) pvOrgIntVec;
        }

        pvOrgIntVec += pImageHeader->cbVectorSpacing;
    }

    return;
}

/***	setIntVector
**
**	Parameters:
**		vec		- interrupt vector number
**		func	- interrupt service routine to install
**
**	Return Value:
**		Returns pointer to previous interrupt service routine for the vector
**              This may return the compiler installed routine if the compiler set one.
**              It will return the address of the general exception handler if no previous ISR was set.
**              It will return 0/NULL if the vector requested is out of range of the processor
**
**	Errors:
**		None as this is used in begin() methods that have no error returns.
**
**	Description:
**		Dynamically install an interrupt service routine for the specified
**		interrupt vector; This will blast over exiting ones without an error
**      because many Arduino begin methods return no errors and just expect this to
**      work. However, this may overwrite a previeously installed ISR.
**
**      This does not change the priority level of the interrupt routine
*/
isrFunc setIntVector(int vec, isrFunc func)
{
    isrFunc t = 0;

    if (vec < NUM_INT_VECTOR)
    {
        t = _isr_primary_install[vec];
        _isr_primary_install[vec] = func;       
    }

    return t;
}

/* ------------------------------------------------------------ */
/***	getIntVector
**
**	Parameters:
**		vec		- interrupt vector number
**
**	Return Value:
**              The current ISR function
**
**	Errors:
**              NULL if vector is out of range
**
**	Description:
**          Returns the currently assigned ISR function without
**          changeing anything.
**
*/
isrFunc getIntVector(int vec)
{

    if (vec < NUM_INT_VECTOR)
    {
        return _isr_primary_install[vec];
    }
    else
    {
        return 0;
    }
}

/* ------------------------------------------------------------ */
/***	clearIntVector
**
**	Parameters:
**		vec		- interrupt vector number
**
**	Return Value:
**      Returns the currently set ISR before clearing it
**
**	Errors:
**		Returns NULL if the vector number specified is out of range
**
**	Description:
**		Sets the priority to 0 thus disabling the ISR, and sets the 
**      pointer to the general exception handler.
*/
isrFunc clearIntVector(int vec)
{
    isrFunc rISR = 0;

    if (vec < NUM_INT_VECTOR)
    {
        rISR = _isr_primary_install[vec];
        setIntPriority(vec, 0, 0);                                  // this will disable the interrupt
        _isr_primary_install[vec] = (isrFunc) &_GEN_EXCPT_ADDR;
    }
    return(rISR);
}
#endif

/* ------------------------------------------------------------ */
/*				Interrupt Management Functions					*/
/* ------------------------------------------------------------ */
/***	enableInterrupts
**
**	Parameters:
**		none
**
**	Return Value:
**		Previous state of the global interrupt enable flag
**
**	Errors:
**		none
**
**	Description:
**		This function sets the global interrupt enable flag,
**		enabling all interrupts.
*/

uint32_t __attribute__((nomips16))  enableInterrupts(void)
{
    uint32_t status = 0;

    asm volatile("ei    %0" : "=r"(status));

    return status;
}

/* ------------------------------------------------------------ */
/***	disableInterrutps
**
**	Parameters:
**		none
**
**	Return Value:
**		Previous state fo the global interrupt enable flag
**
**	Errors:
**		none
**
**	Description:
**		This function clears the global interrupt enable flag,
**		disabling all interrupts.
*/

uint32_t __attribute__((nomips16)) disableInterrupts(void)
{
    uint32_t status = 0;

    asm volatile("di    %0" : "=r"(status));

    return status;
}

/* ------------------------------------------------------------ */
/***	restoreInterrupts
**
**	Parameters:
**		st		- Previous state of global interrupt enable flag
**
**	Return Value:
**		none
**
**	Errors:
**		none
**
**	Description:
**		This function restores the state of the global interrupt
**		enable flag to a previous state. The value passed in for
**		st should be a value previously returned by either
**		enableInterrupts() or disableInterrupts().
*/

void __attribute__((nomips16))  restoreInterrupts(uint32_t st)
{
    if (st & 0x00000001)
	{
        asm volatile("ei");
	}
    else
	{
        asm volatile("di");
	}
}

/* ------------------------------------------------------------ */
/***	getIntFlag
**
**	Parameters:
**		irq		- Interrupt request number
**
**	Return Value:
**		Returns the state of the request interrupt flag.
**
**	Errors:
**		none
**
**	Description:
**		Return the state of the interrupt request flag for the
**		specified interrupt. The return value will be 0 if the
**		flag is not set, and non-zero if the flag is set.
*/

uint32_t getIntFlag(int irq)
{
	p32_regset *	ifs;

	ifs = ((p32_regset *)&IFS0) + (irq / 32);
	return (ifs->reg & (1 << (irq % 32))) != 0;
}


/* ------------------------------------------------------------ */
/***	clearIntFlag
**
**	Parameters:
**		irq		- Interrupt request number
**
**	Return Value:
**		none
**
**	Errors:
**		none
**
**	Description:
**		Clear the interrupt request flag for the specified interrupt.
*/

void clearIntFlag(int irq)
{
	p32_regset *	ifs;

	ifs = ((p32_regset *)&IFS0) + (irq / 32);
	ifs->clr = 1 << (irq % 32);
}

/* ------------------------------------------------------------ */
/***	setIntEnable
**
**	Parameters:
**		irq		- Interrupt request number
**
**	Return Value:
**		Returns the previous state of the specified interrupt enable flag
**
**	Errors:
**		none
**
**	Description:
**		Set the interrupt enable flag for the specified interrupt
**		request. This will enable whatever peripheral interrupt is
**		associated with the specified interrupt request.
*/

uint32_t setIntEnable(int irq)
{
	p32_regset *	iec;
	uint32_t		st;

	iec = ((p32_regset *)&IEC0) + (irq / 32);
	st = iec->reg;
	iec->set = 1 << (irq % 32);
	return st;
}

/* ------------------------------------------------------------ */
/***	clearIntEnable
**
**	Parameters:
**		irq		- interrupt request number
**
**	Return Value:
**		Returns the previous state of the specified interrupt enable flag
**
**	Errors:
**		none
**
**	Description:
**		Disable the interrupt for the specified interrupt request
*/

uint32_t clearIntEnable(int irq)
{
	p32_regset *	iec;
	uint32_t		st;

	iec = ((p32_regset *)&IEC0) + (irq / 32);
	st = iec->reg;
	iec->clr = 1 << (irq % 32);
	return st;
}

/* ------------------------------------------------------------ */
/***	restoreIntEnable
**
**	Parameters:
**		irq			- interrupt request number
**		st			- previous enable state to restore
**
**	Return Value:
**		none
**
**	Errors:
**		none
**
**	Description:
**		This function restores the interrupt enable flag to a
**		previous state. The value specified in the st parameter
**		should be a value previously returned by setIntEnable()
**		or clearIntEnable()
*/

void restoreIntEnable(int irq, uint32_t st)
{
	p32_regset *	iec;
	uint32_t		bit;

	iec = ((p32_regset *)&IEC0) + (irq / 32);
	bit = (1 << (irq % 32));
	if ((st & bit) != 0)
	{
		iec->set = bit;
	}
	else
	{
		iec->clr = bit;
	}
}

/* ------------------------------------------------------------ */
/***	setIntPriority
**
**	Parameters:
**		vec			- interrupt vector number
**		ipl			- interrupt priority level to set
**		spl			- interrupt sub-priority level to set
**
**	Return Value:
**		none
**
**	Errors:
**		none
**
**	Description:
**		This function sets interrupt priority and sub-priority levels
**		for the specified interrupt vector.
*/

void setIntPriority(int vec, int ipl, int spl)
{
	p32_regset *	ipc;
	int             bn;

	/* Compute the address of the interrupt priority control register used
	** by this interrupt vector
	*/
	ipc = ((p32_regset *)&IPC0) + (vec / 4);

	/* Compute the number of bit positions to shift to get to the
	** correct position for the priority bits for this vector.
	*/
	bn = 8 * (vec % 4);

	/* Set the interrupt privilege level and sub-privilege level
	*/
	ipc->clr = (0x1F << bn);
	ipc->set = ((ipl << 2) + spl) << bn;

}

/* ------------------------------------------------------------ */
/***	getIntPriority
**
**	Parameters:
**		vec			- interrupt vector number
**		pipl		- pointer to variable to receive priority
**		pspl		- pointer to variable to receive sub-priority
**
**	Return Value:
**		none
**
**	Errors:
**		none
**
**	Description:
**		This function sets interrupt priority and sub-priority levels
**		for the specified interrupt vector.
*/

void getIntPriority(int vec, int * pipl, int * pspl)
{
	p32_regset *	ipc;
	int				bn;

	/* Compute the address of the interrupt priority control register used
	** by this interrupt vector
	*/
	ipc = ((p32_regset *)&IPC0) + (vec / 4);

	/* Compute the number of bit positions to shift to get to the
	** correct position for the priority bits for this vector.
	*/
	bn = 8 * (vec % 4);

	/* Set the interrupt privilege level and sub-privilege level
	*/
	*pipl = (ipc->reg >> (bn+2)) & 0x07;
	*pspl = (ipc->reg >> bn) & 0x03;

}

/* ------------------------------------------------------------ */
/*			Misc Processor Support Functions					*/
/* ------------------------------------------------------------ */
/***	getPeripheralClock()
**
**	Parameters:
**		none
**
**	Return Value:
**		Returns the current peripheral bus clock frequency
**
**	Errors:
**		none
**
**	Description:
**		Get the peripheral bus clock frequency
*/

uint32_t getPeripheralClock()
{
	uint32_t	clkPb;

    clkPb = F_CPU;

#if defined(__PIC32MZXX__)
    clkPb = (F_CPU / (PB2DIVbits.PBDIV + 1));      // TODO: set ALL PBDIV to 40 MHZ     
#else
    clkPb >>= OSCCONbits.PBDIV;
#endif

    return clkPb;
}

/* ------------------------------------------------------------ */
/***	readCoreTimer
**
**	Parameters:
**		none
**
**	Return Value:
**		Returns core timer count value
**
**	Errors:
**		none
**
**	Description:
**		Returns the current value of the core timer.
*/

uint32_t __attribute__((nomips16)) readCoreTimer(void)
{
    uint32_t tmr;

    // Get the value of the core timer count register.
    asm volatile("mfc0   %0, $9" : "=r"(tmr));

    return tmr;
}

/* ------------------------------------------------------------ */
/***	writeCoreTimer
**
**	Parameters:
**		tmr		- value to write to core timer counter
**
**	Return Value:
**		none
**
**	Errors:
**		none
**
**	Description:
**		Writes the specified value to the core timer count register.
*/

void __attribute__((nomips16)) writeCoreTimer(uint32_t tmr)
{
    // Write the value to the core timer count register
    asm volatile("mtc0   %0, $9": "+r"(tmr));

}

/* ------------------------------------------------------------ */
/*			Private System Configuration Functions				*/
/* ------------------------------------------------------------ */
/***	configSystem
**
**	Parameters:
**		clk		- processor master clock frequency
**
**	Return Value:
**		none
**
**	Errors:
**		none
**
**	Description:
**		Configure the processor. This disables data ram wait states,
**		sets the number of flash wait states and enables predictive
**		prefetch for both cached and non-cached memory segments.
*/

void __attribute__ ((nomips16)) _configSystem(uint32_t clk)
{
	uint32_t	stInt;
#if defined(_CHECON_PREFEN_POSITION)
	uint32_t	stCache;
    uint32_t	wait;
	register unsigned long tmp;
#endif

	stInt = disableInterrupts();

	/* Disable wait states in data ram.
	*/
#if defined(__PIC32MZXX__)

// If alternate ADC implementation
#if defined(__ALT_ADC_IMPL__)
    initADC();

// EC MZ ADC code
#elif defined(__PIC32MZECADC__)
    /* Configure AD1CON1 */
    AD1CON1 = 0;                // No AD1CON1 features are enabled including: Stop-in-Idle, early
                                // interrupt, filter delay Fractional mode and scan trigger source.

    /* Configure AD1CON2 */
    AD1CON2 = 0;                // Boost, Low-power mode off, SAMC set to min, set up the ADC Clock
    AD1CON2bits.ADCSEL  = 1;    // 1 = SYSCLK, 2 REFCLK03, 3 FRC
    AD1CON2bits.ADCDIV  = 10;   // DIV_20 TQ = 1/200 MHz; Tad = 10 * (TQ * 2) = 100 ns; 10 MHz ADC clock; the sweet spot
    AD1CON2bits.SAMC    = 75;    // settling time is 76 TADs  ((samc +1) + 4) * TAD <= 8000    (125Kbps is max, time 1/125000 = 8000 ns) => ((75  + 1) + 4) * 100 ns = 8000

    /* Configure AD1CON3 */
    AD1CON3 = 0;                // ADINSEL is not configured for this example. VREFSEL of ?0?
                                // selects AVDD and AVSS as the voltage reference.

    // AD1CON3bits.VREFSEL = 0b011; // set external VRef+/-

    /* Configure AD1GIRGENx */
    AD1GIRQEN1 = 0; // No global interrupts are used.
    AD1GIRQEN2 = 0;

    /* Configure AD1CSSx */
    AD1CSS1 = 0; // No channel scanning is used.
    AD1CSS2 = 0;

    /* Configure AD1CMPCONx */
    AD1CMPCON1 = 0; // No digital comparators are used. Setting the AD1CMPCONx
    AD1CMPCON2 = 0; // register to ?0? ensures that the comparator is disabled. Other
    AD1CMPCON3 = 0; // registers are ?don?t care?.
    AD1CMPCON4 = 0;
    AD1CMPCON5 = 0;
    AD1CMPCON6 = 0;

    /* Configure AD1FLTRx */
    AD1FLTR1 = 0; // No oversampling filters are used.
    AD1FLTR2 = 0;
    AD1FLTR3 = 0;
    AD1FLTR4 = 0;
    AD1FLTR5 = 0;
    AD1FLTR6 = 0;

    /* Set up the trigger sources */
    AD1TRG1 = 0; // Initialize all sources to no trigger.
    AD1TRG2 = 0;
    AD1TRG3 = 0;

    /* Set up the CAL registers */
    // AD1CAL1 = DEVADC1;          // Copy the configuration data to the
    // AD1CAL2 = DEVADC2;          // AD1CALx special function registers.
    // AD1CAL3 = DEVADC3;
    // AD1CAL4 = DEVADC4;
    // AD1CAL5 = DEVADC5;

    // comply to the errata
    AD1CAL1 = 0xF8894530;
    AD1CAL2 = 0x01E4AF69;
    AD1CAL3 = 0x0FBBBBB8;
    AD1CAL4 = 0x000004AC;
    AD1CAL5 = 0x02000002;

    /* Turn the ADC on, start calibration */
    AD1IMODbits.SH0MOD =  2;            // put in differiential mode for self calibration
    AD1IMODbits.SH1MOD =  2;            // put in differiential mode for self calibration
    AD1IMODbits.SH2MOD =  2;            // put in differiential mode for self calibration
    AD1IMODbits.SH3MOD =  2;            // put in differiential mode for self calibration
    AD1IMODbits.SH4MOD =  2;            // put in differiential mode for self calibration
    AD1IMODbits.SH5MOD =  2;            // put in differiential mode for self calibration
    AD1CON1bits.ADCEN = 1;              // enable, start calibration
    while (AD1CON2bits.ADCRDY == 0);    // wait for calibration to complete
    AD1IMODbits.SH0MOD =  0;            // put in unipolar encoding
    AD1IMODbits.SH1MOD =  0;            // put in unipolar encoding
    AD1IMODbits.SH2MOD =  0;            // put in unipolar encoding
    AD1IMODbits.SH3MOD =  0;            // put in unipolar encoding
    AD1IMODbits.SH4MOD =  0;            // put in unipolar encoding
    AD1IMODbits.SH5MOD =  0;            // put in unipolar encoding

#elif defined(__PIC32MZEFADC__)
    #error EF ADC code not implemented yet

// unknown ADC code
#else
    #error ADC code for this MZ must be added in WSystems.c and wiring_analog.c
#endif

#else
	BMXCONCLR = (1 << _BMXCON_BMXWSDRM_POSITION);
#endif

#if defined(_CHECON_PREFEN_POSITION)

	stCache = CHECON;

	/* Configure predictive prefetch caching for both cached and
	** non-cached memory regions.
	*/
    stCache |= (3 << _CHECON_PREFEN_POSITION);

	/* Turn on caching for KSEG0
	*/
	asm("mfc0 %0,$16,0" :  "=r"(tmp));
	tmp = (tmp & ~7) | 3;
	asm("mtc0 %0,$16,0" :: "r" (tmp));

	/* Configure the number of wait states in the program flash
	*/
    wait = 0;

    while(clk > FLASH_SPEED_HZ)
    {
        wait += 1;
        clk -= FLASH_SPEED_HZ;
    }

    stCache &= ~_CHECON_PFMWS_MASK;
	stCache |= (wait << _CHECON_PFMWS_POSITION);

	CHECON = stCache;

#elif defined(_PRECON_PREFEN_POSITION)
  // 
  // Set wait states and enable prefetch buffer 
  // 
  PRECON = 0u 
         | (2u << _PRECON_PFMWS_POSITION)  // 2 wait states 
         | (3u << _PRECON_PREFEN_POSITION); // Enable prefetch for instructions + data 


#endif


	restoreInterrupts(stInt);
}

/* ------------------------------------------------------------ */
/***	_enableMultiVectorInterrupts
**
**	Parameters:
**		none
**
**	Return Value:
**		none
**
**	Errors:
**		none
**
**	Description:
**		Configure the system for vectored interrupts and turn
**		interrupts on.
*/

void __attribute__ ((nomips16)) _enableMultiVectorInterrupts()
{
    unsigned int val;

    /* Set the CP0 bit so that interrupt exceptions use the
	** special interrupt vector and not the general exception vector.
	*/
    asm volatile("mfc0   %0,$13" : "=r"(val));
    val |= 0x00800000;
    asm volatile("mtc0   %0,$13" : "+r"(val));

	/* Turn on multi-vectored interrupts.
	*/
    INTCONSET = _INTCON_MVEC_MASK;

// set up some default shadow registers for each interrupt priority level
// the shadow register set used is the same as the priority level
#if defined(__PIC32MZXX__)
        PRISS = 0x76543210;
#endif

    /* Enable interrupts.
	*/
    enableInterrupts();

}

/* ------------------------------------------------------------ */
/***	_initCoreTimer
**
**	Parameters:
**		prd		- Core timer interrupt period
**
**	Return Value:
**		none
**
**	Errors:
**		none
**
**	Description:
**		Clear the core timer counter and initialize the compare
**		period register.
*/

void __attribute__((nomips16)) _initCoreTimer(uint32_t prd)
{
	/* Clear the core timer counter
	*/
    asm volatile("mtc0   $0,$9");

    /* Store the requested value in the compare register
	*/
    asm volatile("mtc0   %0,$11" : "+r"(prd));
}

/* ------------------------------------------------------------ */
/***	_softwareReset
**
**	Parameters:
**		none
**
**	Return Value:
**		Does not return
**
**	Errors:
**		none
**
**	Description:
**		This function performs a software reset of the processor. This
**		requires the following steps: Unlock the processor; Set the SWRST
**		bit in the RSWRT register; Read the RSWRT register.
**
**	Note:
**		Something like the while(1) needs to be performed after the read
**		to ensure that no other instructions are executed before the
**		actual reset occurs.
*/

 void __attribute__((noreturn)) _softwareReset(void)
{
	volatile int * p = (volatile int *)&RSWRST;

	// Unlock the system
	disableInterrupts();
	SYSKEY = 0;
	SYSKEY = 0xAA996655;
	SYSKEY = 0x556699AA;

	// Perform the software reset
	RSWRSTSET=_RSWRST_SWRST_MASK;
	*p;

	// Wait for the rest to take place
	while(1);

}

/* ------------------------------------------------------------ */
/***	_disableSeconaryOscillator
**
**	Parameters: none
**
**	Return Value: none
**
**	Errors: none
**
**	Description: Several of our boards need to disable the seconday
**               oscillator on _boart_init(). This function expands
**               the macros from plib.h that previously did the 
**               unlocking/locking of OSCCON writing.
**
*/
void _disableSeconaryOscillator(void)
{
	//*	Turn Secondary oscillator off
	//*	this is only needed on the mega board because the mega uses secondary
	// ocsilator pins as general I/O
	
	unsigned int int_status;
    
    // Expanded mSYSTEMLock() and mSYSTEMUnLock() macros from plib.h
    /// WARNING: According to the datasheet, this unlock sequence should also
    /// turn off DMA before writing the SYSKEY values, and retore it at the
    /// end. This is what the mSYSTEM macros did from plib.h. But since we
    /// don't have that piece of plib.h implemneted in chipKIT yet, we're
    /// going to leave that part out.
    int_status = disableInterrupts();
	SYSKEY = 0;
    SYSKEY = 0xAA996655;
    SYSKEY = 0x556699AA;

	OSCCONCLR =	_OSCCON_SOSCEN_MASK;

	SYSKEY = 0x33333333; 
    restoreInterrupts(int_status);	
}

/* ------------------------------------------------------------ */
/***	ProcName
**
**	Parameters:
**
**	Return Value:
**
**	Errors:
**
**	Description:
**
*/

/* ------------------------------------------------------------ */

/************************************************************************/

