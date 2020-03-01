#ifndef SENSORDATA
#define SENSORDATA

typedef struct _DistanceSensor{
    int pin;
    uint8_t state;
    int prevState;
};

typedef struct _LineSensor
{
    int pin;
    int val;
    int thress = 600;
    int state;
    int prevState;
};

typedef struct SensorData
{
    _DistanceSensor DistanceSensor[5];
    _LineSensor LineSensor[2];
    uint8_t stateLine;
    uint8_t stateDistance;
    uint8_t prevStateDistance;
    uint8_t condition = 0;
};

#endif