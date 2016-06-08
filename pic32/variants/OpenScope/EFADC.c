/************************************************************************/
/*                                                                      */
/*  EFADC.cpp   WiFIRE ADC code for the EF MZ processor line            */
/*                                                                      */
/************************************************************************/
/*  Author:     Keith Vogel                                             */
/*  Copyright 2015, Digilent Inc.                                       */
/************************************************************************/
/* 
*
* Copyright (c) 2015, Digilent <www.digilentinc.com>
* Contact Digilent for the latest version.
*
* This program is free software; distributed under the terms of 
* BSD 3-clause license ("Revised BSD License", "New BSD License", or "Modified BSD License")
*
* Redistribution and use in source and binary forms, with or without modification,
* are permitted provided that the following conditions are met:
*
* 1.    Redistributions of source code must retain the above copyright notice, this
*        list of conditions and the following disclaimer.
* 2.    Redistributions in binary form must reproduce the above copyright notice,
*        this list of conditions and the following disclaimer in the documentation
*        and/or other materials provided with the distribution.
* 3.    Neither the name(s) of the above-listed copyright holder(s) nor the names
*        of its contributors may be used to endorse or promote products derived
*        from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
* OF THE POSSIBILITY OF SUCH DAMAGE.
*/
/************************************************************************/
/*  Module Description:                                                 */
/*                                                                      */
/*      Implements the WiFIRE EF ADC                                    */
/*                                                                      */
/************************************************************************/
/*  Revision History:                                                   */
/*                                                                      */
/*      6/8/2011(KeithV): Created                                     */
/*                                                                      */
/************************************************************************/

#include <p32xxxx.h>
#include <Board_Defs.h>


/* ------------------------------------------------------------ */
/***	initADC
**
**	Parameters:
**		none
**
**	Return Value:
**      none
**
**	Errors:
**     none
**
**	Description:
**      Initialize the MZ EF ADCs for the WiFIRE
**
*/
void initADC(void)
{
    uint32_t    cTADWarmUp = 0;
    uint32_t    i = 0;

    // initialize configuration registers
    ADCCON1     = 0; 
    ADCCON2     = 0; 
    ADCCON3     = 0; 
    ADCANCON    = 0;
    ADCTRGMODE  = 0;
    ADCIMCON1   = 0x00000155;   // signed single ended mode (not differential)
    ADCIMCON2   = 0x00000000;   // signed single ended mode (not differential)
    ADCIMCON3   = 0x00000000;   // signed single ended mode (not differential)
    ADCTRGSNS   = 0;
 
    // resolution 0 - 6bits, 1 - 8bits, 2 - 10bits, 3 - 12bits
    ADCCON1bits.SELRES  =   RES12BITS;  // shared ADC, 12 bits resolution (bits+2 TADs, 12bit resolution = 14 TAD).

    // 0 - no trigger, 1 - clearing software trigger, 2 - not clearing software trigger, the rest see datasheet
    ADCCON1bits.STRGSRC     = 1;    //Global software trigger / self clearing.

    // 0 - internal 3.3, 1 - use external VRef+, 2 - use external VRef-
    ADCCON3bits.VREFSEL     = VREFHEXT;    // use extern VREF3V0

    // this should be set if VRef+ - VRef - < 0.65 VCC; this may not need to be on
    // ADCCON1bits.AICPMPEN    = 1;    // turn on the analog charge pump

    // set up the TQ and TAD and S&H times

    // TCLK: 00- pbClk3, 01 - SysClk, 10 - External Clk3, 11 - interal 8 MHz clk
    ADCCON3bits.ADCSEL      = CLKSRCSYSCLK;             // TCLK clk == Sys Clock == F_CPU  

    // Global ADC TQ Clock: Global ADC prescaler 0 - 63; Divide by (CONCLKDIV*2) However, the value 0 means divide by 1
    ADCCON3bits.CONCLKDIV   = TQCONCLKDIV;                // Divide by 1 == TCLK == SYSCLK == F_CPU

    // must be divisible by 2 
    ADCCON2bits.ADCDIV      = ADCTADDIV;   // run TAD at 50MHz

    ADCCON2bits.SAMC        = (ADCTADSH - 2);   // for the shared S&H this will allow source impedances < 10Kohm

    // with 50MHz TAD and 68 TAD S&H and 14 TAD for 12 bit resolution, that is 25000000 / (68+14) = 609,756 Sps or 1.64 us/sample

    // initialize the warm up timer
    // 20us or 500 TAD which ever is higher 1/20us == 50KHz
    cTADWarmUp = ((F_CPU / (ADCCON3bits.CONCLKDIV == 0 ? 1 : (ADCCON3bits.CONCLKDIV * 2))) / (F_CPU / ADCTADFREQ) / 50000ul);
    if(cTADWarmUp < 500) 
    {
        cTADWarmUp = 500;
    }

    // get the next higher power of the count
    for(i=0; i<16; i++)
    {
        if((cTADWarmUp >> i) == 0)
        {
            break;
        }
    }

    // the warm up count is 2^^X where X = 0 -15
    ADCANCONbits.WKUPCLKCNT = i; // Wakeup exponent = 2^^15 * TADx   
  
    // ADC 0
    ADC0TIMEbits.ADCDIV     = ADCCON2bits.ADCDIV;       // ADC0 clock frequency is half of control clock = TAD0 200 / 2 (pb) / 2 (clkdiv) / 2 (adcdiv) == TAD == 25 MHz
    ADC0TIMEbits.SAMC       = (ANINADCSH-2);            // ADC0 sampling time = (SAMC+2) * TAD0
    ADC0TIMEbits.SELRES     = ADCCON1bits.SELRES;       // ADC0 resolution is 12 bits 
    ADCIMCON1bits.SIGN0     = 1;                        // signed data format

    // ADC 1
    ADC1TIMEbits.ADCDIV     = ADCCON2bits.ADCDIV;       // ADC1 clock frequency is half of control clock = TAD0 200 / 2 (pb) / 2 (clkdiv) / 2 (adcdiv) == TAD == 25 MHz
    ADC1TIMEbits.SAMC       = (ANINADCSH-2);            // ADC1 sampling time = (SAMC+2) * TAD0
    ADC1TIMEbits.SELRES     = ADCCON1bits.SELRES;       // ADC1 resolution is 12 bits 
    ADCIMCON1bits.SIGN1     = 1;                        // signed data format

    // ADC 2
    ADC2TIMEbits.ADCDIV     = ADCCON2bits.ADCDIV;       // ADC2 clock frequency is half of control clock = TAD0 200 / 2 (pb) / 2 (clkdiv) / 2 (adcdiv) == TAD == 25 MHz
    ADC2TIMEbits.SAMC       = (ANINADCSH-2);            // ADC2 sampling time = (SAMC+2) * TAD0
    ADC2TIMEbits.SELRES     = ADCCON1bits.SELRES;       // ADC2 resolution is 12 bits 
    ADCIMCON1bits.SIGN2     = 1;                        // signed data format

    // ADC 3
    ADC3TIMEbits.ADCDIV     = ADCCON2bits.ADCDIV;       // ADC3 clock frequency is half of control clock = TAD0 200 / 2 (pb) / 2 (clkdiv) / 2 (adcdiv) == TAD == 25 MHz
    ADC3TIMEbits.SAMC       = (ANINADCSH-2);            // ADC3 sampling time = (SAMC+2) * TAD0
    ADC3TIMEbits.SELRES     = ADCCON1bits.SELRES;       // ADC3 resolution is 12 bits 
    ADCIMCON1bits.SIGN3     = 1;                        // signed data format

    // ADC 4
    ADC4TIMEbits.ADCDIV     = ADCCON2bits.ADCDIV;       // ADC4 clock frequency is half of control clock = TAD0 200 / 2 (pb) / 2 (clkdiv) / 2 (adcdiv) == TAD == 25 MHz
    ADC4TIMEbits.SAMC       = ADCCON2bits.SAMC;         // ADC4 sampling time = (SAMC+2) * TAD0
    ADC4TIMEbits.SELRES     = ADCCON1bits.SELRES;       // ADC4 resolution is 12 bits 
    ADCIMCON1bits.SIGN4     = 1;                        // signed data format

    /* Configure ADCIRQENx */
    ADCCMPEN1 = 0; // No interrupts are used
    ADCCMPEN2 = 0;
    
    /* Configure ADCCSSx */
    ADCCSS1 = 0; // No scanning is used
    ADCCSS2 = 0;
    
    /* Configure ADCCMPxCON */
    ADCCMP1 = 0; // No digital comparators are used. Setting the ADCCMPxCON
    ADCCMP2 = 0; // register to '0' ensures that the comparator is disabled.
    ADCCMP3 = 0; // Other registers are ?don't care?.
    ADCCMP4 = 0;
    ADCCMP5 = 0;
    ADCCMP6 = 0;    

    /* Configure ADCFLTRx */
    ADCFLTR1 = 0; // Clear all bits
    ADCFLTR2 = 0;
    ADCFLTR3 = 0;
    ADCFLTR4 = 0;
    ADCFLTR5 = 0;
    ADCFLTR6 = 0;
    
    // disable all global interrupts
    ADCGIRQEN1 = 0;
    ADCGIRQEN2 = 0;
    
    /* Early interrupt */
    ADCEIEN1 = 0; // No early interrupt
    ADCEIEN2 = 0;

    // turn on the ADCs
    ADCCON1bits.ON = 1;

    /* Wait for voltage reference to be stable */
    while(!ADCCON2bits.BGVRRDY); // Wait until the reference voltage is ready
    while(ADCCON2bits.REFFLT); // Wait if there is a fault with the reference voltage
    
    /* Enable clock to analog circuit */
    ADCANCONbits.ANEN0 = 1; // Enable the clock to analog bias and digital control
    ADCANCONbits.ANEN1 = 1; // Enable the clock to analog bias and digital control
    ADCANCONbits.ANEN2 = 1; // Enable the clock to analog bias and digital control
    ADCANCONbits.ANEN3 = 1; // Enable the clock to analog bias and digital control
    ADCANCONbits.ANEN4 = 1; // Enable the clock to analog bias and digital control
    ADCANCONbits.ANEN7 = 1; // Enable the clock to analog bias and digital control
   
    /* Wait for ADC to be ready */
    while(!ADCANCONbits.WKRDY0); // Wait until ADC0 is ready
    while(!ADCANCONbits.WKRDY1); // Wait until ADC1 is ready
    while(!ADCANCONbits.WKRDY2); // Wait until ADC2 is ready
    while(!ADCANCONbits.WKRDY3); // Wait until ADC3 is ready
    while(!ADCANCONbits.WKRDY4); // Wait until ADC3 is ready
    while(!ADCANCONbits.WKRDY7); // Wait until ADC0 is ready
        
    /* Enable the ADC module */
    ADCCON3bits.DIGEN0 = 1; // Enable ADC0
    ADCCON3bits.DIGEN1 = 1; // Enable ADC1
    ADCCON3bits.DIGEN2 = 1; // Enable ADC2
    ADCCON3bits.DIGEN3 = 1; // Enable ADC3
    ADCCON3bits.DIGEN4 = 1; // Enable ADC3
    ADCCON3bits.DIGEN7 = 1; // Enable shared ADC
}

/* ------------------------------------------------------------ */
/***	convertADC
**
**	Parameters:
**		channelNumber - The PIC32 analog channel number as in the PIC32 datasheet
**
**	Return Value:
**      The converted value for that channel
**
**	Errors:
**     If return value of zero and error may have occured
**
**	Description:
**      Coverts the analog signal to a digital value on the 
**      given pic32 analog channel number
*/
int convertADC(uint8_t channelNumber)
{ 
    uint8_t vcn = channelNumber;        // assume our vitual channel number is the real one
    uint32_t adcTRGmode = ADCTRGMODE;   // save trigger mode

    // see if we are using alternate inputs
    switch(vcn)
    {
        case 43:
        case 44:
        case 50:
            return(0);
            break;

        case 45:
            ADCTRGMODEbits.SH0ALT = 1;
            vcn -= 45;
            break;

        case 46:
            ADCTRGMODEbits.SH1ALT = 1;
            vcn -= 45;
            break;

        case 47:
            ADCTRGMODEbits.SH2ALT = 1;
            vcn -= 45;
            break;

        case 48:
            ADCTRGMODEbits.SH3ALT = 1;
            vcn -= 45;
            break;

        case 49:
            ADCTRGMODEbits.SH4ALT = 1;
            vcn -= 45;
            break;

        default:
            break;
    }

    ADCCON3bits.ADINSEL   = vcn;            // say which channel to manually trigger
    ADCCON3bits.RQCNVRT  = 1;               // manually trigger it.

    // wait for completion of the conversion
    if(vcn < 32)
    {
        uint32_t mask = 0x1 << vcn;
        while((ADCDSTAT1 & mask) == 0);
    }
    else
    {
        uint32_t mask = 0x1 << (vcn - 32);
        while((ADCDSTAT2 & mask) == 0);
    }

    // return the trigger mode to what it was
    ADCTRGMODE = adcTRGmode;

    // return the converted data
    return((int) ((uint32_t *) &ADCDATA0)[vcn]);
}

/* ------------------------------------------------------------ */
/***	ReadFeedBackADC
**
**	Parameters:
**		channelNumber - The PIC32 analog channel number as in the PIC32 datasheet
**
**	Return Value:
**      The converted value for that channel
**
**	Errors:
**     If return value of zero and error may have occured
**
**	Description:
**      Converts the analog signal to a digital value on the 
**      given pic32 analog channel number. The converter must
**      a class 1 or 2 ADC, that is ADC 0 - 31
*/
uint16_t ReadFeedBackADC(uint8_t channelNumber, uint8_t cAverage)
{
    uint8_t oversample = 0;

    if(channelNumber >= 32)
    {
        return(0);
    }
    
    // figure out the oversampling
    for(oversample=7; oversample>1 && cAverage>=128; oversample--, cAverage <<= 1);
    if(cAverage == 128) oversample--;
    
    // set up the digital filter to average the 
    ADCFLTR1            = 0;                // clear the digital filtering
    ADCFLTR1bits.CHNLID = channelNumber;    // channnel to trigger
    ADCFLTR1bits.DFMODE = 1;                // go into averaging mode
    ADCFLTR1bits.OVRSAM = oversample;       // oversample count
    ADCFLTR1bits.AFEN   = 1;                // enable the digital filtering.   

    ADCCON3bits.ADINSEL  = channelNumber;   // say which channel to manually trigger
    ADCCON3bits.RQCNVRT  = 1;               // manually trigger it.

    while(ADCFLTR1bits.AFRDY == 0);         // wait until oversampling is done
    ADCFLTR1bits.AFEN   = 0;                // enable the digital filtering.   
    
    return((int16_t) ADCFLTR1bits.FLTRDATA);
}

