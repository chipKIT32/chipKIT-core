#ifndef _PLIB_OSC_PROCESSOR_H
#define _PLIB_OSC_PROCESSOR_H

#if defined(__PIC16F__)
    #include "osc_pic_other.h"

#elif defined(__18CXX)
    #include "osc_pic18.h"

#elif defined(_PIC18)
    #include "osc_pic18.h"

#elif defined(__PIC24F__)
    #include "osc_p24Fxxxx.h"

#elif defined(__PIC24H__)
    #include "osc_p24Hxxxx.h"

#elif defined(__dspiC30F__)
    #include "osc_p30Fxxxx.h"

#elif defined(__dspiC33E__)
    #include "osc_p33Exxxx.h"

#elif defined(__dspiC33F__)
    #include "osc_p33Fxxxx.h"

#elif defined(__PIC32MX__)
    #include "osc_p32xxxx.h"

#elif defined(__PIC32MZ__)
    #include "osc_p32xxxx.h"


#else
    #error "Can't find header"

#endif

#endif//_PLIB_OSC_PROCESSOR_H