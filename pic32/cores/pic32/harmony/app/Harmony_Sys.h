#ifndef _HARMONY_SYS_H
#define _HARMONY_SYS_H


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "System_Config.h"
#include "Harmony_System_Definitions.h"


void Harmony_SYS_InitDrivers ( void* data );
void Harmony_SYS_InitDevices ( void* data );
void Harmony_SYS_InitApplication ( void* data );
void Harmony_SYS_Tasks ( void );

#endif
