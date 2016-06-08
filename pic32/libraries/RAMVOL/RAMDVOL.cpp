/************************************************************************/
/*                                                                      */
/*    RAMVOL.cpp                                                        */
/*                                                                      */
/************************************************************************/
/*    Author:     Keith Vogel                                           */
/*    Copyright 2015, Digilent Inc.                                     */
/************************************************************************/
/* 
*
* Copyright (c) 2015, Digilent <www.digilentinc.com>
* Contact Digilent for the latest version.
*
* This program is free software; distributed under the terms of 
* BSD 3-clause license ("Revised BSD License", "New BSD License", or "Modified BSD License")
*
* Redistribution and use in source and binary forms, with or without modification,
* are permitted provided that the following conditions are met:
*
* 1.    Redistributions of source code must retain the above copyright notice, this
*        list of conditions and the following disclaimer.
* 2.    Redistributions in binary form must reproduce the above copyright notice,
*        this list of conditions and the following disclaimer in the documentation
*        and/or other materials provided with the distribution.
* 3.    Neither the name(s) of the above-listed copyright holder(s) nor the names
*        of its contributors may be used to endorse or promote products derived
*        from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
* OF THE POSSIBILITY OF SUCH DAMAGE.
*/
/************************************************************************/
/*  Revision History:                                                   */
/*                                                                      */
/*    10/20/2015(KeithV): Created                                       */
/************************************************************************/
#include <RAMVOL.h>


/*--------------------------------------------------------------------------

   Public Functions

---------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------*/
/* Get Disk Status                                                       */
/*-----------------------------------------------------------------------*/

DSTATUS RAMVOL::disk_status(void)
{
    return(_dStatus);
}

/*-----------------------------------------------------------------------*/
/* Initialize Disk Drive                                                 */
/*-----------------------------------------------------------------------*/

DSTATUS RAMVOL::disk_initialize(void)
{
    _dStatus &= ~STA_NOINIT;
    return(_dStatus);
}

/*-----------------------------------------------------------------------*/
/* Read Sector(s)                                                        */
/*-----------------------------------------------------------------------*/

DRESULT RAMVOL::disk_read(
	uint8_t *buff,		/* Pointer to the data buffer to store read data */
	uint32_t sector,	/* Start sector number (LBA) */
	uint32_t count		/* Sector count (1..128) */
)
{
    uint8_t *   pStart  = _pRAMVolStart + (sector * CBSECTOR);
    uint32_t    cbRead  = count * CBSECTOR;
    uint8_t *   pEnd    = pStart + cbRead;

    if(_dStatus &= STA_NOINIT)
    {
        return(RES_NOTRDY);
    }

    if(pStart < _pRAMVolStart || pStart >= _pRAMVolEnd || pEnd < _pRAMVolStart || pEnd > _pRAMVolEnd)
    {
        return(RES_PARERR);  
    }

    memcpy(buff, pStart, cbRead);
    return(RES_OK); 
}

/*-----------------------------------------------------------------------*/
/* Write Sector(s)                                                       */
/*-----------------------------------------------------------------------*/

#if _USE_WRITE
DRESULT RAMVOL::disk_write (
	const uint8_t *buff,		/* Pointer to the data to be written */
	uint32_t sector,			/* Start sector number (LBA) */
	uint32_t count				/* Sector count (1..128) */
)
{
    uint8_t *   pStart  = _pRAMVolStart + (sector * CBSECTOR);
    uint32_t    cbWrite = count * CBSECTOR;
    uint8_t *   pEnd    = pStart + cbWrite;

    if(_dStatus &= STA_NOINIT)
    {
        return(RES_NOTRDY);
    }

    if(pStart < _pRAMVolStart || pStart >= _pRAMVolEnd || pEnd < _pRAMVolStart || pEnd > _pRAMVolEnd)
    {
        return(RES_PARERR);  
    }

    memcpy(pStart, buff, cbWrite);
    return(RES_OK); 
}
#endif

/*-----------------------------------------------------------------------*/
/* Miscellaneous Functions                                               */
/*-----------------------------------------------------------------------*/

#if _USE_IOCTL
DRESULT RAMVOL::disk_ioctl (
	uint8_t cmd,		/* Control code */
	void *buff		/* Buffer to send/receive data block */
)
{
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
            *(uint32_t*) buff = _cSectors;
            return(RES_OK);
            break;

        /* Get sector size (needed at _MAX_SS != _MIN_SS) */
        case GET_SECTOR_SIZE:
            *(uint32_t*) buff = CBSECTOR;
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
