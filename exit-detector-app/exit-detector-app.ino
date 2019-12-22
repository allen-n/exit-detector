void setup() {
  // put your setup code here, to run once:
  Serial.println("Stared at" + String(millis()));
}

long dt = 10000;
long t = 0;

void loop() {
  // put your main code here, to run repeatedly:
  if ( t < micros()) {
    t += dt;
    Serial.println("Time was " + String(micros()) + " u-seconds.");
  }
}
