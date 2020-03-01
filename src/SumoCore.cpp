#include "SumoCore.h"

SumoCore::SumoCore()
{
}

void SumoCore::begin(SumoPin pin,SensorData *_pSensorData)
{
    myPin = pin;
    myMotor.begin(myPin);
    mySensor.begin(myPin, _pSensorData);
}

void SumoCore::forward(int speed){
    myMotor.forward(speed);
}

void SumoCore::forward(int speedL,int speedR){
    myMotor.forward(speedL,speedR);
}

void SumoCore::backward(int speed){
    myMotor.backward(speed);
}

void SumoCore::backward(int speedL,int speedR){
    myMotor.backward(speedL,speedR);
}

void SumoCore::turnLeft(int speed){
    myMotor.turnLeft(speed);
}

void SumoCore::turnRight(int speed){
    myMotor.turnRight(speed);
}

void SumoCore::stop(){
    myMotor.stop(); 
}

bool SumoCore::scan(){
    return mySensor.readSensor();
}

bool SumoCore::scanState(){
    return mySensor.readStrategy();
}

bool SumoCore::update(){
    return mySensor.readUpdate();
}

//DEBUG
