#include <SPIRAMVOL.h>

SPIRAMVOL::SPIRAMVOL(DSPI &dspi, uint32_t chipSize,
    int cs0, int cs1, int cs2, int cs3,
    int cs4, int cs5, int cs6, int cs7,
    int cs8, int cs9, int cs10, int cs11,
    int cs12, int cs13, int cs14, int cs15
) : DFSVOL(1, 1) {
    _dspi = &dspi;
    _chipSize = chipSize;
    _numChips = 1;
    _cs[0] = cs0;
    _status = STA_NOINIT;

    if (cs1 > -1) { _cs[1] = cs1; _numChips++; }
    if (cs2 > -1) { _cs[2] = cs2; _numChips++; }
    if (cs3 > -1) { _cs[3] = cs3; _numChips++; }
    if (cs4 > -1) { _cs[4] = cs4; _numChips++; }
    if (cs5 > -1) { _cs[5] = cs5; _numChips++; }
    if (cs6 > -1) { _cs[6] = cs6; _numChips++; }
    if (cs7 > -1) { _cs[7] = cs7; _numChips++; }
    if (cs8 > -1) { _cs[8] = cs8; _numChips++; }
    if (cs9 > -1) { _cs[9] = cs9; _numChips++; }
    if (cs10 > -1) { _cs[10] = cs10; _numChips++; }
    if (cs11 > -1) { _cs[11] = cs11; _numChips++; }
    if (cs12 > -1) { _cs[12] = cs12; _numChips++; }
    if (cs13 > -1) { _cs[13] = cs13; _numChips++; }
    if (cs14 > -1) { _cs[14] = cs14; _numChips++; }
    if (cs15 > -1) { _cs[15] = cs15; _numChips++; }
}

SPIRAMVOL::SPIRAMVOL(DSPI *dspi, uint32_t chipSize,
    int cs0, int cs1, int cs2, int cs3,
    int cs4, int cs5, int cs6, int cs7,
    int cs8, int cs9, int cs10, int cs11,
    int cs12, int cs13, int cs14, int cs15
) : DFSVOL(1, 1) {
    _dspi = dspi;
    _chipSize = chipSize;
    _numChips = 1;
    _cs[0] = cs0;
    _status = STA_NOINIT;

    if (cs1 > -1) { _cs[1] = cs1; _numChips++; }
    if (cs2 > -1) { _cs[2] = cs2; _numChips++; }
    if (cs3 > -1) { _cs[3] = cs3; _numChips++; }
    if (cs4 > -1) { _cs[4] = cs4; _numChips++; }
    if (cs5 > -1) { _cs[5] = cs5; _numChips++; }
    if (cs6 > -1) { _cs[6] = cs6; _numChips++; }
    if (cs7 > -1) { _cs[7] = cs7; _numChips++; }
    if (cs8 > -1) { _cs[8] = cs8; _numChips++; }
    if (cs9 > -1) { _cs[9] = cs9; _numChips++; }
    if (cs10 > -1) { _cs[10] = cs10; _numChips++; }
    if (cs11 > -1) { _cs[11] = cs11; _numChips++; }
    if (cs12 > -1) { _cs[12] = cs12; _numChips++; }
    if (cs13 > -1) { _cs[13] = cs13; _numChips++; }
    if (cs14 > -1) { _cs[14] = cs14; _numChips++; }
    if (cs15 > -1) { _cs[15] = cs15; _numChips++; }
}


DSTATUS SPIRAMVOL::disk_status(void) {
    return(_status);
}

DSTATUS SPIRAMVOL::disk_initialize(void) {
    _dspi->begin();
    for (int i = 0; i < _numChips; i++) {
        pinMode(_cs[i], OUTPUT);
        digitalWrite(_cs[i], HIGH);
    }
    _status &= ~STA_NOINIT;
    return(_status);
}

DRESULT SPIRAMVOL::disk_read(uint8_t *buff, uint32_t sector, uint32_t count) {
    if(_status &= STA_NOINIT) {
        return(RES_NOTRDY);
    }

    uint8_t *p = buff;

    for (int sec = 0; sec < count; sec++) {
        int spc = _chipSize / _sectorSize;
        int chipno = (sector + sec) / spc;
        int offset = ((sector + sec) * _sectorSize) % _chipSize;

        if (chipno >= _numChips) {
            return (RES_PARERR);
        }

        digitalWrite(_cs[chipno], LOW);
        _dspi->transfer((uint8_t)0x03);
        _dspi->transfer((uint8_t)(offset >> 16 & 0xFF));
        _dspi->transfer((uint8_t)(offset >> 8 & 0xFF));
        _dspi->transfer((uint8_t)(offset & 0xFF));

        for (int i = 0; i < _sectorSize; i++) {
            *p++ = _dspi->transfer((uint8_t)0xFF);
        }
        digitalWrite(_cs[chipno], HIGH);
    }

    return(RES_OK); 
}

DRESULT SPIRAMVOL::disk_write(const uint8_t *buff, uint32_t sector, uint32_t count) {
    if(_status &= STA_NOINIT) {
        return(RES_NOTRDY);
    }

    const uint8_t *p = buff;

    for (int sec = 0; sec < count; sec++) {
        int spc = _chipSize / _sectorSize;
        int chipno = (sector + sec) / spc;
        int offset = ((sector + sec) * _sectorSize) % _chipSize;

        if (chipno >= _numChips) {
            return (RES_PARERR);
        }

        digitalWrite(_cs[chipno], LOW);
        _dspi->transfer((uint8_t)0x02);
        _dspi->transfer((uint8_t)(offset >> 16 & 0xFF));
        _dspi->transfer((uint8_t)(offset >> 8 & 0xFF));
        _dspi->transfer((uint8_t)(offset & 0xFF));

        for (int i = 0; i < _sectorSize; i++) {
            _dspi->transfer((uint8_t)*p++);
        }
        digitalWrite(_cs[chipno], HIGH);
    }

    return(RES_OK); 
}

#if _USE_IOCTL
DRESULT SPIRAMVOL::disk_ioctl(uint8_t cmd, void *buff) {
    switch(cmd)
    {
        /* Flush write-back cache, Wait for end of internal process */
        /* Complete pending write process (needed at _FS_READONLY == 0) */
        case CTRL_SYNC:
            return(RES_OK);
            break;

        /* Get media size (needed at _USE_MKFS == 1) */
        /* Get number of sectors on the disk (WORD) */
        case GET_SECTOR_COUNT:
            *(uint32_t*) buff = _chipSize * _numChips / _sectorSize;
            return(RES_OK);
            break;

        /* Get sector size (needed at _MAX_SS != _MIN_SS) */
        case GET_SECTOR_SIZE:
            *(uint32_t*) buff = _sectorSize;
            return(RES_OK);
            break;

        /* Get erase block size in unit of sectors (DWORD) */
        /* Get erase block size (needed at _USE_MKFS == 1) */
        case GET_BLOCK_SIZE:	
            *(uint32_t*) buff = 1;
            return(RES_OK);
           break;

        /* Inform device that the data on the block of sectors is no longer used (needed at _USE_TRIM == 1) */
        case CTRL_TRIM:	
        default:
            return(RES_PARERR);
        break;
    }

    return(RES_PARERR);
}
#endif
