#ifndef THERMOCOUPLE_H
#define THERMOCOUPLE_H

#include <Arduino.h>

#if defined THERMOCOUPLE_MAX31855
#include "thermocouple_max31855.h"

#elif defined THERMOCOUPLE_MAX6675
#include "thermocouple_max6675.h"

#else
#define GET_KTYPE_READ_EVERY 0
#endif

void thermocoupleInit(void);
float thermocoupleRead(void);

#endif
