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
#include "system_config.h"
#include "system_definitions.h"

void __attribute__((interrupt(), nomips16)) _IntHandlerUSBInstance0(void);

void Harmony_SYS_InitDrivers ( void* data );
void Harmony_SYS_InitDevices ( void* data );
void Harmony_SYS_InitApplication ( void* data );
void Harmony_SYS_Tasks ( void );

#endif
