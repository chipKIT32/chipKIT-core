
#ifndef __OSAL_DEFINITIONS_H
#define __OSAL_DEFINITIONS_H

#if !defined(OSAL_USE_RTOS) && !defined(OSAL_USE_BASIC) && !defined(OSAL_USE_NONE)
   #define OSAL_USE_BASIC
#endif

#ifdef OSAL_USE_BASIC
   #include "osal/src/osal_impl_basic.h"
#elif defined(OSAL_USE_NONE)
   //#error OSAL_USE_NONE has been defined.  The use of OSAL_USE_NONE, is currently prohibited.  Please select OSAL_USE_BASIC, or OSAL_USE_RTOS.
   #include "osal/src/osal_impl_none.h"
#elif (OSAL_USE_RTOS == 0xFFFF)
   #include "osal/src/osal_user.h"
#elif (OSAL_USE_RTOS == 1)
   #include "osal/src/osal_freertos.h"
#elif (OSAL_USE_RTOS == 2)
   #include "osal/src/osal_freertos_v7xx.h"
#elif (OSAL_USE_RTOS == 3)
   #include "osal/src/osal_openrtos.h"
#elif (OSAL_USE_RTOS == 4)
   #include "osal/src/osal_openrtos_v7xx.h"
#elif (OSAL_USE_RTOS == 5)
   #include "osal/src/osal_ucos3.h"
#elif (OSAL_USE_RTOS == 6)
   #include "osal/src/osal_ucos2.h"
#elif (OSAL_USE_RTOS == 7)
   #include "osal/src/osal_threadx.h"
#elif (OSAL_USE_RTOS == 8)
   #include "osal/src/osal_embos.h"
#else
   #error OSAL_USE_RTOS was defined, but to an unrecognized value.  Define OSAL_USE_RTOS to a value which indicates the RTOS being used.
#endif

#endif//__OSAL_DEFINITIONS_H
