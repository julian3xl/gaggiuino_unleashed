#ifndef REMOTE_SCALES_H
#define REMOTE_SCALES_H

#include "../lib/measurements.h"

void remoteScalesTare(void);
Measurement remoteScalesGetWeight(void);
bool remoteScalesIsPresent(void);

#endif
