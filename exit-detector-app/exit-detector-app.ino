#include <HCSR04.h>
#include "inc/RingBuffer.h"

// Distance Sensor 1
const int triggerPin1 = 12;
const int echoPin1 = 13;
UltraSonicDistanceSensor dSensor1(triggerPin1, echoPin1);

// Distance Sensor 2
const int triggerPin2 = 11;
const int echoPin2 = 10;
UltraSonicDistanceSensor dSensor2(triggerPin2, echoPin2);

RingBuffer buff1(10);
RingBuffer buff2(10);

void setup()
{
  Serial.begin(9600); // We initialize serial connection so that we could print values from sensor.
  Serial.println("Applicationg Running!");
}

const long dt = 100;
long t = 0;

void loop()
{
  // put your main code here, to run repeatedly :
  if (t < millis())
  {
    t += dt;
    double dist1 = 0.0328084 * dSensor1.measureDistanceCm(); // Convert to feet
    buff1.addValue(dist1);
    double dist2 = 0.0328084 * dSensor2.measureDistanceCm(); // Convert to feet
    buff2.addValue(dist2);

    Serial.println("D1: " + String(buff1.getMean()) + ", D2: " + String(buff2.getMean()));
  }
}
