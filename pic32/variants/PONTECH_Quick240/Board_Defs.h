/************************************************************************/
/*																		*/
/*	Board_Defs.h --	Board Customization for Digilent chipKIT Max32		*/
/*																		*/
/************************************************************************/
/*	Author: Gene Apperson												*/
/*	Copyright 2011, Digilent. All rights reserved						*/
/************************************************************************/
/*  File Description:													*/
/*																		*/
/* This file contains the board specific declartions and data structure	*/
/* to customize the chipKIT MPIDE for use with the Digilent chipKIT		*/
/* Max32 board.															*/
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
/*	03/31/2012(GeneA): added support for second LED on Rev D boards		*/
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

/* ------------------------------------------------------------ */
/*				Public Board Declarations						*/
/* ------------------------------------------------------------ */
/* The following define symbols that can be used in a sketch to
** refer to periperhals on the board generically.
*/

#define	_BOARD_NAME_	"chipKIT Max32"

#define VIRTUAL_PROGRAM_BUTTON_TRIS TRISGbits.TRISG15
#define VIRTUAL_PROGRAM_BUTTON LATGbits.LATG15
#define USE_VIRTUAL_PROGRAM_BUTTON 1

/* Define the Microcontroller peripherals available on the board.
*/
#define	NUM_DIGITAL_PINS	87
#define	NUM_ANALOG_PINS		16
#define	NUM_OC_PINS			5
#define	NUM_IC_PINS			5
#define	NUM_TCK_PINS		4
#define	NUM_INT_PINS		5

#define	NUM_SERIAL_PORTS	4
#define	NUM_SPI_PORTS		1
#define	NUM_I2C_PORTS		1

#define	NUM_DSPI_PORTS		4
#define NUM_DTWI_PORTS		5

/* Define I/O devices on the board.
*/
#define	NUM_LED				2
#define NUM_BTN				0
#define	NUM_SWT				0
#define NUM_SERVO			0

/* Define the number of extended i/o pins. These are pins
** that are not native to the microcontroller. This board
** doesn't have any.
*/
#define	NUM_DIGITAL_PINS_EXTENDED	NUM_DIGITAL_PINS
#define	NUM_ANALOG_PINS_EXTENDED	NUM_ANALOG_PINS

#define C0ADR 32
#define C1ADR 31
#define C2ADR 30
#define C3ADR 52
#define C4ADR 29
#define C5ADR 85

#define C0IO0 68
#define C0IO1 58
#define C0IO2 62
#define C0IO3 55
#define C0IO4 82

#define C1IO0 57
#define C1IO1 56
#define C1IO2 63
#define C1IO3 54
#define C1IO4 83

#define C2IO0 86
#define C2IO1 64
#define C2IO2 5
#define C2IO3 70
#define C2IO4 84

#define C3IO0 22
#define C3IO1 76
#define C3IO2 9
#define C3IO3 2
#define C3IO4 35

#define C4IO0 23
#define C4IO1 39
#define C4IO2 8
#define C4IO3 21
#define C4IO4 34

#define C5IO0 78
#define C5IO1 79
#define C5IO2 10
#define C5IO3 20
#define C5IO4 33

/* ------------------------------------------------------------ */
/*						LED Declarations						*/
/* ------------------------------------------------------------ */

/* Define the pin numbers for the LEDs
*/
#define	PIN_LED1	37
#define	PIN_LED2	81

/* ------------------------------------------------------------ */
/*					Button Declarations							*/
/* ------------------------------------------------------------ */

/* No buttons on this board.
*/

/* ------------------------------------------------------------ */
/*					Switch Declarations							*/
/* ------------------------------------------------------------ */

/* No switches on this board.
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
#define	PIN_OC2		5
#define	PIN_OC3		6
#define	PIN_OC4		9
#define	PIN_OC5		10

#define PIN_IC1		48
#define PIN_IC2		74
#define PIN_IC3		38
#define PIN_IC4		49
#define	PIN_IC5		8

#define	PIN_TCK1	4
//#define	PIN_TCK2	not connected
#define	PIN_TCK3	22
#define	PIN_TCK4	23
#define	PIN_TCK5	11

/* ------------------------------------------------------------ */
/*					Interrupt Pin Declarations					*/
/* ------------------------------------------------------------ */

#define	PIN_INT0	3
#define	PIN_INT1	2
#define PIN_INT2	7
#define	PIN_INT3	21
#define	PIN_INT4	20

/* ------------------------------------------------------------ */
/*					SPI Pin Declarations						*/
/* ------------------------------------------------------------ */
/* These symbols are defined for compatibility with the original
** SPI library and the original pins_arduino.h
*/
static const uint8_t SS   = 53;		// PIC32 SS2A
static const uint8_t MOSI = 3;		// PIC32 SDO2A
static const uint8_t MISO = 11;		// PIC32 SDI2A
static const uint8_t SCK  = 38;		// PIC32 SCK2A

/* The Digilent DSPI library uses these ports.
*/
#define	PIN_DSPI0_SS	53
#define	PIN_DSPI1_SS	3
#define	PIN_DSPI2_SS	11
#define	PIN_DSPI3_SS	38

/* ------------------------------------------------------------ */
/*					Analog Pins									*/
/* ------------------------------------------------------------ */
/* Define symbols for accessing the analog pins. This table is
** used to map an analog pin number to the corresponding digital
** pin number.
*/
#define	A0		54
#define	A1		55
#define	A2		56
#define	A3		57
#define	A4		58
#define	A5		59
#define	A6		60
#define	A7		61
#define	A8		62
#define	A9		63
#define	A10		64
#define	A11		65
#define	A12		66
#define	A13		67
#define	A14		68
#define	A15		69

/* ------------------------------------------------------------ */
/*					Change Notice Pins							*/
/* ------------------------------------------------------------ */
/* These define the pin numbers for the various change notice
** pins.
*/
#define	PIN_CN0		4
#define	PIN_CN1		75
#define	PIN_CN2		54
#define	PIN_CN3		55
#define	PIN_CN4		56
#define	PIN_CN5		57
#define	PIN_CN6		58
#define	PIN_CN7		59
#define	PIN_CN8		52
#define	PIN_CN9		29
#define	PIN_CN10	43
#define	PIN_CN11	53
#define	PIN_CN12	69
#define	PIN_CN13	10
#define	PIN_CN14	39
#define	PIN_CN15	47
#define	PIN_CN16	77
#define	PIN_CN17	17
#define	PIN_CN18	16
#define	PIN_CN19	76
#define	PIN_CN20	19
#define	PIN_CN21	18

/* ------------------------------------------------------------ */
/*					Pin Mapping Macros							*/
/* ------------------------------------------------------------ */
/* Macros used to access the port and pin mapping tables.
** These are mostly generic, but some of them may be board specific.
** These perform slightly better as macros compared to inline functions
*/
#define digitalPinToPort(P) ( digital_pin_to_port_PGM[P]  )
#define digitalPinToBitMask(P) ( digital_pin_to_bit_mask_PGM[P]  )
#define digitalPinToTimerOC(P) ( (digital_pin_to_timer_PGM[P] & _MSK_TIMER_OC)  )
#define digitalPinToTimerIC(P) ( (digital_pin_to_timer_PGM[P] & _MSK_TIMER_IC)  )
#define digitalPinToTimerTCK(P) ( (digital_pin_to_timer_PGM[P] & _MSK_TIMER_TCK)  )
#define	digitalPinToTimer(P)	digitalPinToTimerOC(P)
#define portRegisters(P) ( port_to_tris_PGM[P])
#define portModeRegister(P) ( (volatile uint32_t *)port_to_tris_PGM[P] )
#define portInputRegister(P) ( (volatile uint32_t *)(port_to_tris_PGM[P] + 0x0010) )
#define portOutputRegister(P) ( (volatile uint32_t *)(port_to_tris_PGM[P] + 0x0020) )
#define	digitalPinToAnalog(P) ( (P) < 16 ? (P) : ((P) >= 54) && ((P) < 70) ? (P)-54 : NOT_ANALOG_PIN )
#define analogInPinToChannel(P) ( P  )

/* ------------------------------------------------------------ */
/*					Data Definitions							*/
/* ------------------------------------------------------------ */

/* The following declare externals to access the pin mapping
** tables. These tables are defined in Board_Data.c.
*/

#if !defined(OPT_BOARD_DATA)

extern const uint32_t	port_to_tris_PGM[];
extern const uint8_t	digital_pin_to_port_PGM[];
extern const uint16_t	digital_pin_to_bit_mask_PGM[];
extern const uint16_t	digital_pin_to_timer_PGM[];

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
/* This board requires some additional initialization, so it	*/
/* sets OPT_BOARD_INIT to 1 to cause the extra init function	*/
/* to be included.												*/
/*																*/
/* ------------------------------------------------------------ */

#define	OPT_BOARD_INIT			1	//board needs custom init code
#define	OPT_BOARD_DIGITAL_IO	0	//board does not extend digital i/o functions
#define	OPT_BOARD_ANALOG_READ	0	//board does not extend analogRead
#define	OPT_BOARD_ANALOG_WRITE	0	//board does not extend analogWrite

#endif	//OPT_BOARD_INTERNAL

/* ------------------------------------------------------------ */
/*					Serial Port Declarations					*/
/* ------------------------------------------------------------ */

/* Serial port 0 uses UART1 (aka UART1A)
*/
#define	_SER0_BASE		_UART1_BASE_ADDRESS
#define	_SER0_IRQ		_UART1_ERR_IRQ
#define	_SER0_VECTOR	_UART_1_VECTOR
#define _SER0_IPL_ISR	IPL2SOFT
#define	_SER0_IPL		2
#define	_SER0_SPL		0

/* Serial port 1 uses UART4 (aka UART1B)
*/
#define	_SER1_BASE		_UART4_BASE_ADDRESS
#define	_SER1_IRQ		_UART4_ERR_IRQ
#define	_SER1_VECTOR	_UART_4_VECTOR
#define _SER1_IPL_ISR	IPL2SOFT
#define	_SER1_IPL		2
#define	_SER1_SPL		0

/* Serial port 2 uses UART2 (aka UART3A)
*/
#define	_SER2_BASE		_UART2_BASE_ADDRESS
#define	_SER2_IRQ		_UART2_ERR_IRQ
#define	_SER2_VECTOR	_UART_2_VECTOR
#define _SER2_IPL_ISR	IPL2SOFT
#define	_SER2_IPL		2
#define	_SER2_SPL		0

/* Serial port 3 uses UART5 (aka UART3B)
*/
#define	_SER3_BASE		_UART5_BASE_ADDRESS
#define	_SER3_IRQ		_UART5_ERR_IRQ
#define	_SER3_VECTOR	_UART_5_VECTOR
#define _SER3_IPL_ISR	IPL2SOFT
#define	_SER3_IPL		2
#define	_SER3_SPL		0

/* ------------------------------------------------------------ */
/*					SPI Port Declarations						*/
/* ------------------------------------------------------------ */

/* The SPI libraries uses these ports.
*/
#define	_DSPI0_BASE			_SPI1_BASE_ADDRESS
#define	_DSPI0_ERR_IRQ		_SPI1_ERR_IRQ
#define	_DSPI0_RX_IRQ		_SPI1_RX_IRQ
#define	_DSPI0_TX_IRQ		_SPI1_TX_IRQ
#define	_DSPI0_VECTOR		_SPI_1_VECTOR
#define	_DSPI0_IPL_ISR		IPL3SOFT
#define	_DSPI0_IPL			3
#define	_DSPI0_SPL			0

#define	_DSPI1_BASE			_SPI2_BASE_ADDRESS
#define	_DSPI1_ERR_IRQ		_SPI2_ERR_IRQ
#define	_DSPI1_RX_IRQ		_SPI2_RX_IRQ
#define	_DSPI1_TX_IRQ		_SPI2_TX_IRQ
#define	_DSPI1_VECTOR		_SPI_2_VECTOR
#define	_DSPI1_IPL_ISR		IPL3SOFT
#define	_DSPI1_IPL			3
#define	_DSPI1_SPL			0

#define	_SPI3_ERR_IRQ	_SPI1A_ERR_IRQ	//this declaration missing from the
										//Microchip header file
#define	_DSPI2_BASE			_SPI3_BASE_ADDRESS
#define	_DSPI2_ERR_IRQ		_SPI3_ERR_IRQ
#define	_DSPI2_RX_IRQ		_SPI3_RX_IRQ
#define	_DSPI2_TX_IRQ		_SPI3_TX_IRQ
#define	_DSPI2_VECTOR		_SPI_3_VECTOR
#define	_DSPI2_IPL_ISR		IPL3SOFT
#define	_DSPI2_IPL			3
#define	_DSPI2_SPL			0

#define	_DSPI3_BASE			_SPI4_BASE_ADDRESS
#define	_DSPI3_ERR_IRQ		_SPI4_ERR_IRQ
#define	_DSPI3_RX_IRQ		_SPI4_RX_IRQ
#define	_DSPI3_TX_IRQ		_SPI4_TX_IRQ
#define	_DSPI3_VECTOR		_SPI_4_VECTOR
#define	_DSPI3_IPL_ISR		IPL3SOFT
#define	_DSPI3_IPL			3
#define	_DSPI3_SPL			0

/* ------------------------------------------------------------ */
/*					I2C Port Declarations						*/
/* ------------------------------------------------------------ */

/* The standard I2C port uses I2C2 (SCL2/SDA2) on connector J8.
** 
*/
#define	_TWI_BASE		_I2C2_BASE_ADDRESS
#define	_TWI_BUS_IRQ	_I2C2_BUS_IRQ
#define	_TWI_SLV_IRQ	_I2C2_SLAVE_IRQ
#define	_TWI_MST_IRQ	_I2C2_MASTER_IRQ
#define	_TWI_VECTOR		_I2C_2_VECTOR
#define	_TWI_IPL_ISR	IPL3SOFT
#define _TWI_IPL		3
#define	_TWI_SPL		0

/* Declarations for Digilent DTWI library.
**		DTWI0:	SDA pin 20, SCL pin 21
**		DTWI1:	SDA pin 13, SCL pin 12
**		DTWI2:	SDA pin 0,  SCL pin 1
**		DTWI3:	SDA pin 29, SCL pin 43
**		DTWI4:	SDA pin 17, SCL pin 16
*/
#define	_DTWI0_BASE		_I2C1_BASE_ADDRESS
#define	_DTWI0_BUS_IRQ	_I2C1_BUS_IRQ
#define	_DTWI0_VECTOR	_I2C_1_VECTOR
#define	_DTWI0_IPL_ISR	IPL3SOFT
#define	_DTWI0_IPL		3
#define	_DTWI0_SPL		0
#define _DTWI0_SCL_PIN  21 
#define _DTWI0_SDA_PIN  20

#define	_DTWI1_BASE		_I2C2_BASE_ADDRESS
#define	_DTWI1_BUS_IRQ	_I2C2_BUS_IRQ
#define	_DTWI1_VECTOR	_I2C_2_VECTOR
#define	_DTWI1_IPL_ISR	IPL3SOFT
#define	_DTWI1_IPL		3
#define	_DTWI1_SPL		0
#define _DTWI1_SCL_PIN  12 
#define _DTWI1_SDA_PIN  13

#define	_DTWI2_BASE		_I2C3_BASE_ADDRESS
#define	_DTWI2_BUS_IRQ	_I2C3_BUS_IRQ
#define	_DTWI2_VECTOR	_I2C_3_VECTOR
#define	_DTWI2_IPL_ISR	IPL3SOFT
#define	_DTWI2_IPL		3
#define	_DTWI2_SPL		0
#define _DTWI2_SCL_PIN  1 
#define _DTWI2_SDA_PIN  0

#define	_DTWI3_BASE		_I2C4_BASE_ADDRESS
#define	_DTWI3_BUS_IRQ	_I2C4_BUS_IRQ
#define	_DTWI3_VECTOR	_I2C_4_VECTOR
#define	_DTWI3_IPL_ISR	IPL3SOFT
#define	_DTWI3_IPL		3
#define	_DTWI3_SPL		0
#define _DTWI3_SCL_PIN  43 
#define _DTWI3_SDA_PIN  29

#define	_DTWI4_BASE		_I2C5_BASE_ADDRESS
#define	_DTWI4_BUS_IRQ	_I2C5_BUS_IRQ
#define	_DTWI4_VECTOR	_I2C_5_VECTOR
#define	_DTWI4_IPL_ISR	IPL3SOFT
#define	_DTWI4_IPL		3
#define	_DTWI4_SPL		0
#define _DTWI4_SCL_PIN  16 
#define _DTWI4_SDA_PIN  17

/* ------------------------------------------------------------ */
/*					A/D Converter Declarations					*/
/* ------------------------------------------------------------ */


/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/*					Defines for Network                  */
/* ------------------------------------------------------------ */
#define _IM8720PHY_PIN_CONFIG_

#define PHY_TRIS            (TRISEbits.TRISE9)        // = 0; output
#define PHY_ENABLE          (LATEbits.LATE9)          // = 1; to enable
#define PHY_ADDRESS         0x5                     // something other than 0 or 1 (although 1 is okay)

/* ------------------------------------------------------------ */

#endif	// BOARD_DEFS_H

/************************************************************************/
