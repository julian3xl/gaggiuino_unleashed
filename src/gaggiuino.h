#ifndef GAGGIUINO_H
#define GAGGIUINO_H

#include <Arduino.h>
#include <SimpleKalmanFilter.h>

#include "log.h"
#include "eeprom_data/eeprom_data.h"
#include "lib/sensors_state.h"
#include "lib/system_state.h"

#include "peripherals/internal_watchdog.h"
#include "peripherals/peripherals.h"
#include "peripherals/pressure_sensor.h"
#include "peripherals/pump.h"
#include "peripherals/thermocouple.h"

#include "lib/profiling_phases.h"
#include "functional/descale.h"
#include "functional/just_do_coffee.h"
#include "functional/predictive_weight.h"

//***#include "peripherals/esp_comms.h"
//***#include "peripherals/led.h"
//***#include "peripherals/scales.h"
//***#include "peripherals/tof.h"
//#include "lcd/lcd.h"

#define GET_PRESSURE_READ_EVERY 10 // Pressure refresh interval (ms)
#define GET_SCALES_READ_EVERY   100 // Scales refresh interval (ms)
#define REFRESH_SCREEN_EVERY    150 // Screen refresh interval (ms)
#define REFRESH_FLOW_EVERY      50 // Flow refresh interval (ms)
#define HEALTHCHECK_EVERY       30000 // System checks happen every 30sec
#define BOILER_FILL_START_TIME  3000UL // Boiler fill start time - 3 sec since system init.
#define BOILER_FILL_TIMEOUT     8000UL // Boiler fill timeout - 8sec since system init.
#define BOILER_FILL_SKIP_TEMP   85.f // Boiler fill skip temperature threshold
#define SYS_PRESSURE_IDLE       0.7f // System pressure threshold at idle
#define MIN_WATER_LVL           10u // Min allowable tank water lvl

enum class OPERATION_MODES {
  OPMODE_straight9Bar,
  OPMODE_justPreinfusion,
  OPMODE_justPressureProfile,
  OPMODE_manual,
  OPMODE_preinfusionAndPressureProfile,
  OPMODE_flush,
  OPMODE_descale,
  OPMODE_flowPreinfusionStraight9BarProfiling,
  OPMODE_justFlowBasedProfiling,
  OPMODE_steam,
  OPMODE_FlowBasedPreinfusionPressureBasedProfiling,
  OPMODE_everythingFlowProfiled,
  OPMODE_pressureBasedPreinfusionAndFlowProfile
} ;

//Timers
unsigned long systemHealthTimer;
unsigned long pageRefreshTimer;
unsigned long pressureTimer;
unsigned long brewingTimer;
unsigned long thermoTimer;
unsigned long scalesTimer;
unsigned long flowTimer;
unsigned long steamTime;

//scales vars
//***Measurements weightMeasurements(4);

// brew detection vars
bool brewActive = false;
bool nonBrewModeActive = false;

//PP&PI variables
int preInfusionFinishedPhaseIdx = 3;
bool homeScreenScalesEnabled = false;

// Other util vars
float previousSmoothedPressure;
float previousSmoothedPumpFlow;

static void sysHealthCheck(float pressureThreshold);

#endif
