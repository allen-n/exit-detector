# exit-detector
Ultrasonic Proximity Exit Detector IoT System

## What's the Point?
Existing Exit Detection methodologies are overpriced and have limited functionality. By exit detectors, I mean the devides used to determine when someone is trying to leave an electronically operated gate, and then opening said gate. 

This system uses two ultrasonic sensors to determine presence of a car trying to leave a gate (by aiming the beams non-parallel and detecting objects of adequate length and distance from the sensors) and triggering the 'open' mechanism on the gate via mechanical relay.

*Coming Soon*
* *Images of the setup*
* *CAD schematics of the enclosure*
* *Demo Videos*

## Getting up and running

### Hardware Requirements

* 1 x Microcontroller: a board compatible with the Arduino IDE, I am using an Arduino Leonardo for initial testing (you can get one [here](https://store.arduino.cc/usa/leonardo))
* 1 x Mechanical Relay: I used [this](https://smile.amazon.com/gp/product/B07M88JRFY/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1) board from Youngneer but any board with a trigger voltage <= 5 V compatible with Arduino-like boards should do. The opto isolation is also a nice touch.
* 2 x Ultrasonic Distance Sensor: I used the [HC-SR04](https://smile.amazon.com/gp/product/B01COSN7O6/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1) sensor from ELEGOO, but any Arduino compatible (i.e. 5V or less VCC, analog interface) board should do.
* Breadboard, PCB, Various passive components: *Details TBD* 
  
### Software Requirements
* Arduino IDE (get it [here](https://www.arduino.cc/en/main/software)) or VS Code with Arduino Extension. Really, anything that will let you compile and run code for an Arduino.
* 
* *More information TBD*

### TODOs:
- Add a temperature sensor for temperature compensation in distance sensing.

## Usage

## Authors

* [Allen Nikka](https://github.com/allen-n)

## Ackowledgements
* Martin Šošić ([Martinsos](https://github.com/Martinsos)) - For providing the [HC-SR04 Library](https://github.com/Martinsos/arduino-lib-hc-**sr04**) used in this project. 