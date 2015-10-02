#ifndef _USB_PROCESSOR_H
#define _USB_PROCESSOR_H

#if defined(__PIC16F__)
    #include "usb_pic_other.h"

#elif defined(__18CXX)
    #include "peripheral/usb/processor/usb_pic18.h"

#elif defined(_PIC18)
    #include "peripheral/usb/processor/usb_pic18.h"

#elif defined(__PIC24F__)
    #include "usb_p24Fxxxx.h"

#elif defined(__PIC24H__)
    #include "usb_p24Hxxxx.h"

#elif defined(__dsPIC30F__)
    #include "usb_p30Fxxxx.h"

#elif defined(__dsPIC33E__)
    #include "usb_p33Exxxx.h"

#elif defined(__dsPIC33F__)
    #include "usb_p33Fxxxx.h"

#elif defined(__PIC32MX__)
    #include "usb_p32xxxx.h"

#elif defined(__PIC32MZ__)
    #include "usb_p32xxxx.h"
	
#else
    #error "Can't find header"

#endif

#endif//B_USB_PROCESSOR_H
