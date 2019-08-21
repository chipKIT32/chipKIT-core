#if !defined(BOARD_DEFS_H)
#define BOARD_DEFS_H

#include <inttypes.h>
#define _USB

#ifndef _TIMER_1_IRQ
#define _TIMER_1_IRQ _TIMER_1_VECTOR
#endif


#undef digitalPinToAnalog
#define digitalPinToAnalog(P) (((P) < NUM_ANALOG_PINS) ? (P) : (digital_pin_to_analog_PGM[P]))

#undef analogInPinToChannel
#define analogInPinToChannel(P) (analog_pin_to_channel_PGM[P])

#if !defined(OPT_BOARD_DATA)

extern const uint32_t   port_to_tris_PGM[];
extern const uint8_t    digital_pin_to_port_PGM[];
extern const uint16_t   digital_pin_to_bit_mask_PGM[];
extern const uint16_t   digital_pin_to_timer_PGM[];

extern const uint8_t    output_compare_to_digital_pin_PGM[];
extern const uint8_t    external_int_to_digital_pin_PGM[];

extern const uint8_t    analog_pin_to_channel_PGM[];
extern const uint8_t    digital_pin_to_analog_PGM[];

extern const uint8_t    digital_pin_to_pps_out_PGM[];
extern const uint8_t    digital_pin_to_pps_in_PGM[];

#endif

#define _BOARD_NAME_ "chipKIT Pro MZ"

#define NUM_DIGITAL_PINS     45
#define NUM_ANALOG_PINS      15
#define NUM_OC_PINS          5
#define NUM_IC_PINS          0
#define NUM_TCK_PINS         0
#define NUM_INT_PINS         5

#define NUM_DIGITAL_PINS_EXTENDED NUM_DIGITAL_PINS
#define NUM_ANALOG_PINS_EXTENDED NUM_ANALOG_PINS

#define NUM_SERIAL_PORTS     2
#define NUM_SPI_PORTS        1
#define NUM_DSPI_PORTS       2
#define NUM_I2C_PORTS        1
#define NUM_DTWI_PORTS       3

#define NUM_LED              1
#define NUM_BTN              1
#define NUM_SWT              0
#define NUM_SERVO            0

#define PIN_BTN1             23

#define PIN_LED1             21

#define PIN_INT0             0
#define PIN_INT1             1
#define PIN_INT2             2
#define PIN_INT3             3
#define PIN_INT4             4

static const uint8_t A0     = 44;
static const uint8_t A1     = 43;
static const uint8_t A2     = 42;
static const uint8_t A3     = 41;
static const uint8_t A4     = 40;
static const uint8_t A5     = 39;
static const uint8_t A6     = 38;
static const uint8_t A7     = 37;
static const uint8_t A8     = 36;
static const uint8_t A9     = 35;
static const uint8_t A10     = 34;
static const uint8_t A11     = 33;
static const uint8_t A12     = 32;
static const uint8_t A13     = 31;
static const uint8_t A14     = 30;

static const uint8_t SS     = 27;
static const uint8_t MOSI   = 26;
static const uint8_t MISO   = 25;
static const uint8_t SCK    = 24;

static const uint8_t PIN_DSPI0_SS     = 27;
static const uint8_t PIN_DSPI0_MOSI   = 26;
static const uint8_t PIN_DSPI0_MISO   = 25;
static const uint8_t PIN_DSPI0_SCK    = 24;

static const uint8_t PIN_DSPI1_SS     = 2;
static const uint8_t PIN_DSPI1_MOSI   = 10;
static const uint8_t PIN_DSPI1_MISO   = 9;
static const uint8_t PIN_DSPI1_SCK    = 8;

#if defined(OPT_BOARD_INTERNAL)
#define OPT_BOARD_INIT          0   //board needs no special init code
#define OPT_BOARD_DIGITAL_IO    0   //board does not extend digital i/o functions
#define OPT_BOARD_ANALOG_READ   0   //board does not extend analogRead
#define OPT_BOARD_ANALOG_WRITE  0   //board does not extend analogWrite

#define _SER0_BASE            _UART1_BASE_ADDRESS
#define _SER0_IRQ             _UART1_FAULT_VECTOR
#define _SER0_VECTOR          _UART1_FAULT_VECTOR
#define _SER0_IPL_ISR         IPL1SRS
#define _SER0_IPL             2
#define _SER0_SPL             0
#define _SER0_TX_OUT          PPS_OUT_U1TX
#define _SER0_TX_PIN          29
#define _SER0_RX_IN           PPS_IN_U1RX
#define _SER0_RX_PIN          28

#define _SER1_BASE            _UART5_BASE_ADDRESS
#define _SER1_IRQ             _UART5_FAULT_VECTOR
#define _SER1_VECTOR          _UART5_FAULT_VECTOR
#define _SER1_IPL_ISR         IPL1SRS
#define _SER1_IPL             2
#define _SER1_SPL             0
#define _SER1_TX_OUT          PPS_OUT_U5TX
#define _SER1_TX_PIN          10
#define _SER1_RX_IN           PPS_IN_U5RX
#define _SER1_RX_PIN          9

#define _DSPI0_BASE            _SPI2_BASE_ADDRESS
#define _DSPI0_ERR_IRQ         _SPI2_FAULT_VECTOR
#define _DSPI0_RX_IRQ          _SPI2_RX_VECTOR
#define _DSPI0_TX_IRQ          _SPI2_TX_VECTOR
#define _DSPI0_VECTOR          _SPI2_FAULT_VECTOR
#define _DSPI0_IPL_ISR         IPL3SRS
#define _DSPI0_IPL             3
#define _DSPI0_SPL             0
#define _DSPI0_MISO_IN         PPS_IN_SDI2
#define _DSPI0_MISO_PIN        25
#define _DSPI0_MOSI_OUT        PPS_OUT_SDO2
#define _DSPI0_MOSI_PIN        26

#define _DSPI1_BASE            _SPI1_BASE_ADDRESS
#define _DSPI1_ERR_IRQ         _SPI1_FAULT_VECTOR
#define _DSPI1_RX_IRQ          _SPI1_RX_VECTOR
#define _DSPI1_TX_IRQ          _SPI1_TX_VECTOR
#define _DSPI1_VECTOR          _SPI1_FAULT_VECTOR
#define _DSPI1_IPL_ISR         IPL3SRS
#define _DSPI1_IPL             3
#define _DSPI1_SPL             0
#define _DSPI1_MISO_IN         PPS_IN_SDI1
#define _DSPI1_MISO_PIN        9
#define _DSPI1_MOSI_OUT        PPS_OUT_SDO1
#define _DSPI1_MOSI_PIN        10

#define _DTWI0_BASE            _I2C1_BASE_ADDRESS
#define _DTWI0_BUS_IRQ         _I2C1_BUS_VECTOR
#define _DTWI0_VECTOR          _I2C1_BUS_VECTOR
#define _DTWI0_IPL_ISR         IPL3SRS
#define _DTWI0_IPL             3
#define _DTWI0_SPL             0
#define _DTWI0_SCL_PIN         3
#define _DTWI0_SDA_PIN         2

#define _DTWI1_BASE            _I2C4_BASE_ADDRESS
#define _DTWI1_BUS_IRQ         _I2C4_BUS_VECTOR
#define _DTWI1_VECTOR          _I2C4_BUS_VECTOR
#define _DTWI1_IPL_ISR         IPL3SRS
#define _DTWI1_IPL             3
#define _DTWI1_SPL             0
#define _DTWI1_SCL_PIN         26
#define _DTWI1_SDA_PIN         25

#define _DTWI2_BASE            _I2C3_BASE_ADDRESS
#define _DTWI2_BUS_IRQ         _I2C3_BUS_VECTOR
#define _DTWI2_VECTOR          _I2C3_BUS_VECTOR
#define _DTWI2_IPL_ISR         IPL3SRS
#define _DTWI2_IPL             3
#define _DTWI2_SPL             0
#define _DTWI2_SCL_PIN         10
#define _DTWI2_SDA_PIN         9

#define _PORTB
#define _PORTC
#define _PORTD
#define _PORTE
#define _PORTF
#define _PORTG

#define _JTAG 0

#endif  // OPT_BOARD_INTERNAL

#define ADCRANGE        4096ul              // analog read will return a max number of ADCRANGE-1
#define ADCTADFREQ      25000000ul          // How fast to run the TAD ADC clock
#define ADCTADSH        68ul                // How many TADs the Sample and Hold will charge

/* ------------------------------------------------------------ */
/*                  Defines for the On Board uSD                */
/* ------------------------------------------------------------ */

#define _uSD_SPI_CONFIG_

#define SD_CS_PIN PIN_DSPI0_SS

#define DefineSDSPI(spi) DSPI0 spi
#define DefineDSDVOL(vol, spi) DSDVOL vol(spi, 10)

#endif  // BOARD_DEFS_H

