#ifndef ESP_COMMS_H
#define ESP_COMMS_H

#include "../lib/mcu_comms.h"

void espCommsInit();

void espCommsReadData();

void espCommsSendSensorData(const SensorState& state, uint32_t frequency = 1000);
void espCommsSendShotData(ShotSnapshot& shotData, uint32_t frequency = 100);
void espCommsSendTareScalesCommand();

void onProfileReceived(Profile& profile);
void onRemoteScalesWeightReceived(float weight);
void onRemoteScalesDisconnected();

#endif
