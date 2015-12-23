/************************************************************************/
/*                                                                      */
/*    deWebIOServer                                                     */
/*                                                                      */
/*    A Example chipKIT HTTP Server implementation                      */
/*    This sketch is designed to work with web browser clients          */
/*                                                                      */
/************************************************************************/
/*    Author:     Keith Vogel                                           */
/*    Copyright 2014, Digilent Inc.                                     */
/************************************************************************/
/* 
*
* Copyright (c) 2013-2014, Digilent <www.digilentinc.com>
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
/*    6/15/2014(KeithV): Created                                        */
/************************************************************************/
/************************************************************************/
/*                                                                      */
/*  This HTTP Server Example contains sample content in the content     */
/*  subdirectory under the sketch directory. The files in the content   */
/*  directory should be copied to the root of your SD card. However,    */
/*  you can view the content by opening HomePage.htm page               */
/*  with your browser right out of the content subdirectory before      */
/*  loading it on the SD card. The sample pages contain                 */
/*  instructions on how to set up this example and therefore may be     */
/*  valuable to read before proceeding.                                 */
/*                                                                      */
/************************************************************************/

//************************************************************************
//************************************************************************
//**************************  READ THIS  *********************************
//************************************************************************
//***********  !! COPY THIS SKETCH TO YOUR SKETCH DIRECTORY !! ***********
//************************************************************************
//************************************************************************
//************** You will not be able to modify the network **************
//************** parameters as long as this sketch is in a  **************
//************* library subdirectory. Even if you modify in **************
//************* MPIDE it will not take effect when you build  ************
//************** and you will not be able to connect to ******************
//************** your router, the connection will timeout ****************
//************************************************************************
//************************************************************************

/************************************************************************/
/*                       Supported hardware:                            */
/*                                                                      */
/*  uC32 with a WiFiShield                                              */
/*  WF32                                                                */
/*  WiFIRE                                                              */
/*  MX7cK with a pmodSD on JPF                                          */
/*                                                                      */
/*  NOTE: you can NOT stack a NetworkShield and a WiFiShield on a Max32 */
/************************************************************************/

//************************************************************************
//************************************************************************
//********  SET THESE LIBRARIES FOR YOUR HARDWARE CONFIGURATION **********
//************************************************************************
//************************************************************************

/************************************************************************/
/*                                                                      */
/*    Network Hardware libraries                                        */
/*    INCLUDE ONLY ONE                                                  */
/*                                                                      */
/************************************************************************/
// You MUST select 1 and ONLY 1 of the following hardware libraries
// they are here so that MPIDE will put the lib path on the compiler include path.
#include <MRF24G.h>                         // This is for the MRF24WGxx on a pmodWiFi or WiFiShield
//#include <IM8720PHY.h>                      // This is for the the Internal MAC and SMSC 8720 PHY

/************************************************************************/
/*    Network libraries                                                 */
/************************************************************************/
// The base network library
// this is a required library
// Do not comment out this library
#include <DEIPcK.h>

//  -----  COMMENT THIS OUT IF YOU ARE NOT USING WIFI  -----
#include <DEWFcK.h>

//************************************************************************
//************************************************************************
//**************** END OF LIBRARY CONFIGURATION **************************
//************************************************************************
//************************************************************************

/************************************************************************/
/*                                                                      */
/*           YOU MUST.....                                              */
/*                                                                      */
/*    You MUST put HTTPServerConfig.h in your sketch director           */
/*    And you MUST configure it with your network parameters            */
/*                                                                      */
/*    You also MUST load your content onto your SD card and             */
/*    the file HomePage.htm MUST exist at the root of the SD            */
/*    file structure. Of course you must insert your SD card            */
/*    into the SD reader on the chipKIT board                           */
/*                                                                      */
/*    Go do this now....                                                */
/*                                                                      */
/************************************************************************/

/************************************************************************/
/*    Other libraries; Required libraries                               */
/************************************************************************/
// You must have an SD card reader somewhere
// as the HTTP server uses the SD card to hold the HTML pages.
// this is a required library; we must specify this in the .pde for
// MPIDE to include it.
// required include files.
#include <DFATFS.h>     // the FAT implementation
#include <DSDVOL.h>     // the SD implementation

// the SD SPI implementation used by the SD Volume
// it is not required that both of these be included, only the one
// that is needed must be included. If both are included, the code
// will work but some unnecessary code be linked into your final HEX file.
#include <DSPI.h>       // include for hardware SPI
#include <SoftSPI.h>    // include for bit banged spi

// and this is the HTTPServer library code.
// this is a required library
#include    <HTTPServer.h>

