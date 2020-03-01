#include <Sumo.h>

bool strategyFront = false;
bool strategyBack = false;
bool strategyLeft = false;
bool strategyRight = false;

void setup()
{
    Serial.begin(9600);
    Sumo.begin(mySumoPin, &mySensorData);
    pinMode(7, INPUT_PULLUP);
    pinMode(13, OUTPUT);
    while (digitalRead(7) || mySensorData.condition == 0)
    {
        if (Sumo.scan())
        {
            if (Sumo.scanState())
            {
                // Serial.println(mySensorData.stateDistance, BIN);
                Serial.println(mySensorData.condition);
            }
        }
    }

    switch (mySensorData.condition)
    {
    case 1:
        digitalWrite(13, HIGH);
        delay(300);
        digitalWrite(13, LOW);
        strategyRight = true;
        break;

    case 2:
        digitalWrite(13, HIGH);
        delay(300);
        digitalWrite(13, LOW);
        delay(300);
        digitalWrite(13, HIGH);
        delay(300);
        digitalWrite(13, LOW);
        strategyLeft = true;
        break;

    case 3:
        digitalWrite(13, HIGH);
        delay(300);
        digitalWrite(13, LOW);
        delay(300);
        digitalWrite(13, HIGH);
        delay(300);
        digitalWrite(13, LOW);
        delay(300);
        digitalWrite(13, HIGH);
        delay(300);
        digitalWrite(13, LOW);
        strategyFront = true;
        break;
    case 4:
        digitalWrite(13, HIGH);
        delay(300);
        digitalWrite(13, LOW);
        delay(300);
        digitalWrite(13, HIGH);
        delay(300);
        digitalWrite(13, LOW);
        delay(300);
        digitalWrite(13, HIGH);
        delay(300);
        digitalWrite(13, LOW);
        delay(300);
        digitalWrite(13, HIGH);
        delay(300);
        digitalWrite(13, LOW);
        strategyBack = true;
        break;
    }
    while (digitalRead(7))
    {
    }
    delay(3000);
}

void loop()
{
    if (Sumo.scan())
    {
        if (strategyLeft)
        {
            task1();
        }

        else if (strategyRight)
        {
            task2();
        }

        else if (strategyFront)
        {
            task3();
        }

        else if (strategyBack)
        {
            task4();
        }
    }
}

void task1()
{
    Serial.println("Left");
    if (!mySensorData.LineSensor[0].state || !mySensorData.LineSensor[1].state)
    {
        if (mySensorData.stateDistance == 0b00001)
        {
            Sumo.turnRight(100);
        }
        else if (mySensorData.stateDistance == 0b00011)
        {
            Sumo.turnRight(100);
        }
        else if (mySensorData.stateDistance == 0b00010)
        {
            Sumo.forward(100);
        }
        else if (mySensorData.stateDistance == 0b00110)
        {
            Sumo.forward(100);
        }
        else if (mySensorData.stateDistance == 0b00100)
        {
            Sumo.forward(100);
        }
        else if (mySensorData.stateDistance == 0b01100)
        {
            Sumo.forward(100);
        }
        else if (mySensorData.stateDistance == 0b01000)
        {
            Sumo.forward(100);
        }
        else if (mySensorData.stateDistance == 0b11000)
        {
            Sumo.turnLeft(100);
        }
        else if (mySensorData.stateDistance == 0b10000)
        {
            Sumo.turnLeft(100);
        }
        else if (mySensorData.stateDistance == 0b00000)
        {
            Sumo.turnLeft(100);
        }
        
    }
    else{
        Sumo.stop();
        delay(100);
        Sumo.backward(100);
        delay(500);
    }
}

void task2()
{
    Serial.println("Right");
}

void task3()
{
    Serial.println("Front");
}

void task4()
{
    Serial.println("Back");
}