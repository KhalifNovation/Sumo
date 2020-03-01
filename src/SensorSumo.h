#ifndef SENSORSUMO
#define SENSORSUMO

#include <Arduino.h>
#include "SensorData.h"
#include "SumoPin.h"

class SensorSumo
{
private:
    SensorData *pSensorData;
    unsigned long pMillis;
public:
    SensorSumo();

    void begin(SumoPin myPin, SensorData *_pSensorData);
    
    bool readSensor();
    bool readUpdate();
    bool readStrategy();
};

#endif