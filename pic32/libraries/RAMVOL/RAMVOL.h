/************************************************************************/
/*                                                                      */
/*    RAMVOL.h                                                          */
/*                                                                      */
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
/*    12/7/2015(KeithV): Created                                        */
/************************************************************************/
#ifndef _RAMVOL_INCLUDE_
#define _RAMVOL_INCLUDE_

#include "../DFATFS/DFATFS.h"       // required for the interface DFSVOL
class RAMVOL : public DFSVOL
{
    private:

        uint8_t * const _pRAMVolStart;
        uint8_t * const _pRAMVolEnd;
        uint32_t  const _cSectors;
        DSTATUS         _dStatus;
 
        // make default constructor illegal to use
        RAMVOL();

    public:

        static const uint32_t CBSECTOR = _MIN_SS;
        static const uint32_t CMINSECTORS = 128;

        RAMVOL(uint8_t * pRAMVol, uint32_t cSectors) : DFSVOL(1,1), _pRAMVolStart(pRAMVol), _pRAMVolEnd(pRAMVol + (cSectors * CBSECTOR)), _cSectors(cSectors)
        {
            _dStatus = STA_NOINIT; 
            DFATFS::fsmkfs(*this);
        }

        DSTATUS disk_initialize (void);
        DSTATUS disk_status (void);
        DRESULT disk_read (uint8_t* buff, uint32_t sector, uint32_t count);
        DRESULT disk_write (const uint8_t* buff, uint32_t sector, uint32_t count);
        DRESULT disk_ioctl (uint8_t cmd, void* buff);
};

#endif // _RAMVOL_INCLUDE_

