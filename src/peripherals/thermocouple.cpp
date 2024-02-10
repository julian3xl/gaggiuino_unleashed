#include "thermocouple.h"

#ifndef thermocouple
#define GET_KTYPE_READ_EVERY 0

class DummyThermocouple {
public:
  void begin() {}

  float readCelsius() { return 0; }
} thermocouple;

#endif

void thermocoupleInit(void) {
  thermocouple.begin();
}

float thermocoupleRead(void) {
  return thermocouple.readCelsius();
}
