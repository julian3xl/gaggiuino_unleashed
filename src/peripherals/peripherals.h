#ifndef PERIPHERALS_H
#define PERIPHERALS_H

#include "pindef.h"
#include "peripherals.h"
#include <Arduino.h>

static inline void pinInit(void) {
  //pinMode(brewValvePin, OUTPUT_OPEN_DRAIN);
  pinMode(brewValvePin, OUTPUT);
  pinMode(boilerRelayPin, OUTPUT);
  #ifdef steamValveRelayPin
  pinMode(steamValveRelayPin, OUTPUT);
  #endif
  #ifdef steamBoilerRelayPin
  pinMode(steamBoilerRelayPin, OUTPUT);
  #endif
  pinMode(brewSwitchPin,  INPUT_PULLUP);
  pinMode(steamSwitchPin, INPUT_PULLUP);
  #ifdef hotWaterSwitchPin
  pinMode(hotWaterSwitchPin, INPUT_PULLUP);
  #endif
}

// Actuating the heater element
static inline void setBoilerOn(void) {
  digitalWrite(boilerRelayPin, HIGH);  // boilerRelayPin -> HIGH
}

static inline void setBoilerOff(void) {
  digitalWrite(boilerRelayPin, LOW);  // boilerRelayPin -> LOW
}

static inline void setSteamValveRelayOn(void) {
  #ifdef steamValveRelayPin
  digitalWrite(steamValveRelayPin, HIGH);  // steamValveRelayPin -> HIGH
  #endif
}

static inline void setSteamValveRelayOff(void) {
  #ifdef steamValveRelayPin
  digitalWrite(steamValveRelayPin, LOW);  // steamValveRelayPin -> LOW
  #endif
}

static inline void setSteamBoilerRelayOn(void) {
  #ifdef steamBoilerRelayPin
  digitalWrite(steamBoilerRelayPin, HIGH);  // steamBoilerRelayPin -> HIGH
  #endif
}

static inline void setSteamBoilerRelayOff(void) {
  #ifdef steamBoilerRelayPin
  digitalWrite(steamBoilerRelayPin, LOW);  // steamBoilerRelayPin -> LOW
  #endif
}

//Function to get the state of the brew switch button
//returns true or false based on the read P(power) value
static inline bool brewState(void) {
  return digitalRead(brewSwitchPin) == LOW; // pin will be low when switch is ON.
}

// Returns HIGH when switch is OFF and LOW when ON
// pin will be high when switch is ON.
static inline bool steamState(void) {
  return digitalRead(steamSwitchPin) == LOW; // pin will be low when switch is ON.
}

static inline bool hotWaterSwitchPinState(void) {
  #ifdef hotWaterSwitchPin
  return digitalRead(hotWaterSwitchPin) == LOW; // pin will be low when switch is ON.
  #else
  return false;
  #endif
}

static inline void openValve(void) {
  digitalWrite(brewValvePin, HIGH);
}

static inline void closeValve(void) {
  digitalWrite(brewValvePin, LOW);
}

#endif
