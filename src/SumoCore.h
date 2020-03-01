#ifndef SUMOCORE
#define SUMOCORE

#include <Arduino.h>
#include "SumoPin.h"
#include "MOTOR.h"
#include "SensorSumo.h"


class SumoCore
{
private:
    MOTOR myMotor;
    SensorSumo mySensor;
    SumoPin myPin;
    
public:
    SumoCore();

    void begin(SumoPin pin, SensorData *_pSensorData);

    void forward(int speed);
    void forward(int speedL, int speedR);

    void backward(int speed);
    void backward(int speed, int speedR);
    
    void turnLeft(int speed);
    void turnRight(int speed);

    void stop();

    bool scan();
    bool scanState();
    bool update();



//DEBUG
};

#endif