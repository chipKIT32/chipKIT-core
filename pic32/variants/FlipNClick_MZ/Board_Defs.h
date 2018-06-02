/************************************************************************/
/*																		*/
/*	Board_Defs.h --	Board Customization for MikroElektronika FlipNClick */
/*																		*/
/************************************************************************/
/*	Author: Larry Standage												*/
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
/*	07/08/2016(LarryS): Created											*/
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

#define	_BOARD_NAME_	"Mikroe FlipNClick MZ"
#define _USB

/* Define the Microcontroller peripherals available on the board.
*/
#define	NUM_DIGITAL_PINS	75
#define	NUM_ANALOG_PINS		10
#define NUM_OC_PINS			9
#define	NUM_IC_PINS			4
#define	NUM_TCK_PINS		4
#define	NUM_INT_PINS		5

#define	NUM_SERIAL_PORTS	5   
#define	NUM_SPI_PORTS		3   
#define	NUM_I2C_PORTS		3   

#define NUM_DSPI_PORTS		3
#define	NUM_DTWI_PORTS		3

/* Define I/O devices on the board.
*/
#define	NUM_LED				5
#define NUM_BTN				2
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
#define VIRTUAL_PROGRAM_BUTTON_TRIS     TRISBbits.TRISB4
#define VIRTUAL_PROGRAM_BUTTON          LATBbits.LATB4

/* ------------------------------------------------------------ */
/*						LED Declarations						*/
/* ------------------------------------------------------------ */

/* Define the pin numbers for the LEDs.
*/
#define	PIN_LED1	13
#define	PIN_LED2	22
#define LEDA		22
#define	PIN_LED3	23
#define LEDB		23
#define	PIN_LED4	24
#define LEDC		24
#define PIN_LED5    25
#define LEDD		25

/* ------------------------------------------------------------ */
/*					Button Declarations							*/
/* ------------------------------------------------------------ */

/* Define buttons on this board.
*/
#define	PIN_BTN1	46	
#define	PIN_BTN2	47

/* ------------------------------------------------------------ */
/*					Switch Declarations							*/
/* ------------------------------------------------------------ */

/* No switches on this board.
*/

/* ------------------------------------------------------------ */
/*					Pots and Monitor Declarations   			*/
/* ------------------------------------------------------------ */

/* No Pots or other monitors on this board.
*/

/* ------------------------------------------------------------ */
/*					Servo Pin Declarations						*/
/* ------------------------------------------------------------ */

/* No servo connectors on this board.
*/

/* ------------------------------------------------------------ */
/*					Timer Pin Declarations						*/
/* ------------------------------------------------------------ */

#define PIN_OC1		3
#define	PIN_OC2		8
#define	PIN_OC3		68
#define	PIN_OC4		56
#define	PIN_OC5		5
#define	PIN_OC6		32
#define PIN_OC7     44
#define PIN_OC8     6
#define PIN_OC9     9

#define PIN_IC1		2      
#define PIN_IC2		7      
#define PIN_IC3		8      
#define PIN_IC4		10

//#define	PIN_TCK1	not connected
#define	PIN_TCK2	34      
#define	PIN_TCK3	35      
#define	PIN_TCK4	36      
#define	PIN_TCK5	38

/* ------------------------------------------------------------ */
/*					Interrupt Pin Declarations					*/
/* ------------------------------------------------------------ */

#define	PIN_INT0	2   // Arduino header
#define	PIN_INT1	57  // Click C
#define PIN_INT2    69  // Click D
#define	PIN_INT3	45  // Click B
#define	PIN_INT4	33  // Click A

#define PIN_RD14	0
#define PIN_RD15	1
#define PIN_RD0		2
#define PIN_RF13	3
#define PIN_RF8		4
#define PIN_RF12	5
#define PIN_RB15	6
#define PIN_RC13	7
#define PIN_RF3		8
#define PIN_RF2		9
#define PIN_RB8		10
#define PIN_RB10	11
#define PIN_RB9		12
#define PIN_RB14	13
#define PIN_RB3		14
#define PIN_RB2		15
#define PIN_RB1		16
#define PIN_RB0		17
#define PIN_RB4		18
#define PIN_RG15	19
#define PIN_RA3		20
#define PIN_RA2		21

#define PIN_RA6		22
#define PIN_RA7		23
#define PIN_RE0		24
#define PIN_RE1		25

#define PIN_RB11	26
#define PIN_RE2		27
#define PIN_RA0		28
#define PIN_RG6		29
#define PIN_RC4		30
#define PIN_RB5		31
#define PIN_RC14	32
#define PIN_RD9		33
#define PIN_RG9		34
#define PIN_RE3		35
#define PIN_RE7		38
#define PIN_RG13	39
#define PIN_RE4		40
#define PIN_RG0		44
#define PIN_RG1		45
#define PIN_RF0		46
#define PIN_RF1		47
#define PIN_RA5		50
#define PIN_RG14	51
#define PIN_RD12	52
#define PIN_RD1		53
#define PIN_RD2		54
#define PIN_RD3		55
#define PIN_RG7		56
#define PIN_RD5		57
#define PIN_RC1		58
#define PIN_RE5		59
#define PIN_RA14	60
#define PIN_RA15	61
#define PIN_RE6		62
#define PIN_RG12	63
#define PIN_RD13	64
#define PIN_RG8		68
#define PIN_RD4		69
#define PIN_RC3		70
#define PIN_RC2		71
#define PIN_RD10	74
#define PIN_RD11	75

#define PIN_CA_AN       26
#define PIN_CA_RST      27
#define PIN_CA_CS       28
#define PIN_CA_SCK      29
#define PIN_CA_MISO     30
#define PIN_CA_MOSI     31
#define PIN_CA_PWM      32
#define PIN_CA_INT      33
#define PIN_CA_RX       34
#define PIN_CA_TX       35
#define PIN_CA_SCL      36
#define PIN_CA_SDA      37

#define PIN_CB_AN       38
#define PIN_CB_RST      39
#define PIN_CB_CS       40
#define PIN_CB_SCK      41
#define PIN_CB_MISO     42
#define PIN_CB_MOSI     43
#define PIN_CB_PWM      44
#define PIN_CB_INT      45
#define PIN_CB_RX       46
#define PIN_CB_TX       47
#define PIN_CB_SCL      48
#define PIN_CB_SDA      49

#define PIN_CC_AN       50
#define PIN_CC_RST      51
#define PIN_CC_CS       52
#define PIN_CC_SCK      53
#define PIN_CC_MISO     54
#define PIN_CC_MOSI     55
#define PIN_CC_PWM      56
#define PIN_CC_INT      57
#define PIN_CC_RX       58
#define PIN_CC_TX       59
#define PIN_CC_SCL      60
#define PIN_CC_SDA      61

#define PIN_CD_AN       62
#define PIN_CD_RST      63
#define PIN_CD_CS       64
#define PIN_CD_SCK      65
#define PIN_CD_MISO     66
#define PIN_CD_MOSI     67
#define PIN_CD_PWM      68
#define PIN_CD_INT      69
#define PIN_CD_RX       70
#define PIN_CD_TX       71
#define PIN_CD_SCL      72
#define PIN_CD_SDA      73

#define PIN_DSPI0_SS	10	/* Arduino side */
#define PIN_DSPI1_SS	28	/* Click A SS - Needs to be changed if using Click B */
#define PIN_DSPI2_SS	52	/* Click C SS - Needs to be changed if using Click D */

/* ------------------------------------------------------------ */
/*					SPI Pin Declarations						*/
/* ------------------------------------------------------------ */
/* These symbols are defined for compatibility with the original
** SPI library and the original pins_arduino.h
*/
static const uint8_t SS   = 10;		// for SPI master operation, shared with pin 10
static const uint8_t MOSI = 11;		// PIC32 SDO3
static const uint8_t MISO = 12;		// PIC32 SDI3
static const uint8_t SCK  = 13;		// PIC32 SCK3

/* Click SPI definitions 
*/
static const uint8_t SS_A   = 28;   // SPI2_SS1
static const uint8_t MOSI_A = 31;   // SPI2_MOSI
static const uint8_t MISO_A = 30;   // SPI2_MISO
static const uint8_t SCK_A  = 29;   // SPI2_SCK

static const uint8_t SS_B   = 40;   // SPI2_SS0
static const uint8_t MOSI_B = 43;   // SPI2_MOSI
static const uint8_t MISO_B = 42;   // SPI2_MISO
static const uint8_t SCK_B  = 41;   // SPI2_SCK

static const uint8_t SS_C   = 52;   // SPI1_SS0
static const uint8_t MOSI_C = 55;   // SPI1_MOSI
static const uint8_t MISO_C = 54;   // SPI1_MISO
static const uint8_t SCK_C  = 53;   // SPI1_SCK

static const uint8_t SS_D   = 64;   // SPI1_SS1
static const uint8_t MOSI_D = 67;   // SPI1_MOSI
static const uint8_t MISO_D = 66;   // SPI1_MISO
static const uint8_t SCK_D  = 65;   // SPI1_SCK

/* ------------------------------------------------------------ */
/*					Analog Pins									*/
/* ------------------------------------------------------------ */
/* Define symbols for accessing the analog pins. This table is
** used to map an analog pin number to the corresponding digital
** pin number.
*/
#define	A0		14      // AN3
#define	A1		15      // AN2
#define A2		16      // AN1
#define A3		17      // AN0
#define A4		18      // AN4
#define A5		19      // AN23
#define A6		26      // AN6
#define A7		38      // AN15
#define A8		50      // AN34
#define A9		62      // AN16

/* ------------------------------------------------------------ */
/*					Change Notice Pins							*/
/* ------------------------------------------------------------ */
/* These define the pin numbers for the various change notice
** pins.
** TODO: Update for FlipNClck
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
// FlipNClick does not have dedicated JTAG pins
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
#define _SER0_TX_OUT    PPS_OUT_U5TX     // (RPF8R = 0b0010)   RF8 -> U4TX   
#define _SER0_TX_PIN    1                // REBIRDY2/RPF8/SCL3/RF8   
#define _SER0_RX_IN     PPS_IN_U5RX      // (U4RXR = 0b1011)    RPF2 -> U4RX
#define _SER0_RX_PIN    0                // EBIRDY3/RPF2/SDA3/RF2 

/* Serial port 1 uses UART4; this goes to pins 34&35 (Click A)
*/
#define	_SER1_BASE		_UART4_BASE_ADDRESS
#define	_SER1_IRQ		_UART4_FAULT_VECTOR
#define	_SER1_VECTOR	_UART4_FAULT_VECTOR
#define	_SER1_IPL_ISR	IPL2SRS
#define	_SER1_IPL		2
#define	_SER1_SPL		0
#define _SER1_TX_OUT    PPS_OUT_U4TX     
#define _SER1_TX_PIN    35               
#define _SER1_RX_IN     PPS_IN_U4RX      
#define _SER1_RX_PIN    34               

/* Serial port 2 uses UART3; this goes to pins 46&47 (Click B)
*/
#define	_SER2_BASE		_UART3_BASE_ADDRESS
#define	_SER2_IRQ		_UART3_FAULT_VECTOR
#define	_SER2_VECTOR	_UART3_FAULT_VECTOR
#define	_SER2_IPL_ISR	IPL2SRS
#define	_SER2_IPL		2
#define	_SER2_SPL		0
#define _SER2_TX_OUT    PPS_OUT_U3TX     
#define _SER2_TX_PIN    47               
#define _SER2_RX_IN     PPS_IN_U3RX      
#define _SER2_RX_PIN    46               

/* Serial port 3 uses UART1; this goes to pins 55&56 (Click C)
*/
#define	_SER3_BASE		_UART1_BASE_ADDRESS
#define	_SER3_IRQ		_UART1_FAULT_VECTOR
#define	_SER3_VECTOR	_UART1_FAULT_VECTOR
#define	_SER3_IPL_ISR	IPL2SRS
#define	_SER3_IPL		2
#define	_SER3_SPL		0
#define _SER3_TX_OUT    PPS_OUT_U1TX     
#define _SER3_TX_PIN    59               
#define _SER3_RX_IN     PPS_IN_U1RX      
#define _SER3_RX_PIN    58               

/* Serial port 4 uses UART2; this goes to pins 64&65 (Click D)
*/
#define	_SER4_BASE		_UART2_BASE_ADDRESS
#define	_SER4_IRQ		_UART2_FAULT_VECTOR
#define	_SER4_VECTOR	_UART2_FAULT_VECTOR
#define	_SER4_IPL_ISR	IPL2SRS
#define	_SER4_IPL		2
#define	_SER4_SPL		0
#define _SER4_TX_OUT    PPS_OUT_U2TX     
#define _SER4_TX_PIN    71               
#define _SER4_RX_IN     PPS_IN_U2RX      
#define _SER4_RX_PIN    70               


/* ------------------------------------------------------------ */
/*					SPI Port Declarations						*/
/* ------------------------------------------------------------ */

/* The Digilent DSPI and standard SPI libraries uses these ports.
*/

// same as the default SPI port
#define	_DSPI0_BASE			_SPI3_BASE_ADDRESS
#define	_DSPI0_ERR_IRQ		_SPI3_FAULT_VECTOR
#define	_DSPI0_RX_IRQ		_SPI3_RX_VECTOR
#define	_DSPI0_TX_IRQ		_SPI3_TX_VECTOR
#define	_DSPI0_VECTOR		_SPI3_FAULT_VECTOR
#define _DSPI0_IPL_ISR		IPL3SRS
#define	_DSPI0_IPL			3
#define	_DSPI0_SPL			0

#define _DSPI0_MISO_IN		PPS_IN_SDI3
#define _DSPI0_MISO_PIN		MISO		    // RA1  SDI1    SDI1R = RPA1 = 0 
#define _DSPI0_MOSI_OUT		PPS_OUT_SDO3
#define _DSPI0_MOSI_PIN		MOSI		    // RA4  SDO1    RPA4R = SDO1 = 3


// 2nd SPI - For Click A and Click B
#define	_DSPI1_BASE			_SPI2_BASE_ADDRESS
#define	_DSPI1_ERR_IRQ		_SPI2_FAULT_VECTOR
#define	_DSPI1_RX_IRQ		_SPI2_RX_VECTOR
#define	_DSPI1_TX_IRQ		_SPI2_TX_VECTOR
#define	_DSPI1_VECTOR		_SPI2_FAULT_VECTOR
#define _DSPI1_IPL_ISR		IPL3SRS
#define	_DSPI1_IPL			3
#define	_DSPI1_SPL			0

#define _DSPI1_MISO_IN		PPS_IN_SDI2
#define _DSPI1_MISO_PIN		PIN_CA_MISO		        // RA1  SDI1    SDI1R = RPA1 = 0 
#define _DSPI1_MOSI_OUT		PPS_OUT_SDO2
#define _DSPI1_MOSI_PIN		PIN_CA_MOSI		        // RA4  SDO1    RPA4R = SDO1 = 3

// 3rd SPI - For Click C and Click D
#define	_DSPI2_BASE			_SPI1_BASE_ADDRESS
#define	_DSPI2_ERR_IRQ		_SPI1_FAULT_VECTOR
#define	_DSPI2_RX_IRQ		_SPI1_RX_VECTOR
#define	_DSPI2_TX_IRQ		_SPI1_TX_VECTOR
#define	_DSPI2_VECTOR		_SPI1_FAULT_VECTOR
#define _DSPI2_IPL_ISR		IPL3SRS
#define	_DSPI2_IPL			3
#define	_DSPI2_SPL			0

#define _DSPI2_MISO_IN		PPS_IN_SDI1
#define _DSPI2_MISO_PIN		PIN_CC_MISO		    // RA1  SDI1    SDI1R = RPA1 = 0 
#define _DSPI2_MOSI_OUT		PPS_OUT_SDO1
#define _DSPI2_MOSI_PIN		PIN_CC_MOSI		    // RA4  SDO1    RPA4R = SDO1 = 3


/* ------------------------------------------------------------ */
/*					I2C Port Declarations						*/
/* ------------------------------------------------------------ */

/* The standard I2C port uses I2C5 (SCL5/SDA5). These come to pins
** 20/21 on the Arduino connectors.
*/
#define	_TWI_BASE		_I2C5_BASE_ADDRESS
#define	_TWI_BUS_IRQ	_I2C5_BUS_VECTOR
#define	_TWI_SLV_IRQ	_I2C5_SLAVE_VECTOR
#define	_TWI_MST_IRQ	_I2C5_MASTER_VECTOR
#define	_TWI_VECTOR		_I2C5_BUS_VECTOR
#define _TWI_IPL_ISR	IPL3SRS
#define _TWI_IPL		3
#define	_TWI_SPL		0

/* Declarations for Digilent DTWI library.
**		DTWI0 is SDA5/SCL5 on pins 20/21 (see above comment).
*/

#define	_DTWI0_BASE		_I2C5_BASE_ADDRESS
#define	_DTWI0_BUS_IRQ	_I2C5_BUS_VECTOR
#define	_DTWI0_VECTOR	_I2C5_BUS_VECTOR
#define	_DTWI0_IPL_ISR	IPL3SRS 
#define	_DTWI0_IPL		3
#define	_DTWI0_SPL		0
#define _DTWI0_SCL_PIN  21 
#define _DTWI0_SDA_PIN  20

#define	_DTWI1_BASE		_I2C2_BASE_ADDRESS
#define	_DTWI1_BUS_IRQ	_I2C2_BUS_VECTOR
#define	_DTWI1_VECTOR	_I2C2_BUS_VECTOR
#define	_DTWI1_IPL_ISR	IPL3SRS 
#define	_DTWI1_IPL		3
#define	_DTWI1_SPL		0
#define _DTWI1_SCL_PIN  36
#define _DTWI1_SDA_PIN  37

#define	_DTWI2_BASE		_I2C1_BASE_ADDRESS
#define	_DTWI2_BUS_IRQ	_I2C1_BUS_VECTOR
#define	_DTWI2_VECTOR	_I2C1_BUS_VECTOR
#define	_DTWI2_IPL_ISR	IPL3SRS 
#define	_DTWI2_IPL		3
#define	_DTWI2_SPL		0
#define _DTWI2_SCL_PIN  60
#define _DTWI2_SDA_PIN  61

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
/* ------------------------------------------------------------ */
/*					A/D Converter Declarations					*/
/* ------------------------------------------------------------ */
#define ADCRANGE        4096ul              // analog read will return a max number of ADCRANGE-1
#define ADCTADFREQ      25000000ul          // How fast to run the TAD ADC clock
#define ADCTADSH        68ul                // How many TADs the Sample and Hold will charge
#define __ALT_ADC_IMPL__
extern void initADC(void);
extern int convertADC(uint8_t channelNumber);

/* ------------------------------------------------------------ */

#endif	// BOARD_DEFS_H

/************************************************************************/
