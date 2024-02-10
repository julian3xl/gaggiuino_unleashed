#ifndef INTERNALWATCHDOG_H
#define INTERNALWATCHDOG_H

#include <Arduino.h>

#define WATCHDOG_TIMEOUT 5000000 // ms

void watchdogInit(void);
void watchdogReload(void);

#endif
