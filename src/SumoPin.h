#ifndef SUMOPIN
#define SUMOPIN

#include <Arduino.h>

struct SumoPin
{
    int leftMotor_A=10;
    int leftMotor_B=11;
    int rightMotor_A=6;
    int rightMotor_B=3;



    int sensorDistance[5]={
        8,5,A4,A3,A2
    };

    int sensorLine[2] = {
        A0,A1
    };

    void setLeftMotor(int leftMotor_A,int leftMotor_B){
        this->leftMotor_A = leftMotor_A;
        this->leftMotor_B = leftMotor_B;
    }

    void setRightMotor(int rightMotor_A, int rightMotor_B){
        this->rightMotor_A = rightMotor_A;
        this->rightMotor_B = rightMotor_B;
    }

    void setSensorDistance(int sensorLeft, int sensorCenterLeft, int sensorCenter, int sensorCenterRight, int sensorRight){
        sensorDistance[0] = sensorLeft;
        sensorDistance[1] = sensorCenterLeft;
        sensorDistance[2] = sensorCenter;
        sensorDistance[3] = sensorCenterRight;
        sensorDistance[4] = sensorRight;
    }

    void setSensorLine(int leftSensor, int rightSensor){
        sensorLine[0] = leftSensor;
        sensorLine[1] = rightSensor;
    }


};

#endif