/*
  Button

 Turns on and off a light emitting diode(LED) connected to digital
 pin 13, when pressing a pushbutton attached to pin 2.


 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground

 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.


 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Button
 */

 #include <RCSwitch.h>
 
// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 7;     // the number of the pushbutton pin
const int ledPin =  4;      // the number of the LED pin
const int switchPin = 2;
const int doorPin = 13;


// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
boolean wasOn = HIGH;
boolean x = LOW;
RCSwitch mySwitch = RCSwitch();

void setup() {

  Serial.begin(9600);
  mySwitch.enableTransmit(10);
  
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

  pinMode(switchPin, INPUT);

  pinMode(doorPin, OUTPUT);

  digitalWrite(switchPin, HIGH);
}

void loop() {
  
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    wasOn = HIGH;
    digitalWrite(ledPin, x);
  } else {
    // turn LED off:
    if(wasOn){
      x = !x;
      wasOn = LOW;
    }
  }
  
  if(x == HIGH) {
    if(digitalRead(switchPin) == LOW){
      mySwitch.send(5393, 24);
      digitalWrite(doorPin, LOW);  
    }
    else{
      mySwitch.send(5396, 24);
      digitalWrite(doorPin, HIGH);
      delay(10);
      digitalWrite(doorPin, LOW);
    }
   }
}
