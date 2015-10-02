#ifndef _PLIB_TMR_PROCESSOR_H
#define _PLIB_TMR_PROCESSOR_H

#if defined(__PIC16F__)
    #include "tmr_pic_other.h"

#elif defined(__18CXX)
    #include "tmr_pic18.h"

#elif defined(_PIC18)
    #include "tmr_pic18.h"

#elif defined(__PIC24F__)
    #include "tmr_p24Fxxxx.h"

#elif defined(__PIC24H__)
    #include "tmr_p24Hxxxx.h"

#elif defined(__dsPIC30F__)
    #include "tmr_p30Fxxxx.h"

#elif defined(__dsPIC33E__)
    #include "tmr_p33Exxxx.h"

#elif defined(__dsPIC33F__)
    #include "tmr_p33Fxxxx.h"

#elif defined(__PIC32MX__)
    #include "tmr_p32xxxx.h"

#elif defined(__PIC32MZ__)
    #include "tmr_p32xxxx.h"


#else
    #error "Can't find header"

#endif

#endif//_PLIB_TMR_PROCESSOR_H