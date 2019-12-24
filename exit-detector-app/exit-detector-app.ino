#include <HCSR04.h>

const int triggerPin = 12;
const int echoPin = 13;
UltraSonicDistanceSensor distanceSensor(triggerPin, echoPin);
void setup()
{
  Serial.begin(9600); // We initialize serial connection so that we could print values from sensor.
  Serial.println("Stared at" + String(millis()));
}

const long dt = 100000;
long t = 0;
const int buff_size = 5;
float buff[buff_size];
float avg = 0;
int i = 0;

void loop()
{
  // put your main code here, to run repeatedly:
  // if (t < micros())
  // {
  //   t += dt;
  //   float dist = usonic.measureDistanceCm();
  //   Serial.println(dist);
  // }
  // Every 500 miliseconds, do a measurement using the sensor and print the distance in centimeters.
  float dist = 0.0328084 * distanceSensor.measureDistanceCm(); // Convert to feet

  i += 1;
  i = i % buff_size;
  float total = (float)(buff_size * avg);
  total -= buff[i];
  buff[i] = dist;
  total += buff[i];
  avg = total / (float)buff_size;
  Serial.println(avg);
  delay(500);
}
