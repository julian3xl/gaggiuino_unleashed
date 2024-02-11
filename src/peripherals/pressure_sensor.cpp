#include "pressure_sensor.h"

#include "i2c_bus_reset.h"
//***#include "../lcd/lcd.h"
#include "../log.h"
#include "../pindef.h"

#if defined ADC_ADS1015
#include "pressure_sensor_ads1015.h"

#elif defined ADC_ADS1115
#include "pressure_sensor_ads1115.h"

#else
class DummyADS {
public:
  void begin() {}

  void setGain(uint8_t gain) {}
  void setDataRate(uint8_t dataRate) {}
  void setMode(uint8_t mode) {}
  int16_t readADC_SingleEnded() { return 0; }
  int16_t readADC_Differential_0_1() { return 0; }
  int16_t readADC_Differential_2_3() { return 0; }
  int16_t readADC(uint8_t channel) { return 0; }
  int16_t getLastConversionResults() { return 0; }
  bool isConnected() { return false; }
  short getError() { return 0; }
} ADS;
#endif

float previousPressure;
float currentPressure;

void adsInit(void) {
  ADS.begin();
  ADS.setGain(0);      // 6.144 volt
  ADS.setDataRate(4);  // fast
  ADS.setMode(0);      // continuous mode
  ADS.readADC(0);      // first read to trigger
}

float getPressure(void) {  //returns sensor pressure data
  // voltageZero = 0.5V --> 25.6 (8 bit) or 102.4 (10 bit) or 2666.7 (ADS 15 bit)
  // voltageMax = 4.5V --> 230.4 (8 bit) or 921.6 (10 bit) or 24000 (ADS 15 bit)
  // range 921.6 - 102.4 = 204.8 or 819.2 or 21333.3
  // pressure gauge range 0-1.2MPa - 0-12 bar
  // 1 bar = 17.1 or 68.27 or 1777.8

  getAdsError();

  previousPressure = currentPressure;
#if defined ADC_ADS1015
  currentPressure = (ADS.getValue() - 166) / 111.11f; // 12bit
#elif defined ADC_ADS1115
  currentPressure = (ADS.getValue() - 2666) / 1777.8f; // 16bit
#else
  currentPressure = 0;
  LOG_ERROR("ADS not defined");
#endif

  return currentPressure;
}

void getAdsError(void) {
  // Reset the hw i2c to try and recover comms
  // on fail to do so throw error
  i2cResetState();

  // Throw error code on ADS malfunction/miswiring
  // Invalid Voltage error code: -100
  // Invalid gain error code: 255
  // Invalid mode error code: 254
  short result = ADS.getError();
  if (result == 0) return;
  char tmp[25];
  unsigned int check = snprintf(tmp, sizeof(tmp), "ADS error code: %i", result);
  if (check > 0 && check <= sizeof(tmp)) {
    //***lcdShowPopup(tmp);
  }
}

//Serial.print(digitalRead(PIN_SCL));    //should be HIGH
//Serial.println(digitalRead(PIN_SDA));   //should be HIGH, is LOW on stuck I2C bus
// ERROR CODE 1: I2C bus error. Could not clear sclPin clock line held low
// ERROR CODE 2: I2C bus error. Could not clear. sclPin clock line held low by slave clock for > 2sec
// ERROR CODE 3: I2C bus error. Could not clear. sdaPin data line held low
void i2cResetState(void) {
  if (digitalRead(PIN_WIRE_SDA) != HIGH || digitalRead(PIN_WIRE_SCL) != HIGH || !ADS.isConnected()) {
    LOG_INFO("Reset I2C pins");
    short result = I2C_ClearBus(PIN_WIRE_SDA, PIN_WIRE_SCL);
    char tmp[25];
    unsigned int check = snprintf(tmp, sizeof(tmp), "I2C error code: %i", result);

    if (check > 0 && check <= sizeof(tmp)) {
      //***result == 0 ? adsInit() : lcdShowPopup(tmp);
      if (result == 0) {
        adsInit();
      }
    }

    delay(50);
  }
}
