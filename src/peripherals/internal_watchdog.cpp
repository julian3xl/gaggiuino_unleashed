#include "internal_watchdog.h"

#include "../log.h"

#ifdef ESP32 // Espressif ESP32
#include <esp_task_wdt.h>

void watchdogInit(void) {
  esp_task_wdt_init(WATCHDOG_TIMEOUT, true);
  esp_task_wdt_add(NULL);
  LOG_INFO("ESP32 watchdog init");
}

void watchdogReload(void) {
  esp_task_wdt_reset();
}
#endif

#ifdef STM32F4 // STM32F4 Black Pill
#include <IWatchdog.h>

void watchdogInit(void) {
  if (IWatchdog.isReset()) {
    LOG_INFO("STM32F4 watchdog restarted");
    IWatchdog.clearReset();
  }

  IWatchdog.begin(WATCHDOG_TIMEOUT);
  LOG_INFO("STM32F4 watchdog init");
}

void watchdogReload(void) {
  IWatchdog.reload();
}
#endif

#ifdef __AVR_ATmega328P__ // Arduino Uno
#include <avr/wdt.h>

void watchdogInit(void) {
  wdt_disable();
  wdt_enable(WATCHDOG_TIMEOUT);
  LOG_INFO("ATmega328P watchdog init");
}

void watchdogReload(void) {
  wdt_reset();
}
#endif
