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
const uint8_t	digital_pin_to_port_PGM[] = {
    // Main outer pins
    NOT_A_PIN,          // 0    - no pin
    NOT_A_PIN,          // 1    - VSYS
    NOT_A_PIN,          // 2    - GND
    _IOPORT_PB,         // 3    - RB15
    _IOPORT_PB,         // 4    - RB14
    _IOPORT_PB,         // 5    - RB13
    _IOPORT_PB,         // 6    - RB11
    _IOPORT_PB,         // 7    - RB10
    _IOPORT_PB,         // 8    - RB9
    _IOPORT_PB,         // 9    - RB8
    _IOPORT_PA,         // 10   - A14
    _IOPORT_PA,         // 11   - A15
    _IOPORT_PE,         // 12   - E9
    _IOPORT_PE,         // 13   - E8
    _IOPORT_PF,         // 14   - F12
    _IOPORT_PD,         // 15   - D9
    _IOPORT_PD,         // 16   - D8
    _IOPORT_PA,         // 17   - A4
    _IOPORT_PA,         // 18   - A9
    _IOPORT_PF,         // 19   - F3
    _IOPORT_PA,         // 20   - A0
    _IOPORT_PE,         // 21   - E6
    _IOPORT_PG,         // 22   - G6  - SCK   // NOTE: SHARED
    _IOPORT_PG,         // 23   - G7  - MISO  // NOTE: SHARED
    _IOPORT_PG,         // 24   - G8  - MOSI  // NOTE: SHARED
    NOT_A_PIN,          // 25   - 3.3V
    NOT_A_PIN,          // 26   - GND

    NOT_A_PIN,          // 27   - RESET
    NOT_A_PIN,          // 28   - GND
    NOT_A_PIN,          // 29   - NC
    NOT_A_PIN,          // 30   - NC
    _IOPORT_PD,         // 31   - D1
    _IOPORT_PD,         // 32   - D2
    _IOPORT_PD,         // 33   - D3
    _IOPORT_PD,         // 34   - D0  - INT0   // NOTE: SHARED
    _IOPORT_PD,         // 35   - D12
    _IOPORT_PD,         // 36   - D13
    _IOPORT_PD,         // 37   - D5
    _IOPORT_PD,         // 38   - D6
    _IOPORT_PD,         // 39   - D7
    _IOPORT_PF,         // 40   - F0
    _IOPORT_PF,         // 41   - F1
    _IOPORT_PG,         // 42   - G0
    _IOPORT_PA,         // 43   - A6
    _IOPORT_PA,         // 44   - A7
    _IOPORT_PE,         // 45   - E0
    _IOPORT_PG,         // 46   - G14
    _IOPORT_PF,         // 47   - F4
    _IOPORT_PF,         // 48   - F5
    _IOPORT_PA,         // 49   - A2  - SCL   // NOTE: SHARED
    _IOPORT_PA,         // 50   - A3  - SDA   // NOTE: SHARED
    NOT_A_PIN,          // 51   - 3.3V
    NOT_A_PIN,          // 52   - GND

    // Click 1
    _IOPORT_PB,         // 53   - B0  - AN
    _IOPORT_PE,         // 54   - E2  - RST
    _IOPORT_PG,         // 55   - G13 - CS
    _IOPORT_PG,         // 56   - G6  - SCK   // NOTE: SHARED
    _IOPORT_PG,         // 57   - G7  - MISO  // NOTE: SHARED
    _IOPORT_PG,         // 58   - G8  - MOSI  // NOTE: SHARED
    NOT_A_PIN,          // 59   - 3.3V
    NOT_A_PIN,          // 60   - GND

    _IOPORT_PD,         // 61   - D4  - PWM
    _IOPORT_PE,         // 62   - E8  - INT
    _IOPORT_PF,         // 63   - F2  - RX
    _IOPORT_PF,         // 64   - F8  - TX
    _IOPORT_PA,         // 65   - A2  - SCL   // NOTE: SHARED
    _IOPORT_PA,         // 66   - A3  - SDA   // NOTE: SHARED
    NOT_A_PIN,          // 67   - 5V
    NOT_A_PIN,          // 68   - GND
    
    // Click 2
    _IOPORT_PB,         // 69   - B4  - AN
    _IOPORT_PB,         // 70   - B2  - RST
    _IOPORT_PB,         // 71   - B1  - CS
    _IOPORT_PG,         // 72   - G6  - SCK   // NOTE: SHARED
    _IOPORT_PG,         // 73   - G7  - MISO  // NOTE: SHARED
    _IOPORT_PG,         // 74   - G8  - MOSI  // NOTE: SHARED
    NOT_A_PIN,          // 75   - 3.3V
    NOT_A_PIN,          // 76   - GND

    _IOPORT_PD,         // 77   - D0  - PWM   // NOTE: SHARED
    _IOPORT_PE,         // 78   - E9  - INT
    _IOPORT_PF,         // 79   - F4  - RX    // NOTE: SHARED
    _IOPORT_PF,         // 80   - F5  - TX    // NOTE: SHARED
    _IOPORT_PA,         // 81   - A2  - SCL   // NOTE: SHARED
    _IOPORT_PA,         // 82   - A3  - SDA   // NOTE: SHARED
    NOT_A_PIN,          // 83   - 5V
    NOT_A_PIN,          // 84   - GND

    // LEDs

    _IOPORT_PE,         // 85   - E3  - LD1
    _IOPORT_PA,         // 86   - A10 - LD2

    // Buttons

    _IOPORT_PE,         // 87   - E4  - BTN1
    _IOPORT_PG,         // 88   - G9  - BTN2

    // Battery monitor
    _IOPORT_PF,         // 89   - F13 - SENSEL
    _IOPORT_PB,         // 90   - B12 - VSENSE
    _IOPORT_PG,         // 91   - G15 - STAT
};

/* ------------------------------------------------------------ */
/* This table is used to map from digital pin number to a bit mask
** for the corresponding bit within the port.
*/
const uint16_t	digital_pin_to_bit_mask_PGM[] = {
    // Main outer pins
    NOT_A_PIN,          // 0    - no pin
    NOT_A_PIN,          // 1    - VSYS
    NOT_A_PIN,          // 2    - GND
    _BV(15 ),           // 3    - RB15
    _BV(14 ),           // 4    - RB14
    _BV(13 ),           // 5    - RB13
    _BV(11 ),           // 6    - RB11
    _BV(10 ),           // 7    - RB10
    _BV( 9 ),           // 8    - RB9
    _BV( 8 ),           // 9    - RB8
    _BV(14 ),           // 10   - A14
    _BV(15 ),           // 11   - A15
    _BV( 9 ),           // 12   - E9
    _BV( 8 ),           // 13   - E8
    _BV(12 ),           // 14   - F12
    _BV( 9 ),           // 15   - D9
    _BV( 8 ),           // 16   - D8
    _BV( 4 ),           // 17   - A4
    _BV( 9 ),           // 18   - A9
    _BV( 3 ),           // 19   - F3
    _BV( 0 ),           // 20   - A0
    _BV( 6 ),           // 21   - E6
    _BV( 6 ),           // 22   - G6  - SCK   // NOTE: SHARED
    _BV( 7 ),           // 23   - G7  - MISO  // NOTE: SHARED
    _BV( 8 ),           // 24   - G8  - MOSI  // NOTE: SHARED
    NOT_A_PIN,          // 25   - 3.3V
    NOT_A_PIN,          // 26   - GND

    NOT_A_PIN,          // 27   - RESET
    NOT_A_PIN,          // 28   - GND
    NOT_A_PIN,          // 29   - NC
    NOT_A_PIN,          // 30   - NC
    _BV( 1 ),           // 31   - D1
    _BV( 2 ),           // 32   - D2
    _BV( 3 ),           // 33   - D3
    _BV( 0 ),           // 34   - D0    // NOTE: SHARED
    _BV(12 ),           // 35   - D12
    _BV(13 ),           // 36   - D13
    _BV( 5 ),           // 37   - D5
    _BV( 6 ),           // 38   - D6
    _BV( 7 ),           // 39   - D7
    _BV( 0 ),           // 40   - F0
    _BV( 1 ),           // 41   - F1
    _BV( 0 ),           // 42   - G0
    _BV( 6 ),           // 43   - A6
    _BV( 7 ),           // 44   - A7
    _BV( 0 ),           // 45   - E0
    _BV(14 ),           // 46   - G14
    _BV( 4 ),           // 47   - F4
    _BV( 5 ),           // 48   - F5
    _BV( 2 ),           // 49   - A2  - SCL   // NOTE: SHARED
    _BV( 3 ),           // 50   - A3  - SDA   // NOTE: SHARED
    NOT_A_PIN,          // 51   - 3.3V
    NOT_A_PIN,          // 52   - GND

    // Click 1
    _BV( 0 ),           // 53   - B0  - AN
    _BV( 2 ),           // 54   - E2  - RST
    _BV(13 ),           // 55   - G13 - CS
    _BV( 6 ),           // 56   - G6  - SCK   // NOTE: SHARED
    _BV( 7 ),           // 57   - G7  - MISO  // NOTE: SHARED
    _BV( 8 ),           // 58   - G8  - MOSI  // NOTE: SHARED
    NOT_A_PIN,          // 59   - 3.3V
    NOT_A_PIN,          // 60   - GND

    _BV( 4 ),           // 61   - D4  - PWM
    _BV( 8 ),           // 62   - E8  - INT
    _BV( 2 ),           // 63   - F2  - RX
    _BV( 8 ),           // 64   - F8  - TX
    _BV( 2 ),           // 65   - A2  - SCL   // NOTE: SHARED
    _BV( 3 ),           // 66   - A3  - SDA   // NOTE: SHARED
    NOT_A_PIN,          // 67   - 5V
    NOT_A_PIN,          // 68   - GND
    
    // Click 2
    _BV( 4 ),           // 69   - B4  - AN
    _BV( 2 ),           // 70   - B2  - RST
    _BV( 1 ),           // 71   - B1  - CS
    _BV( 6 ),           // 72   - G6  - SCK   // NOTE: SHARED
    _BV( 7 ),           // 73   - G7  - MISO  // NOTE: SHARED
    _BV( 8 ),           // 74   - G8  - MOSI  // NOTE: SHARED
    NOT_A_PIN,          // 75   - 3.3V
    NOT_A_PIN,          // 76   - GND

    _BV( 0 ),           // 77   - D0  - PWM   // NOTE: SHARED
    _BV( 9 ),           // 78   - E9  - INT
    _BV( 4 ),           // 79   - F4  - RX    // NOTE: SHARED
    _BV( 5 ),           // 80   - F5  - TX    // NOTE: SHARED
    _BV( 2 ),           // 81   - A2  - SCL   // NOTE: SHARED
    _BV( 3 ),           // 82   - A3  - SDA   // NOTE: SHARED
    NOT_A_PIN,          // 83   - 5V
    NOT_A_PIN,          // 84   - GND

    // LEDs

    _BV( 3 ),           // 85   - E3  - LD1
    _BV(10 ),           // 86   - A10 - LD2

    // Buttons

    _BV( 4 ),           // 87   - E4  - BTN1
    _BV( 9 ),           // 88   - G9  - BTN2

    // Battery monitor
    _BV(13 ),           // 89   - F13 - SENSEL
    _BV(12 ),           // 90   - B12 - VSENSE
    _BV(15 ),           // 91   - G15 - STAT
};

/* ------------------------------------------------------------ */
/* This table is used to map from digital pin number to the output
** compare number, input capture number, and timer external clock
** input associated with that pin.
*/
const uint16_t	digital_pin_to_timer_PGM[] = {

    // Main outer pins
    NOT_ON_TIMER,       // 0    - no pin
    NOT_ON_TIMER,       // 1    - VSYS
    NOT_ON_TIMER,       // 2    - GND
    NOT_ON_TIMER,       // 3    - RB15
    NOT_ON_TIMER,       // 4    - RB14
    NOT_ON_TIMER,       // 5    - RB13
    NOT_ON_TIMER,       // 6    - RB11
    NOT_ON_TIMER,       // 7    - RB10
    NOT_ON_TIMER,       // 8    - RB9
    NOT_ON_TIMER,       // 9    - RB8
    NOT_ON_TIMER,       // 10   - A14
    NOT_ON_TIMER,       // 11   - A15
    NOT_ON_TIMER,       // 12   - E9
    NOT_ON_TIMER,       // 13   - E8
    NOT_ON_TIMER,       // 14   - F12
    NOT_ON_TIMER,       // 15   - D9
    NOT_ON_TIMER,       // 16   - D8
    NOT_ON_TIMER,       // 17   - A4
    NOT_ON_TIMER,       // 18   - A9
    NOT_ON_TIMER,       // 19   - F3
    NOT_ON_TIMER,       // 20   - A0
    NOT_ON_TIMER,       // 21   - E6
    NOT_ON_TIMER,       // 22   - G6  - SCK   // NOTE: SHARED
    NOT_ON_TIMER,       // 23   - G7  - MISO  // NOTE: SHARED
    NOT_ON_TIMER,       // 24   - G8  - MOSI  // NOTE: SHARED
    NOT_ON_TIMER,       // 25   - 3.3V
    NOT_ON_TIMER,       // 26   - GND

    NOT_ON_TIMER,       // 27   - RESET
    NOT_ON_TIMER,       // 28   - GND
    NOT_ON_TIMER,       // 29   - NC
    NOT_ON_TIMER,       // 30   - NC
    _TIMER_OC2,         // 31   - D1
    _TIMER_OC3,         // 32   - D2
    _TIMER_OC4,         // 33   - D3
    _TIMER_OC1,         // 34   - D0    // NOTE: SHARED
    NOT_ON_TIMER,       // 35   - D12
    NOT_ON_TIMER,       // 36   - D13
    NOT_ON_TIMER,       // 37   - D5
    NOT_ON_TIMER,       // 38   - D6
    NOT_ON_TIMER,       // 39   - D7
    NOT_ON_TIMER,       // 40   - F0
    NOT_ON_TIMER,       // 41   - F1
    NOT_ON_TIMER,       // 42   - G0
    NOT_ON_TIMER,       // 43   - A6
    NOT_ON_TIMER,       // 44   - A7
    NOT_ON_TIMER,       // 45   - E0
    NOT_ON_TIMER,       // 46   - G14
    NOT_ON_TIMER,       // 47   - F4
    NOT_ON_TIMER,       // 48   - F5
    NOT_ON_TIMER,       // 49   - A2  - SCL   // NOTE: SHARED
    NOT_ON_TIMER,       // 50   - A3  - SDA   // NOTE: SHARED
    NOT_ON_TIMER,       // 51   - 3.3V
    NOT_ON_TIMER,       // 52   - GND

    // Click 1
    NOT_ON_TIMER,       // 53   - B0  - AN
    NOT_ON_TIMER,       // 54   - E2  - RST
    NOT_ON_TIMER,       // 55   - G13 - CS
    NOT_ON_TIMER,       // 56   - G6  - SCK   // NOTE: SHARED
    NOT_ON_TIMER,       // 57   - G7  - MISO  // NOTE: SHARED
    NOT_ON_TIMER,       // 58   - G8  - MOSI  // NOTE: SHARED
    NOT_ON_TIMER,       // 59   - 3.3V
    NOT_ON_TIMER,       // 60   - GND

    _TIMER_OC5,         // 61   - D4  - PWM
    NOT_ON_TIMER,       // 62   - E8  - INT
    NOT_ON_TIMER,       // 63   - F2  - RX
    NOT_ON_TIMER,       // 64   - F8  - TX
    NOT_ON_TIMER,       // 65   - A2  - SCL   // NOTE: SHARED
    NOT_ON_TIMER,       // 66   - A3  - SDA   // NOTE: SHARED
    NOT_ON_TIMER,       // 67   - 5V
    NOT_ON_TIMER,       // 68   - GND
    
    // Click 2
    NOT_ON_TIMER,       // 69   - B4  - AN
    NOT_ON_TIMER,       // 70   - B2  - RST
    NOT_ON_TIMER,       // 71   - B1  - CS
    NOT_ON_TIMER,       // 72   - G6  - SCK   // NOTE: SHARED
    NOT_ON_TIMER,       // 73   - G7  - MISO  // NOTE: SHARED
    NOT_ON_TIMER,       // 74   - G8  - MOSI  // NOTE: SHARED
    NOT_ON_TIMER,       // 75   - 3.3V
    NOT_ON_TIMER,       // 76   - GND

    _TIMER_OC1,         // 77   - D0  - PWM   // NOTE: SHARED
    NOT_ON_TIMER,       // 78   - E9  - INT
    NOT_ON_TIMER,       // 79   - F4  - RX    // NOTE: SHARED
    NOT_ON_TIMER,       // 80   - F5  - TX    // NOTE: SHARED
    NOT_ON_TIMER,       // 81   - A2  - SCL   // NOTE: SHARED
    NOT_ON_TIMER,       // 82   - A3  - SDA   // NOTE: SHARED
    NOT_ON_TIMER,       // 83   - 5V
    NOT_ON_TIMER,       // 84   - GND

    // LEDs

    NOT_ON_TIMER,       // 85   - E3  - LD1
    NOT_ON_TIMER,       // 86   - A10 - LD2

    // Buttons

    NOT_ON_TIMER,       // 87   - E4  - BTN1
    NOT_ON_TIMER,       // 88   - G9  - BTN2

    // Battery monitor
    NOT_ON_TIMER,       // 89   - F13 - SENSEL
    NOT_ON_TIMER,       // 90   - B12 - VSENSE
    NOT_ON_TIMER,       // 91   - G15 - STAT

};

/* ------------------------------------------------------------ */
/* This table maps from a digital pin number to the corresponding
** analog pin number.
*/
//#if defined(_NOT_USED_)
const uint8_t digital_pin_to_analog_PGM[] = {
    // Main outer pins
    NOT_ANALOG_PIN,     // 0    - no pin
    NOT_ANALOG_PIN,     // 1    - VSYS
    NOT_ANALOG_PIN,     // 2    - GND
    _BOARD_AN15,        // 3    - RB15
    _BOARD_AN14,        // 4    - RB14
    _BOARD_AN13,        // 5    - RB13
    _BOARD_AN11,        // 6    - RB11
    _BOARD_AN10,        // 7    - RB10
    _BOARD_AN9,         // 8    - RB9
    _BOARD_AN8,         // 9    - RB8
    NOT_ANALOG_PIN,     // 10   - A14
    NOT_ANALOG_PIN,     // 11   - A15
    NOT_ANALOG_PIN,     // 12   - E9
    NOT_ANALOG_PIN,     // 13   - E8
    NOT_ANALOG_PIN,     // 14   - F12
    NOT_ANALOG_PIN,     // 15   - D9
    NOT_ANALOG_PIN,     // 16   - D8
    NOT_ANALOG_PIN,     // 17   - A4
    NOT_ANALOG_PIN,     // 18   - A9
    NOT_ANALOG_PIN,     // 19   - F3
    NOT_ANALOG_PIN,     // 20   - A0
    NOT_ANALOG_PIN,     // 21   - E6
    NOT_ANALOG_PIN,     // 22   - G6  - SCK   // NOTE: SHARED
    NOT_ANALOG_PIN,     // 23   - G7  - MISO  // NOTE: SHARED
    NOT_ANALOG_PIN,     // 24   - G8  - MOSI  // NOTE: SHARED
    NOT_ANALOG_PIN,     // 25   - 3.3V
    NOT_ANALOG_PIN,     // 26   - GND

    NOT_ANALOG_PIN,     // 27   - RESET
    NOT_ANALOG_PIN,     // 28   - GND
    NOT_ANALOG_PIN,     // 29   - NC
    NOT_ANALOG_PIN,     // 30   - NC
    NOT_ANALOG_PIN,     // 31   - D1
    NOT_ANALOG_PIN,     // 32   - D2
    NOT_ANALOG_PIN,     // 33   - D3
    NOT_ANALOG_PIN,     // 34   - D0    // NOTE: SHARED
    NOT_ANALOG_PIN,     // 35   - D12
    NOT_ANALOG_PIN,     // 36   - D13
    NOT_ANALOG_PIN,     // 37   - D5
    NOT_ANALOG_PIN,     // 38   - D6
    NOT_ANALOG_PIN,     // 39   - D7
    NOT_ANALOG_PIN,     // 40   - F0
    NOT_ANALOG_PIN,     // 41   - F1
    NOT_ANALOG_PIN,     // 42   - G0
    NOT_ANALOG_PIN,     // 43   - A6
    NOT_ANALOG_PIN,     // 44   - A7
    NOT_ANALOG_PIN,     // 45   - E0
    NOT_ANALOG_PIN,     // 46   - G14
    NOT_ANALOG_PIN,     // 47   - F4
    NOT_ANALOG_PIN,     // 48   - F5
    NOT_ANALOG_PIN,     // 49   - A2  - SCL   // NOTE: SHARED
    NOT_ANALOG_PIN,     // 50   - A3  - SDA   // NOTE: SHARED
    NOT_ANALOG_PIN,     // 51   - 3.3V
    NOT_ANALOG_PIN,     // 52   - GND

    // Click 1
    _BOARD_AN0,         // 53   - B0  - AN
    NOT_ANALOG_PIN,     // 54   - E2  - RST
    NOT_ANALOG_PIN,     // 55   - G13 - CS
    NOT_ANALOG_PIN,     // 56   - G6  - SCK   // NOTE: SHARED
    NOT_ANALOG_PIN,     // 57   - G7  - MISO  // NOTE: SHARED
    NOT_ANALOG_PIN,     // 58   - G8  - MOSI  // NOTE: SHARED
    NOT_ANALOG_PIN,     // 59   - 3.3V
    NOT_ANALOG_PIN,     // 60   - GND

    NOT_ANALOG_PIN,     // 61   - D4  - PWM
    NOT_ANALOG_PIN,     // 62   - E8  - INT
    NOT_ANALOG_PIN,     // 63   - F2  - RX
    NOT_ANALOG_PIN,     // 64   - F8  - TX
    NOT_ANALOG_PIN,     // 65   - A2  - SCL   // NOTE: SHARED
    NOT_ANALOG_PIN,     // 66   - A3  - SDA   // NOTE: SHARED
    NOT_ANALOG_PIN,     // 67   - 5V
    NOT_ANALOG_PIN,     // 68   - GND
    
    // Click 2
    _BOARD_AN4,         // 69   - B4  - AN
    _BOARD_AN2,         // 70   - B2  - RST
    _BOARD_AN1,         // 71   - B1  - CS
    NOT_ANALOG_PIN,     // 72   - G6  - SCK   // NOTE: SHARED
    NOT_ANALOG_PIN,     // 73   - G7  - MISO  // NOTE: SHARED
    NOT_ANALOG_PIN,     // 74   - G8  - MOSI  // NOTE: SHARED
    NOT_ANALOG_PIN,     // 75   - 3.3V
    NOT_ANALOG_PIN,     // 76   - GND

    NOT_ANALOG_PIN,     // 77   - D0  - PWM   // NOTE: SHARED
    NOT_ANALOG_PIN,     // 78   - E9  - INT
    NOT_ANALOG_PIN,     // 79   - F4  - RX    // NOTE: SHARED
    NOT_ANALOG_PIN,     // 80   - F5  - TX    // NOTE: SHARED
    NOT_ANALOG_PIN,     // 81   - A2  - SCL   // NOTE: SHARED
    NOT_ANALOG_PIN,     // 82   - A3  - SDA   // NOTE: SHARED
    NOT_ANALOG_PIN,     // 83   - 5V
    NOT_ANALOG_PIN,     // 84   - GND

    // LEDs

    NOT_ANALOG_PIN,     // 85   - E3  - LD1
    NOT_ANALOG_PIN,     // 86   - A10 - LD2

    // Buttons

    NOT_ANALOG_PIN,     // 87   - E4  - BTN1
    NOT_ANALOG_PIN,     // 88   - G9  - BTN2

    // Battery monitor
    NOT_ANALOG_PIN,     // 89   - F13 - SENSEL
    _BOARD_AN12,        // 90   - B12 - VSENSE
    NOT_ANALOG_PIN,     // 91   - G15 - STAT
};
//#endif

/* ------------------------------------------------------------ */
/* This table is used to map from the analog pin number to the
** actual A/D converter channel used for that pin.
** In the default case, where there is a one-to-one mapping, this
** table isn't needed as the analogInPinToChannel() macro is defined
** to provide the mapping.
*/
#if defined(_NOT_USED_)
const uint8_t analog_pin_to_channel_PGM[] = {
			//*	Arduino Pin		PIC32 Analog channel
	0,		//*	A0				1 to 1 mapping
	1,		//*	A1
	2,		//*	A2
	3,		//*	A3
	4,		//*	A4
	5,		//*	A5
	6,		//*	A6
	7,		//*	A7
	8,		//*	A8
	9,		//*	A9
	10,		//*	A10
	11,		//*	A11
	12,		//*	A12
	13,		//*	A13
	14,		//*	A14
	15,		//*	A15
};
#endif

/* ------------------------------------------------------------ */
/*		Include Files for Board Customization Functions			*/
/* ------------------------------------------------------------ */


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

void _board_init(void) {


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
*/#if	(OPT_BOARD_DIGITAL_IO != 0)

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
