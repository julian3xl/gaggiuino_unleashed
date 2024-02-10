#ifndef PINDEF_H
#define PINDEF_H

#define brewSwitchPin     PIN_BREW_SWITCH
#define steamSwitchPin    PIN_STEAM_SWITCH
#if defined(PIN_HOT_WATER_SWITCH)
#define hotWaterSwitchPin PIN_HOT_WATER_SWITCH
#endif

#define boilerRelayPin    PIN_BOILER_RELAY
#define brewValvePin      PIN_BREW_VALVE

#if defined(PIN_STEAM_VALVE_RELAY)
#define steamValveRelayPin PIN_STEAM_VALVE_RELAY
#endif
#if defined(PIN_STEAM_BOILER_RELAY)
#define steamBoilerRelayPin PIN_STEAM_BOILER_RELAY
#endif

#define pumpDimmerPin     PIN_DIMMER_PUMP
#define pumpZcPin         PIN_DIMMER_ZC

#define thermocoupleDO    PIN_THERMOCOUPLE_DO
#define thermocoupleDI    PIN_THERMOCOUPLE_DI // not used
#define thermocoupleCS    PIN_THERMOCOUPLE_CS
#define thermocoupleCLK   PIN_THERMOCOUPLE_CLK

// scales stuff
#define HX711_sck_1   1 //PB0
#define HX711_dout_1  1 //PB8
#define HX711_dout_2  1 //PB9

#define USART_LCD     Serial2 // PA2(TX) & PA3(RX)
#define USART_ESP     Serial1 // PA9(TX) & PA10(RX)
#define USART_DEBUG   Serial  // USB-CDC (Takes PA8,PA9,PA10,PA11)

#ifndef PIN_WIRE_SDA
#define PIN_WIRE_SDA SDA // backward compatibility
#endif
#ifndef PIN_WIRE_SCL
#define PIN_WIRE_SCL SCL // backward compatibility
#endif

#endif
