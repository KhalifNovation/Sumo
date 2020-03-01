#ifndef _MOTOR_h
#define _MOTOR_h
#include <Arduino.h>
#include "SumoPin.h"
class MOTOR
{
public:

private:
	unsigned long prev;

	int P_LeftA;
	int P_LeftB;
	int P_RightA;
	int P_RightB;

	int pinList[4];
	int ArraySize;

	bool DirL;
	bool DirR;
	int SpeedL;
	int SpeedR;
	bool invertDirL;
	bool invertDirR;

public:
	MOTOR();
	
	void begin(SumoPin myPin,bool DirL=false, bool DirR=false);

	void forward(int speed);
    void forward(int setSpeedL, int setSpeedR);
	
    void backward(int speed);
    void backward(int setSpeedL, int setSpeedR);

	void turnLeft(int speed);
	void turnRight(int speed);
	void stop();

	void drive(double heading, int speed, int gain);

	void motor_left(int speed);
	void motor_right(int speed);

	void run();
	void run(int duration,bool debug=false);
private:


};


#endif