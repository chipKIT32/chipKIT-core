/************************************************************************/
/*                                                                      */
/*    SDWriteReadSrc.cpp                                                */
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
/************************************************************************/
/*  NOTE:You must have an SD reader and card insterted enable for write */
/************************************************************************/
// Include the SD Volume implemenation
#include <DSDVOL.h>

// Error code global variable
static FRESULT fr = FR_OK;

// The file to open
static const char txtFileToOpen[] = "sdfile.txt"; 

// the drive to mount the SD volume too.
// options are: "0:", "1:", "2:", "3:", "4:"
static const char driveNbr[] = "0:";

static const char szDataToWrite[] = 
"This is text written to the SD card.\r\n\
Mulitiple lines are written.\r\n\
Then all lines are read back.";

// the default buff size is used so that we don't attempt
// to read/write too many bytes in one call. By default
// the max read/write buffer size is 1 sector of 512 bytes
// which could take as long as 1 msec to read and more to write.
// On the fsread() and fswrite() methods you can specify the number of
// sectors you can read without an invalid parameter failure; the default is 1 sector.
// The string functions do not take a max sector read/write size as it is
// assumed that most strings will be less than a sector (512 bytes). But if 
// they are longer the methods could take excessive time to complete thus
// effecting other time critical functions in your loop().
char buff[DFILE::FS_DEFAULT_BUFF_SIZE];

// create the sd volume and a file instance to use
DefineSDSPI(dSDSpi);            // Macro from Board_Defs.h to create an SPI object to the uSD
DSDVOL      dSDVol(dSDSpi);     // Create an SD Vol
DFILE       dFile;              // Create a File handle to use to open files with

void setup() {
    uint32_t cbWritten = 0;

    // Open Serial Monitor
    Serial.begin(9600);

    // print out sketch title
    Serial.println("SDWriteRead v1.0");

    // Mount the SD Vol to drive "0" as known by FATFS
    // Note that there is only one global pre initialized dFatFs instance
    if((fr = dFatFs.fsmount(dSDVol, driveNbr, 1)) == FR_OK)
    {
        Serial.print("Drive ");
        Serial.print(driveNbr);
        Serial.println(" mounted!");
    }
    else
    {
        Serial.print("Failed to mount drive ");
        Serial.print(driveNbr);
        Serial.print("! Error: ");
        Serial.println((int) fr, DEC);
        exit(1);
    }

    // Open the file on the current (implied) drive "0"
    // create always so it will truncate the file.
    if((fr = dFile.fsopen(txtFileToOpen, FA_CREATE_ALWAYS | FA_WRITE | FA_READ)) == FR_OK)
    {
        Serial.print(txtFileToOpen);
        Serial.println(" opened successfully");
    }
    else
    {
        Serial.print("Failed to open file: ");
        Serial.print(txtFileToOpen);
        Serial.print(" Error: ");
        Serial.println((int) fr, DEC);
        exit(1);
    }

    // write to the file
    if((fr = dFile.fswrite(szDataToWrite, sizeof(szDataToWrite)-1, &cbWritten)) == FR_OK)
    {
        
        Serial.print("Successfully wrote "); 
        Serial.print(cbWritten, DEC);
        Serial.print(" bytes to file: "); 
        Serial.println(txtFileToOpen);
    }
    else
    {
        Serial.print("Failed to write of file: ");
        Serial.print(txtFileToOpen);
        Serial.print(" Error: ");
        Serial.println((int) fr, DEC);
        dFile.fsclose();
        exit(1);
    }

    if((fr = dFile.fslseek(0)) == FR_OK)
    {       
        Serial.print("Successfully seeked to begining of file: "); 
        Serial.println(txtFileToOpen);
    }
    else
    {
        Serial.print("Failed to seek to begining of file: ");
        Serial.print(txtFileToOpen);
        Serial.print(" Error: ");
        Serial.println((int) fr, DEC);
        dFile.fsclose();
        exit(1);
    }

    // print out all of the lines from the file on the SD card
    Serial.println("Text From File: ");
    while(dFile.fsgets(buff, sizeof(buff)) != NULL)
    {
        Serial.print(buff);
    }	

    // close the file
    if(dFile)
    {
        dFile.fsclose();
    }
    else
    {
        Serial.print("File already closed");
    }

}

void loop() {
  // put your main code here, to run repeatedly:

}


