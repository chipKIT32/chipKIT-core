/************************************************************************/
/*																		*/
/*	Board_Defs.h --	Board Customization for Digilent chipKIT Uno32		*/
/*																		*/
/************************************************************************/
/*	Author: Gene Apperson												*/
/*	Copyright 2011, Digilent. All rights reserved						*/
/************************************************************************/
/*  File Description:													*/
/*																		*/
/* This file contains the board specific declartions and data structure	*/
/* to customize the chipKIT MPIDE for use with the Digilent chipKIT		*/
/* Uno32 board.															*/
/*																		*/
/* This code is based on earlier work:									*/
/*		Copyright (c) 2010, 2011 by Mark Sproul							*/
/*		Copyright (c) 2005, 2006 by David A. Mellis						*/
/*																		*/
/************************************************************************/
/*  Revision History:													*/
/*																		*/
/*	10/06/2011(GeneA): Created											*/
/*	11/28/2011(GeneA): Moved data definitions and configuration			*/
/*		functions to Board_Data.c										*/
/*	11/29/2011(GeneA): Moved int priority definitions to System_Defs.h	*/
/*	Feb 17, 2012	<KeithV> Added PPS support for MZ devices           */
/*																		*/
/************************************************************************/
//*	This library is free software; you can redistribute it and/or
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

#if !defined(BOARD_DEFS_H)
#define BOARD_DEFS_H

#include <inttypes.h>

//    #define  _OCMP1_BASE_ADDRESS ((uint32_t) &OC1CON)
    #define  _TIMER_1_IRQ _TIMER_1_VECTOR

/* ------------------------------------------------------------ */
/*				Public Board Declarations						*/
/* ------------------------------------------------------------ */
/* The following define symbols that can be used in a sketch to
** refer to periperhals on the board generically.
*/

#define	_BOARD_NAME_	"OpenScope"

/* Define the Microcontroller peripherals available on the board.
*/
#define	NUM_DIGITAL_PINS	79
#define	NUM_ANALOG_PINS		12
#define NUM_OC_PINS			6
#define	NUM_IC_PINS			4
#define	NUM_TCK_PINS		6
#define	NUM_INT_PINS		5

#define	NUM_SERIAL_PORTS	2   
#define	NUM_SPI_PORTS		1   
#define	NUM_I2C_PORTS		1   

#define NUM_DSPI_PORTS		4
#define	NUM_DTWI_PORTS		1

/* Define I/O devices on the board.
*/
#define	NUM_LED				4
#define NUM_BTN				0
#define	NUM_SWT				0
#define NUM_SERVO			0

/* Define the number of pins including extended i/o pins.
** These are pins that are not native to the microcontroller, such
** as implemented via an i/o expander or external A/D or D/A.
** This board doesn't have any.
*/
#define	NUM_DIGITAL_PINS_EXTENDED	NUM_DIGITAL_PINS
#define	NUM_ANALOG_PINS_EXTENDED	NUM_ANALOG_PINS

/* ------------------------------------------------------------ */
/*					Virtual Program Button						*/
/* ------------------------------------------------------------ */
#define USE_VIRTUAL_PROGRAM_BUTTON      1
#define VIRTUAL_PROGRAM_BUTTON_TRIS     TRISCbits.TRISC12
#define VIRTUAL_PROGRAM_BUTTON          LATCbits.LATC12

/* ------------------------------------------------------------ */
/*						LED Declarations						*/
/* ------------------------------------------------------------ */

/* Define the pin numbers for the LEDs.
*/
#define	PIN_LED1	13
#define	PIN_LED2	48
#define	PIN_LED3	49
#define	PIN_LED4	50

/* ------------------------------------------------------------ */
/*					Button Declarations							*/
/* ------------------------------------------------------------ */

/* Define buttons on this board.
*/

/* ------------------------------------------------------------ */
/*					Switch Declarations							*/
/* ------------------------------------------------------------ */

/* No switches on this board.
*/

/* ------------------------------------------------------------ */
/*					Pots and Monitor Declarations   			*/
/* ------------------------------------------------------------ */

/* Define other components on the board
*/
#define	ADC1            14	
#define	ADC2            15	
#define	ADC1_OFFSET_FB  16	
#define	ADC2_OFFSET_FB  17	
#define	DC_PLUS_FB      18	
#define	DC_MINUS_FB     19	
#define	AWG_FB          20	
#define	USB5V0_FB       21	
#define	VCC3V3_FB       22	
#define	VREF3V0_FB      23	
#define	VREF1V5_FB      24	
#define	MINUS_VSS5V0_FB 25	

#define DC_PLUS_OUT     9
#define DC_PLUS_EN      42
#define DC_MINUS_OUT    11

#define AIN1_EN         40
#define AIN2_EN         41

/* ------------------------------------------------------------ */
/*					Servo Pin Declarations						*/
/* ------------------------------------------------------------ */

/* No servo connectors on this board.
*/

/* ------------------------------------------------------------ */
/*					Timer Pin Declarations						*/
/* ------------------------------------------------------------ */

#define PIN_OC1		3   
#define	PIN_OC2		5
#define	PIN_OC3		6
#define	PIN_OC4		9
#define	PIN_OC5		10
#define	PIN_OC6		11

#define PIN_IC1		2      
#define PIN_IC2		7      
#define PIN_IC3		8      
#define PIN_IC4		10

#define	PIN_TCK1	0
#define	PIN_TCK2	2      
#define	PIN_TCK3	3      
#define	PIN_TCK4	7      
#define	PIN_TCK5	9
#define	PIN_TCK6	11

/* ------------------------------------------------------------ */
/*					Interrupt Pin Declarations					*/
/* ------------------------------------------------------------ */

#define	PIN_INT0	2   
#define	PIN_INT1	3
#define PIN_INT2	7
#define	PIN_INT3	59   // used by MRF and is not on uno32 pin 35.
#define	PIN_INT4	8  

/* ------------------------------------------------------------ */
/*					SPI Pin Declarations						*/
/* ------------------------------------------------------------ */
/* These symbols are defined for compatibility with the original
** SPI library and the original pins_arduino.h
*/
static const uint8_t SS   = 10;		// SS2
static const uint8_t MOSI = 8;		// PIC32 SDO2
static const uint8_t MISO = 12;		// PIC32 SDI2
static const uint8_t SCK  = 6;		// PIC32 SCK2

/* The Digilent DSPI library uses these ports.
*/
#define	PIN_DSPI0_SS	10      // SS2;     Protocol port
#define	PIN_DSPI1_SS	56      // SS4;     Dedicated to the MRF 24
#define	PIN_DSPI2_SS	52      // SS6;     Dedicated to the SD
#define	PIN_DSPI3_SS	76      // SS4;     Dedicated to the SPI DAC   

/* ------------------------------------------------------------ */
/*					Analog Pins									*/
/* ------------------------------------------------------------ */
/* Define symbols for accessing the analog pins. This table is
** used to map an analog pin number to the corresponding digital
** pin number.
*/
#define	A0		14      // AN0
#define	A1		15      // AN2
#define A2		16      // AN24
#define A3		17      // AN29
#define A4		18      // AN6
#define A5		19      // AN7
#define A6		20      // AN8
#define A7		21      // AN37
#define A8		22      // AN23
#define A9		23      // AN35
#define A10		24      // AN36
#define A11		25      // AN19

/* ------------------------------------------------------------ */
/*					Change Notice Pins							*/
/* ------------------------------------------------------------ */
/* These define the pin numbers for the various change notice
** pins.
*/
#define	PIN_CN0		0
#define	PIN_CN1		1
#define	PIN_CN2		2      
#define	PIN_CN3		3      
#define	PIN_CN4		4
#define	PIN_CN5		5
#define	PIN_CN6		6
#define	PIN_CN7		7
#define	PIN_CN8		8
#define	PIN_CN9		9
#define	PIN_CN10	10
#define	PIN_CN11	11
#define	PIN_CN12	12
#define	PIN_CN13	13
#define	PIN_CN14	14      
#define	PIN_CN15	15
#define	PIN_CN16	16
#define	PIN_CN17	17      
#define	PIN_CN18	18      
#define	PIN_CN19	19
#define	PIN_CN20	20
#define	PIN_CN21	21
#define	PIN_CN22	22
#define	PIN_CN23	23      
#define	PIN_CN24	24
#define	PIN_CN25	25
#define	PIN_CN26	26      
#define	PIN_CN27	27      
#define	PIN_CN28	28      
#define	PIN_CN29	29      
#define	PIN_CN30	30
#define	PIN_CN31	31
#define	PIN_CN32	32
#define	PIN_CN33	33
#define	PIN_CN34	34      
#define	PIN_CN35	35
#define	PIN_CN36	36
#define	PIN_CN37	37      
#define	PIN_CN38	38      
#define	PIN_CN39	39
#define	PIN_CN40	40
#define	PIN_CN41	41
#define	PIN_CN42	42
#define	PIN_CN43	43
#define	PIN_CN44	44
#define	PIN_CN45	45
#define	PIN_CN46	46
#define	PIN_CN47	47
#define	PIN_CN48	48
#define	PIN_CN49	49
#define	PIN_CN50	50
#define	PIN_CN51	51
#define	PIN_CN52	52
#define	PIN_CN53	53
#define	PIN_CN54	54
#define	PIN_CN55	55
#define	PIN_CN56	56
#define	PIN_CN57	57
#define	PIN_CN58	58
#define	PIN_CN59	59
#define	PIN_CN60	60
#define	PIN_CN61	61
#define	PIN_CN62	62
#define	PIN_CN63	63
#define	PIN_CN64	64
#define	PIN_CN65	65
#define	PIN_CN66	66
#define	PIN_CN67	67
#define	PIN_CN68	68
#define	PIN_CN69	69
#define	PIN_CN70	70
#define	PIN_CN71	71
#define	PIN_CN72	72
#define	PIN_CN73	73
#define	PIN_CN74	74
#define	PIN_CN75	75
#define	PIN_CN76	76
#define	PIN_CN77	77
#define	PIN_CN78	78


/* ------------------------------------------------------------ */
/*					Pin Mapping Macros							*/
/* ------------------------------------------------------------ */
/* This section contains the definitions for pin mapping macros that
** are being redefined for this board variant.
*/

// NUM_ANALOG_PINS == 14, the first analog pin as represented as a digital pin is also 14
// if the analog pin is less than 14, then you can put in the analog number 
// if the pin is greater than 14, it must be a digital pin number.

#undef digitalPinToAnalog
//#define	digitalPinToAnalog(P) (digital_pin_to_analog_PGM[P])
#define digitalPinToAnalog(P) (((P) < NUM_ANALOG_PINS) ? (P) : (digital_pin_to_analog_PGM[P]))

#undef analogInPinToChannel
#define analogInPinToChannel(P) (analog_pin_to_channel_PGM[P])


/* ------------------------------------------------------------ */
/*					Data Declarations							*/
/* ------------------------------------------------------------ */

/* The following declare externals to access the pin mapping
** tables. These tables are defined in Board_Data.c.
*/

#if !defined(OPT_BOARD_DATA)

extern const uint32_t	port_to_tris_PGM[];
extern const uint8_t	digital_pin_to_port_PGM[];
extern const uint16_t	digital_pin_to_bit_mask_PGM[];
extern const uint16_t	digital_pin_to_timer_PGM[];

extern const uint8_t	output_compare_to_digital_pin_PGM[];
extern const uint8_t	external_int_to_digital_pin_PGM[];

extern const uint8_t	analog_pin_to_channel_PGM[];
extern const uint8_t 	digital_pin_to_analog_PGM[];

extern const uint8_t	digital_pin_to_pps_out_PGM[];
extern const uint8_t	digital_pin_to_pps_in_PGM[];

#endif

/* ------------------------------------------------------------ */
/*				Internal Declarations							*/
/* ------------------------------------------------------------ */
/* The following declarations are used to map peripherals for	*/
/* the core and libraries and to provide configuration options	*/
/* for the core. They are not normally needed by a user sketch.	*/
/* ------------------------------------------------------------ */

#if defined(OPT_BOARD_INTERNAL)

/* ------------------------------------------------------------ */
/*				Core Configuration Declarations					*/
/* ------------------------------------------------------------ */
/*																*/
/* These are conditional compilation switches that control the	*/
/* board core configuration functions. These functions provide	*/
/* hooks that can call from some of the core functions into		*/
/* functions defined below that can be used to extend or		*/
/* replace the default behavior of the core function. To use	*/
/* this, enter the appropriate code into the appropriate		*/
/* function skeleton below and then set the appropriate switch	*/
/* value to 1. This will cause the configuration function to be	*/
/* compiled into the build and will cause the code to call the	*/
/* hook function to be compiled into the core function.			*/
/*																*/
/* ------------------------------------------------------------ */

#define	OPT_BOARD_INIT			0	//board needs no special init code
#define	OPT_BOARD_DIGITAL_IO	0	//board does not extend digital i/o functions
#define	OPT_BOARD_ANALOG_READ	0	//board does not extend analogRead
#define	OPT_BOARD_ANALOG_WRITE	0	//board does not extend analogWrite

/* ------------------------------------------------------------ */
/*  JTAG Support, set to 1 if you want JTAG enabled             */
/*  otherwise JTAG will be disabled                             */
/* ------------------------------------------------------------ */
// OpenScope does not support JTAG
#define _JTAG 0

/* ------------------------------------------------------------ */

#endif	// OPT_BOARD_INTERNAL

/* ------------------------------------------------------------ */
/*					Serial Port Declarations					*/
/* ------------------------------------------------------------ */

/* Serial port 0 uses UART5
*/
#define	_SER0_BASE      _UART5_BASE_ADDRESS
#define	_SER0_IRQ       _UART5_FAULT_VECTOR
#define	_SER0_VECTOR    _UART5_FAULT_VECTOR
#define	_SER0_IPL_ISR   IPL2SRS
#define	_SER0_IPL       2
#define	_SER0_SPL       0
#define _SER0_TX_OUT    PPS_OUT_U5TX     
#define _SER0_TX_PIN    1                
#define _SER0_RX_IN     PPS_IN_U5RX      
#define _SER0_RX_PIN    0                

/* Serial port 1 uses UART1; this goes to pins 39&40
*/
#define	_SER1_BASE		_UART1_BASE_ADDRESS
#define	_SER1_IRQ		_UART1_FAULT_VECTOR
#define	_SER1_VECTOR	_UART1_FAULT_VECTOR
#define	_SER1_IPL_ISR	IPL2SRS
#define	_SER1_IPL		2
#define	_SER1_SPL		0
#define _SER1_TX_OUT    PPS_OUT_U1TX        
#define _SER1_TX_PIN    12                  
#define _SER1_RX_IN     PPS_IN_U1RX      
#define _SER1_RX_PIN    4                


/* ------------------------------------------------------------ */
/*					SPI Port Declarations						*/
/* ------------------------------------------------------------ */

/* The Digilent DSPI and standard SPI libraries uses these ports.
*/

// same as the default SPI port
#define	_DSPI0_BASE			_SPI2_BASE_ADDRESS
#define	_DSPI0_ERR_IRQ		_SPI2_FAULT_VECTOR
#define	_DSPI0_RX_IRQ		_SPI2_RX_VECTOR
#define	_DSPI0_TX_IRQ		_SPI2_TX_VECTOR
#define	_DSPI0_VECTOR		_SPI2_FAULT_VECTOR
#define _DSPI0_IPL_ISR		IPL3SRS
#define	_DSPI0_IPL			3
#define	_DSPI0_SPL			0

#define _DSPI0_MISO_IN		PPS_IN_SDI2
#define _DSPI0_MISO_PIN		MISO		    
#define _DSPI0_MOSI_OUT		PPS_OUT_SDO2
#define _DSPI0_MOSI_PIN		MOSI		    

// MRF24 SPI
#define	_DSPI1_BASE			_SPI4_BASE_ADDRESS
#define	_DSPI1_ERR_IRQ		_SPI4_FAULT_VECTOR
#define	_DSPI1_RX_IRQ		_SPI4_RX_VECTOR
#define	_DSPI1_TX_IRQ		_SPI4_TX_VECTOR
#define	_DSPI1_VECTOR		_SPI4_FAULT_VECTOR
#define _DSPI1_IPL_ISR		IPL3SRS
#define	_DSPI1_IPL			3
#define	_DSPI1_SPL			0

#define _DSPI1_MISO_IN		PPS_IN_SDI4
#define _DSPI1_MISO_PIN		57		        
#define _DSPI1_MOSI_OUT		PPS_OUT_SDO4
#define _DSPI1_MOSI_PIN		58		        

// SD Card
#define	_DSPI2_BASE			_SPI6_BASE_ADDRESS
#define	_DSPI2_ERR_IRQ		_SPI6_FAULT_VECTOR
#define	_DSPI2_RX_IRQ		_SPI6_RX_VECTOR
#define	_DSPI2_TX_IRQ		_SPI6_TX_VECTOR
#define	_DSPI2_VECTOR		_SPI6_FAULT_VECTOR
#define _DSPI2_IPL_ISR		IPL3SRS
#define	_DSPI2_IPL			3
#define	_DSPI2_SPL			0

#define _DSPI2_MISO_IN		PPS_IN_SDI6
#define _DSPI2_MISO_PIN		53		    
#define _DSPI2_MOSI_OUT		PPS_OUT_SDO6
#define _DSPI2_MOSI_PIN		54		    

// SPI DAC
#define	_DSPI3_BASE			_SPI3_BASE_ADDRESS
#define	_DSPI3_ERR_IRQ		_SPI3_FAULT_VECTOR
#define	_DSPI3_RX_IRQ		_SPI3_RX_VECTOR
#define	_DSPI3_TX_IRQ		_SPI3_TX_VECTOR
#define	_DSPI3_VECTOR		_SPI3_FAULT_VECTOR
#define _DSPI3_IPL_ISR		IPL3SRS
#define	_DSPI3_IPL			3
#define	_DSPI3_SPL			0

#define _DSPI3_MISO_IN		PPS_IN_SDI3
#define _DSPI3_MISO_PIN		77		    
#define _DSPI3_MOSI_OUT		PPS_OUT_SDO3
#define _DSPI3_MOSI_PIN		78		    


/* ------------------------------------------------------------ */
/*					I2C Port Declarations						*/
/* ------------------------------------------------------------ */

// TWI is implemented on DTWI0

/* Declarations for Digilent DTWI library.
**		DTWI0 is SDA5/SCL5 on pins 5/12
*/

#define	_DTWI0_BASE		_I2C5_BASE_ADDRESS
#define	_DTWI0_BUS_IRQ	_I2C5_BUS_VECTOR
#define	_DTWI0_VECTOR	_I2C5_BUS_VECTOR
#define	_DTWI0_IPL_ISR	IPL3SRS 
#define	_DTWI0_IPL		3
#define	_DTWI0_SPL		0
#define _DTWI0_SCL_PIN  12 
#define _DTWI0_SDA_PIN  5

/* ------------------------------------------------------------ */
/*  On MZ parts, ports are defined                              */
/* ------------------------------------------------------------ */

#define _PORTA
#define _PORTB
#define _PORTC
#define _PORTD
#define _PORTE
#define _PORTF
#define _PORTG
#define _PORTH
#define _PORTJ

/* ------------------------------------------------------------ */
/*					A/D Converter Declarations					*/
/* ------------------------------------------------------------ */
#define ADCRANGE        4096ul              // analog read will return a max number of ADCRANGE-1
#define ADCTADFREQ      50000000ul          // How fast to run the TAD ADC clock
#define ADCTADSH        68ul                // How many TADs the Sample and Hold will charge for must ADCs
#define ANINADCSH       2ul                 // How many TADs the Sample and Hold will charge the analog input ADCs (Didicated)
#define VREFMV          3000                // we are using a 3v reference voltage
#define __ALT_ADC_IMPL__
extern void initADC(void);
extern int convertADC(uint8_t channelNumber);

//**************************************************************************
//**************************************************************************
//******************* ADC Macros       *********************************
//**************************************************************************
//**************************************************************************

// ADC resolution
#define RES6BITS        0b00        // 6 bit resolution
#define RES8BITS        0b01        // 8 bit resolution
#define RES10BITS       0b10        // 10 bit resolution
#define RES12BITS       0b11        // 12 bit resolution

// ADC reference soruces
#define VREFPWR         0b000       // internal 3.3v ref
#define VREFHEXT        0b001       // external high ref 
#define VREFLEXT        0b010       // external low ref

// ADC clock sources
#define CLKSRCFRC       0b11        // Internal 8 MHz FRC clock source
#define CLKSRCREFCLK3   0b10        // External Clk 3 clock source
#define CLKSRCSYSCLK    0b01        // System clock source
#define CLKSRCPBCLK3    0b00        // PB Bus 3 as clock source

//#define F_CPU               (200000000ul)

// PB 3, ADC, OC, Timers 
#define PBUS3DIV    2               // divide system clock by (1-128); the default is 2 and that is what we are using
#define PB3FREQ     (F_CPU / PBUS3DIV)

// TQ CLOCK
#define TQCLKDIV    1                               // we want to run the TQ at F_CPU == 200MHz
// Global ADC TQ Clock prescaler 0 - 63; Divide by (CONCLKDIV*2) However, the value 0 means divide by 1
#define TQCONCLKDIV (TQCLKDIV >> 1)            
#define TQ          (F_CPU / TQCLKDIV)              // ADC TQ clock frequency

// TAD = TQ / (2 * ADCTADDIV), ADCTADDIV may not be zero
#define ADCTADDIV   ((TQ / ADCTADFREQ) / 2)
#if (ADCTADDIV == 0)
    #error ADCTADFREQ is too high or TQ is too low
#endif

#define CBITSRES    ((2ul * RES12BITS) + 6ul)
#define CTADCONV    (CBITSRES + 2ul)
#define CTADTOTAL   (CTADCONV + ANINADCSH)
#define SHCONVFREQ  (ADCTADFREQ / CTADTOTAL)        // how fast we can turn around and do the next sample, must be faster than sample rate

/* ------------------------------------------------------------ */

//**************************************************************************
//**************************************************************************
//******************* Defines for the WiFi Module  *************************
//**************************************************************************
//**************************************************************************

#define _MRF24_SPI_CONFIG_

#define WF_INT              3
#define WF_SPI              4
#define WF_SPI_FREQ         20000000
#define WF_IPL_ISR          IPL3SRS
#define WF_IPL              3
#define WF_SUB_IPL          0

#define WF_INT_TRIS         (TRISGbits.TRISG8)
#define WF_INT_IO           (PORTGbits.RG8)

#define WF_HIBERNATE_TRIS   (TRISDbits.TRISD13)
#define	WF_HIBERNATE_IO     (PORTDbits.RD13)

#define WF_RESET_TRIS       (TRISAbits.TRISA4)
#define WF_RESET_IO         (LATAbits.LATA4)

#define WF_CS_TRIS          (TRISBbits.TRISB15)
#define WF_CS_IO            (LATBbits.LATB15)

// for PPS devices
#define WF_INT_PPS()    INT3R   = 0b0001    // INT3     G8      INT3R = 0b0001
#define WF_HIB_PPS()    // RPD13R  = 0b0000    // HIB      D13     GPIO
#define WF_RESET_PPS()  // RPA4R   = 0b0000    // RESET    A4      GPIO
#define WF_CS_PPS()     RPB15R  = 0b0000    // CS       B15     GPIO
#define WF_SCK_PPS()    RPD10R  = 0b0000    // SCK4     RD10    GPIO
#define WF_SDI_PPS()    SDI4R   = 0b0001    // SDI4     RG7     SDI4R = 0b0001
#define WF_SDO_PPS()    RPA15R  = 0b1000    // SDO4     RA15    RPA15R = 0b1000


#define DefineSDSPI(spi) DSPI2 spi
#define DefineDSDVOL(vol, spi) DSDVOL vol(spi, 53)     // Create an DSDVOL object

#endif	// BOARD_DEFS_H

/************************************************************************/
