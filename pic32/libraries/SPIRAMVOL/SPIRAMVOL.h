#ifndef _SPIRAMVOL_H
#define _SPIRAMVOL_H

#include <Arduino.h>
#include <DFATFS.h>
#include <DSPI.h>

class SPIRAMVOL : public DFSVOL {
    private:
        SPIRAMVOL();
        uint32_t _numChips;
        int _cs[16];
        DSPI *_dspi;
        uint32_t _chipSize;
        DSTATUS _status;
        static const uint32_t _sectorSize = _MIN_SS;

    public:
        SPIRAMVOL(DSPI &dspi, uint32_t chipSize, 
            int cs0, int cs1 = -1, int cs2 = -1, int cs3 = -1,
            int cs4 = -1, int cs5 = -1, int cs6 = -1, int cs7 = -1,
            int cs8 = -1, int cs9 = -1, int cs10 = -1, int cs11 = -1,
            int cs12 = -1, int cs13 = -1, int cs14 = -1, int cs15 = -1);

        SPIRAMVOL(DSPI *dspi, uint32_t chipSize, 
            int cs0, int cs1 = -1, int cs2 = -1, int cs3 = -1,
            int cs4 = -1, int cs5 = -1, int cs6 = -1, int cs7 = -1,
            int cs8 = -1, int cs9 = -1, int cs10 = -1, int cs11 = -1,
            int cs12 = -1, int cs13 = -1, int cs14 = -1, int cs15 = -1);

        DSTATUS disk_initialize (void);
        DSTATUS disk_status (void);
        DRESULT disk_read (uint8_t* buff, uint32_t sector, uint32_t count);
        DRESULT disk_write (const uint8_t* buff, uint32_t sector, uint32_t count);
        DRESULT disk_ioctl (uint8_t cmd, void* buff);
};

#endif

