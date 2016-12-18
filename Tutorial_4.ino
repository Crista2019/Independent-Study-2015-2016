//inputs 
const int greenLEDPin = 9; //const is unchangeable
const int redLEDPin = 11;
const int blueLEDPin = 10;

//outputs
const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

//sensor value input
int redValue = 0; //set to 0 because they can be redifined
int greenValue = 0;
int blueValue = 0;

//output for dafing LEDS
int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue= 0;

void setup() {
  Serial.begin(9600); //bits per second

  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
}

void loop() {
  //read sensor values of RGB Photoresistors
  redSensorValue = analogRead(redSensorPin);
  delay(5);
  greenSensorValue = analogRead(redSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);

  //prints sensor values on one line \t is tab
  Serial.print("Raw Sensor Values \t Red ");
  Serial.print(redSensorValue);
  Serial.print("\t Green: ");
  Serial.print(greenSensorValue);
  Serial.print("\t Blue: ");
  Serial.print(blueSensorValue);

  //converts sensor reading(between 0-1023) to an analog value between 0-255
  redValue = redSensorValue/4;
  greenValue = greenSensorValue/4;
  blueValue = blueSensorValue/4;

  //prints new mapped values on own line
  Serial.print("Mapped Sensor Value \t Red:");
  Serial.print(redValue);
  Serial.print("\t Green: ");
  Serial.print(greenValue);
  Serial.print("\t Blue: ");
  Serial.print(blueValue);

  //sets the LED light levels\
  analogWrite(redLEDPin, redValue);
  analogWrite(greenLEDPin, greenValue);
  analogWrite(blueLEDPin, blueValue);
  
}
