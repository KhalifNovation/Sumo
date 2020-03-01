#include "SensorSumo.h"

SensorSumo::SensorSumo()
{
}

void SensorSumo::begin(SumoPin myPin, SensorData *_pSensorData)
{
    pSensorData = _pSensorData;
    for (int i = 0; i < 5; i++)
    {
        pSensorData->DistanceSensor[i].pin = myPin.sensorDistance[i];
        pinMode(pSensorData->DistanceSensor[i].pin, INPUT);
        if (i < 2)
            pSensorData->LineSensor[i].pin = myPin.sensorLine[i];
    }
}

bool SensorSumo::readSensor()
{
    unsigned long nMillis = millis();
    if (nMillis - pMillis > 30)
    {
        uint8_t sensorState = 0;
        uint8_t sensorStateLine = 0;
        for (int i = 0; i < 5; i++)
        {
            pSensorData->DistanceSensor[i].state = digitalRead(pSensorData->DistanceSensor[i].pin);
            sensorState |= (uint8_t) pSensorData->DistanceSensor[i].state << (4-i);
            if (i < 2)
            {
                pSensorData->LineSensor[i].val =  analogRead(pSensorData->LineSensor[i].pin);
                pSensorData->LineSensor[i].state = pSensorData->LineSensor[i].val > pSensorData->LineSensor[i].thress ? false : true;
                sensorStateLine |= (uint8_t) pSensorData->LineSensor[i].state << (1-i);
                
            }
        }
        pSensorData->stateLine = sensorStateLine;
        pSensorData->stateDistance = sensorState;
        pMillis = nMillis;
        return 1;
    }
    return 0;
}

bool SensorSumo::readUpdate(){
    uint8_t sensorState = pSensorData->stateDistance;
    if(sensorState != pSensorData->prevStateDistance){
        pSensorData->prevStateDistance = sensorState;
        return 1;
    }
    return 0;
}

bool SensorSumo::readStrategy(){
    
    uint8_t sensorState = pSensorData->stateDistance;
    if(sensorState != pSensorData->prevStateDistance){
        uint8_t condition = 0;
        if(sensorState == 0b00001){
            condition = 1;
        }
        else if(sensorState == 0b10000){
            condition = 2;
        }
        else if(bitRead(sensorState,2) && (!bitRead(sensorState,0) && !bitRead(sensorState,4))){
            condition = 3;
        }
        else if(sensorState == 0b11111){
            condition = 4;
        }
        pSensorData->condition = condition;
        pSensorData->prevStateDistance = sensorState;
        return 1;
    }
    return 0;
        
    

    // uint8_t prevState = pSensorData->prevDistanceSensorCondition;
    // uint8_t state = sensorState;
    // if(state != prevState){
    //     pSensorData->prevDistanceSensorCondition = state;
    //     return 1;
    // }
    // return 0;
}