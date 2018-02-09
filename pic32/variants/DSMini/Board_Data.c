#if !defined(BOARD_DATA_C)
#define BOARD_DATA_C

#include <inttypes.h>

/* ------------------------------------------------------------ */
/*					Data Tables									*/
/* ------------------------------------------------------------ */
/* The following declarations define data used in pin mapping.	*/
/* ------------------------------------------------------------ */

#if defined(OPT_BOARD_DATA)

/* ------------------------------------------------------------ */
/* This table is used to map from port number to the address of
** the TRIS register for the port. This is used for setting the
** pin direction.
*/
const uint32_t	port_to_tris_PGM[] = {
	NOT_A_PORT,				//index value 0 is not used

#if defined(_PORTA)
	(uint32_t)&TRISA,
#else
	NOT_A_PORT,
#endif

#if defined(_PORTB)
	(uint32_t)&TRISB,
#else
	NOT_A_PORT,
#endif

#if defined(_PORTC)
	(uint32_t)&TRISC,
#else
	NOT_A_PORT,
#endif

#if defined(_PORTD)
	(uint32_t)&TRISD,
#else
	NOT_A_PORT,
#endif

#if defined(_PORTE)
	(uint32_t)&TRISE,
#else
	NOT_A_PORT,
#endif

#if defined(_PORTF)
	(uint32_t)&TRISF,
#else
	NOT_A_PORT,
#endif

#if defined(_PORTG)
	(uint32_t)&TRISG,
#else
	NOT_A_PORT,
#endif

	NOT_A_PORT,
};

/* ------------------------------------------------------------ */
/* This table is used to map the digital pin number to the port
** containing that pin. The default mapping is to assign pin numbers
** for every possible port bit in order from PORTA to PORTG.
*/
const uint8_t digital_pin_to_port_PGM[] = {
    // Click Header
    _IOPORT_PA, //  0   RA0     AN          (INT4)
    _IOPORT_PB, //  1   RB12    RES
    _IOPORT_PB, //  2   RB10    CS          
    _IOPORT_PB, //  3   RB15    SCK2
    _IOPORT_PB, //  4   RB13    SDI2        (SDI1)
    _IOPORT_PB, //  5   RB11    SDO2        (SDO2/INT3)
    _IOPORT_PB, //  6   RB9     SDA1        
    _IOPORT_PB, //  7   RB8     SCL1
    _IOPORT_PC, //  8   RC0     U1TX        (U1TX)
    _IOPORT_PC, //  9   RC1     U1RX        (U1RX)
    _IOPORT_PB, // 10   RB7     INT0
    _IOPORT_PB, // 11   RB8     PWM         (OC2)

    // LED & Button
    _IOPORT_PB, // 12   RB9     Button      (INT1)
    _IOPORT_PC, // 13   RC3     LED         (OC4)

    // Power
    _IOPORT_PA, // 14   RA1     SENSECTL
    _IOPORT_PB, // 15   RB14    RFCTL

    // Bluetooth
    _IOPORT_PB, // 16   RB1     U2RX
    _IOPORT_PB, // 17   RB0     U2TX

    // ICSP
    _IOPORT_PB, // 18   RB5     PGD
    _IOPORT_PB, // 19   RB6     PGC
};

/* ------------------------------------------------------------ */
/* This table is used to map from digital pin number to a bit mask
** for the corresponding bit within the port.
*/
const uint16_t	digital_pin_to_bit_mask_PGM[] = {
    // Click Header
    _BV( 0 ),   //  0   RA0     AN
    _BV(12 ),   //  1   RB12    RES
    _BV(10 ),   //  2   RB10    CS
    _BV(15 ),   //  3   RB15    SCK2
    _BV(13 ),   //  4   RB13    SDI2
    _BV(11 ),   //  5   RB11    SDO2
    _BV( 2 ),   //  6   RB2     SDA2
    _BV( 3 ),   //  7   RB3     SCL2
    _BV( 0 ),   //  8   RC0     U1TX
    _BV( 1 ),   //  9   RC1     U1RX
    _BV( 7 ),   // 10   RB7     INT0
    _BV( 8 ),   // 11   RB8     PWM (OC2)

    // LED & Button
    _BV( 9 ),   // 12   RB9     Button
    _BV( 3 ),   // 13   RC3     LED

    // Power
    _BV( 1 ),   // 14   RA1     SENSECTL
    _BV(14 ),   // 15   RB14    RFCTL

    // Bluetooth
    _BV( 1 ),   // 16   RB1     U2RX
    _BV( 0 ),   // 17   RB0     U2TX

    // ICSP
    _BV( 5 ),   // 18   RB5     PGD
    _BV( 6 ),   // 19   RB6     PGC
};

/* ------------------------------------------------------------ */
/* This table is used to map from digital pin number to the output
** compare number, input capture number, and timer external clock
** input associated with that pin.
*/
const uint16_t	digital_pin_to_timer_PGM[] = {
    // Click Header
    NOT_ON_TIMER, //  0   RA0     AN
    NOT_ON_TIMER, //  1   RB12    RES
    NOT_ON_TIMER, //  2   RB10    CS
    NOT_ON_TIMER, //  3   RB15    SCK2
    NOT_ON_TIMER, //  4   RB13    SDI2
    NOT_ON_TIMER, //  5   RB11    SDO2
    NOT_ON_TIMER, //  6   RB2     SDA1
    NOT_ON_TIMER, //  7   RB3     SCL1
    NOT_ON_TIMER, //  8   RC0     U1TX
    NOT_ON_TIMER, //  9   RC1     U1RX
    NOT_ON_TIMER, // 10   RB7     INT0
    _TIMER_OC2,   // 11   RB8     PWM (OC2)

    // LED & Button
    NOT_ON_TIMER, // 12   RB2     Button
    _TIMER_OC4,   // 13   RC3     LED

    // Power
    NOT_ON_TIMER, // 14   RA1     SENSECTL
    NOT_ON_TIMER, // 15   RB14    RFCTL

    // Bluetooth
    NOT_ON_TIMER, // 16   RB1     U2RX
    NOT_ON_TIMER, // 17   RB0     U2TX

    // ICSP
    NOT_ON_TIMER, // 18   RB5     PGD
    NOT_ON_TIMER, // 19   RB6     PGC
};

/* ------------------------------------------------------------ */
/* This table maps from a digital pin number to the corresponding
** PPS register. This register is used to select the peripheral output
** connected to the pin. The register is set to 0 to disconnect the
** pin from any peripheral so it can be used as GPIO.
** For PIC32MX1xx/2xx series devices, the PPS output select registers
** are arranged as a contiguous series of 32 bit registers. This table
** treats these registers as an array of DWORDs an stores the index
** to the register.
*/
const uint8_t digital_pin_to_pps_out_PGM[] = {
    // Click Header
    _PPS_OUT(_PPS_RPA0R ),  //  0   RA0     AN
    NOT_PPS_PIN,            //  1   RB12    RES
    _PPS_OUT(_PPS_RPB10R),  //  2   RB10    CS
    _PPS_OUT(_PPS_RPB15R),  //  3   RB15    SCK2
    _PPS_OUT(_PPS_RPB13R),  //  4   RB13    SDI2
    _PPS_OUT(_PPS_RPB11R),  //  5   RB11    SDO2
    _PPS_OUT(_PPS_RPB2R ),  //  6   RB9     SDA1
    _PPS_OUT(_PPS_RPB3R ),  //  7   RB8     SCL1
    _PPS_OUT(_PPS_RPC0R ),  //  8   RC0     U1TX
    _PPS_OUT(_PPS_RPC1R ),  //  9   RC1     U1RX
    _PPS_OUT(_PPS_RPB7R ),  // 10   RB7     INT0
    _PPS_OUT(_PPS_RPB8R ),  // 11   RB8     PWM (OC2)

    // LED & Button
    _PPS_OUT(_PPS_RPB9R ),  // 12   RB9     Button
    _PPS_OUT(_PPS_RPC3R ),  // 13   RC3     LED

    // Power
    _PPS_OUT(_PPS_RPA1R ),  // 14   RA1     SENSECTL
    _PPS_OUT(_PPS_RPB14R),  // 15   RB14    RFCTL

    // Bluetooth
    _PPS_OUT(_PPS_RPB1R ),  // 16   RB1     U2RX
    _PPS_OUT(_PPS_RPB0R ),  // 17   RB0     U2TX

    // ICSP
    _PPS_OUT(_PPS_RPB5R ),  // 18   RB5     PGD
    _PPS_OUT(_PPS_RPB6R ),  // 19   RB6     PGC
};

/* ------------------------------------------------------------ */
/* This table maps from the digital pin number to the value to be
** loaded into a PPS input select register to select that pin.
** It also maps from digital pin number to input/output pin set to 
** which the pin belongs. The set mask is in the high four bits,
** the select value is in the low four bits.
** Note: if the PIC32 device has more than four pin sets, or more than
** 16 pin mapping choices per input function, then this table will have
** to be redefined as a table of uint16_t values and the macros used to
** access the table redefined as well.
*/
const uint8_t digital_pin_to_pps_in_PGM[] = {
    // Click Header
    _PPS_IN(_PPS_RPA0 ),  //  0   RA0     AN
    NOT_PPS_PIN,          //  1   RB12    RES
    _PPS_IN(_PPS_RPB10),  //  2   RB10    CS
    _PPS_IN(_PPS_RPB15),  //  3   RB15    SCK2
    _PPS_IN(_PPS_RPB13),  //  4   RB13    SDI2
    _PPS_IN(_PPS_RPB11),  //  5   RB11    SDO2
    _PPS_IN(_PPS_RPB2 ),  //  6   RB9     SDA1
    _PPS_IN(_PPS_RPB3 ),  //  7   RB8     SCL1
    _PPS_IN(_PPS_RPC0 ),  //  8   RC0     U1TX
    _PPS_IN(_PPS_RPC1 ),  //  9   RC1     U1RX
    _PPS_IN(_PPS_RPB7 ),  // 10   RB7     INT0
    _PPS_IN(_PPS_RPB8 ),  // 11   RB8     PWM (OC3)
    
    // LED & Button
    _PPS_IN(_PPS_RPB9 ),  // 12   RB9     Button    (INT1)
    _PPS_IN(_PPS_RPC3 ),  // 13   RC3     LED
    
    // Power
    _PPS_IN(_PPS_RPA1 ),  // 14   RA1     SENSECTL
    _PPS_IN(_PPS_RPB14),  // 15   RB14    RFCTL
    
    // Bluetooth
    _PPS_IN(_PPS_RPB1 ),  // 16   RB1     U2RX
    _PPS_IN(_PPS_RPB0 ),  // 17   RB0     U2TX
    
    // ICSP
    _PPS_IN(_PPS_RPB5 ),  // 18   RB5     PGD
    _PPS_IN(_PPS_RPB6 ),  // 19   RB6     PGC
};

/* ------------------------------------------------------------ */
/* This table maps from a digital pin number to the corresponding
** analog pin number.
*/
//#if defined(_NOT_USED_)
const uint8_t digital_pin_to_analog_PGM[] = {
    // Click Header
    _BOARD_AN0,     //  0   RA0     AN
    NOT_ANALOG_PIN, //  1   RB12    RES
    NOT_ANALOG_PIN, //  2   RB10    CS
    NOT_ANALOG_PIN, //  3   RB15    SCK2
    NOT_ANALOG_PIN, //  4   RB13    SDI2
    NOT_ANALOG_PIN, //  5   RB11    SDO2
    NOT_ANALOG_PIN, //  6   RB9     SDA1
    NOT_ANALOG_PIN, //  7   RB8     SCL1
    NOT_ANALOG_PIN, //  8   RC0     U1TX
    NOT_ANALOG_PIN, //  9   RC1     U1RX
    NOT_ANALOG_PIN, // 10   RB7     INT0
    NOT_ANALOG_PIN, // 11   RB3     PWM (OC1)

    // LED & Button
    NOT_ANALOG_PIN, // 12   RB2     Button
    NOT_ANALOG_PIN, // 13   RC3     LED

    // Power
    NOT_ANALOG_PIN, // 14   RA1     SENSECTL
    NOT_ANALOG_PIN, // 15   RB14    RFCTL

    // Bluetooth
    NOT_ANALOG_PIN, // 16   RB1     U2RX
    NOT_ANALOG_PIN, // 17   RB0     U2TX

    // ICSP
    NOT_ANALOG_PIN, // 18   RB5     PGD
    NOT_ANALOG_PIN, // 19   RB6     PGC
};
//#endif

/* ------------------------------------------------------------ */
/* This table is used to map from the analog pin number to the
** actual A/D converter channel used for that pin.
** In the default case, where there is a one-to-one mapping, this
** table isn't needed as the analogInPinToChannel() macro is defined
** to provide the mapping.
*/
//#if defined(_NOT_USED_)
const uint8_t analog_pin_to_channel_PGM[] = {
			//*	Arduino Pin		PIC32 Analog channel
	0,		//*	A0				0
};
//#endif

/* ------------------------------------------------------------ */
/* This table maps from an output compare number as stored in the
** digital_pin_to_timer_PGM table to the digital pin number of the
** pin that OC is connected to. This table is only required for
** devices that support peripheral pin select (PPS), i.e. PIC32MX1xx/2xx
** devices.
*/

const uint8_t output_compare_to_digital_pin_PGM[] = {
	NOT_PPS_PIN,		// There is no OC0, so this one needs to be blank
	PIN_OC1,	        // A0, B3, B4, B15, B7  ; B7    RPB7R   = 5  	
	PIN_OC2,	        // A1, B5, B1, B11, B8  ; B11   RPB11R  = 5
	PIN_OC3,	        // A3, B14, B0, B10, B9 ; B10   RPB10R  = 5
	PIN_OC4,	        // A2, B6, A4, B13, B2  ; B13   RPB13R  = 5
	PIN_OC5,	        // A2, B6, A4, B13, B2	; A4    RPA4R   = 6
};

/* ------------------------------------------------------------ */
/* This table maps from an external interrupt number to the digital
** pin for that interrupt.
*/

const uint8_t external_int_to_digital_pin_PGM[] = {
	NOT_PPS_PIN,		// INT0 is not mappable;    RB7
	PIN_INT1,			// A3, B14, B0, B10, B9;    B10  INT1R = RPB10 = 3
	PIN_INT2,			// A2, B6, A4, B13, B2;     B13  INT2R = RPB13 = 3
	PIN_INT3,			// A1, B5, B1, B11, B8;     B5  INT3R = RPB5 = 1
	PIN_INT4			// A0, B3, B4, B15, B7;     B4  INT4R = RPB4 = 2
};

/* ------------------------------------------------------------ */
/*		Include Files for Board Customization Functions			*/
/* ------------------------------------------------------------ */
#if	(OPT_BOARD_INIT != 0)
#endif

/* ------------------------------------------------------------ */
/*				Board Customization Functions					*/
/* ------------------------------------------------------------ */
/*																*/
/* The following can be used to customize the behavior of some	*/
/* of the core API functions. These provide hooks that can be	*/
/* used to extend or replace the default behavior of the core	*/
/* functions. To use one of these functions, add the desired	*/
/* code to the function skeleton below and then set the value	*/
/* of the appropriate compile switch above to 1. This will		*/
/* cause the hook function to be compiled into the build and	*/
/* to cause the code to call the hook function to be compiled	*/
/* into the appropriate core function.							*/
/*																*/
/* ------------------------------------------------------------ */
/***	_board_init
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
**		This function is called from the core init() function.
**		This can be used to perform any board specific init
**		that needs to be done when the processor comes out of
**		reset and before the user sketch is run.
*/
#if	(OPT_BOARD_INIT != 0)
extern void _disableSeconaryOscillator(void);
void _board_init(void) {
    _disableSeconaryOscillator();
}   

#endif

/* ------------------------------------------------------------ */
/***	_board_pinMode
**
**	Parameters:
**		pin		- digital pin number to configure
**		mode	- mode to which the pin should be configured
**
**	Return Value:
**		Returns 0 if not handled, !0 if handled.
**
**	Errors:
**		none
**
**	Description:
**		This function is called at the beginning of the pinMode
**		function. It can perform any special processing needed
**		when setting the pin mode. If this function returns zero,
**		control will pass through the normal pinMode code. If
**		it returns a non-zero value the normal pinMode code isn't
**		executed.
*/
#if	(OPT_BOARD_DIGITAL_IO != 0)

int	_board_pinMode(uint8_t pin, uint8_t mode) {
	
	return 0;

}

#endif

/* ------------------------------------------------------------ */
/***	_board_getPinMode
**
**	Parameters:
**		pin		- digital pin number
**		mode	- pointer to variable to receive mode value
**
**	Return Value:
**		Returns 0 if not handled, !0 if handled.
**
**	Errors:
**		none
**
**	Description:
**		This function is called at the beginning of the getPinMode
**		function. It can perform any special processing needed
**		when getting the pin mode. If this function returns zero,
**		control will pass through the normal getPinMode code. If
**		it returns a non-zero value the normal getPinMode code isn't
**		executed.
*/
#if	(OPT_BOARD_DIGITAL_IO != 0)

int	_board_getPinMode(uint8_t pin, uint8_t * mode) {
	
	return 0;

}

#endif

/* ------------------------------------------------------------ */
/***	_board_digitalWrite
**
**	Parameters:
**		pin		- digital pin number
**		val		- value to write to the pin
**
**	Return Value:
**		Returns 0 if not handled, !0 if handled.
**
**	Errors:
**		none
**
**	Description:
**		This function is called at the beginning of the digitalWrite
**		function. It can perform any special processing needed
**		in writing to the pin. If this function returns zero,
**		control will pass through the normal digitalWrite code. If
**		it returns a non-zero value the normal digitalWrite code isn't
**		executed.
*/
#if	(OPT_BOARD_DIGITAL_IO != 0)

int	_board_digitalWrite(uint8_t pin, uint8_t val) {
	
	return 0;

}

#endif

/* ------------------------------------------------------------ */
/***	_board_digitalRead
**
**	Parameters:
**		pin		- digital pin number
**		val		- pointer to variable to receive pin value
**
**	Return Value:
**		Returns 0 if not handled, !0 if handled.
**
**	Errors:
**		none
**
**	Description:
**		This function is called at the beginning of the digitalRead
**		function. It can perform any special processing needed
**		in reading from the pin. If this function returns zero,
**		control will pass through the normal digitalRead code. If
**		it returns a non-zero value the normal digitalRead code isn't
**		executed.
*/
#if	(OPT_BOARD_DIGITAL_IO != 0)

int	_board_digitalRead(uint8_t pin, uint8_t * val) {
	
	return 0;

}

#endif

/* ------------------------------------------------------------ */
/***	_board_analogRead
**
**	Parameters:
**		pin		- analog channel number
**		val		- pointer to variable to receive analog value
**
**	Return Value:
**		Returns 0 if not handled, !0 if handled.
**
**	Errors:
**		none
**
**	Description:
**		This function is called at the beginning of the analogRead
**		function. It can perform any special processing needed
**		in reading from the pin. If this function returns zero,
**		control will pass through the normal analogRead code. If
**		it returns a non-zero value the normal analogRead code isn't
**		executed.
*/
#if (OPT_BOARD_ANALOG_READ != 0)

int	_board_analogRead(uint8_t pin, int * val) {

	return 0;

}

#endif

/* ------------------------------------------------------------ */
/***	_board_analogReference
**
**	Parameters:
**
**	Return Value:
**		Returns 0 if not handled, !0 if handled.
**
**	Errors:
**		none
**
**	Description:
**		This function is called at the beginning of the analogReference
**		function. It can perform any special processing needed
**		to set the reference voltage. If this function returns zero,
**		control will pass through the normal analogReference code. If
**		it returns a non-zero value the normal analogReference code isn't
**		executed.
*/
#if (OPT_BOARD_ANALOG_READ != 0)

int	_board_analogReference(uint8_t mode) {

	return 0;

}

#endif

/* ------------------------------------------------------------ */
/***	_board_analogWrite
**
**	Parameters:
**		pin		- pin number
**		val		- analog value to write
**
**	Return Value:
**		Returns 0 if not handled, !0 if handled.
**
**	Errors:
**		none
**
**	Description:
**		This function is called at the beginning of the analogWrite
**		function. It can perform any special processing needed
**		in writing to the pin. If this function returns zero,
**		control will pass through the normal analogWrite code. If
**		it returns a non-zero value the normal analogWrite code isn't
**		executed.
*/
#if (OPT_BOARD_ANALOG_WRITE != 0)

int	_board_analogWrite(uint8_t pin, int val) {

	return 0;

}

#endif

#endif // OPT_BOARD_DATA

/* ------------------------------------------------------------ */

#endif	// BOARD_DATA_C

/************************************************************************/
