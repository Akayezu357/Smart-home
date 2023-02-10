#include <Servo.h>

Servo myservo; 
int motionPin = 2; // motion sensor on A0 of arduino
int  motionState = 0;  
int buzzerPin = 10;   // buzzer pin
int ledPin =8;// led on pin 8

void setup() {
  myservo.attach(9);// servo on pin 10 of arduino
   myservo.write(90); //initial state of servo motor at 90 degrees
  pinMode(motionPin, INPUT);// declare motion sensor as INPUT
    pinMode(ledPin, OUTPUT);// declare led as OUTPUT
    digitalWrite(ledPin, LOW);// LED initially as turn off
    pinMode(buzzerPin, OUTPUT); // sets buzzer pin as output
}
//}

void loop() {
  motionState = digitalRead(motionPin);
  if (motionState == HIGH) { // if motion detected
    myservo.write(0);// servo turn to 0 degree
    digitalWrite(buzzerPin, HIGH);      // turn on buzzer
    digitalWrite(ledPin, HIGH);// then led turn on
  } else {
    myservo.write(90);// if no motion is still around return to 90 degree
   digitalWrite(ledPin, LOW);// led turn off
   digitalWrite(buzzerPin, LOW);      // turn OFF buzzer
  }
}

