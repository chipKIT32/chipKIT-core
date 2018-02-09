#if !defined(BOARD_DEFS_H)
#define BOARD_DEFS_H

#include <inttypes.h>

/* ------------------------------------------------------------ */
/*				Public Board Declarations						*/
/* ------------------------------------------------------------ */
/* The following define symbols that can be used in a sketch to
** refer to peripherals on the board generically.
*/

#define	_BOARD_NAME_	"DSMini"

/* Define the peripherals available on the board.
*/
#define	NUM_DIGITAL_PINS	20
#define	NUM_ANALOG_PINS		1
#define NUM_OC_PINS			2
#define	NUM_IC_PINS			0
#define	NUM_TCK_PINS		0
#define	NUM_INT_PINS		4

#define	NUM_SERIAL_PORTS	2       
#define	NUM_SPI_PORTS		1
#define	NUM_I2C_PORTS		1       

#define NUM_DSPI_PORTS		1
#define NUM_DTWI_PORTS		1       

/* Define I/O devices on the board.
*/
#define	NUM_LED				1
#define NUM_BTN				1
#define	NUM_SWT				0
#define NUM_SERVO			0


#define PIN_C1 AN       0
#define PIN_AN          0
#define PIN_C1_RST      1
#define PIN_RST         1
#define PIN_C1_CS       2
#define PIN_CS          2
#define PIN_C1_SCK      3
#define PIN_SCK         3
#define PIN_C1_MOSI     4
#define PIN_MOSI        4
#define PIN_C1_MISO     5
#define PIN_MISO        5
#define PIN_C1_SDA      6
#define PIN_SDA         6
#define PIN_C1_SCL      7
#define PIN_SCL         7
#define PIN_C1_TX       8
#define PIN_TX          8
#define PIN_C1_RX       9
#define PIN_RX          9
#define PIN_C1_INT     10
#define PIN_INT        10
#define PIN_C1_PWM     11
#define PIN_PWM        11

#define PIN_USER        12
#define INT_USER        1

#define PIN_SENSOR_POWER    14
#define PIN_BLUETOOTH_POWER 15
/* ------------------------------------------------------------ */
/*						LED Declarations						*/
/* ------------------------------------------------------------ */

/* Define the pin numbers for the LEDs
NOTE: The ChipKIT Pi has two user LEDs
*/
#define	PIN_LED1	13      // 11  RA0

/* ------------------------------------------------------------ */
/*					Button Declarations							*/
/* ------------------------------------------------------------ */

/* No buttons or this board
*/

/* Also define the virtual program button for soft reset */
//#define USE_VIRTUAL_PROGRAM_BUTTON      1
//#define VIRTUAL_PROGRAM_BUTTON_TRIS     TRISBbits.TRISB9
//#define VIRTUAL_PROGRAM_BUTTON          LATBbits.LATB9

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

#define PIN_OC1		11     
#define	PIN_OC2		NOT_ON_TIMER
#define	PIN_OC3		NOT_ON_TIMER
#define	PIN_OC4		13      
#define	PIN_OC5		NOT_ON_TIMER

#define PIN_IC1		NOT_ON_TIMER
#define PIN_IC2		NOT_ON_TIMER
#define PIN_IC3		NOT_ON_TIMER
#define PIN_IC4		NOT_ON_TIMER
#define	PIN_IC5		NOT_ON_TIMER

#define	PIN_TCK1	NOT_ON_TIMER
#define	PIN_TCK2	NOT_ON_TIMER
#define	PIN_TCK3	NOT_ON_TIMER
#define	PIN_TCK4	NOT_ON_TIMER
#define	PIN_TCK5	NOT_ON_TIMER

/* ------------------------------------------------------------ */
/*					Interrupt Pin Declarations					*/
/* ------------------------------------------------------------ */

#define	PIN_INT0	10      // INT
#define	PIN_INT1	12      // Button
#define PIN_INT2	 6      // CS
#define	PIN_INT3	 5      // SDO
#define	PIN_INT4	 0      // AN

/* ------------------------------------------------------------ */
/*					SPI Pin Declarations						*/
/* ------------------------------------------------------------ */
/* These symbols are defined for compatibility with the original
** SPI library and the original pins_arduino.h. 
*/
static const uint8_t SS   = 2;
static const uint8_t MISO = 4;
static const uint8_t MOSI = 5;
static const uint8_t SCK  = 3;

/* The Digilent DSPI library uses these ports.
*/
#define	PIN_DSPI0_SS	2

/* ------------------------------------------------------------ */
/*					Analog Pins									*/
/* ------------------------------------------------------------ */
/* Define symbols for accessing the analog pins. This table is  
** used to map an analog pin number to the corresponding digital
** pin number.
*/
#define	A0		0

/* ------------------------------------------------------------ */
/*					Change Notice Pins							*/
/* ------------------------------------------------------------ */
/* These define the pin numbers for the various change notice
** pins.
*/
#define	PIN_CN0	     0 //  0   RA4     SOSCO/RPA4/T1CK/CTED9/PMA1/RA4
#define	PIN_CN1	     1 //  1   RB4     SOSCI/RPB4/RB4
#define	PIN_CN2	     2 //  2   RB5     TMS/RPB5/USBID/RB5
#define	PIN_CN3	     3 //  3   RB13    AN11/RPB13/CTPLS/PMRD/RB13 
#define	PIN_CN4      4 //  4   RB1     PGEC1/AN3/C1INC/C2INA/RPB1/CTED12/PMD1/RB1 (does not come out on Arduino header)
#define	PIN_CN5      5 //  5   RB0     PGED1/AN2/C1IND/C2INB/C3IND/RPB0/PMD0/RB0 (does not come out on Arduino header)
#define	PIN_CN6      6 //  6   RA2     OSC1/CLKI/RPA2/RA2 (does not come out on Arduino header)
#define	PIN_CN7      7 //  7   RA3     OSC2/CLKO/RPA3/PMA0/RA3 (does not come out on Arduino header)
#define	PIN_CN8      8 //  8   RB10    PGED2/RPB10/D+/CTED11/RB10
#define	PIN_CN9	     9 //  9   RB11    PGEC2/RPB11/D-/RB11 
#define	PIN_CN10    10 // 10   RB7     TDI/RPB7/CTED3/PMD5/INT0/RB7
#define	PIN_CN11    11 // 11   RA1     PGEC3/VREF-/CVREF-/AN1/RPA1/CTED2/PMD6/RA1
#define	PIN_CN12    12 // 12   RB8     TCK/RPB8/SCL1/CTED10/PMD4/RB8
#define	PIN_CN13    13 // 13   RB14    CVREF/AN10/C3INB/RPB14/VBUSON/SCK1/CTED5/RB14 
#define	PIN_CN14    14 // 14   RA0     PGED3/VREF+/CVREF+/AN0/C3INC/RPA0/CTED1/PMD7/RA0 (Jumper to either Arduino Analog 1 or LED1)
#define	PIN_CN15    15 // 15   RB15    AN9/C3INA/RPB15/SCK2/CTED6/PMCS1/RB15 (Jumper to either Arduino Analog 1 or LED2)
#define	PIN_CN16    16 // 16   RB2     AN4/C1INB/C2IND/RPB2/SDA2/CTED13/PMD2/RB2 (Arduino A4 / SDA)
#define	PIN_CN17    17 // 17   RB3     AN5/C1INA/C2INC/RTCC/RPB3/SCL2/PMWR/RB3 (Arduino A5 / SCL)
#define	PIN_CN18    18 // 18   RB9     TDO/RPB9/SDA1/CTED4/PMD3/RB9 (does not come out on Arduino header - used for Bootloader Enable switch)

/* ------------------------------------------------------------ */
/*					Pin Mapping Macros							*/
/* ------------------------------------------------------------ */
/* Macros used to access the port and pin mapping tables.
** These are mostly generic, but some of them may be board specific.
** These perform slightly better as macros compared to in-line functions
*/
// This definition can be used for the non-default case where there
// is a mapping table to go from digital pin to analog pin
#undef digitalPinToAnalog
#define	digitalPinToAnalog(P) (P == 0 ? 0 : NOT_ANALOG_PIN)

#undef analogInPinToChannel
#define analogInPinToChannel(P) ( analog_pin_to_channel_PGM[P]  )

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
extern const uint8_t	digital_pin_to_pps_out_PGM[];
extern const uint8_t	digital_pin_to_pps_in_PGM[];
extern const uint8_t 	digital_pin_to_analog_PGM[];
extern const uint8_t	analog_pin_to_channel_PGM[];

extern const uint8_t	output_compare_to_digital_pin_PGM[];
extern const uint8_t	external_int_to_digital_pin_PGM[];

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

#endif	// OPT_BOARD_INTERNAL

/* ------------------------------------------------------------ */
/*					Serial Port Declarations					*/
/* ------------------------------------------------------------ */

/* Serial port 0 uses UART1  for the serial monitor
*/
#define       _SER0_BASE           _UART1_BASE_ADDRESS
#define       _SER0_IRQ            _UART1_ERR_IRQ
#define       _SER0_VECTOR         _UART_1_VECTOR
#define       _SER0_IPL_ISR        IPL2SOFT
#define       _SER0_IPL            2
#define       _SER0_SPL            0
#define       _SER0_TX_OUT         PPS_OUT_U1TX
#define       _SER0_TX_PIN         8          
#define       _SER0_RX_IN          PPS_IN_U1RX 
#define       _SER0_RX_PIN         9            


/* Serial port 1 uses UART2
*/
#define       _SER1_BASE           _UART2_BASE_ADDRESS
#define       _SER1_IRQ            _UART2_ERR_IRQ
#define       _SER1_VECTOR         _UART_2_VECTOR
#define       _SER1_IPL_ISR        IPL2SOFT
#define       _SER1_IPL            2
#define       _SER1_SPL            0
#define       _SER1_TX_OUT         PPS_OUT_U2TX  
#define       _SER1_TX_PIN         17
#define       _SER1_RX_IN          PPS_IN_U2RX    
#define       _SER1_RX_PIN         16


/* ------------------------------------------------------------ */
/*					SPI Port Declarations						*/
/* ------------------------------------------------------------ */

/* The Digilent DSPI and standard SPI libraries uses these ports.
*/
#define	_DSPI0_BASE			_SPI2_BASE_ADDRESS
#define	_DSPI0_ERR_IRQ		_SPI2_ERR_IRQ
#define	_DSPI0_RX_IRQ		_SPI2_RX_IRQ
#define	_DSPI0_TX_IRQ		_SPI2_TX_IRQ
#define	_DSPI0_VECTOR		_SPI_2_VECTOR
#define	_DSPI0_IPL_ISR		_SPI2_IPL_ISR
#define	_DSPI0_IPL			_SPI2_IPL_IPC
#define	_DSPI0_SPL			_SPI2_SPL_IPC

#define _DSPI0_MISO_IN		PPS_IN_SDI2
#define _DSPI0_MISO_PIN		MISO
#define _DSPI0_MOSI_OUT		PPS_OUT_SDO2
#define _DSPI0_MOSI_PIN		MOSI

/* ------------------------------------------------------------ */
/*					I2C Port Declarations						*/
/* ------------------------------------------------------------ */

/* The standard I2C port uses PIC32 peripheral I2C2
** SCL is on RB3 which is Arduino analog pin A5
** SDA is on RB2 which is Arduino analog pin A4
*/
#define	_TWI_BASE		_I2C2_BASE_ADDRESS
#define	_TWI_BUS_IRQ	_I2C2_BUS_IRQ
#define	_TWI_SLV_IRQ	_I2C2_SLAVE_IRQ
#define	_TWI_MST_IRQ	_I2C2_MASTER_IRQ
#define	_TWI_VECTOR		_I2C_2_VECTOR
#define	_TWI_IPL_ISR	_I2C2_IPL_ISR
#define _TWI_IPL		_I2C2_IPL_IPC
#define	_TWI_SPL		_I2C2_SPL_IPC

/* Declarations for Digilent DTWI library.
** DTWI0 is on PIC32 peripheral I2C2
** SCL is on RB3 which is Arduino analog pin A5
** SDA is on RB2 which is Arduino analog pin A4
*/
#define	_DTWI0_BASE		_I2C2_BASE_ADDRESS
#define	_DTWI0_BUS_IRQ	_I2C2_BUS_IRQ
#define	_DTWI0_VECTOR	_I2C_2_VECTOR
#define	_DTWI0_IPL_ISR	_I2C2_IPL_ISR
#define	_DTWI0_IPL		_I2C2_IPL_IPC
#define	_DTWI0_SPL		_I2C2_SPL_IPC
#define _DTWI0_SCL_PIN  7 
#define _DTWI0_SDA_PIN  6

/* ------------------------------------------------------------ */
/*					A/D Converter Declarations					*/
/* ------------------------------------------------------------ */


/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */

#endif	// BOARD_DEFS_H

/************************************************************************/
