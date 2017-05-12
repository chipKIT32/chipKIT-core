#include <stdint.h>
#include "Deeprom.h"

uint8_t eeprom_read_byte(uint8_t *index) {
    uint8_t val = 0;
    if (readEeprom((uint32_t)index, &val)) {
        return val;
    }
    return 0xFF;
}

void eeprom_write_byte(uint8_t *index, uint8_t in) {
    writeEeprom((uint32_t)index, in);
}
