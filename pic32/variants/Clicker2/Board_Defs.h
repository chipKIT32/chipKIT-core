/*
 * Copyright (c) 2015, Majenko Technologies
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * 
 * * Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 * 
 * * Neither the name of Majenko Technologies nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#if !defined(BOARD_DEFS_H)
#define BOARD_DEFS_H

#include <inttypes.h>

/* ------------------------------------------------------------ */
/*				Public Board Declarations						*/
/* ------------------------------------------------------------ */
/* The following define symbols that can be used in a sketch to
** refer to peripherals on the board generically.
*/

#define	_BOARD_NAME_	"PIC32MX Clicker"

/* Define the peripherals available on the board.
*/
#define	NUM_DIGITAL_PINS	92
#define	NUM_ANALOG_PINS		16
#define NUM_OC_PINS			5
#define	NUM_IC_PINS			0
#define	NUM_TCK_PINS		0
#define	NUM_INT_PINS		5

#define	NUM_SERIAL_PORTS	2
#define	NUM_SPI_PORTS		1
#define	NUM_I2C_PORTS		0

#define NUM_DSPI_PORTS		2
#define NUM_DTWI_PORTS		2

/* Define I/O devices on the board.
*/
#define	NUM_LED				2
#define NUM_BTN				2
#define	NUM_SWT				0
#define NUM_SERVO			0

/* ------------------------------------------------------------ */
/*						LED Declarations						*/
/* ------------------------------------------------------------ */

/* Define the pin numbers for the LEDs
*/
#define	PIN_LED1	85
#define	PIN_LED2	86

/* ------------------------------------------------------------ */
/*					Button Declarations							*/
/* ------------------------------------------------------------ */

/* One button (PRG) for this board
*/
#define	PIN_BTN1	87
#define	PIN_BTN2	88
/* Also define the virtual program button for soft reset */
#define USE_VIRTUAL_PROGRAM_BUTTON      1
#define VIRTUAL_PROGRAM_BUTTON_TRIS     TRISBbits.TRISB4
#define VIRTUAL_PROGRAM_BUTTON          LATBbits.LATB4

/* ------------------------------------------------------------ */
/*					IO Pin Declarations							*/
/* ------------------------------------------------------------ */


/* ------------------------------------------------------------ */
/*					Timer Pin Declarations						*/
/* ------------------------------------------------------------ */

#define PIN_OC1		6
#define	PIN_OC2		23
#define	PIN_OC3		12
#define	PIN_OC4		13
#define	PIN_OC5		22

/* ------------------------------------------------------------ */
/*					Interrupt Pin Declarations					*/
/* ------------------------------------------------------------ */

#define	PIN_INT0	34
#define	PIN_INT1	62
#define	PIN_INT2	78
#define	PIN_INT3	10
#define	PIN_INT4	11


#define PIN_SENSEL 89
#define PIN_VSENSE 90
#define PIN_STAT   91

#define PIN_RB15        3
#define PIN_RB14        4
#define PIN_RB13        5
#define PIN_RB11        6
#define PIN_RB10        7
#define PIN_RB9         8
#define PIN_RB8         9
#define PIN_RA14        10
#define PIN_RA15        11
#define PIN_RE9         12
#define PIN_RE8         13
#define PIN_RF12        14
#define PIN_RD9         15
#define PIN_RD8         16
#define PIN_RA4         17
#define PIN_RA9         18
#define PIN_RF3         19
#define PIN_RA0         20
#define PIN_RE6         21
#define PIN_RG6         22
#define PIN_RG7         23
#define PIN_RG8         24

#define PIN_RD1         31
#define PIN_RD2         32
#define PIN_RD3         33
#define PIN_RD0         34
#define PIN_RD12        35
#define PIN_RD13        36
#define PIN_RD5         37
#define PIN_RD6         38
#define PIN_RD7         39
#define PIN_RF0         40
#define PIN_RF1         41
#define PIN_RG0         42
#define PIN_RA6         43
#define PIN_RA7         44
#define PIN_RE0         45
#define PIN_RG14        46
#define PIN_RF4         47
#define PIN_RF5         48
#define PIN_RA2         49
#define PIN_RA3         50

#define PIN_C1_AN       53
#define PIN_C1_RST      54
#define PIN_C1_CS       55
#define PIN_C1_SCK      56
#define PIN_C1_MISO     57
#define PIN_C1_MOSI     58
#define PIN_C1_PWM      61
#define PIN_C1_INT      62
#define PIN_C1_RX       63
#define PIN_C1_TX       64
#define PIN_C1_SCL      65
#define PIN_C1_SDA      66

#define PIN_C2_AN       69
#define PIN_C2_RST      70
#define PIN_C2_CS       71
#define PIN_C2_SCK      72
#define PIN_C2_MISO     73
#define PIN_C2_MOSI     74
#define PIN_C2_PWM      77
#define PIN_C2_INT      78
#define PIN_C2_RX       79
#define PIN_C2_TX       80
#define PIN_C2_SCL      81
#define PIN_C2_SDA      82


/* ------------------------------------------------------------ */
/*					SPI Pin Declarations						*/
/* ------------------------------------------------------------ */
/* These symbols are defined for compatibility with the original
** SPI library and the original pins_arduino.h. SPI2 is used for
** the default SPI port as it's pin numbers stay constant on all
** devices.
*/
static const uint8_t SS   = 71;
static const uint8_t MOSI = 74;
static const uint8_t MISO = 73;	
static const uint8_t SCK  = 72;

/* The Digilent DSPI library uses these ports.
*/
#define	PIN_DSPI0_SS	71
#define	PIN_DSPI1_SS    11	

/* ------------------------------------------------------------ */
/*					Analog Pins									*/
/* ------------------------------------------------------------ */
/* Define symbols for accessing the analog pins. This table is
** used to map an analog pin number to the corresponding digital
** pin number.
*/
#define	A0		0
#define A1      1
#define A2      2
#define A3      3
#define A4      4
#define A5      5
#define A6      6
#define A7      7
#define A8      8
#define A9      9
#define A10     10
#define A11     11
#define A12     12
#define A13     13
#define A14     14
#define A15     15

/* ------------------------------------------------------------ */
/*					Change Notice Pins							*/
/* ------------------------------------------------------------ */
/* These define the pin numbers for the various change notice
** pins.
*/
//#define	PIN_CN0		6       // RC14
//#define	PIN_CN1		5       // RC13
#define	PIN_CN2		25      // RB0
//#define	PIN_CN3		33      // RB1
//#define	PIN_CN4		32      // RB2
#define	PIN_CN5		0       // RB3
#define	PIN_CN6		24      // RB4
//#define	PIN_CN7		29      // RB5
#define	PIN_CN8		3       // RG6
#define	PIN_CN9		4       // RG7
#define	PIN_CN10	5       // RG8
#define	PIN_CN11	2       // RG9
//#define	PIN_CN12	44      // RB15
#define	PIN_CN13	22      // RD4
//#define	PIN_CN14	11      // RD5
//#define	PIN_CN15	12      // RD6
#define	PIN_CN16	1       // RD7
#define	PIN_CN17	11      // RF4
#define	PIN_CN18	10      // RF5

/* ------------------------------------------------------------ */
/*					Pin Mapping Macros							*/
/* ------------------------------------------------------------ */
/* Macros used to access the port and pin mapping tables.
** These are mostly generic, but some of them may be board specific.
** These perform slightly better as macros compared to inline functions
*/
#define digitalPinToPort(P) ( digital_pin_to_port_PGM[P]  )
#define digitalPinToBitMask(P) ( digital_pin_to_bit_mask_PGM[P]  )
#define digitalPinToTimerOC(P)  ( (digital_pin_to_timer_PGM[P] & _MSK_TIMER_OC)  )
#define digitalPinToTimerIC(P)  ( (digital_pin_to_timer_PGM[P] & _MSK_TIMER_IC)  )
#define digitalPinToTimerTCK(P) ( (digital_pin_to_timer_PGM[P] & _MSK_TIMER_TCK) )
#define	digitalPinToTimer(P)	digitalPinToTimerOC(P)
#define portRegisters(P) ( port_to_tris_PGM[P] )
#define portModeRegister(P) ( (volatile uint32_t *)port_to_tris_PGM[P] )
#define portInputRegister(P) ( (volatile uint32_t *)(port_to_tris_PGM[P] + 0x0010) )
#define portOutputRegister(P) ( (volatile uint32_t *)(port_to_tris_PGM[P] + 0x0020) )

// This definition can be used for the default mapping.
//#define	digitalPinToAnalog(P) ( (((P) > 15) && ((P) < 32)) ? (P)-16 : NOT_ANALOG_PIN )
// This definition can be used for the non-default case where there
// is a mapping table to go from digital pin to analog pin
#define	digitalPinToAnalog(P) digital_pin_to_analog_PGM[P]

// This definition can be used for the default one-to-one mapping
#define analogInPinToChannel(P) ( P )
// This definition is used when there isn't a one-to-one mapping
// This uses a table to do the mapping.
//#define analogInPinToChannel(P) ( analog_pin_to_channel_PGM[P]  )

/* ------------------------------------------------------------ */
/*					Data Definitions							*/
/* ------------------------------------------------------------ */

/* The following declare externals to access the pin mapping
** tables.
*/

#if !defined(OPT_BOARD_DATA)

extern const uint32_t	port_to_tris_PGM[];
extern const uint8_t	digital_pin_to_port_PGM[];
extern const uint16_t	digital_pin_to_bit_mask_PGM[];
extern const uint16_t	digital_pin_to_timer_PGM[];

//#if defined(_NOT_USED_)
extern const uint8_t 	digital_pin_to_analog_PGM[];
//#endif

//#if defined(_NOT_USED_)
extern const uint8_t	analog_pin_to_channel_PGM[];
//#endif

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

#define	OPT_BOARD_INIT			1	//board needs special init code
#define	OPT_BOARD_DIGITAL_IO	0	//board does not extend digital i/o functions
#define	OPT_BOARD_ANALOG_READ	0	//board does not extend analogRead
#define	OPT_BOARD_ANALOG_WRITE	0	//board does not extend analogWrite

/* ------------------------------------------------------------ */
/*					Serial Port Declarations					*/
/* ------------------------------------------------------------ */

/* Serial port 0 uses UART1
*/
#define	_SER0_BASE		_UART1_BASE_ADDRESS
#define	_SER0_IRQ		_UART1_ERR_IRQ
#define	_SER0_VECTOR	_UART_1_VECTOR
#define	_SER0_IPL_ISR	IPL2SOFT
#define	_SER0_IPL		2
#define	_SER0_SPL		0

#define	_SER1_BASE		_UART2_BASE_ADDRESS
#define	_SER1_IRQ		_UART2_ERR_IRQ
#define	_SER1_VECTOR	_UART_2_VECTOR
#define	_SER1_IPL_ISR	IPL2SOFT
#define	_SER1_IPL		2
#define	_SER1_SPL		0
//UART1 TX = PIC pin 51, RD3, Arduino pin 9
//UART1 RX = PIC pin 50, RD2, Arduino pin 8

/* ------------------------------------------------------------ */
/*					SPI Port Declarations						*/
/* ------------------------------------------------------------ */

/* The default SPI port uses SPI2. The pins for SPI2 stay the
** same on all PIC32 devices. The pins for SPI1 move around,
** and the ports beyond SPI2 aren't defined on some parts.
*/
#define	_SPI_BASE		_SPI2_BASE_ADDRESS
#define _SPI_ERR_IRQ	_SPI2_ERR_IRQ
#define	_SPI_RX_IRQ		_SPI2_RX_IRQ
#define	_SPI_TX_IRQ		_SPI2_TX_IRQ
#define	_SPI_VECTOR		_SPI_2_VECTOR
#define	_SPI_IPL_ISR	IPL3SOFT
#define	_SPI_IPL		3
#define	_SPI_SPL		0

/* The Digilent DSPI library uses the same port.
*/
#define	_DSPI0_BASE			_SPI2_BASE_ADDRESS
#define	_DSPI0_ERR_IRQ		_SPI2_ERR_IRQ
#define	_DSPI0_RX_IRQ		_SPI2_RX_IRQ
#define	_DSPI0_TX_IRQ		_SPI2_TX_IRQ
#define	_DSPI0_VECTOR		_SPI_2_VECTOR
#define	_DSPI0_IPL_ISR		IPL3SOFT
#define	_DSPI0_IPL			3
#define	_DSPI0_SPL			0

#define	_DSPI1_BASE			_SPI1_BASE_ADDRESS
#define	_DSPI1_ERR_IRQ		_SPI1_ERR_IRQ
#define	_DSPI1_RX_IRQ		_SPI1_RX_IRQ
#define	_DSPI1_TX_IRQ		_SPI1_TX_IRQ
#define	_DSPI1_VECTOR		_SPI_1_VECTOR
#define	_DSPI1_IPL_ISR		IPL3SOFT
#define	_DSPI1_IPL			3
#define	_DSPI1_SPL			0

/* ------------------------------------------------------------ */
/*					I2C Port Declarations						*/
/* ------------------------------------------------------------ */

/* The standard I2C port uses I2C1 (SCL1/SDA1). These come to pins
** A4/A5 on the analog connector. It is necessary to have jumpers
** JP6/JP8 set appropriately (RG2/RG3 position) to access the I2C
** signals.
*/
#define	_TWI_BASE		_I2C5_BASE_ADDRESS
#define	_TWI_BUS_IRQ	_I2C5_BUS_IRQ
#define	_TWI_SLV_IRQ	_I2C5_SLAVE_IRQ
#define	_TWI_MST_IRQ	_I2C5_MASTER_IRQ
#define	_TWI_VECTOR		_I2C_5_VECTOR
#define	_TWI_IPL_ISR	IPL3SOFT
#define _TWI_IPL		3
#define	_TWI_SPL		0

/* Declarations for Digilent DTWI library.
**		DTWI0 is on 1/2
**		DTWI1 is on digital pins 29/28
*/
#define	_DTWI0_BASE		_I2C2_BASE_ADDRESS
#define	_DTWI0_BUS_IRQ	_I2C2_BUS_IRQ
#define	_DTWI0_VECTOR	_I2C_2_VECTOR
#define	_DTWI0_IPL_ISR	IPL3SOFT
#define	_DTWI0_IPL		3
#define	_DTWI0_SPL		0
#define _DTWI0_SCL_PIN  10
#define _DTWI0_SDA_PIN  11

#define	_DTWI1_BASE		_I2C1_BASE_ADDRESS
#define	_DTWI1_BUS_IRQ	_I2C1_BUS_IRQ
#define	_DTWI1_VECTOR	_I2C_1_VECTOR
#define	_DTWI1_IPL_ISR	IPL3SOFT
#define	_DTWI1_IPL		3
#define	_DTWI1_SPL		0
#define _DTWI1_SCL_PIN  10
#define _DTWI1_SDA_PIN  11

/* ------------------------------------------------------------ */
/*					A/D Converter Declarations					*/
/* ------------------------------------------------------------ */


/* ------------------------------------------------------------ */

#endif	// OPT_BOARD_INTERNAL

/* ------------------------------------------------------------ */

#endif	// BOARD_DEFS_H

/************************************************************************/
