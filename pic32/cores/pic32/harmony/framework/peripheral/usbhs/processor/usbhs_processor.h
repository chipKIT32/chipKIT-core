#ifndef _USBHS_PROCESSOR_H
#define _USBHS_PROCESSOR_H

#if defined(__PIC16F__)
    #include "usbhs_pic_other.h"

#elif defined(__18CXX)
    #include "usbhs_pic18.h"

#elif defined(_PIC18)
    #include "usbhs_pic18.h"

#elif defined(__PIC24F__)
    #include "usbhs_p24Fxxxx.h"

#elif defined(__PIC24H__)
    #include "usbhs_p24Hxxxx.h"

#elif defined(__dsPIC30F__)
    #include "usbhs_p30Fxxxx.h"

#elif defined(__dsPIC33E__)
    #include "usbhs_p33Exxxx.h"

#elif defined(__dsPIC33F__)
    #include "usbhs_p33Fxxxx.h"

#elif defined(__PIC32MX__)
    #include "usbhs_p32xxxx.h"

#elif defined(__PIC32MZ__)
    #include "usbhs_p32xxxx.h"

#else
    #error "Can't find header"

#endif

#endif//_USBHS_PROCESSOR_H
