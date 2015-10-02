#ifndef _PLIB_INT_PROCESSOR_H
#define _PLIB_INT_PROCESSOR_H

#if defined(__PIC16F__)
    #include "int_pic_other.h"

#elif defined(__18CXX)
    #include "peripheral/int/processor/int_pic18.h"

#elif defined(_PIC18)
    #include "peripheral/int/processor/int_pic18.h"

#elif defined(__PIC24F__)
    #include "int_p24Fxxxx.h"

#elif defined(__PIC24H__)
    #include "int_p24Hxxxx.h"

#elif defined(__dsPIC30F__)
    #include "int_p30Fxxxx.h"

#elif defined(__dsPIC33E__)
    #include "int_p33Exxxx.h"

#elif defined(__dsPIC33F__)
    #include "int_p33Fxxxx.h"

#elif defined(__PIC32MX__)
    #include "int_p32xxxx.h"

#elif defined(__PIC32MZ__)
	#include "int_p32xxxx.h"

#else
    #error Cant find header

#endif

#endif//_PLIB_INT_PROCESSOR_H