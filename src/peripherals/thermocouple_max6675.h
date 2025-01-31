#ifndef THERMOCOUPLE_MAX6675_H
#define THERMOCOUPLE_MAX6675_H

#include <Wire.h>
#include <max6675.h>
#include "../pindef.h"

#define GET_KTYPE_READ_EVERY 250

SPIClass thermocoupleSPI(thermocoupleDI, thermocoupleDO, thermocoupleCLK);
MAX6675 thermocouple(thermocoupleCS, &thermocoupleSPI);

#endif
