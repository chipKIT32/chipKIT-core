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

#define _BOARD_NAME_ "chipKIT MZ Lite"

#define NUM_DIGITAL_PINS     45
#define NUM_ANALOG_PINS      15
#define NUM_OC_PINS          5
#define NUM_IC_PINS          0
#define NUM_TCK_PINS         0
#define NUM_INT_PINS         5

#define NUM_DIGITAL_PINS_EXTENDED NUM_DIGITAL_PINS
#define NUM_ANALOG_PINS_EXTENDED NUM_ANALOG_PINS

#define NUM_SERIAL_PORTS     6
#define NUM_SPI_PORTS        1
#define NUM_DSPI_PORTS       1
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

#define PIN_D34             34
#define PIN_D37             37
#define PIN_D21             21
#define PIN_D2             2
#define PIN_D20             20
#define PIN_D25             25
#define PIN_D39             39
#define PIN_D28             28
#define PIN_D6             6
#define PIN_D23             23
#define PIN_D19             19
#define PIN_D26             26
#define PIN_D22             22
#define PIN_D44             44
#define PIN_D14             14
#define PIN_D17             17
#define PIN_D36             36
#define PIN_D1             1
#define PIN_D4             4
#define PIN_D32             32
#define PIN_D41             41
#define PIN_D11             11
#define PIN_D18             18
#define PIN_D33             33
#define PIN_D7             7
#define PIN_D15             15
#define PIN_D40             40
#define PIN_D10             10
#define PIN_D13             13
#define PIN_D9             9
#define PIN_D43             43
#define PIN_D30             30
#define PIN_D35             35
#define PIN_D29             29
#define PIN_D38             38
#define PIN_D0             0
#define PIN_D27             27
#define PIN_D24             24
#define PIN_D8             8
#define PIN_D31             31
#define PIN_D3             3
#define PIN_D5             5
#define PIN_D16             16
#define PIN_D42             42
#define PIN_D12             12

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

#define _SER2_BASE            _UART2_BASE_ADDRESS
#define _SER2_IRQ             _UART2_FAULT_VECTOR
#define _SER2_VECTOR          _UART2_FAULT_VECTOR
#define _SER2_IPL_ISR         IPL1SRS
#define _SER2_IPL             2
#define _SER2_SPL             0
#define _SER2_TX_OUT          PPS_OUT_U2TX
#define _SER2_TX_PIN          8
#define _SER2_RX_IN           PPS_IN_U2RX
#define _SER2_RX_PIN          12

#define _SER3_BASE            _UART3_BASE_ADDRESS
#define _SER3_IRQ             _UART3_FAULT_VECTOR
#define _SER3_VECTOR          _UART3_FAULT_VECTOR
#define _SER3_IPL_ISR         IPL1SRS
#define _SER3_IPL             2
#define _SER3_SPL             0
#define _SER3_TX_OUT          PPS_OUT_U3TX
#define _SER3_TX_PIN          14
#define _SER3_RX_IN           PPS_IN_U3RX
#define _SER3_RX_PIN          20

#define _SER4_BASE            _UART4_BASE_ADDRESS
#define _SER4_IRQ             _UART4_FAULT_VECTOR
#define _SER4_VECTOR          _UART4_FAULT_VECTOR
#define _SER4_IPL_ISR         IPL1SRS
#define _SER4_IPL             2
#define _SER4_SPL             0
#define _SER4_TX_OUT          PPS_OUT_U4TX
#define _SER4_TX_PIN          35
#define _SER4_RX_IN           PPS_IN_U4RX
#define _SER4_RX_PIN          36

#define _SER5_BASE            _UART6_BASE_ADDRESS
#define _SER5_IRQ             _UART6_FAULT_VECTOR
#define _SER5_VECTOR          _UART6_FAULT_VECTOR
#define _SER5_IPL_ISR         IPL1SRS
#define _SER5_IPL             2
#define _SER5_SPL             0
#define _SER5_TX_OUT          PPS_OUT_U6TX
#define _SER5_TX_PIN          1
#define _SER5_RX_IN           PPS_IN_U6RX
#define _SER5_RX_PIN          0

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

#define _DTWI0_BASE            _I2C1_BASE_ADDRESS
#define _DTWI0_BUS_IRQ         _I2C1_BUS_VECTOR
#define _DTWI0_VECTOR          _I2C1_BUS_VECTOR
#define _DTWI0_IPL_ISR         IPL3SRS
#define _DTWI0_IPL             3
#define _DTWI0_SPL             0
#define _DTWI0_SCL_PIN         3
#define _DTWI0_SDA_PIN         2

#define _DTWI1_BASE            _I2C3_BASE_ADDRESS
#define _DTWI1_BUS_IRQ         _I2C3_BUS_VECTOR
#define _DTWI1_VECTOR          _I2C3_BUS_VECTOR
#define _DTWI1_IPL_ISR         IPL3SRS
#define _DTWI1_IPL             3
#define _DTWI1_SPL             0
#define _DTWI1_SCL_PIN         10
#define _DTWI1_SDA_PIN         9

#define _DTWI2_BASE            _I2C4_BASE_ADDRESS
#define _DTWI2_BUS_IRQ         _I2C4_BUS_VECTOR
#define _DTWI2_VECTOR          _I2C4_BUS_VECTOR
#define _DTWI2_IPL_ISR         IPL3SRS
#define _DTWI2_IPL             3
#define _DTWI2_SPL             0
#define _DTWI2_SCL_PIN         26
#define _DTWI2_SDA_PIN         25

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

#endif  // BOARD_DEFS_H

