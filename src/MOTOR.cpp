
#include "MOTOR.h"

MOTOR::MOTOR(){

}

void MOTOR::begin(SumoPin myPin, bool DirL, bool DirR)
{
	P_LeftA = myPin.leftMotor_A;
	P_LeftB = myPin.leftMotor_B;
	P_RightA = myPin.rightMotor_A;
	P_RightB = myPin.rightMotor_B;

	invertDirL = DirL;
	invertDirR = DirR;

	if (invertDirL)
	{
		int tmp = P_LeftA;
		P_LeftA = P_LeftB;
		P_LeftB = tmp;
	}

	if (invertDirR)
	{
		int tmp = P_RightA;
		P_RightA = P_RightB;
		P_RightB = tmp;
	}

	pinMode(P_LeftA,OUTPUT);
	pinMode(P_LeftB,OUTPUT);
	pinMode(P_RightA,OUTPUT);
	pinMode(P_RightB,OUTPUT);

}

void MOTOR::forward(int speed)
{
	forward(speed, speed);
}

void MOTOR::forward(int setSpeedL, int setSpeedR)
{
	motor_left(setSpeedL);
	motor_right(setSpeedR);
	run();
}

void MOTOR::backward(int speed)
{
	backward(speed,speed);
}

void MOTOR::backward(int setSpeedL, int setSpeedR)
{
	motor_left(-setSpeedL);
	motor_right(-setSpeedR);
	run();
}

void MOTOR::turnLeft(int speed)
{
	motor_left(-speed);
	motor_right(speed);
	run();
}

void MOTOR::turnRight(int speed)
{
	motor_left(speed);
	motor_right(-speed);
	run();
}

void MOTOR::stop()
{
	motor_left(0);
	motor_right(0);
	run();
}

void MOTOR::drive(double heading, int speed, int gain)
{
	int Lspeed;
	int Rspeed;
	Lspeed = speed + (heading);
	Rspeed = speed - (heading);

	motor_left(Lspeed);
	motor_right(Rspeed);
	run();
}

void MOTOR::motor_left(int speed)
{
	speed = constrain(speed, -255, 255);

	if (speed > 0)
	{
		DirL = true;
	}

	else
	{
		DirL = false;
	}

	SpeedL = abs(speed);
}

void MOTOR::motor_right(int speed)
{
	speed = constrain(speed, -255, 255);

	if (speed > 0)
	{
		DirR = true;
	}

	else
	{
		DirR = false;
	}

	SpeedR = abs(speed);
}

void MOTOR::run(int duration, bool debug = false)
{
	unsigned long now = millis();
	if (now - prev > duration)
	{
		if (!debug)
		{
			if (DirL)
			{
				analogWrite(P_LeftA, SpeedL);
				analogWrite(P_LeftB, 0);
			}
			else
			{
				analogWrite(P_LeftA, 0);
				analogWrite(P_LeftB, SpeedL);
			}

			if (DirR)
			{
				analogWrite(P_RightA, SpeedR);
				analogWrite(P_RightB, 0);
			}
			else
			{
				analogWrite(P_RightA, 0);
				analogWrite(P_RightB, SpeedR);
			}
		}
		else
		{
			Serial.print(SpeedL);
			Serial.print("  ");
			Serial.println(SpeedR);
		}
		prev = now;
	}
}

void MOTOR::run()
{
	if (DirL)
	{
		analogWrite(P_LeftA, SpeedL);
		analogWrite(P_LeftB, 0);
	}
	else
	{
		analogWrite(P_LeftA, 0);
		analogWrite(P_LeftB, SpeedL);
	}

	if (DirR)
	{
		analogWrite(P_RightA, SpeedR);
		analogWrite(P_RightB, 0);
	}
	else
	{
		analogWrite(P_RightA, 0);
		analogWrite(P_RightB, SpeedR);
	}
}