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
    _IOPORT_PD,    // 0: RD0
    _IOPORT_PF,    // 1: RF3
    _IOPORT_PD,    // 2: RD9
    _IOPORT_PD,    // 3: RD10
    _IOPORT_PD,    // 4: RD11
    _IOPORT_PC,    // 5: RC15
    _IOPORT_PC,    // 6: RC13
    _IOPORT_PC,    // 7: RC14
    _IOPORT_PD,    // 8: RD1
    _IOPORT_PD,    // 9: RD2
    _IOPORT_PD,    // 10: RD3
    _IOPORT_PD,    // 11: RD4
    _IOPORT_PD,    // 12: RD5
    _IOPORT_PF,    // 13: RF7
    _IOPORT_PF,    // 14: RF1
    _IOPORT_PE,    // 15: RE0
    _IOPORT_PE,    // 16: RE1
    _IOPORT_PE,    // 17: RE2
    _IOPORT_PE,    // 18: RE3
    _IOPORT_PE,    // 19: RE4
    _IOPORT_PE,    // 20: RE5
    _IOPORT_PE,    // 21: RE6
    _IOPORT_PE,    // 22: RE7
    _IOPORT_PB,    // 23: RB5
    _IOPORT_PG,    // 24: RG6
    _IOPORT_PG,    // 25: RG7
    _IOPORT_PG,    // 26: RG8
    _IOPORT_PG,    // 27: RG9
    _IOPORT_PF,    // 28: RF4
    _IOPORT_PF,    // 29: RF5
    _IOPORT_PB,    // 30: RB4
    _IOPORT_PB,    // 31: RB3
    _IOPORT_PB,    // 32: RB2
    _IOPORT_PB,    // 33: RB1
    _IOPORT_PB,    // 34: RB0
    _IOPORT_PB,    // 35: RB7
    _IOPORT_PB,    // 36: RB6
    _IOPORT_PB,    // 37: RB8
    _IOPORT_PB,    // 38: RB9
    _IOPORT_PB,    // 39: RB10
    _IOPORT_PB,    // 40: RB11
    _IOPORT_PB,    // 41: RB12
    _IOPORT_PB,    // 42: RB13
    _IOPORT_PB,    // 43: RB14
    _IOPORT_PB,    // 44: RB15
};

const uint16_t digital_pin_to_bit_mask_PGM[] = {
    _BV(0),   // 0: RD0
    _BV(3),   // 1: RF3
    _BV(9),   // 2: RD9
    _BV(10),   // 3: RD10
    _BV(11),   // 4: RD11
    _BV(15),   // 5: RC15
    _BV(13),   // 6: RC13
    _BV(14),   // 7: RC14
    _BV(1),   // 8: RD1
    _BV(2),   // 9: RD2
    _BV(3),   // 10: RD3
    _BV(4),   // 11: RD4
    _BV(5),   // 12: RD5
    _BV(7),   // 13: RF7
    _BV(1),   // 14: RF1
    _BV(0),   // 15: RE0
    _BV(1),   // 16: RE1
    _BV(2),   // 17: RE2
    _BV(3),   // 18: RE3
    _BV(4),   // 19: RE4
    _BV(5),   // 20: RE5
    _BV(6),   // 21: RE6
    _BV(7),   // 22: RE7
    _BV(5),   // 23: RB5
    _BV(6),   // 24: RG6
    _BV(7),   // 25: RG7
    _BV(8),   // 26: RG8
    _BV(9),   // 27: RG9
    _BV(4),   // 28: RF4
    _BV(5),   // 29: RF5
    _BV(4),   // 30: RB4
    _BV(3),   // 31: RB3
    _BV(2),   // 32: RB2
    _BV(1),   // 33: RB1
    _BV(0),   // 34: RB0
    _BV(7),   // 35: RB7
    _BV(6),   // 36: RB6
    _BV(8),   // 37: RB8
    _BV(9),   // 38: RB9
    _BV(10),   // 39: RB10
    _BV(11),   // 40: RB11
    _BV(12),   // 41: RB12
    _BV(13),   // 42: RB13
    _BV(14),   // 43: RB14
    _BV(15),   // 44: RB15
};

const uint16_t digital_pin_to_timer_PGM[] = {
    NOT_ON_TIMER,   // 0: RD0
    NOT_ON_TIMER,   // 1: RF3
    NOT_ON_TIMER,   // 2: RD9
    NOT_ON_TIMER,   // 3: RD10
    _TIMER_OC4,   // 4: RD11
    NOT_ON_TIMER,   // 5: RC15
    NOT_ON_TIMER,   // 6: RC13
    _TIMER_OC3,   // 7: RC14
    _TIMER_OC2,   // 8: RD1
    _TIMER_OC6,   // 9: RD2
    _TIMER_OC7,   // 10: RD3
    NOT_ON_TIMER,   // 11: RD4
    NOT_ON_TIMER,   // 12: RD5
    NOT_ON_TIMER,   // 13: RF7
    NOT_ON_TIMER,   // 14: RF1
    NOT_ON_TIMER,   // 15: RE0
    NOT_ON_TIMER,   // 16: RE1
    NOT_ON_TIMER,   // 17: RE2
    NOT_ON_TIMER,   // 18: RE3
    NOT_ON_TIMER,   // 19: RE4
    NOT_ON_TIMER,   // 20: RE5
    NOT_ON_TIMER,   // 21: RE6
    NOT_ON_TIMER,   // 22: RE7
    NOT_ON_TIMER,   // 23: RB5
    NOT_ON_TIMER,   // 24: RG6
    NOT_ON_TIMER,   // 25: RG7
    NOT_ON_TIMER,   // 26: RG8
    NOT_ON_TIMER,   // 27: RG9
    NOT_ON_TIMER,   // 28: RF4
    NOT_ON_TIMER,   // 29: RF5
    NOT_ON_TIMER,   // 30: RB4
    NOT_ON_TIMER,   // 31: RB3
    NOT_ON_TIMER,   // 32: RB2
    NOT_ON_TIMER,   // 33: RB1
    NOT_ON_TIMER,   // 34: RB0
    NOT_ON_TIMER,   // 35: RB7
    NOT_ON_TIMER,   // 36: RB6
    NOT_ON_TIMER,   // 37: RB8
    NOT_ON_TIMER,   // 38: RB9
    NOT_ON_TIMER,   // 39: RB10
    NOT_ON_TIMER,   // 40: RB11
    NOT_ON_TIMER,   // 41: RB12
    NOT_ON_TIMER,   // 42: RB13
    NOT_ON_TIMER,   // 43: RB14
    NOT_ON_TIMER,   // 44: RB15
};

const uint8_t digital_pin_to_analog_PGM[] = {
    NOT_ANALOG_PIN,   // 0: RD0
    NOT_ANALOG_PIN,   // 1: RF3
    NOT_ANALOG_PIN,   // 2: RD9
    NOT_ANALOG_PIN,   // 3: RD10
    NOT_ANALOG_PIN,   // 4: RD11
    NOT_ANALOG_PIN,   // 5: RC15
    NOT_ANALOG_PIN,   // 6: RC13
    NOT_ANALOG_PIN,   // 7: RC14
    NOT_ANALOG_PIN,   // 8: RD1
    NOT_ANALOG_PIN,   // 9: RD2
    NOT_ANALOG_PIN,   // 10: RD3
    NOT_ANALOG_PIN,   // 11: RD4
    NOT_ANALOG_PIN,   // 12: RD5
    NOT_ANALOG_PIN,   // 13: RF7
    NOT_ANALOG_PIN,   // 14: RF1
    NOT_ANALOG_PIN,   // 15: RE0
    NOT_ANALOG_PIN,   // 16: RE1
    NOT_ANALOG_PIN,   // 17: RE2
    NOT_ANALOG_PIN,   // 18: RE3
    NOT_ANALOG_PIN,   // 19: RE4
    NOT_ANALOG_PIN,   // 20: RE5
    NOT_ANALOG_PIN,   // 21: RE6
    NOT_ANALOG_PIN,   // 22: RE7
    NOT_ANALOG_PIN,   // 23: RB5
    NOT_ANALOG_PIN,   // 24: RG6
    NOT_ANALOG_PIN,   // 25: RG7
    NOT_ANALOG_PIN,   // 26: RG8
    NOT_ANALOG_PIN,   // 27: RG9
    NOT_ANALOG_PIN,   // 28: RF4
    NOT_ANALOG_PIN,   // 29: RF5
    _BOARD_AN14,   // 30: RB4
    _BOARD_AN13,   // 31: RB3
    _BOARD_AN12,   // 32: RB2
    _BOARD_AN11,   // 33: RB1
    _BOARD_AN10,   // 34: RB0
    _BOARD_AN9,   // 35: RB7
    _BOARD_AN8,   // 36: RB6
    _BOARD_AN7,   // 37: RB8
    _BOARD_AN6,   // 38: RB9
    _BOARD_AN5,   // 39: RB10
    _BOARD_AN4,   // 40: RB11
    _BOARD_AN3,   // 41: RB12
    _BOARD_AN2,   // 42: RB13
    _BOARD_AN1,   // 43: RB14
    _BOARD_AN0,   // 44: RB15
};

const uint8_t analog_pin_to_channel_PGM[] = {
    10,     // A0 => AN10 (RB15, 44)
    9,     // A1 => AN9 (RB14, 43)
    8,     // A2 => AN8 (RB13, 42)
    7,     // A3 => AN7 (RB12, 41)
    6,     // A4 => AN6 (RB11, 40)
    5,     // A5 => AN5 (RB10, 39)
    49,     // A6 => AN49 (RB9, 38)
    48,     // A7 => AN48 (RB8, 37)
    46,     // A8 => AN46 (RB6, 36)
    47,     // A9 => AN47 (RB7, 35)
    0,     // A10 => AN0 (RB0, 34)
    1,     // A11 => AN1 (RB1, 33)
    2,     // A12 => AN2 (RB2, 32)
    3,     // A13 => AN3 (RB3, 31)
    4,     // A14 => AN4 (RB4, 30)
};

const  uint8_t digital_pin_to_pps_out_PGM[] = {
    _PPS_OUT(_PPS_RPD0R),
    _PPS_OUT(_PPS_RPF3R),
    _PPS_OUT(_PPS_RPD9R),
    _PPS_OUT(_PPS_RPD10R),
    _PPS_OUT(_PPS_RPD11R),
    NOT_PPS_PIN,
    _PPS_OUT(_PPS_RPC13R),
    _PPS_OUT(_PPS_RPC14R),
    _PPS_OUT(_PPS_RPD1R),
    _PPS_OUT(_PPS_RPD2R),
    _PPS_OUT(_PPS_RPD3R),
    _PPS_OUT(_PPS_RPD4R),
    _PPS_OUT(_PPS_RPD5R),
    NOT_PPS_PIN,
    _PPS_OUT(_PPS_RPF1R),
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    _PPS_OUT(_PPS_RPE3R),
    NOT_PPS_PIN,
    _PPS_OUT(_PPS_RPE5R),
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    _PPS_OUT(_PPS_RPB5R),
    _PPS_OUT(_PPS_RPG6R),
    _PPS_OUT(_PPS_RPG7R),
    _PPS_OUT(_PPS_RPG8R),
    _PPS_OUT(_PPS_RPG9R),
    _PPS_OUT(_PPS_RPF4R),
    _PPS_OUT(_PPS_RPF5R),
    NOT_PPS_PIN,
    _PPS_OUT(_PPS_RPB3R),
    _PPS_OUT(_PPS_RPB2R),
    _PPS_OUT(_PPS_RPB1R),
    _PPS_OUT(_PPS_RPB0R),
    _PPS_OUT(_PPS_RPB7R),
    _PPS_OUT(_PPS_RPB6R),
    _PPS_OUT(_PPS_RPB8R),
    _PPS_OUT(_PPS_RPB9R),
    _PPS_OUT(_PPS_RPB10R),
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    _PPS_OUT(_PPS_RPB14R),
    _PPS_OUT(_PPS_RPB15R),
};

const  uint8_t digital_pin_to_pps_in_PGM[] = {
    _PPS_IN(_PPS_RPD0),
    _PPS_IN(_PPS_RPF3),
    _PPS_IN(_PPS_RPD9),
    _PPS_IN(_PPS_RPD10),
    _PPS_IN(_PPS_RPD11),
    NOT_PPS_PIN,
    _PPS_IN(_PPS_RPC13),
    _PPS_IN(_PPS_RPC14),
    _PPS_IN(_PPS_RPD1),
    _PPS_IN(_PPS_RPD2),
    _PPS_IN(_PPS_RPD3),
    _PPS_IN(_PPS_RPD4),
    _PPS_IN(_PPS_RPD5),
    NOT_PPS_PIN,
    _PPS_IN(_PPS_RPF1),
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    _PPS_IN(_PPS_RPE3),
    NOT_PPS_PIN,
    _PPS_IN(_PPS_RPE5),
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    _PPS_IN(_PPS_RPB5),
    _PPS_IN(_PPS_RPG6),
    _PPS_IN(_PPS_RPG7),
    _PPS_IN(_PPS_RPG8),
    _PPS_IN(_PPS_RPG9),
    _PPS_IN(_PPS_RPF4),
    _PPS_IN(_PPS_RPF5),
    NOT_PPS_PIN,
    _PPS_IN(_PPS_RPB3),
    _PPS_IN(_PPS_RPB2),
    _PPS_IN(_PPS_RPB1),
    _PPS_IN(_PPS_RPB0),
    _PPS_IN(_PPS_RPB7),
    _PPS_IN(_PPS_RPB6),
    _PPS_IN(_PPS_RPB8),
    _PPS_IN(_PPS_RPB9),
    _PPS_IN(_PPS_RPB10),
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    _PPS_IN(_PPS_RPB14),
    _PPS_IN(_PPS_RPB15),
};

const uint8_t output_compare_to_digital_pin_PGM[] = {
    NOT_PPS_PIN,
    NOT_PPS_PIN,
    8, // RD1
    7, // RC14
    4, // RD11
    NOT_PPS_PIN,
    9, // RD2
    10, // RD3
    NOT_PPS_PIN,
    NOT_PPS_PIN,
};

const uint8_t external_int_to_digital_pin_PGM[] = {
    0, // RD0
    1, // RF3
    2, // RD9
    3, // RD10
    4, // RD11
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

