/* Created by plibgen $Revision: 1.31 $ */

#ifndef _PORTS_P32MZ2048ECH144_H
#define _PORTS_P32MZ2048ECH144_H

/* Section 1 - Enumerate instances, define constants, VREGs */

#include <xc.h>
#include <stdbool.h>

#include "peripheral/peripheral_common_32bit.h"

/* Default definition used for all API dispatch functions */
#ifndef PLIB_INLINE_API
    #define PLIB_INLINE_API extern inline
#endif

/* Default definition used for all other functions */
#ifndef PLIB_INLINE
    #define PLIB_INLINE extern inline
#endif

typedef enum {

    PORTS_ID_0 = 0,
    PORTS_NUMBER_OF_MODULES

} PORTS_MODULE_ID;

typedef enum {

    PORTS_PIN_MODE_ANALOG = 0,
    PORTS_PIN_MODE_DIGITAL = 1

} PORTS_PIN_MODE;

typedef enum {

    PORTS_CHANGE_NOTICE_PIN_NONE

} PORTS_CHANGE_NOTICE_PIN;

typedef enum {

    PORTS_CN_PIN_NONE

} PORTS_CN_PIN;

typedef enum {

    PORTS_ANALOG_PIN_0 = 16,
    PORTS_ANALOG_PIN_1 = 17,
    PORTS_ANALOG_PIN_2 = 18,
    PORTS_ANALOG_PIN_3 = 19,
    PORTS_ANALOG_PIN_4 = 20,
    PORTS_ANALOG_PIN_5 = 26,
    PORTS_ANALOG_PIN_6 = 27,
    PORTS_ANALOG_PIN_7 = 28,
    PORTS_ANALOG_PIN_8 = 29,
    PORTS_ANALOG_PIN_9 = 30,
    PORTS_ANALOG_PIN_10 = 31,
    PORTS_ANALOG_PIN_11 = 105,
    PORTS_ANALOG_PIN_12 = 104,
    PORTS_ANALOG_PIN_13 = 103,
    PORTS_ANALOG_PIN_14 = 102,
    PORTS_ANALOG_PIN_15 = 71,
    PORTS_ANALOG_PIN_16 = 70,
    PORTS_ANALOG_PIN_17 = 69,
    PORTS_ANALOG_PIN_18 = 68,
    PORTS_ANALOG_PIN_19 = 36,
    PORTS_ANALOG_PIN_20 = 35,
    PORTS_ANALOG_PIN_21 = 34,
    PORTS_ANALOG_PIN_22 = 33,
    PORTS_ANALOG_PIN_23 = 111,
    PORTS_ANALOG_PIN_24 = 0,
    PORTS_ANALOG_PIN_25 = 72,
    PORTS_ANALOG_PIN_26 = 73,
    PORTS_ANALOG_PIN_27 = 9,
    PORTS_ANALOG_PIN_28 = 10,
    PORTS_ANALOG_PIN_29 = 1,
    PORTS_ANALOG_PIN_30 = 93,
    PORTS_ANALOG_PIN_31 = 92,
    PORTS_ANALOG_PIN_32 = 62,
    PORTS_ANALOG_PIN_33 = 63,
    PORTS_ANALOG_PIN_34 = 5,
    PORTS_ANALOG_PIN_35 = 136,
    PORTS_ANALOG_PIN_36 = 137,
    PORTS_ANALOG_PIN_37 = 139,
    PORTS_ANALOG_PIN_38 = 112,
    PORTS_ANALOG_PIN_39 = 113,
    PORTS_ANALOG_PIN_40 = 116,
    PORTS_ANALOG_PIN_41 = 117,
    PORTS_ANALOG_PIN_42 = 118,
    PORTS_ANALOG_PIN_45 = 21,
    PORTS_ANALOG_PIN_46 = 22,
    PORTS_ANALOG_PIN_47 = 23,
    PORTS_ANALOG_PIN_48 = 24,
    PORTS_ANALOG_PIN_49 = 25

} PORTS_ANALOG_PIN;

typedef enum {

    PORTS_AN_PIN_NONE

} PORTS_AN_PIN;

typedef enum {

    PORTS_BIT_POS_0 = 0,
    PORTS_BIT_POS_1 = 1,
    PORTS_BIT_POS_2 = 2,
    PORTS_BIT_POS_3 = 3,
    PORTS_BIT_POS_4 = 4,
    PORTS_BIT_POS_5 = 5,
    PORTS_BIT_POS_6 = 6,
    PORTS_BIT_POS_7 = 7,
    PORTS_BIT_POS_8 = 8,
    PORTS_BIT_POS_9 = 9,
    PORTS_BIT_POS_10 = 10,
    PORTS_BIT_POS_11 = 11,
    PORTS_BIT_POS_12 = 12,
    PORTS_BIT_POS_13 = 13,
    PORTS_BIT_POS_14 = 14,
    PORTS_BIT_POS_15 = 15

} PORTS_BIT_POS;

typedef enum {

    INPUT_FUNC_INT1 = 0,
    INPUT_FUNC_INT2 = 1,
    INPUT_FUNC_INT3 = 2,
    INPUT_FUNC_INT4 = 3,
    INPUT_FUNC_T2CK = 5,
    INPUT_FUNC_T3CK = 6,
    INPUT_FUNC_T4CK = 7,
    INPUT_FUNC_T5CK = 8,
    INPUT_FUNC_T6CK = 9,
    INPUT_FUNC_T7CK = 10,
    INPUT_FUNC_T8CK = 11,
    INPUT_FUNC_T9CK = 12,
    INPUT_FUNC_IC1 = 13,
    INPUT_FUNC_IC2 = 14,
    INPUT_FUNC_IC3 = 15,
    INPUT_FUNC_IC4 = 16,
    INPUT_FUNC_IC5 = 17,
    INPUT_FUNC_IC6 = 18,
    INPUT_FUNC_IC7 = 19,
    INPUT_FUNC_IC8 = 20,
    INPUT_FUNC_IC9 = 21,
    INPUT_FUNC_OCFA = 23,
    INPUT_FUNC_U1RX = 25,
    INPUT_FUNC_U1CTS = 26,
    INPUT_FUNC_U2RX = 27,
    INPUT_FUNC_U2CTS = 28,
    INPUT_FUNC_U3RX = 29,
    INPUT_FUNC_U3CTS = 30,
    INPUT_FUNC_U4RX = 31,
    INPUT_FUNC_U4CTS = 32,
    INPUT_FUNC_U5RX = 33,
    INPUT_FUNC_U5CTS = 34,
    INPUT_FUNC_U6RX = 35,
    INPUT_FUNC_U6CTS = 36,
    INPUT_FUNC_SDI1 = 38,
    INPUT_FUNC_SS1 = 39,
    INPUT_FUNC_SDI2 = 41,
    INPUT_FUNC_SS2 = 42,
    INPUT_FUNC_SDI3 = 44,
    INPUT_FUNC_SS3 = 45,
    INPUT_FUNC_SDI4 = 47,
    INPUT_FUNC_SS4 = 48,
    INPUT_FUNC_SDI5 = 50,
    INPUT_FUNC_SS5 = 51,
    INPUT_FUNC_SDI6 = 53,
    INPUT_FUNC_SS6 = 54,
    INPUT_FUNC_C1RX = 55,
    INPUT_FUNC_C2RX = 56,
    INPUT_FUNC_REFCLKI1 = 57,
    INPUT_FUNC_REFCLKI3 = 59,
    INPUT_FUNC_REFCLKI4 = 60

} PORTS_REMAP_INPUT_FUNCTION;

typedef enum {

    INPUT_PIN_RPD2 = 0x00,
    INPUT_PIN_RPG8 = 0x01,
    INPUT_PIN_RPF4 = 0x02,
    INPUT_PIN_RPD10 = 0x03,
    INPUT_PIN_RPF1 = 0x04,
    INPUT_PIN_RPB9 = 0x05,
    INPUT_PIN_RPB10 = 0x06,
    INPUT_PIN_RPC14 = 0x07,
    INPUT_PIN_RPB5 = 0x08,
    INPUT_PIN_RPC1 = 0x0A,
    INPUT_PIN_RPD14 = 0x0B,
    INPUT_PIN_RPG1 = 0x0C,
    INPUT_PIN_RPA14 = 0x0D,
    INPUT_PIN_RPD6 = 0x0E,
    INPUT_PIN_RPD3 = 0x00,
    INPUT_PIN_RPG7 = 0x01,
    INPUT_PIN_RPF5 = 0x02,
    INPUT_PIN_RPD11 = 0x03,
    INPUT_PIN_RPF0 = 0x04,
    INPUT_PIN_RPB1 = 0x05,
    INPUT_PIN_RPE5 = 0x06,
    INPUT_PIN_RPC13 = 0x07,
    INPUT_PIN_RPB3 = 0x08,
    INPUT_PIN_RPC4 = 0x0A,
    INPUT_PIN_RPD15 = 0x0B,
    INPUT_PIN_RPG0 = 0x0C,
    INPUT_PIN_RPA15 = 0x0D,
    INPUT_PIN_RPD7 = 0x0E,
    INPUT_PIN_RPD9 = 0x00,
    INPUT_PIN_RPG6 = 0x01,
    INPUT_PIN_RPB8 = 0x02,
    INPUT_PIN_RPB15 = 0x03,
    INPUT_PIN_RPD4 = 0x04,
    INPUT_PIN_RPB0 = 0x05,
    INPUT_PIN_RPE3 = 0x06,
    INPUT_PIN_RPB7 = 0x07,
    INPUT_PIN_RPF12 = 0x09,
    INPUT_PIN_RPD12 = 0x0A,
    INPUT_PIN_RPF8 = 0x0B,
    INPUT_PIN_RPC3 = 0x0C,
    INPUT_PIN_RPE9 = 0x0D,
    INPUT_PIN_RPD1 = 0x00,
    INPUT_PIN_RPG9 = 0x01,
    INPUT_PIN_RPB14 = 0x02,
    INPUT_PIN_RPD0 = 0x03,
    INPUT_PIN_RPB6 = 0x05,
    INPUT_PIN_RPD5 = 0x06,
    INPUT_PIN_RPB2 = 0x07,
    INPUT_PIN_RPF3 = 0x08,
    INPUT_PIN_RPF13 = 0x09,
    INPUT_PIN_NC = 0x0A,
    INPUT_PIN_RPF2 = 0x0B,
    INPUT_PIN_RPC2 = 0x0C,
    INPUT_PIN_RPE8 = 0x0D

} PORTS_REMAP_INPUT_PIN;

typedef enum {

    OTPUT_FUNC_U3TX = 0x01,
    OTPUT_FUNC_U4RTS = 0x02,
    OTPUT_FUNC_SDO1 = 0x05,
    OTPUT_FUNC_SDO2 = 0x06,
    OTPUT_FUNC_SDO3 = 0x07,
    OTPUT_FUNC_SDO5 = 0x09,
    OTPUT_FUNC_SS6 = 0x0A,
    OTPUT_FUNC_OC3 = 0x0B,
    OTPUT_FUNC_OC6 = 0x0C,
    OTPUT_FUNC_REFCLKO4 = 0x0D,
    OTPUT_FUNC_C2OUT = 0x0E,
    OTPUT_FUNC_C1TX = 0x0F,
    OTPUT_FUNC_U1TX = 0x01,
    OTPUT_FUNC_U2RTS = 0x02,
    OTPUT_FUNC_U5TX = 0x03,
    OTPUT_FUNC_U6RTS = 0x04,
    OTPUT_FUNC_SDO4 = 0x08,
    OTPUT_FUNC_OC4 = 0x0B,
    OTPUT_FUNC_OC7 = 0x0C,
    OTPUT_FUNC_REFCLKO1 = 0x0F,
    OTPUT_FUNC_U3RTS = 0x01,
    OTPUT_FUNC_U4TX = 0x02,
    OTPUT_FUNC_U6TX = 0x04,
    OTPUT_FUNC_SS1 = 0x05,
    OTPUT_FUNC_SS3 = 0x07,
    OTPUT_FUNC_SS4 = 0x08,
    OTPUT_FUNC_SS5 = 0x09,
    OTPUT_FUNC_SDO6 = 0x0A,
    OTPUT_FUNC_OC5 = 0x0B,
    OTPUT_FUNC_OC8 = 0x0C,
    OTPUT_FUNC_C1OUT = 0x0E,
    OTPUT_FUNC_REFCLKO3 = 0x0F,
    OTPUT_FUNC_U1RTS = 0x01,
    OTPUT_FUNC_U2TX = 0x02,
    OTPUT_FUNC_U5RTS = 0x03,
    OTPUT_FUNC_SS2 = 0x06,
    OTPUT_FUNC_OC2 = 0x0B,
    OTPUT_FUNC_OC1 = 0x0C,
    OTPUT_FUNC_OC9 = 0x0D,
    OTPUT_FUNC_C2TX = 0x0F,
    OTPUT_FUNC_NO_CONNECT = 0x00,
    OUTPUT_FUNC_U3TX = 0x01,
    OUTPUT_FUNC_U4RTS = 0x02,
    OUTPUT_FUNC_SDO1 = 0x05,
    OUTPUT_FUNC_SDO2 = 0x06,
    OUTPUT_FUNC_SDO3 = 0x07,
    OUTPUT_FUNC_SDO5 = 0x09,
    OUTPUT_FUNC_SS6 = 0x0A,
    OUTPUT_FUNC_OC3 = 0x0B,
    OUTPUT_FUNC_OC6 = 0x0C,
    OUTPUT_FUNC_REFCLKO4 = 0x0D,
    OUTPUT_FUNC_C2OUT = 0x0E,
    OUTPUT_FUNC_C1TX = 0x0F,
    OUTPUT_FUNC_U1TX = 0x01,
    OUTPUT_FUNC_U2RTS = 0x02,
    OUTPUT_FUNC_U5TX = 0x03,
    OUTPUT_FUNC_U6RTS = 0x04,
    OUTPUT_FUNC_SDO4 = 0x08,
    OUTPUT_FUNC_OC4 = 0x0B,
    OUTPUT_FUNC_OC7 = 0x0C,
    OUTPUT_FUNC_REFCLKO1 = 0x0F,
    OUTPUT_FUNC_U3RTS = 0x01,
    OUTPUT_FUNC_U4TX = 0x02,
    OUTPUT_FUNC_U6TX = 0x04,
    OUTPUT_FUNC_SS1 = 0x05,
    OUTPUT_FUNC_SS3 = 0x07,
    OUTPUT_FUNC_SS4 = 0x08,
    OUTPUT_FUNC_SS5 = 0x09,
    OUTPUT_FUNC_SDO6 = 0x0A,
    OUTPUT_FUNC_OC5 = 0x0B,
    OUTPUT_FUNC_OC8 = 0x0C,
    OUTPUT_FUNC_C1OUT = 0x0E,
    OUTPUT_FUNC_REFCLKO3 = 0x0F,
    OUTPUT_FUNC_U1RTS = 0x01,
    OUTPUT_FUNC_U2TX = 0x02,
    OUTPUT_FUNC_U5RTS = 0x03,
    OUTPUT_FUNC_SS2 = 0x06,
    OUTPUT_FUNC_OC2 = 0x0B,
    OUTPUT_FUNC_OC1 = 0x0C,
    OUTPUT_FUNC_OC9 = 0x0D,
    OUTPUT_FUNC_C2TX = 0x0F,
    OUTPUT_FUNC_NO_CONNECT = 0x00

} PORTS_REMAP_OUTPUT_FUNCTION;

typedef enum {

    OUTPUT_PIN_RPA14 = 0,
    OUTPUT_PIN_RPA15 = 1,
    OUTPUT_PIN_RPB0 = 2,
    OUTPUT_PIN_RPB1 = 3,
    OUTPUT_PIN_RPB2 = 4,
    OUTPUT_PIN_RPB3 = 5,
    OUTPUT_PIN_RPB5 = 7,
    OUTPUT_PIN_RPB6 = 8,
    OUTPUT_PIN_RPB7 = 9,
    OUTPUT_PIN_RPB8 = 10,
    OUTPUT_PIN_RPB9 = 11,
    OUTPUT_PIN_RPB10 = 12,
    OUTPUT_PIN_RPB14 = 16,
    OUTPUT_PIN_RPB15 = 17,
    OUTPUT_PIN_RPC1 = 19,
    OUTPUT_PIN_RPC2 = 20,
    OUTPUT_PIN_RPC3 = 21,
    OUTPUT_PIN_RPC4 = 22,
    OUTPUT_PIN_RPC13 = 31,
    OUTPUT_PIN_RPC14 = 32,
    OUTPUT_PIN_RPD0 = 34,
    OUTPUT_PIN_RPD1 = 35,
    OUTPUT_PIN_RPD2 = 36,
    OUTPUT_PIN_RPD3 = 37,
    OUTPUT_PIN_RPD4 = 38,
    OUTPUT_PIN_RPD5 = 39,
    OUTPUT_PIN_RPD6 = 40,
    OUTPUT_PIN_RPD7 = 41,
    OUTPUT_PIN_RPD9 = 43,
    OUTPUT_PIN_RPD10 = 44,
    OUTPUT_PIN_RPD11 = 45,
    OUTPUT_PIN_RPD12 = 46,
    OUTPUT_PIN_RPD14 = 48,
    OUTPUT_PIN_RPD15 = 49,
    OUTPUT_PIN_RPE3 = 53,
    OUTPUT_PIN_RPE5 = 55,
    OUTPUT_PIN_RPE8 = 58,
    OUTPUT_PIN_RPE9 = 59,
    OUTPUT_PIN_RPF0 = 66,
    OUTPUT_PIN_RPF1 = 67,
    OUTPUT_PIN_RPF2 = 68,
    OUTPUT_PIN_RPF3 = 69,
    OUTPUT_PIN_RPF4 = 70,
    OUTPUT_PIN_RPF5 = 71,
    OUTPUT_PIN_RPF8 = 74,
    OUTPUT_PIN_RPF12 = 78,
    OUTPUT_PIN_RPF13 = 79,
    OUTPUT_PIN_RPG0 = 82,
    OUTPUT_PIN_RPG1 = 83,
    OUTPUT_PIN_RPG6 = 88,
    OUTPUT_PIN_RPG7 = 89,
    OUTPUT_PIN_RPG8 = 90,
    OUTPUT_PIN_RPG9 = 91

} PORTS_REMAP_OUTPUT_PIN;

typedef enum {

    PORT_CHANNEL_A = 0x00,
    PORT_CHANNEL_B = 0x01,
    PORT_CHANNEL_C = 0x02,
    PORT_CHANNEL_D = 0x03,
    PORT_CHANNEL_E = 0x04,
    PORT_CHANNEL_F = 0x05,
    PORT_CHANNEL_G = 0x06,
    PORT_CHANNEL_H = 0x07,
    PORT_CHANNEL_J = 0x08,
    PORT_CHANNEL_K = 0x09

} PORTS_CHANNEL;

typedef enum {

    PORTS_CHANGE_NOTICE_EDGE_NONE

} PORTS_CHANGE_NOTICE_EDGE;

typedef enum {

    PORTS_PIN_SLEW_RATE_NONE

} PORTS_PIN_SLEW_RATE;

typedef enum {

    PORTS_CHANGE_NOTICE_METHOD_NONE

} PORTS_CHANGE_NOTICE_METHOD;

PLIB_INLINE SFR_TYPE* _PORTS_READ_A_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &PORTA;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_WRITE_A_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &LATA;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_DIRECTION_A_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &TRISA;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_OPEN_DRAIN_A_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &ODCA;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_PIN_MODE_A_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &ANSELA;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_CHANGE_NOTICE_PULL_UP_A_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNPUA;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_PIN_CHANGE_NOTICE_A_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNENA;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_CHANGE_NOTICE_PULL_DOWN_A_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNPDA;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_CHANGE_NOTICE_STATUS_A_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNSTATA;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_PIN_CHANGE_NOTICE_TURN_ON_A_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNCONA;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_A_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNCONA;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_READ_B_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &PORTB;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_WRITE_B_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &LATB;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_DIRECTION_B_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &TRISB;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_OPEN_DRAIN_B_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &ODCB;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_PIN_MODE_B_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &ANSELB;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_CHANGE_NOTICE_PULL_UP_B_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNPUB;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_PIN_CHANGE_NOTICE_B_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNENB;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_CHANGE_NOTICE_PULL_DOWN_B_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNPDB;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_CHANGE_NOTICE_STATUS_B_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNSTATB;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_PIN_CHANGE_NOTICE_TURN_ON_B_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNCONB;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_B_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNCONB;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_READ_C_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &PORTC;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_WRITE_C_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &LATC;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_DIRECTION_C_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &TRISC;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_OPEN_DRAIN_C_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &ODCC;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_PIN_MODE_C_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &ANSELC;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_CHANGE_NOTICE_PULL_UP_C_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNPUC;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_PIN_CHANGE_NOTICE_C_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNENC;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_CHANGE_NOTICE_PULL_DOWN_C_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNPDC;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_CHANGE_NOTICE_STATUS_C_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNSTATC;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_PIN_CHANGE_NOTICE_TURN_ON_C_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNCONC;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_C_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNCONC;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_READ_D_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &PORTD;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_WRITE_D_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &LATD;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_DIRECTION_D_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &TRISD;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_OPEN_DRAIN_D_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &ODCD;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_PIN_MODE_D_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &ANSELD;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_CHANGE_NOTICE_PULL_UP_D_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNPUD;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_PIN_CHANGE_NOTICE_D_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNEND;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_CHANGE_NOTICE_PULL_DOWN_D_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNPDD;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_CHANGE_NOTICE_STATUS_D_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNSTATD;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_PIN_CHANGE_NOTICE_TURN_ON_D_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNCOND;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_D_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNCOND;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_READ_E_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &PORTE;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_WRITE_E_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &LATE;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_DIRECTION_E_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &TRISE;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_OPEN_DRAIN_E_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &ODCE;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_PIN_MODE_E_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &ANSELE;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_CHANGE_NOTICE_PULL_UP_E_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNPUE;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_PIN_CHANGE_NOTICE_E_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNENE;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_CHANGE_NOTICE_PULL_DOWN_E_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNPDE;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_CHANGE_NOTICE_STATUS_E_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNSTATE;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_PIN_CHANGE_NOTICE_TURN_ON_E_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNCONE;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_E_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNCONE;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_READ_F_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &PORTF;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_WRITE_F_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &LATF;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_DIRECTION_F_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &TRISF;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_OPEN_DRAIN_F_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &ODCF;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_PIN_MODE_F_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &ANSELF;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_CHANGE_NOTICE_PULL_UP_F_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNPUF;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_PIN_CHANGE_NOTICE_F_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNENF;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_CHANGE_NOTICE_PULL_DOWN_F_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNPDF;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_CHANGE_NOTICE_STATUS_F_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNSTATF;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_PIN_CHANGE_NOTICE_TURN_ON_F_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNCONF;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_F_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNCONF;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_READ_G_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &PORTG;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_WRITE_G_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &LATG;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_DIRECTION_G_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &TRISG;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_OPEN_DRAIN_G_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &ODCG;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_PIN_MODE_G_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &ANSELG;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_CHANGE_NOTICE_PULL_UP_G_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNPUG;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_PIN_CHANGE_NOTICE_G_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNENG;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_CHANGE_NOTICE_PULL_DOWN_G_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNPDG;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_CHANGE_NOTICE_STATUS_G_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNSTATG;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_PIN_CHANGE_NOTICE_TURN_ON_G_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNCONG;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_G_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNCONG;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_READ_H_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &PORTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_WRITE_H_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &LATH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_DIRECTION_H_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &TRISH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_OPEN_DRAIN_H_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &ODCH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_PIN_MODE_H_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &ANSELH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_CHANGE_NOTICE_PULL_UP_H_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNPUH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_PIN_CHANGE_NOTICE_H_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNENH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_CHANGE_NOTICE_PULL_DOWN_H_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNPDH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_CHANGE_NOTICE_STATUS_H_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNSTATH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_PIN_CHANGE_NOTICE_TURN_ON_H_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNCONH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_H_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNCONH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_READ_J_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &PORTJ;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_WRITE_J_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &LATJ;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_DIRECTION_J_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &TRISJ;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_OPEN_DRAIN_J_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &ODCJ;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_PIN_MODE_J_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &ANSELJ;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_CHANGE_NOTICE_PULL_UP_J_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNPUJ;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_PIN_CHANGE_NOTICE_J_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNENJ;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_CHANGE_NOTICE_PULL_DOWN_J_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNPDJ;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_CHANGE_NOTICE_STATUS_J_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNSTATJ;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_PIN_CHANGE_NOTICE_TURN_ON_J_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNCONJ;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_J_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNCONJ;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_READ_K_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &PORTK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_WRITE_K_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &LATK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_DIRECTION_K_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &TRISK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_OPEN_DRAIN_K_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &ODCK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_CHANGE_NOTICE_PULL_UP_K_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNPUK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_PIN_CHANGE_NOTICE_K_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNENK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_CHANGE_NOTICE_PULL_DOWN_K_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNPDK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_CHANGE_NOTICE_STATUS_K_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNSTATK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_PIN_CHANGE_NOTICE_TURN_ON_K_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNCONK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_K_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &CNCONK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_INT1_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &INT1R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_INT2_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &INT2R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_INT3_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &INT3R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_INT4_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &INT4R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_T2CK_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &T2CKR;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_T3CK_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &T3CKR;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_T4CK_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &T4CKR;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_T5CK_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &T5CKR;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_T6CK_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &T6CKR;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_T7CK_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &T7CKR;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_T8CK_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &T8CKR;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_T9CK_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &T9CKR;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_IC1_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &IC1R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_IC2_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &IC2R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_IC3_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &IC3R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_IC4_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &IC4R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_IC5_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &IC5R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_IC6_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &IC6R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_IC7_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &IC7R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_IC8_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &IC8R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_IC9_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &IC9R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_OCFA_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &OCFAR;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_U1RX_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &U1RXR;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_U1CTS_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &U1CTSR;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_U2RX_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &U2RXR;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_U2CTS_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &U2CTSR;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_U3RX_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &U3RXR;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_U3CTS_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &U3CTSR;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_U4RX_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &U4RXR;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_U4CTS_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &U4CTSR;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_U5RX_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &U5RXR;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_U5CTS_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &U5CTSR;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_U6RX_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &U6RXR;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_U6CTS_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &U6CTSR;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_SDI1_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &SDI1R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_SS1_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &SS1R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_SDI2_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &SDI2R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_SS2_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &SS2R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_SDI3_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &SDI3R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_SS3_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &SS3R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_SDI4_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &SDI4R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_SS4_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &SS4R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_SDI5_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &SDI5R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_SS5_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &SS5R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_SDI6_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &SDI6R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_SS6_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &SS6R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_C1RX_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &C1RXR;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_C2RX_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &C2RXR;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_FUNC_REFCLKI1_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &REFCLKI1R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPA14_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPA14R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPA15_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPA15R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPB0_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPB0R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPB1_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPB1R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPB2_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPB2R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPB3_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPB3R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPB5_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPB5R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPB6_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPB6R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPB7_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPB7R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPB8_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPB8R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPB9_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPB9R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPB10_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPB10R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPB14_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPB14R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPB15_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPB15R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPC1_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPC1R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPC2_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPC2R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPC3_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPC3R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPC4_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPC4R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPC13_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPC13R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPC14_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPC14R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPD1_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPD1R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPD2_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPD2R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPD3_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPD3R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPD4_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPD4R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPD5_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPD5R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPD6_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPD6R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPD7_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPD7R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPD9_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPD9R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPD10_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPD10R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPD11_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPD11R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPD12_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPD12R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPD14_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPD14R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPD15_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPD15R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPE3_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPE3R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPE5_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPE5R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPE8_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPE8R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPE9_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPE9R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPF0_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPF0R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPF1_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPF1R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPF2_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPF2R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPF3_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPF3R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPF4_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPF4R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPF5_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPF5R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPF8_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPF8R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPF12_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPF12R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPF13_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPF13R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPG0_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPG0R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPG1_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPG1R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPG6_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPG6R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPG7_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPG7R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPG8_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPG8R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _PORTS_REMAP_PIN_RPG9_VREG(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return &RPG9R;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_READ_A_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_WRITE_A_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_DIRECTION_A_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_OPEN_DRAIN_A_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_MODE_A_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_UP_A_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_A_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_DOWN_A_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_STATUS_A_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_TURN_ON_A_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONA_ON_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_A_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONA_SIDL_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_READ_B_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_WRITE_B_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_DIRECTION_B_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_OPEN_DRAIN_B_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_MODE_B_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_UP_B_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_B_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_DOWN_B_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_STATUS_B_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_TURN_ON_B_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONB_ON_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_B_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONB_SIDL_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_READ_C_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_WRITE_C_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_DIRECTION_C_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_OPEN_DRAIN_C_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_MODE_C_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_UP_C_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_C_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_DOWN_C_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_STATUS_C_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_TURN_ON_C_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONC_ON_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_C_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONC_SIDL_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_READ_D_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_WRITE_D_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_DIRECTION_D_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_OPEN_DRAIN_D_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_MODE_D_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_UP_D_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_D_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_DOWN_D_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_STATUS_D_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_TURN_ON_D_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCOND_ON_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_D_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCOND_SIDL_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_READ_E_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_WRITE_E_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_DIRECTION_E_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_OPEN_DRAIN_E_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_MODE_E_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_UP_E_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_E_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_DOWN_E_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_STATUS_E_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_TURN_ON_E_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONE_ON_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_E_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONE_SIDL_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_READ_F_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_WRITE_F_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_DIRECTION_F_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_OPEN_DRAIN_F_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_MODE_F_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_UP_F_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_F_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_DOWN_F_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_STATUS_F_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_TURN_ON_F_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONF_ON_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_F_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONF_SIDL_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_READ_G_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_WRITE_G_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_DIRECTION_G_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_OPEN_DRAIN_G_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_MODE_G_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_UP_G_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_G_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_DOWN_G_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_STATUS_G_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_TURN_ON_G_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONG_ON_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_G_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONG_SIDL_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_READ_H_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_WRITE_H_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_DIRECTION_H_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_OPEN_DRAIN_H_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_MODE_H_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_UP_H_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_H_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_DOWN_H_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_STATUS_H_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_TURN_ON_H_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONH_ON_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_H_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONH_SIDL_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_READ_J_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_WRITE_J_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_DIRECTION_J_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_OPEN_DRAIN_J_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_MODE_J_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_UP_J_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_J_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_DOWN_J_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_STATUS_J_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_TURN_ON_J_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONJ_ON_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_J_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONJ_SIDL_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_READ_K_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_WRITE_K_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_DIRECTION_K_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_OPEN_DRAIN_K_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_UP_K_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_K_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_DOWN_K_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_STATUS_K_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)-1;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_TURN_ON_K_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONK_ON_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_K_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONK_SIDL_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_INT1_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _INT1R_INT1R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_INT2_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _INT2R_INT2R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_INT3_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _INT3R_INT3R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_INT4_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _INT4R_INT4R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_T2CK_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _T2CKR_T2CKR_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_T3CK_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _T3CKR_T3CKR_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_T4CK_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _T4CKR_T4CKR_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_T5CK_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _T5CKR_T5CKR_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_T6CK_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _T6CKR_T6CKR_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_T7CK_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _T7CKR_T7CKR_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_T8CK_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _T8CKR_T8CKR_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_T9CK_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _T9CKR_T9CKR_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_IC1_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _IC1R_IC1R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_IC2_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _IC2R_IC2R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_IC3_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _IC3R_IC3R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_IC4_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _IC4R_IC4R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_IC5_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _IC5R_IC5R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_IC6_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _IC6R_IC6R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_IC7_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _IC7R_IC7R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_IC8_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _IC8R_IC8R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_IC9_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _IC9R_IC9R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_OCFA_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _OCFAR_OCFAR_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_U1RX_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _U1RXR_U1RXR_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_U1CTS_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _U1CTSR_U1CTSR_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_U2RX_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _U2RXR_U2RXR_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_U2CTS_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _U2CTSR_U2CTSR_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_U3RX_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _U3RXR_U3RXR_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_U3CTS_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _U3CTSR_U3CTSR_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_U4RX_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _U4RXR_U4RXR_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_U4CTS_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _U4CTSR_U4CTSR_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_U5RX_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _U5RXR_U5RXR_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_U5CTS_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _U5CTSR_U5CTSR_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_U6RX_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _U6RXR_U6RXR_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_U6CTS_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _U6CTSR_U6CTSR_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_SDI1_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _SDI1R_SDI1R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_SS1_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _SS1R_SS1R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_SDI2_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _SDI2R_SDI2R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_SS2_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _SS2R_SS2R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_SDI3_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _SDI3R_SDI3R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_SS3_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _SS3R_SS3R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_SDI4_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _SDI4R_SDI4R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_SS4_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _SS4R_SS4R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_SDI5_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _SDI5R_SDI5R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_SS5_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _SS5R_SS5R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_SDI6_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _SDI6R_SDI6R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_SS6_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _SS6R_SS6R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_C1RX_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _C1RXR_C1RXR_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_C2RX_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _C2RXR_C2RXR_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_REFCLKI1_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _REFCLKI1R_REFCLKI1R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPA14_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPA14R_RPA14R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPA15_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPA15R_RPA15R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPB0_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPB0R_RPB0R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPB1_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPB1R_RPB1R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPB2_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPB2R_RPB2R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPB3_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPB3R_RPB3R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPB5_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPB5R_RPB5R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPB6_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPB6R_RPB6R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPB7_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPB7R_RPB7R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPB8_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPB8R_RPB8R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPB9_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPB9R_RPB9R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPB10_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPB10R_RPB10R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPB14_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPB14R_RPB14R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPB15_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPB15R_RPB15R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPC1_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPC1R_RPC1R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPC2_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPC2R_RPC2R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPC3_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPC3R_RPC3R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPC4_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPC4R_RPC4R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPC13_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPC13R_RPC13R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPC14_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPC14R_RPC14R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPD1_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPD1R_RPD1R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPD2_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPD2R_RPD2R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPD3_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPD3R_RPD3R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPD4_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPD4R_RPD4R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPD5_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPD5R_RPD5R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPD6_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPD6R_RPD6R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPD7_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPD7R_RPD7R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPD9_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPD9R_RPD9R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPD10_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPD10R_RPD10R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPD11_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPD11R_RPD11R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPD12_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPD12R_RPD12R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPD14_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPD14R_RPD14R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPD15_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPD15R_RPD15R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPE3_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPE3R_RPE3R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPE5_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPE5R_RPE5R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPE8_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPE8R_RPE8R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPE9_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPE9R_RPE9R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPF0_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPF0R_RPF0R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPF1_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPF1R_RPF1R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPF2_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPF2R_RPF2R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPF3_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPF3R_RPF3R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPF4_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPF4R_RPF4R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPF5_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPF5R_RPF5R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPF8_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPF8R_RPF8R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPF12_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPF12R_RPF12R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPF13_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPF13R_RPF13R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPG0_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPG0R_RPG0R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPG1_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPG1R_RPG1R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPG6_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPG6R_RPG6R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPG7_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPG7R_RPG7R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPG8_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPG8R_RPG8R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPG9_MASK(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPG9R_RPG9R_MASK;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_READ_A_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_WRITE_A_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_DIRECTION_A_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_OPEN_DRAIN_A_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_MODE_A_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_UP_A_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_A_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_DOWN_A_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_STATUS_A_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_TURN_ON_A_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONA_ON_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_A_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONA_SIDL_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_READ_B_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_WRITE_B_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_DIRECTION_B_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_OPEN_DRAIN_B_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_MODE_B_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_UP_B_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_B_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_DOWN_B_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_STATUS_B_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_TURN_ON_B_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONB_ON_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_B_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONB_SIDL_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_READ_C_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_WRITE_C_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_DIRECTION_C_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_OPEN_DRAIN_C_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_MODE_C_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_UP_C_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_C_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_DOWN_C_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_STATUS_C_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_TURN_ON_C_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONC_ON_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_C_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONC_SIDL_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_READ_D_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_WRITE_D_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_DIRECTION_D_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_OPEN_DRAIN_D_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_MODE_D_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_UP_D_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_D_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_DOWN_D_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_STATUS_D_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_TURN_ON_D_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCOND_ON_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_D_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCOND_SIDL_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_READ_E_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_WRITE_E_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_DIRECTION_E_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_OPEN_DRAIN_E_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_MODE_E_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_UP_E_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_E_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_DOWN_E_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_STATUS_E_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_TURN_ON_E_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONE_ON_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_E_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONE_SIDL_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_READ_F_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_WRITE_F_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_DIRECTION_F_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_OPEN_DRAIN_F_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_MODE_F_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_UP_F_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_F_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_DOWN_F_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_STATUS_F_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_TURN_ON_F_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONF_ON_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_F_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONF_SIDL_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_READ_G_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_WRITE_G_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_DIRECTION_G_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_OPEN_DRAIN_G_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_MODE_G_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_UP_G_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_G_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_DOWN_G_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_STATUS_G_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_TURN_ON_G_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONG_ON_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_G_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONG_SIDL_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_READ_H_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_WRITE_H_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_DIRECTION_H_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_OPEN_DRAIN_H_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_MODE_H_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_UP_H_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_H_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_DOWN_H_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_STATUS_H_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_TURN_ON_H_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONH_ON_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_H_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONH_SIDL_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_READ_J_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_WRITE_J_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_DIRECTION_J_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_OPEN_DRAIN_J_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_MODE_J_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_UP_J_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_J_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_DOWN_J_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_STATUS_J_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_TURN_ON_J_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONJ_ON_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_J_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONJ_SIDL_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_READ_K_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_WRITE_K_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_DIRECTION_K_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_OPEN_DRAIN_K_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_UP_K_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_K_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_DOWN_K_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_STATUS_K_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)0;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_TURN_ON_K_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONK_ON_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_K_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONK_SIDL_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_INT1_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _INT1R_INT1R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_INT2_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _INT2R_INT2R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_INT3_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _INT3R_INT3R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_INT4_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _INT4R_INT4R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_T2CK_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _T2CKR_T2CKR_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_T3CK_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _T3CKR_T3CKR_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_T4CK_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _T4CKR_T4CKR_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_T5CK_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _T5CKR_T5CKR_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_T6CK_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _T6CKR_T6CKR_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_T7CK_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _T7CKR_T7CKR_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_T8CK_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _T8CKR_T8CKR_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_T9CK_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _T9CKR_T9CKR_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_IC1_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _IC1R_IC1R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_IC2_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _IC2R_IC2R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_IC3_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _IC3R_IC3R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_IC4_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _IC4R_IC4R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_IC5_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _IC5R_IC5R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_IC6_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _IC6R_IC6R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_IC7_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _IC7R_IC7R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_IC8_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _IC8R_IC8R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_IC9_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _IC9R_IC9R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_OCFA_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _OCFAR_OCFAR_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_U1RX_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _U1RXR_U1RXR_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_U1CTS_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _U1CTSR_U1CTSR_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_U2RX_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _U2RXR_U2RXR_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_U2CTS_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _U2CTSR_U2CTSR_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_U3RX_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _U3RXR_U3RXR_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_U3CTS_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _U3CTSR_U3CTSR_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_U4RX_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _U4RXR_U4RXR_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_U4CTS_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _U4CTSR_U4CTSR_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_U5RX_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _U5RXR_U5RXR_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_U5CTS_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _U5CTSR_U5CTSR_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_U6RX_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _U6RXR_U6RXR_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_U6CTS_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _U6CTSR_U6CTSR_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_SDI1_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _SDI1R_SDI1R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_SS1_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _SS1R_SS1R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_SDI2_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _SDI2R_SDI2R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_SS2_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _SS2R_SS2R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_SDI3_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _SDI3R_SDI3R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_SS3_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _SS3R_SS3R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_SDI4_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _SDI4R_SDI4R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_SS4_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _SS4R_SS4R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_SDI5_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _SDI5R_SDI5R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_SS5_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _SS5R_SS5R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_SDI6_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _SDI6R_SDI6R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_SS6_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _SS6R_SS6R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_C1RX_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _C1RXR_C1RXR_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_C2RX_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _C2RXR_C2RXR_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_REFCLKI1_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _REFCLKI1R_REFCLKI1R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPA14_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPA14R_RPA14R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPA15_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPA15R_RPA15R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPB0_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPB0R_RPB0R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPB1_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPB1R_RPB1R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPB2_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPB2R_RPB2R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPB3_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPB3R_RPB3R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPB5_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPB5R_RPB5R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPB6_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPB6R_RPB6R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPB7_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPB7R_RPB7R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPB8_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPB8R_RPB8R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPB9_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPB9R_RPB9R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPB10_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPB10R_RPB10R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPB14_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPB14R_RPB14R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPB15_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPB15R_RPB15R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPC1_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPC1R_RPC1R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPC2_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPC2R_RPC2R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPC3_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPC3R_RPC3R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPC4_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPC4R_RPC4R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPC13_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPC13R_RPC13R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPC14_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPC14R_RPC14R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPD1_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPD1R_RPD1R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPD2_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPD2R_RPD2R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPD3_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPD3R_RPD3R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPD4_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPD4R_RPD4R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPD5_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPD5R_RPD5R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPD6_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPD6R_RPD6R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPD7_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPD7R_RPD7R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPD9_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPD9R_RPD9R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPD10_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPD10R_RPD10R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPD11_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPD11R_RPD11R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPD12_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPD12R_RPD12R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPD14_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPD14R_RPD14R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPD15_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPD15R_RPD15R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPE3_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPE3R_RPE3R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPE5_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPE5R_RPE5R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPE8_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPE8R_RPE8R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPE9_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPE9R_RPE9R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPF0_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPF0R_RPF0R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPF1_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPF1R_RPF1R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPF2_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPF2R_RPF2R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPF3_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPF3R_RPF3R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPF4_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPF4R_RPF4R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPF5_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPF5R_RPF5R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPF8_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPF8R_RPF8R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPF12_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPF12R_RPF12R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPF13_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPF13R_RPF13R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPG0_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPG0R_RPG0R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPG1_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPG1R_RPG1R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPG6_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPG6R_RPG6R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPG7_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPG7R_RPG7R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPG8_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPG8R_RPG8R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPG9_POS(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPG9R_RPG9R_POSITION;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_READ_A_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_WRITE_A_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_DIRECTION_A_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_OPEN_DRAIN_A_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_MODE_A_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_UP_A_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_A_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_DOWN_A_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_STATUS_A_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_TURN_ON_A_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONA_ON_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_A_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONA_SIDL_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_READ_B_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_WRITE_B_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_DIRECTION_B_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_OPEN_DRAIN_B_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_MODE_B_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_UP_B_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_B_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_DOWN_B_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_STATUS_B_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_TURN_ON_B_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONB_ON_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_B_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONB_SIDL_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_READ_C_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_WRITE_C_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_DIRECTION_C_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_OPEN_DRAIN_C_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_MODE_C_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_UP_C_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_C_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_DOWN_C_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_STATUS_C_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_TURN_ON_C_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONC_ON_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_C_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONC_SIDL_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_READ_D_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_WRITE_D_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_DIRECTION_D_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_OPEN_DRAIN_D_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_MODE_D_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_UP_D_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_D_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_DOWN_D_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_STATUS_D_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_TURN_ON_D_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCOND_ON_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_D_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCOND_SIDL_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_READ_E_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_WRITE_E_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_DIRECTION_E_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_OPEN_DRAIN_E_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_MODE_E_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_UP_E_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_E_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_DOWN_E_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_STATUS_E_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_TURN_ON_E_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONE_ON_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_E_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONE_SIDL_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_READ_F_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_WRITE_F_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_DIRECTION_F_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_OPEN_DRAIN_F_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_MODE_F_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_UP_F_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_F_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_DOWN_F_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_STATUS_F_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_TURN_ON_F_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONF_ON_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_F_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONF_SIDL_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_READ_G_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_WRITE_G_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_DIRECTION_G_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_OPEN_DRAIN_G_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_MODE_G_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_UP_G_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_G_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_DOWN_G_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_STATUS_G_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_TURN_ON_G_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONG_ON_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_G_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONG_SIDL_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_READ_H_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_WRITE_H_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_DIRECTION_H_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_OPEN_DRAIN_H_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_MODE_H_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_UP_H_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_H_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_DOWN_H_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_STATUS_H_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_TURN_ON_H_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONH_ON_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_H_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONH_SIDL_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_READ_J_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_WRITE_J_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_DIRECTION_J_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_OPEN_DRAIN_J_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_MODE_J_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_UP_J_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_J_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_DOWN_J_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_STATUS_J_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_TURN_ON_J_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONJ_ON_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_J_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONJ_SIDL_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_READ_K_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_WRITE_K_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_DIRECTION_K_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_OPEN_DRAIN_K_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_UP_K_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_K_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_PULL_DOWN_K_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_CHANGE_NOTICE_STATUS_K_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_TURN_ON_K_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONK_ON_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_PIN_CHANGE_NOTICE_IN_IDLE_K_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _CNCONK_SIDL_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_INT1_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _INT1R_INT1R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_INT2_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _INT2R_INT2R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_INT3_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _INT3R_INT3R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_INT4_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _INT4R_INT4R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_T2CK_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _T2CKR_T2CKR_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_T3CK_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _T3CKR_T3CKR_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_T4CK_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _T4CKR_T4CKR_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_T5CK_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _T5CKR_T5CKR_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_T6CK_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _T6CKR_T6CKR_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_T7CK_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _T7CKR_T7CKR_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_T8CK_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _T8CKR_T8CKR_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_T9CK_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _T9CKR_T9CKR_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_IC1_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _IC1R_IC1R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_IC2_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _IC2R_IC2R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_IC3_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _IC3R_IC3R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_IC4_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _IC4R_IC4R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_IC5_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _IC5R_IC5R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_IC6_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _IC6R_IC6R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_IC7_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _IC7R_IC7R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_IC8_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _IC8R_IC8R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_IC9_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _IC9R_IC9R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_OCFA_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _OCFAR_OCFAR_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_U1RX_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _U1RXR_U1RXR_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_U1CTS_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _U1CTSR_U1CTSR_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_U2RX_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _U2RXR_U2RXR_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_U2CTS_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _U2CTSR_U2CTSR_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_U3RX_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _U3RXR_U3RXR_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_U3CTS_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _U3CTSR_U3CTSR_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_U4RX_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _U4RXR_U4RXR_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_U4CTS_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _U4CTSR_U4CTSR_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_U5RX_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _U5RXR_U5RXR_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_U5CTS_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _U5CTSR_U5CTSR_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_U6RX_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _U6RXR_U6RXR_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_U6CTS_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _U6CTSR_U6CTSR_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_SDI1_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _SDI1R_SDI1R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_SS1_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _SS1R_SS1R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_SDI2_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _SDI2R_SDI2R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_SS2_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _SS2R_SS2R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_SDI3_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _SDI3R_SDI3R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_SS3_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _SS3R_SS3R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_SDI4_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _SDI4R_SDI4R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_SS4_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _SS4R_SS4R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_SDI5_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _SDI5R_SDI5R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_SS5_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _SS5R_SS5R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_SDI6_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _SDI6R_SDI6R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_SS6_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _SS6R_SS6R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_C1RX_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _C1RXR_C1RXR_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_C2RX_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _C2RXR_C2RXR_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_FUNC_REFCLKI1_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _REFCLKI1R_REFCLKI1R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPA14_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPA14R_RPA14R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPA15_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPA15R_RPA15R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPB0_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPB0R_RPB0R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPB1_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPB1R_RPB1R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPB2_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPB2R_RPB2R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPB3_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPB3R_RPB3R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPB5_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPB5R_RPB5R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPB6_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPB6R_RPB6R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPB7_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPB7R_RPB7R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPB8_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPB8R_RPB8R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPB9_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPB9R_RPB9R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPB10_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPB10R_RPB10R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPB14_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPB14R_RPB14R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPB15_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPB15R_RPB15R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPC1_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPC1R_RPC1R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPC2_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPC2R_RPC2R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPC3_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPC3R_RPC3R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPC4_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPC4R_RPC4R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPC13_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPC13R_RPC13R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPC14_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPC14R_RPC14R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPD1_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPD1R_RPD1R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPD2_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPD2R_RPD2R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPD3_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPD3R_RPD3R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPD4_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPD4R_RPD4R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPD5_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPD5R_RPD5R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPD6_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPD6R_RPD6R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPD7_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPD7R_RPD7R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPD9_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPD9R_RPD9R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPD10_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPD10R_RPD10R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPD11_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPD11R_RPD11R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPD12_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPD12R_RPD12R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPD14_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPD14R_RPD14R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPD15_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPD15R_RPD15R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPE3_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPE3R_RPE3R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPE5_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPE5R_RPE5R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPE8_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPE8R_RPE8R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPE9_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPE9R_RPE9R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPF0_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPF0R_RPF0R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPF1_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPF1R_RPF1R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPF2_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPF2R_RPF2R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPF3_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPF3R_RPF3R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPF4_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPF4R_RPF4R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPF5_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPF5R_RPF5R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPF8_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPF8R_RPF8R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPF12_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPF12R_RPF12R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPF13_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPF13R_RPF13R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPG0_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPG0R_RPG0R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPG1_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPG1R_RPG1R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPG6_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPG6R_RPG6R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPG7_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPG7R_RPG7R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPG8_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPG8R_RPG8R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _PORTS_REMAP_PIN_RPG9_LEN(PORTS_MODULE_ID i)
{
    switch (i) {
        case PORTS_ID_0 :
            return _RPG9R_RPG9R_LENGTH;
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

/* Section 2 - Feature variant inclusion */

#define PLIB_TEMPLATE PLIB_INLINE
#include "../templates/ports_RemapInput_default.h"
#include "../templates/ports_RemapOutput_PIC32_1.h"
#include "../templates/ports_PinMode_PPS.h"
#include "../templates/ports_AnPinsMode_Unsupported.h"
#include "../templates/ports_PortsRead_MCU32_PPS.h"
#include "../templates/ports_LatchRead_MCU32_PPS.h"
#include "../templates/ports_PortsWrite_MCU32_PPS.h"
#include "../templates/ports_PortsDirection_MCU32_PPS.h"
#include "../templates/ports_PortsOpenDrain_MCU32_PPS.h"
#include "../templates/ports_ChangeNotice_Unsupported.h"
#include "../templates/ports_PinChangeNotice_Unsupported.h"
#include "../templates/ports_ChangeNoticeInIdle_Unsupported.h"
#include "../templates/ports_ChangeNoticePullup_Unsupported.h"
#include "../templates/ports_PinModePerPort_Default.h"
#include "../templates/ports_ChangeNoticePullDownPerPort_Default.h"
#include "../templates/ports_ChangeNoticePullUpPerPort_Default.h"
#include "../templates/ports_PinChangeNoticePerPort_Default.h"
#include "../templates/ports_ChangeNoticePerPortTurnOn_Default.h"
#include "../templates/ports_ChangeNoticeInIdlePerPort_Default.h"
#include "../templates/ports_ChangeNoticePerPortStatus_Default.h"
#include "../templates/ports_SlewRateControl_Unsupported.h"
#include "../templates/ports_ChannelChangeNoticeMethod_Unsupported.h"
#include "../templates/ports_ChangeNoticeEdgeControl_Unsupported.h"
#include "../templates/ports_ChangeNoticeEdgeStatus_Unsupported.h"

/* Section 3 - PLIB dispatch function definitions */

PLIB_INLINE_API void PLIB_PORTS_RemapInput(PORTS_MODULE_ID index, PORTS_REMAP_INPUT_FUNCTION inputFunction, PORTS_REMAP_INPUT_PIN remapInputPin)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_RemapInput_default(index, inputFunction, remapInputPin);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_PORTS_ExistsRemapInput(PORTS_MODULE_ID index)
{
    switch (index) {
        case PORTS_ID_0 :
            return PORTS_ExistsRemapInput_default(index);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_PORTS_RemapOutput(PORTS_MODULE_ID index, PORTS_REMAP_OUTPUT_FUNCTION outputFunction, PORTS_REMAP_OUTPUT_PIN remapOutputPin)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_RemapOutput_PIC32_1(index, outputFunction, remapOutputPin);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_PORTS_ExistsRemapOutput(PORTS_MODULE_ID index)
{
    switch (index) {
        case PORTS_ID_0 :
            return PORTS_ExistsRemapOutput_PIC32_1(index);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_PORTS_PinModeSelect(PORTS_MODULE_ID index, PORTS_ANALOG_PIN pin, PORTS_PIN_MODE mode)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_PinModeSelect_PPS(index, pin, mode);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_PORTS_ExistsPinMode(PORTS_MODULE_ID index)
{
    switch (index) {
        case PORTS_ID_0 :
            return PORTS_ExistsPinMode_PPS(index);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PORTS_AnPinsModeSelect(PORTS_MODULE_ID index, PORTS_AN_PIN anPins, PORTS_PIN_MODE mode)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_AnPinsModeSelect_Unsupported(index, anPins, mode);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_PORTS_ExistsAnPinsMode(PORTS_MODULE_ID index)
{
    switch (index) {
        case PORTS_ID_0 :
            return PORTS_ExistsAnPinsMode_Unsupported(index);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_PORTS_PinGet(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_BIT_POS bitPos)
{
    switch (index) {
        case PORTS_ID_0 :
            return PORTS_PinGet_MCU32_PPS(index, channel, bitPos);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API PORTS_DATA_TYPE PLIB_PORTS_Read(PORTS_MODULE_ID index, PORTS_CHANNEL channel)
{
    switch (index) {
        case PORTS_ID_0 :
            return PORTS_Read_MCU32_PPS(index, channel);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (PORTS_DATA_TYPE)0;
    }
}

PLIB_INLINE_API bool PLIB_PORTS_ExistsPortsRead(PORTS_MODULE_ID index)
{
    switch (index) {
        case PORTS_ID_0 :
            return PORTS_ExistsPortsRead_MCU32_PPS(index);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_PORTS_PinGetLatched(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_BIT_POS bitPos)
{
    switch (index) {
        case PORTS_ID_0 :
            return PORTS_PinGetLatched_MCU32_PPS(index, channel, bitPos);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API PORTS_DATA_TYPE PLIB_PORTS_ReadLatched(PORTS_MODULE_ID index, PORTS_CHANNEL channel)
{
    switch (index) {
        case PORTS_ID_0 :
            return PORTS_ReadLatched_MCU32_PPS(index, channel);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (PORTS_DATA_TYPE)0;
    }
}

PLIB_INLINE_API bool PLIB_PORTS_ExistsLatchRead(PORTS_MODULE_ID index)
{
    switch (index) {
        case PORTS_ID_0 :
            return PORTS_ExistsLatchRead_MCU32_PPS(index);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_PORTS_PinWrite(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_BIT_POS bitPos, bool value)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_PinWrite_MCU32_PPS(index, channel, bitPos, value);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_PORTS_PinSet(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_BIT_POS bitPos)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_PinSet_MCU32_PPS(index, channel, bitPos);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_PORTS_PinClear(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_BIT_POS bitPos)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_PinClear_MCU32_PPS(index, channel, bitPos);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_PORTS_PinToggle(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_BIT_POS bitPos)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_PinToggle_MCU32_PPS(index, channel, bitPos);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_PORTS_Write(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_DATA_TYPE value)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_Write_MCU32_PPS(index, channel, value);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_PORTS_Set(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_DATA_TYPE value, PORTS_DATA_MASK mask)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_Set_MCU32_PPS(index, channel, value, mask);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_PORTS_Toggle(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_DATA_MASK toggleMask)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_Toggle_MCU32_PPS(index, channel, toggleMask);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_PORTS_Clear(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_DATA_MASK clearMask)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_Clear_MCU32_PPS(index, channel, clearMask);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_PORTS_ExistsPortsWrite(PORTS_MODULE_ID index)
{
    switch (index) {
        case PORTS_ID_0 :
            return PORTS_ExistsPortsWrite_MCU32_PPS(index);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_PORTS_PinDirectionInputSet(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_BIT_POS bitPos)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_PinDirectionInputSet_MCU32_PPS(index, channel, bitPos);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_PORTS_PinDirectionOutputSet(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_BIT_POS bitPos)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_PinDirectionOutputSet_MCU32_PPS(index, channel, bitPos);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_PORTS_DirectionInputSet(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_DATA_MASK mask)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_DirectionInputSet_MCU32_PPS(index, channel, mask);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_PORTS_DirectionOutputSet(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_DATA_MASK mask)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_DirectionOutputSet_MCU32_PPS(index, channel, mask);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API PORTS_DATA_MASK PLIB_PORTS_DirectionGet(PORTS_MODULE_ID index, PORTS_CHANNEL channel)
{
    switch (index) {
        case PORTS_ID_0 :
            return PORTS_DirectionGet_MCU32_PPS(index, channel);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (PORTS_DATA_MASK)0;
    }
}

PLIB_INLINE_API bool PLIB_PORTS_ExistsPortsDirection(PORTS_MODULE_ID index)
{
    switch (index) {
        case PORTS_ID_0 :
            return PORTS_ExistsPortsDirection_MCU32_PPS(index);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_PORTS_PinOpenDrainEnable(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_BIT_POS bitPos)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_PinOpenDrainEnable_MCU32_PPS(index, channel, bitPos);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_PORTS_PinOpenDrainDisable(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_BIT_POS bitPos)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_PinOpenDrainDisable_MCU32_PPS(index, channel, bitPos);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_PORTS_OpenDrainEnable(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_DATA_MASK mask)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_OpenDrainEnable_MCU32_PPS(index, channel, mask);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_PORTS_OpenDrainDisable(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_DATA_MASK mask)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_OpenDrainDisable_MCU32_PPS(index, channel, mask);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_PORTS_ExistsPortsOpenDrain(PORTS_MODULE_ID index)
{
    switch (index) {
        case PORTS_ID_0 :
            return PORTS_ExistsPortsOpenDrain_MCU32_PPS(index);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PORTS_ChangeNoticeEnable(PORTS_MODULE_ID index)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_ChangeNoticeEnable_Unsupported(index);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PORTS_ChangeNoticeDisable(PORTS_MODULE_ID index)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_ChangeNoticeDisable_Unsupported(index);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_PORTS_ExistsChangeNotice(PORTS_MODULE_ID index)
{
    switch (index) {
        case PORTS_ID_0 :
            return PORTS_ExistsChangeNotice_Unsupported(index);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PORTS_PinChangeNoticeEnable(PORTS_MODULE_ID index, PORTS_CHANGE_NOTICE_PIN pinNum)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_PinChangeNoticeEnable_Unsupported(index, pinNum);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PORTS_PinChangeNoticeDisable(PORTS_MODULE_ID index, PORTS_CHANGE_NOTICE_PIN pinNum)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_PinChangeNoticeDisable_Unsupported(index, pinNum);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PORTS_CnPinsEnable(PORTS_MODULE_ID index, PORTS_CN_PIN cnPins)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_CnPinsEnable_Unsupported(index, cnPins);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PORTS_CnPinsDisable(PORTS_MODULE_ID index, PORTS_CN_PIN cnPins)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_CnPinsDisable_Unsupported(index, cnPins);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_PORTS_ExistsPinChangeNotice(PORTS_MODULE_ID index)
{
    switch (index) {
        case PORTS_ID_0 :
            return PORTS_ExistsPinChangeNotice_Unsupported(index);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PORTS_ChangeNoticeInIdleEnable(PORTS_MODULE_ID index)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_ChangeNoticeInIdleEnable_Unsupported(index);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PORTS_ChangeNoticeInIdleDisable(PORTS_MODULE_ID index)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_ChangeNoticeInIdleDisable_Unsupported(index);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_PORTS_ExistsChangeNoticeInIdle(PORTS_MODULE_ID index)
{
    switch (index) {
        case PORTS_ID_0 :
            return PORTS_ExistsChangeNoticeInIdle_Unsupported(index);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PORTS_ChangeNoticePullUpEnable(PORTS_MODULE_ID index, PORTS_CHANGE_NOTICE_PIN pinNum)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_ChangeNoticePullUpEnable_Unsupported(index, pinNum);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PORTS_ChangeNoticePullUpDisable(PORTS_MODULE_ID index, PORTS_CHANGE_NOTICE_PIN pinNum)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_ChangeNoticePullUpDisable_Unsupported(index, pinNum);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PORTS_CnPinsPullUpEnable(PORTS_MODULE_ID index, PORTS_CN_PIN cnPins)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_CnPinsPullUpEnable_Unsupported(index, cnPins);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PORTS_CnPinsPullUpDisable(PORTS_MODULE_ID index, PORTS_CN_PIN cnPins)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_CnPinsPullUpDisable_Unsupported(index, cnPins);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_PORTS_ExistsChangeNoticePullUp(PORTS_MODULE_ID index)
{
    switch (index) {
        case PORTS_ID_0 :
            return PORTS_ExistsChangeNoticePullUp_Unsupported(index);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_PORTS_PinModePerPortSelect(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_BIT_POS bitPos, PORTS_PIN_MODE mode)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_PinModePerPortSelect_Default(index, channel, bitPos, mode);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_PORTS_ChannelModeSelect(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_DATA_MASK modeMask, PORTS_PIN_MODE mode)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_ChannelModeSelect_Default(index, channel, modeMask, mode);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_PORTS_ExistsPinModePerPort(PORTS_MODULE_ID index)
{
    switch (index) {
        case PORTS_ID_0 :
            return PORTS_ExistsPinModePerPort_Default(index);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_PORTS_ChangeNoticePullDownPerPortEnable(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_BIT_POS bitPos)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_ChangeNoticePullDownPerPortEnable_Default(index, channel, bitPos);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_PORTS_ChangeNoticePullDownPerPortDisable(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_BIT_POS bitPos)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_ChangeNoticePullDownPerPortDisable_Default(index, channel, bitPos);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_PORTS_ChannelChangeNoticePullDownEnable(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_DATA_MASK mask)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_ChannelChangeNoticePullDownEnable_Default(index, channel, mask);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_PORTS_ChannelChangeNoticePullDownDisable(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_DATA_MASK mask)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_ChannelChangeNoticePullDownDisable_Default(index, channel, mask);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_PORTS_ExistsChangeNoticePullDownPerPort(PORTS_MODULE_ID index)
{
    switch (index) {
        case PORTS_ID_0 :
            return PORTS_ExistsChangeNoticePullDownPerPort_Default(index);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_PORTS_ChangeNoticePullUpPerPortEnable(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_BIT_POS bitPos)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_ChangeNoticePullUpPerPortEnable_Default(index, channel, bitPos);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_PORTS_ChangeNoticePullUpPerPortDisable(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_BIT_POS bitPos)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_ChangeNoticePullUpPerPortDisable_Default(index, channel, bitPos);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_PORTS_ChannelChangeNoticePullUpEnable(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_DATA_MASK mask)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_ChannelChangeNoticePullUpEnable_Default(index, channel, mask);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_PORTS_ChannelChangeNoticePullUpDisable(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_DATA_MASK mask)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_ChannelChangeNoticePullUpDisable_Default(index, channel, mask);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_PORTS_ExistsChangeNoticePullUpPerPort(PORTS_MODULE_ID index)
{
    switch (index) {
        case PORTS_ID_0 :
            return PORTS_ExistsChangeNoticePullUpPerPort_Default(index);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_PORTS_PinChangeNoticePerPortEnable(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_BIT_POS bitPos)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_PinChangeNoticePerPortEnable_Default(index, channel, bitPos);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_PORTS_PinChangeNoticePerPortDisable(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_BIT_POS bitPos)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_PinChangeNoticePerPortDisable_Default(index, channel, bitPos);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_PORTS_ChannelChangeNoticeEnable(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_DATA_MASK mask)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_ChannelChangeNoticeEnable_Default(index, channel, mask);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_PORTS_ChannelChangeNoticeDisable(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_DATA_MASK mask)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_ChannelChangeNoticeDisable_Default(index, channel, mask);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_PORTS_ExistsPinChangeNoticePerPort(PORTS_MODULE_ID index)
{
    switch (index) {
        case PORTS_ID_0 :
            return PORTS_ExistsPinChangeNoticePerPort_Default(index);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_PORTS_ChangeNoticePerPortTurnOn(PORTS_MODULE_ID index, PORTS_CHANNEL channel)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_ChangeNoticePerPortTurnOn_Default(index, channel);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_PORTS_ChangeNoticePerPortTurnOff(PORTS_MODULE_ID index, PORTS_CHANNEL channel)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_ChangeNoticePerPortTurnOff_Default(index, channel);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_PORTS_ExistsChangeNoticePerPortTurnOn(PORTS_MODULE_ID index)
{
    switch (index) {
        case PORTS_ID_0 :
            return PORTS_ExistsChangeNoticePerPortTurnOn_Default(index);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_PORTS_ChangeNoticeInIdlePerPortEnable(PORTS_MODULE_ID index, PORTS_CHANNEL channel)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_ChangeNoticeInIdlePerPortEnable_Default(index, channel);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_PORTS_ChangeNoticeInIdlePerPortDisable(PORTS_MODULE_ID index, PORTS_CHANNEL channel)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_ChangeNoticeInIdlePerPortDisable_Default(index, channel);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_PORTS_ExistsChangeNoticePerPortInIdle(PORTS_MODULE_ID index)
{
    switch (index) {
        case PORTS_ID_0 :
            return PORTS_ExistsChangeNoticePerPortInIdle_Default(index);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_PORTS_ChangeNoticePerPortHasOccured(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_BIT_POS bitPos)
{
    switch (index) {
        case PORTS_ID_0 :
            return PORTS_ChangeNoticePerPortHasOccured_Default(index, channel, bitPos);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_PORTS_ChangeNoticePerPortHasOccurred(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_BIT_POS bitPos)
{
    switch (index) {
        case PORTS_ID_0 :
            return PORTS_ChangeNoticePerPortHasOccurred_Default(index, channel, bitPos);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_PORTS_ExistsChangeNoticePerPortStatus(PORTS_MODULE_ID index)
{
    switch (index) {
        case PORTS_ID_0 :
            return PORTS_ExistsChangeNoticePerPortStatus_Default(index);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PORTS_ChannelSlewRateSelect(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_DATA_MASK channelMask, PORTS_PIN_SLEW_RATE slewRate)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_ChannelSlewRateSelect_Unsupported(index, channel, channelMask, slewRate);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API PORTS_PIN_SLEW_RATE _PLIB_UNSUPPORTED PLIB_PORTS_PinSlewRateGet(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_BIT_POS bitPos)
{
    switch (index) {
        case PORTS_ID_0 :
            return PORTS_PinSlewRateGet_Unsupported(index, channel, bitPos);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (PORTS_PIN_SLEW_RATE)0;
    }
}

PLIB_INLINE_API bool PLIB_PORTS_ExistsSlewRateControl(PORTS_MODULE_ID index)
{
    switch (index) {
        case PORTS_ID_0 :
            return PORTS_ExistsSlewRateControl_Unsupported(index);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PORTS_ChannelChangeNoticeMethodSelect(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_CHANGE_NOTICE_METHOD changeNoticeMethod)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_ChannelChangeNoticeMethodSelect_Unsupported(index, channel, changeNoticeMethod);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API PORTS_CHANGE_NOTICE_METHOD _PLIB_UNSUPPORTED PLIB_PORTS_ChannelChangeNoticeMethodGet(PORTS_MODULE_ID index, PORTS_CHANNEL channel)
{
    switch (index) {
        case PORTS_ID_0 :
            return PORTS_ChannelChangeNoticeMethodGet_Unsupported(index, channel);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (PORTS_CHANGE_NOTICE_METHOD)0;
    }
}

PLIB_INLINE_API bool PLIB_PORTS_ExistsChannelChangeNoticeMethod(PORTS_MODULE_ID index)
{
    switch (index) {
        case PORTS_ID_0 :
            return PORTS_ExistsChannelChangeNoticeMethod_Unsupported(index);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PORTS_ChannelChangeNoticeEdgeEnable(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_DATA_MASK edgeRisingMask, PORTS_DATA_MASK edgeFallingMask)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_ChannelChangeNoticeEdgeEnable_Unsupported(index, channel, edgeRisingMask, edgeFallingMask);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_PORTS_ChannelChangeNoticeEdgeDisable(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_DATA_MASK edgeRisingMask, PORTS_DATA_MASK edgeFallingMask)
{
    switch (index) {
        case PORTS_ID_0 :
            PORTS_ChannelChangeNoticeEdgeDisable_Unsupported(index, channel, edgeRisingMask, edgeFallingMask);
            break;
        case PORTS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_PORTS_PinChangeNoticeEdgeIsEnabled(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_BIT_POS bitPos, PORTS_CHANGE_NOTICE_EDGE cnEdgeType)
{
    switch (index) {
        case PORTS_ID_0 :
            return PORTS_PinChangeNoticeEdgeIsEnabled_Unsupported(index, channel, bitPos, cnEdgeType);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_PORTS_ExistsChangeNoticeEdgeControl(PORTS_MODULE_ID index)
{
    switch (index) {
        case PORTS_ID_0 :
            return PORTS_ExistsChangeNoticeEdgeControl_Unsupported(index);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_PORTS_PinChangeNoticeEdgeHasOccurred(PORTS_MODULE_ID index, PORTS_CHANNEL channel, PORTS_BIT_POS bitPos)
{
    switch (index) {
        case PORTS_ID_0 :
            return PORTS_PinChangeNoticeEdgeHasOccurred_Unsupported(index, channel, bitPos);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_PORTS_ExistsChangeNoticeEdgeStatus(PORTS_MODULE_ID index)
{
    switch (index) {
        case PORTS_ID_0 :
            return PORTS_ExistsChangeNoticeEdgeStatus_Unsupported(index);
        case PORTS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

#endif
