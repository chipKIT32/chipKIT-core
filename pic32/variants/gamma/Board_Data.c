#if !defined(BOARD_DATA_C)
#define BOARD_DATA_C

#include <inttypes.h>

#if defined(OPT_BOARD_DATA)

/* ------------------------------------------------------------ */
/* This table is used to map from port number to the address of
** the TRIS register for the port. This is used for setting the
** pin direction.
*/
const uint32_t port_to_tris_PGM[] = {
    NOT_A_PORT,                //index value 0 is not used

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

#if defined(_PORTH)
    (uint32_t)&TRISH,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTJ)
    (uint32_t)&TRISJ,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTK)
    (uint32_t)&TRISK,
#else
    NOT_A_PORT,
#endif
    
    NOT_A_PORT,
};  


const uint8_t digital_pin_to_port_PGM[] = {
    _IOPORT_PE,    // 0: RE8
    _IOPORT_PE,    // 1: RE9
    _IOPORT_PC,    // 2: RC2
    _IOPORT_PC,    // 3: RC1
    _IOPORT_PF,    // 4: RF12
    _IOPORT_PD,    // 5: RD0
    _IOPORT_PC,    // 6: RC14
    _IOPORT_PB,    // 7: RB8
    _IOPORT_PF,    // 8: RF8
    _IOPORT_PD,    // 9: RD1
    _IOPORT_PD,    // 10: RD9
    _IOPORT_PB,    // 11: RB9
    _IOPORT_PB,    // 12: RB10
    _IOPORT_PB,    // 13: RB14
    _IOPORT_PB,    // 14: RB5
    _IOPORT_PB,    // 15: RB4
    _IOPORT_PB,    // 16: RB3
    _IOPORT_PB,    // 17: RB2
    _IOPORT_PB,    // 18: RB1
    _IOPORT_PB,    // 19: RB0
    _IOPORT_PA,    // 20: RA10
    _IOPORT_PA,    // 21: RA15
    _IOPORT_PA,    // 22: RA14
    _IOPORT_PC,    // 23: RC13
    _IOPORT_PD,    // 24: RD11
    _IOPORT_PD,    // 25: RD10
    _IOPORT_PD,    // 26: RD4
    _IOPORT_PD,    // 27: RD5
    _IOPORT_PA,    // 28: RA6
    _IOPORT_PA,    // 29: RA3
    _IOPORT_PF,    // 30: RF2
    _IOPORT_PA,    // 31: RA7
    _IOPORT_PG,    // 32: RG13
    _IOPORT_PG,    // 33: RG12
    _IOPORT_PG,    // 34: RG14
    _IOPORT_PA,    // 35: RA9
    _IOPORT_PB,    // 36: RB11
    _IOPORT_PA,    // 37: RA0
    _IOPORT_PB,    // 38: RB13
    _IOPORT_PB,    // 39: RB12
    _IOPORT_PD,    // 40: RD15
    _IOPORT_PD,    // 41: RD14
    _IOPORT_PF,    // 42: RF13
    _IOPORT_PF,    // 43: RF4
    _IOPORT_PF,    // 44: RF5
    _IOPORT_PG,    // 45: RG8
    _IOPORT_PG,    // 46: RG7
    _IOPORT_PG,    // 47: RG6
    _IOPORT_PG,    // 48: RG9
    _IOPORT_PA,    // 49: RA1
    _IOPORT_PG,    // 50: RG15
    _IOPORT_PA,    // 51: RA5
    _IOPORT_PC,    // 52: RC15
    _IOPORT_PB,    // 53: RB6
    _IOPORT_PB,    // 54: RB7
    _IOPORT_PE,    // 55: RE0
    _IOPORT_PE,    // 56: RE1
    _IOPORT_PE,    // 57: RE2
    _IOPORT_PE,    // 58: RE3
    _IOPORT_PE,    // 59: RE4
    _IOPORT_PE,    // 60: RE5
    _IOPORT_PE,    // 61: RE6
    _IOPORT_PE,    // 62: RE7
    _IOPORT_PG,    // 63: RG0
    _IOPORT_PG,    // 64: RG1
    _IOPORT_PF,    // 65: RF1
    _IOPORT_PF,    // 66: RF0
    _IOPORT_PD,    // 67: RD12
    _IOPORT_PD,    // 68: RD13
    _IOPORT_PD,    // 69: RD2
    _IOPORT_PD,    // 70: RD3
    _IOPORT_PC,    // 71: RC3
    _IOPORT_PC,    // 72: RC4
    _IOPORT_PB,    // 73: RB15
    _IOPORT_PA,    // 74: RA2
};

const uint16_t digital_pin_to_bit_mask_PGM[] = {
    _BV(8),   // 0: RE8
    _BV(9),   // 1: RE9
    _BV(2),   // 2: RC2
    _BV(1),   // 3: RC1
    _BV(12),   // 4: RF12
    _BV(0),   // 5: RD0
    _BV(14),   // 6: RC14
    _BV(8),   // 7: RB8
    _BV(8),   // 8: RF8
    _BV(1),   // 9: RD1
    _BV(9),   // 10: RD9
    _BV(9),   // 11: RB9
    _BV(10),   // 12: RB10
    _BV(14),   // 13: RB14
    _BV(5),   // 14: RB5
    _BV(4),   // 15: RB4
    _BV(3),   // 16: RB3
    _BV(2),   // 17: RB2
    _BV(1),   // 18: RB1
    _BV(0),   // 19: RB0
    _BV(10),   // 20: RA10
    _BV(15),   // 21: RA15
    _BV(14),   // 22: RA14
    _BV(13),   // 23: RC13
    _BV(11),   // 24: RD11
    _BV(10),   // 25: RD10
    _BV(4),   // 26: RD4
    _BV(5),   // 27: RD5
    _BV(6),   // 28: RA6
    _BV(3),   // 29: RA3
    _BV(2),   // 30: RF2
    _BV(7),   // 31: RA7
    _BV(13),   // 32: RG13
    _BV(12),   // 33: RG12
    _BV(14),   // 34: RG14
    _BV(9),   // 35: RA9
    _BV(11),   // 36: RB11
    _BV(0),   // 37: RA0
    _BV(13),   // 38: RB13
    _BV(12),   // 39: RB12
    _BV(15),   // 40: RD15
    _BV(14),   // 41: RD14
    _BV(13),   // 42: RF13
    _BV(4),   // 43: RF4
    _BV(5),   // 44: RF5
    _BV(8),   // 45: RG8
    _BV(7),   // 46: RG7
    _BV(6),   // 47: RG6
    _BV(9),   // 48: RG9
    _BV(1),   // 49: RA1
    _BV(15),   // 50: RG15
    _BV(5),   // 51: RA5
    _BV(15),   // 52: RC15
    _BV(6),   // 53: RB6
    _BV(7),   // 54: RB7
    _BV(0),   // 55: RE0
    _BV(1),   // 56: RE1
    _BV(2),   // 57: RE2
    _BV(3),   // 58: RE3
    _BV(4),   // 59: RE4
    _BV(5),   // 60: RE5
    _BV(6),   // 61: RE6
    _BV(7),   // 62: RE7
    _BV(0),   // 63: RG0
    _BV(1),   // 64: RG1
    _BV(1),   // 65: RF1
    _BV(0),   // 66: RF0
    _BV(12),   // 67: RD12
    _BV(13),   // 68: RD13
    _BV(2),   // 69: RD2
    _BV(3),   // 70: RD3
    _BV(3),   // 71: RC3
    _BV(4),   // 72: RC4
    _BV(15),   // 73: RB15
    _BV(2),   // 74: RA2
};

const uint16_t digital_pin_to_timer_PGM[] = {
    NOT_ON_TIMER,   // 0: RE8
    NOT_ON_TIMER,   // 1: RE9
    _TIMER_OC1,   // 2: RC2
    _TIMER_OC3,   // 3: RC1
    _TIMER_OC5,   // 4: RF12
    _TIMER_OC2,   // 5: RD0
    NOT_ON_TIMER,   // 6: RC14
    NOT_ON_TIMER,   // 7: RB8
    NOT_ON_TIMER,   // 8: RF8
    _TIMER_OC9,   // 9: RD1
    _TIMER_OC8,   // 10: RD9
    _TIMER_OC6,   // 11: RB9
    NOT_ON_TIMER,   // 12: RB10
    NOT_ON_TIMER,   // 13: RB14
    NOT_ON_TIMER,   // 14: RB5
    NOT_ON_TIMER,   // 15: RB4
    _TIMER_OC4,   // 16: RB3
    NOT_ON_TIMER,   // 17: RB2
    _TIMER_OC7,   // 18: RB1
    NOT_ON_TIMER,   // 19: RB0
    NOT_ON_TIMER,   // 20: RA10
    NOT_ON_TIMER,   // 21: RA15
    NOT_ON_TIMER,   // 22: RA14
    NOT_ON_TIMER,   // 23: RC13
    NOT_ON_TIMER,   // 24: RD11
    NOT_ON_TIMER,   // 25: RD10
    NOT_ON_TIMER,   // 26: RD4
    NOT_ON_TIMER,   // 27: RD5
    NOT_ON_TIMER,   // 28: RA6
    NOT_ON_TIMER,   // 29: RA3
    NOT_ON_TIMER,   // 30: RF2
    NOT_ON_TIMER,   // 31: RA7
    NOT_ON_TIMER,   // 32: RG13
    NOT_ON_TIMER,   // 33: RG12
    NOT_ON_TIMER,   // 34: RG14
    NOT_ON_TIMER,   // 35: RA9
    NOT_ON_TIMER,   // 36: RB11
    NOT_ON_TIMER,   // 37: RA0
    NOT_ON_TIMER,   // 38: RB13
    NOT_ON_TIMER,   // 39: RB12
    NOT_ON_TIMER,   // 40: RD15
    NOT_ON_TIMER,   // 41: RD14
    NOT_ON_TIMER,   // 42: RF13
    NOT_ON_TIMER,   // 43: RF4
    NOT_ON_TIMER,   // 44: RF5
    NOT_ON_TIMER,   // 45: RG8
    NOT_ON_TIMER,   // 46: RG7
    NOT_ON_TIMER,   // 47: RG6
    NOT_ON_TIMER,   // 48: RG9
    NOT_ON_TIMER,   // 49: RA1
    NOT_ON_TIMER,   // 50: RG15
    NOT_ON_TIMER,   // 51: RA5
    NOT_ON_TIMER,   // 52: RC15
    NOT_ON_TIMER,   // 53: RB6
    NOT_ON_TIMER,   // 54: RB7
    NOT_ON_TIMER,   // 55: RE0
    NOT_ON_TIMER,   // 56: RE1
    NOT_ON_TIMER,   // 57: RE2
    NOT_ON_TIMER,   // 58: RE3
    NOT_ON_TIMER,   // 59: RE4
    NOT_ON_TIMER,   // 60: RE5
    NOT_ON_TIMER,   // 61: RE6
    NOT_ON_TIMER,   // 62: RE7
    NOT_ON_TIMER,   // 63: RG0
    NOT_ON_TIMER,   // 64: RG1
    NOT_ON_TIMER,   // 65: RF1
    NOT_ON_TIMER,   // 66: RF0
    NOT_ON_TIMER,   // 67: RD12
    NOT_ON_TIMER,   // 68: RD13
    NOT_ON_TIMER,   // 69: RD2
    NOT_ON_TIMER,   // 70: RD3
    NOT_ON_TIMER,   // 71: RC3
    NOT_ON_TIMER,   // 72: RC4
    NOT_ON_TIMER,   // 73: RB15
    NOT_ON_TIMER,   // 74: RA2
};

const uint8_t digital_pin_to_analog_PGM[] = {
    NOT_ANALOG_PIN,   // 0: RE8
    NOT_ANALOG_PIN,   // 1: RE9
    NOT_ANALOG_PIN,   // 2: RC2
    NOT_ANALOG_PIN,   // 3: RC1
    NOT_ANALOG_PIN,   // 4: RF12
    NOT_ANALOG_PIN,   // 5: RD0
    NOT_ANALOG_PIN,   // 6: RC14
    NOT_ANALOG_PIN,   // 7: RB8
    NOT_ANALOG_PIN,   // 8: RF8
    NOT_ANALOG_PIN,   // 9: RD1
    NOT_ANALOG_PIN,   // 10: RD9
    NOT_ANALOG_PIN,   // 11: RB9
    NOT_ANALOG_PIN,   // 12: RB10
    NOT_ANALOG_PIN,   // 13: RB14
    _BOARD_AN0,   // 14: RB5
    _BOARD_AN1,   // 15: RB4
    _BOARD_AN2,   // 16: RB3
    _BOARD_AN3,   // 17: RB2
    _BOARD_AN4,   // 18: RB1
    _BOARD_AN5,   // 19: RB0
    _BOARD_AN6,   // 20: RA10
    NOT_ANALOG_PIN,   // 21: RA15
    NOT_ANALOG_PIN,   // 22: RA14
    NOT_ANALOG_PIN,   // 23: RC13
    NOT_ANALOG_PIN,   // 24: RD11
    NOT_ANALOG_PIN,   // 25: RD10
    NOT_ANALOG_PIN,   // 26: RD4
    NOT_ANALOG_PIN,   // 27: RD5
    NOT_ANALOG_PIN,   // 28: RA6
    NOT_ANALOG_PIN,   // 29: RA3
    NOT_ANALOG_PIN,   // 30: RF2
    NOT_ANALOG_PIN,   // 31: RA7
    NOT_ANALOG_PIN,   // 32: RG13
    NOT_ANALOG_PIN,   // 33: RG12
    NOT_ANALOG_PIN,   // 34: RG14
    _BOARD_AN7,   // 35: RA9
    _BOARD_AN8,   // 36: RB11
    _BOARD_AN10,   // 37: RA0
    _BOARD_AN11,   // 38: RB13
    NOT_ANALOG_PIN,   // 39: RB12
    NOT_ANALOG_PIN,   // 40: RD15
    NOT_ANALOG_PIN,   // 41: RD14
    NOT_ANALOG_PIN,   // 42: RF13
    NOT_ANALOG_PIN,   // 43: RF4
    NOT_ANALOG_PIN,   // 44: RF5
    NOT_ANALOG_PIN,   // 45: RG8
    NOT_ANALOG_PIN,   // 46: RG7
    NOT_ANALOG_PIN,   // 47: RG6
    NOT_ANALOG_PIN,   // 48: RG9
    NOT_ANALOG_PIN,   // 49: RA1
    NOT_ANALOG_PIN,   // 50: RG15
    NOT_ANALOG_PIN,   // 51: RA5
    NOT_ANALOG_PIN,   // 52: RC15
    NOT_ANALOG_PIN,   // 53: RB6
    NOT_ANALOG_PIN,   // 54: RB7
    NOT_ANALOG_PIN,   // 55: RE0
    NOT_ANALOG_PIN,   // 56: RE1
    NOT_ANALOG_PIN,   // 57: RE2
    NOT_ANALOG_PIN,   // 58: RE3
    NOT_ANALOG_PIN,   // 59: RE4
    NOT_ANALOG_PIN,   // 60: RE5
    NOT_ANALOG_PIN,   // 61: RE6
    NOT_ANALOG_PIN,   // 62: RE7
    NOT_ANALOG_PIN,   // 63: RG0
    NOT_ANALOG_PIN,   // 64: RG1
    NOT_ANALOG_PIN,   // 65: RF1
    NOT_ANALOG_PIN,   // 66: RF0
    NOT_ANALOG_PIN,   // 67: RD12
    NOT_ANALOG_PIN,   // 68: RD13
    NOT_ANALOG_PIN,   // 69: RD2
    NOT_ANALOG_PIN,   // 70: RD3
    NOT_ANALOG_PIN,   // 71: RC3
    NOT_ANALOG_PIN,   // 72: RC4
    NOT_ANALOG_PIN,   // 73: RB15
    NOT_ANALOG_PIN,   // 74: RA2
};

const uint8_t analog_pin_to_channel_PGM[] = {
    45,     // A0 => AN45 (RB5, 14)
    4,     // A1 => AN4 (RB4, 15)
    3,     // A2 => AN3 (RB3, 16)
    2,     // A3 => AN2 (RB2, 17)
    1,     // A4 => AN1 (RB1, 18)
    0,     // A5 => AN0 (RB0, 19)
    28,     // A6 => AN28 (RA10, 20)
    27,     // A7 => AN27 (RA9, 35)
    6,     // A8 => AN6 (RB11, 36)
    NOT_ANALOG_PIN,
    24,     // A10 => AN24 (RA0, 37)
    8,     // A11 => AN8 (RB13, 38)
};

const  uint8_t digital_pin_to_pps_out_PGM[] = {
    _PPS_OUT(_PPS_RPE8R),
    _PPS_OUT(_PPS_RPE9R),
    _PPS_OUT(_PPS_RPC2R),
    _PPS_OUT(_PPS_RPC1R),
    _PPS_OUT(_PPS_RPF12R),
    _PPS_OUT(_PPS_RPD0R),
    _PPS_OUT(_PPS_RPC14R),
    _PPS_OUT(_PPS_RPB8R),
    _PPS_OUT(_PPS_RPF8R),
    _PPS_OUT(_PPS_RPD1R),
    _PPS_OUT(_PPS_RPD9R),
    _PPS_OUT(_PPS_RPB9R),
    _PPS_OUT(_PPS_RPB10R),
    _PPS_OUT(_PPS_RPB14R),
    _PPS_OUT(_PPS_RPB5R),
    NOT_PPS_PIN,
    _PPS_OUT(_PPS_RPB3R),
    _PPS_OUT(_PPS_RPB2R),
    _PPS_OUT(_PPS_RPB1R),
    _PPS_OUT(_PPS_RPB0R),
    NOT_PPS_PIN,
    _PPS_OUT(_PPS_RPA15R),
    _PPS_OUT(_PPS_RPA14R),
    _PPS_OUT(_PPS_RPC13R),
    _PPS_OUT(_PPS_RPD11R),
    _PPS_OUT(_PPS_RPD10R),
    _PPS_OUT(_PPS_RPD4R),
    _PPS_OUT(_PPS_RPD5R),
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    _PPS_OUT(_PPS_RPF2R),
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    _PPS_OUT(_PPS_RPD15R),
    _PPS_OUT(_PPS_RPD14R),
    _PPS_OUT(_PPS_RPF13R),
    _PPS_OUT(_PPS_RPF4R),
    _PPS_OUT(_PPS_RPF5R),
    _PPS_OUT(_PPS_RPG8R),
    _PPS_OUT(_PPS_RPG7R),
    _PPS_OUT(_PPS_RPG6R),
    _PPS_OUT(_PPS_RPG9R),
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    _PPS_OUT(_PPS_RPB6R),
    _PPS_OUT(_PPS_RPB7R),
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    _PPS_OUT(_PPS_RPE3R),
    NOT_PPS_PIN,
    _PPS_OUT(_PPS_RPE5R),
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    _PPS_OUT(_PPS_RPG0R),
    _PPS_OUT(_PPS_RPG1R),
    _PPS_OUT(_PPS_RPF1R),
    _PPS_OUT(_PPS_RPF0R),
    _PPS_OUT(_PPS_RPD12R),
    NOT_PPS_PIN,
    _PPS_OUT(_PPS_RPD2R),
    _PPS_OUT(_PPS_RPD3R),
    _PPS_OUT(_PPS_RPC3R),
    _PPS_OUT(_PPS_RPC4R),
    _PPS_OUT(_PPS_RPB15R),
    NOT_PPS_PIN,
};

const  uint8_t digital_pin_to_pps_in_PGM[] = {
    _PPS_IN(_PPS_RPE8),
    _PPS_IN(_PPS_RPE9),
    _PPS_IN(_PPS_RPC2),
    _PPS_IN(_PPS_RPC1),
    _PPS_IN(_PPS_RPF12),
    _PPS_IN(_PPS_RPD0),
    _PPS_IN(_PPS_RPC14),
    _PPS_IN(_PPS_RPB8),
    _PPS_IN(_PPS_RPF8),
    _PPS_IN(_PPS_RPD1),
    _PPS_IN(_PPS_RPD9),
    _PPS_IN(_PPS_RPB9),
    _PPS_IN(_PPS_RPB10),
    _PPS_IN(_PPS_RPB14),
    _PPS_IN(_PPS_RPB5),
    NOT_PPS_PIN,
    _PPS_IN(_PPS_RPB3),
    _PPS_IN(_PPS_RPB2),
    _PPS_IN(_PPS_RPB1),
    _PPS_IN(_PPS_RPB0),
    NOT_PPS_PIN,
    _PPS_IN(_PPS_RPA15),
    _PPS_IN(_PPS_RPA14),
    _PPS_IN(_PPS_RPC13),
    _PPS_IN(_PPS_RPD11),
    _PPS_IN(_PPS_RPD10),
    _PPS_IN(_PPS_RPD4),
    _PPS_IN(_PPS_RPD5),
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    _PPS_IN(_PPS_RPF2),
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    _PPS_IN(_PPS_RPD15),
    _PPS_IN(_PPS_RPD14),
    _PPS_IN(_PPS_RPF13),
    _PPS_IN(_PPS_RPF4),
    _PPS_IN(_PPS_RPF5),
    _PPS_IN(_PPS_RPG8),
    _PPS_IN(_PPS_RPG7),
    _PPS_IN(_PPS_RPG6),
    _PPS_IN(_PPS_RPG9),
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    _PPS_IN(_PPS_RPB6),
    _PPS_IN(_PPS_RPB7),
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    _PPS_IN(_PPS_RPE3),
    NOT_PPS_PIN,
    _PPS_IN(_PPS_RPE5),
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    _PPS_IN(_PPS_RPG0),
    _PPS_IN(_PPS_RPG1),
    _PPS_IN(_PPS_RPF1),
    _PPS_IN(_PPS_RPF0),
    _PPS_IN(_PPS_RPD12),
    NOT_PPS_PIN,
    _PPS_IN(_PPS_RPD2),
    _PPS_IN(_PPS_RPD3),
    _PPS_IN(_PPS_RPC3),
    _PPS_IN(_PPS_RPC4),
    _PPS_IN(_PPS_RPB15),
    NOT_PPS_PIN,
};

const uint8_t output_compare_to_digital_pin_PGM[] = {
    NOT_PPS_PIN,
    2, // RC2
    5, // RD0
    3, // RC1
    16, // RB3
    4, // RF12
    11, // RB9
    18, // RB1
    10, // RD9
    9, // RD1
};

const uint8_t external_int_to_digital_pin_PGM[] = {
    5, // RD0
    2, // RC2
    4, // RF12
    3, // RC1
    18, // RB1
};

#if    (OPT_BOARD_INIT != 0)

void _board_init(void) {

}

#endif
#if    (OPT_BOARD_DIGITAL_IO != 0)

int    _board_pinMode(uint8_t pin, uint8_t mode) {

    return 0;

}

#endif
#if    (OPT_BOARD_DIGITAL_IO != 0)

int    _board_getPinMode(uint8_t pin, uint8_t * mode) {

    return 0;

}

#endif
#if    (OPT_BOARD_DIGITAL_IO != 0)

int    _board_digitalWrite(uint8_t pin, uint8_t val) {

    return 0;

}

#endif
#if    (OPT_BOARD_DIGITAL_IO != 0)

int    _board_digitalRead(uint8_t pin, uint8_t * val) {

    return 0;

}

#endif
#if (OPT_BOARD_ANALOG_READ != 0)

int    _board_analogRead(uint8_t pin, int * val) {

    return 0;

}

#endif
#if (OPT_BOARD_ANALOG_READ != 0)

int    _board_analogReference(uint8_t mode) {

    return 0;

}

#endif
#if (OPT_BOARD_ANALOG_WRITE != 0)

int    _board_analogWrite(uint8_t pin, int val) {

    return 0;

}

#endif
#endif // OPT_BOARD_DATA

/* ------------------------------------------------------------ */

#endif    // BOARD_DATA_C

