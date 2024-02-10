#ifndef PRESSURE_SENSOR_H
#define PRESSURE_SENSOR_H

#include <Arduino.h>

void adsInit(void);
void i2cResetState(void);
float getPressure(void);
void getAdsError(void);

#endif
