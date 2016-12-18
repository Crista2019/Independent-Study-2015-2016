#include <Servo.h>
Servo myServo;

const int piezo = A0;
const int switchPin = 2;
const int yellowLed = 3;
const int greenLed = 4;
const int redLed = 5;

int knockVal;
int switchVal;
const int quietKnock = 10;
const int loudKnock = 100;

boolean locked = false;
int numberOfKnocks = 0;

//creating function to check validity of knocks
boolean checkForKnock(int value){
  if(value > quietKnock && value < loudKnock){
    digitalWrite(yellowLed, HIGH);
    delay(1000);
    digitalWrite(yellowLed, LOW);
    Serial.print("Valid knock of value ");
    Serial.print(value);
    return true;
    }
  else {
    Serial.print("Bad knock value ");
    Serial.print(value);
    return false;
  }
}


void setup(){
  myServo.attach(9);
  pinMode(yellowLed, OUTPUT);
   pinMode(redLed, OUTPUT);
   pinMode(greenLed, OUTPUT);
   pinMode(switchPin, INPUT);
   Serial.begin(9600);

  //UNLOCK at the beginning
   digitalWrite(greenLed, HIGH);
   myServo.write(0);
   Serial.print("The box is unlocked");
   delay(1000);
   }

void loop() {
  //Checking switch
  if(locked == false){
    switchVal = digitalRead(switchPin);

    //LOCK
    if(switchVal == HIGH){
      locked = true;
      digitalWrite(greenLed, LOW);
      digitalWrite(redLed, HIGH);
      myServo.write(90);
      Serial.print("The box is locked!");
      delay(1000);
    }
  }

  //Checking the knock sensor
  if(locked == true){
    knockVal = analogRead(piezo);

    //Only counting valid knocks
    if(numberOfKnocks < 3 && knockVal > 0){
      if(checkForKnock(knockVal) == true){
        numberOfKnocks ++;
      }
      Serial.print(3-numberOfKnocks);
      Serial.print(" more knocks to go");
    }

    //UNLOCK
    if(numberOfKnocks >= 3){
      locked = false;
      myServo.write(0);
      digitalWrite(greenLed, HIGH);
      digitalWrite(redLed, LOW);
      Serial.print("The box is unlocked");
      delay(2000000);
    }
  }
}

