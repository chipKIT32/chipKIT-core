#ifndef _ROMVOL_H
#define _ROMVOL_H

#include "../DFATFS/DFATFS.h"       // required for the interface DFSVOL
class ROMVOL : public DFSVOL {
    private:
        const uint8_t *_start;
        const uint8_t *_end;
        const uint32_t _sectors;
        DSTATUS _status;
 
        ROMVOL();

    public:
        static const uint32_t SectorSize = _MIN_SS;
        static const uint32_t MinSectors = 128;

        ROMVOL(const uint8_t * start, uint32_t sectors) : DFSVOL(1,1), _start(start), _end(_start + sectors * SectorSize), _sectors(sectors) {
            _status = STA_NOINIT; 
        }

        DSTATUS disk_initialize (void);
        DSTATUS disk_status (void);
        DRESULT disk_read (uint8_t* buff, uint32_t sector, uint32_t count);
        DRESULT disk_write (const uint8_t* buff, uint32_t sector, uint32_t count);
        DRESULT disk_ioctl (uint8_t cmd, void* buff);
};

#endif

