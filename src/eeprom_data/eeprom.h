#ifndef EEPROM_H
#define EEPROM_H

#include <Arduino.h>

#ifdef ESP32 // Espressif ESP32
#include <EEPROM.h>
#endif

#ifdef STM32F4 // STM32F4 Black Pill
#include <FlashStorage_STM32.h>
#endif

#ifdef __AVR_ATmega328P__ // Arduino Uno
#error "foo flash_storage"
#endif

#endif
