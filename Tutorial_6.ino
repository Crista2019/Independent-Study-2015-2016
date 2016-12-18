int sensorValue; //value of Photoresistor
int sensorLow = 1023; //may change w/ callibration
int sensorHigh = 0; //"" ""

const int ledPin = 13; //on-board LED, for callibration

void setup() {
  
  pinMode(ledPin, OUTPUT); //turns LED to output
  digitalWrite(ledPin, HIGH); //turns on LED
  
  //calibration
  while (millis() < 5000) { //millis = how long Arduino has been running since last power on or restart: FIRST 5 SECONDS
    sensorValue = analogRead(A0);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }
  
  digitalWrite(ledPin, LOW); //once calibration is complete, turn LED off
}

void loop() {
  sensorValue = analogRead(A0);
  int pitch = 
    map(sensorValue, sensorLow, sensorHigh, 50, 4000); //change last two parameters to change range of piezo frequency
    
    tone(8, pitch, 20); //(what pin to play sound on, frequency to play, length in ms)
    
    delay(10);
}
