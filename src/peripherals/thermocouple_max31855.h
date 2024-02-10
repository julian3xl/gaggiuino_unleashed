#ifndef THERMOCOUPLE_MAX31855_H
#define THERMOCOUPLE_MAX31855_H

#include <Wire.h>
#include <Adafruit_MAX31855.h>
#include "../pindef.h"

#define GET_KTYPE_READ_EVERY 70

SPIClass thermocoupleSPI(thermocoupleDI, thermocoupleDO, thermocoupleCLK);
Adafruit_MAX31855 thermocouple(thermocoupleCS, &thermocoupleSPI);

#endif
