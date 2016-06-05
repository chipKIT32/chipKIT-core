#include <ROMVOL.h>

DSTATUS ROMVOL::disk_status(void) {
    return(_status);
}

DSTATUS ROMVOL::disk_initialize(void) {
    _status &= ~STA_NOINIT;
    return(_status);
}

DRESULT ROMVOL::disk_read(
	uint8_t *buff,		/* Pointer to the data buffer to store read data */
	uint32_t sector,	/* Start sector number (LBA) */
	uint32_t count		/* Sector count (1..128) */
) {
    const uint8_t *   pStart  = _start + (sector * SectorSize);
    uint32_t    cbRead  = count * SectorSize;
    const uint8_t *   pEnd    = pStart + cbRead;

    if(_status &= STA_NOINIT)
    {
        return(RES_NOTRDY);
    }

    if(pStart < _start || pStart >= _end || pEnd < _start || pEnd > _end)
    {
        return(RES_PARERR);  
    }

    memcpy(buff, pStart, cbRead);
    return(RES_OK); 
}

DRESULT ROMVOL::disk_write (
	const uint8_t *buff,		/* Pointer to the data to be written */
	uint32_t sector,			/* Start sector number (LBA) */
	uint32_t count				/* Sector count (1..128) */
) {
    return(RES_NOTRDY);
}

DRESULT ROMVOL::disk_ioctl (
	uint8_t cmd,		/* Control code */
	void *buff		/* Buffer to send/receive data block */
) {
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
            *(uint32_t*) buff = _sectors;
            return(RES_OK);
            break;

        /* Get sector size (needed at _MAX_SS != _MIN_SS) */
        case GET_SECTOR_SIZE:
            *(uint32_t*) buff = SectorSize;
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
