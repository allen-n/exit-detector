#include <HCSR04.h>
#include "inc/RingBuffer.h"
#include "inc/DistDebouncer.h"

// Distance Sensor 1
const int triggerPin1 = 12;
const int echoPin1 = 13;
UltraSonicDistanceSensor dSensor1(triggerPin1, echoPin1);

// Distance Sensor 2
// const int triggerPin2 = 11;
// const int echoPin2 = 10;
// UltraSonicDistanceSensor dSensor2(triggerPin2, echoPin2);

// Constants
const int buffSize = 40;
const int relayPin = 8;

// Ring buffers
RingBuffer buff1(buffSize);
// RingBuffer buff2(10);

// Target Distance Debouncing
const double targetDist = 5;
const double threshold = 0.30;
const int dbTime = 4000; // Debounce time in ms

DistDebouncer db(targetDist, threshold, dbTime);

void setup()
{
  Serial.begin(9600);
  Serial.println("Application Running!");
  pinMode(relayPin, OUTPUT);
}

// Delta time variables for main loop
const unsigned long dt = 100;
unsigned long prevMillis = 0;
const double cmToFeet = 0.0328084; // Conversion from cm to feet

void loop()
{

  unsigned long currentMillis = millis();
  if (currentMillis - prevMillis > dt)
  {
    // Update main delta time loop
    prevMillis = currentMillis;

    // Read and buffer sensor 1
    double dist1 = cmToFeet * dSensor1.measureDistanceCm(); // Convert to feet
    buff1.addValue(dist1);

    // Read and buffer sensor 2
    // double dist2 = cmToFeet * dSensor2.measureDistanceCm(); // Convert to feet
    // buff2.addValue(dist2);

    // Determine if sensor 1 is in target range
    bool isTarget = db.isAtTarget(buff1.getMean());
    
    // Two sensor print statement
    // Serial.println("D1: " + String(buff1.getMean()) + ", ~=3: " + String(isTarget) + ", D2: " + String(buff2.getMean()));
    
    // One sensor print statement
    Serial.println("D1: " + String(buff1.getMean()) + ", @target(" + String(targetDist) + "): " + String(isTarget));

    // Relay activation
    if (isTarget)
    {

      digitalWrite(relayPin, HIGH);
      delay(100);
      digitalWrite(relayPin, LOW);
    }
  }
}
