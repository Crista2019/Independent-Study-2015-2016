#include <Servo.h> //includes servo library
Servo myServo; //object

int const potPin = A0; //input
int potVal; //hold analog value
int angle; //value of angle to move to, output

void setup() {
  myServo.attach(9);

  Serial.begin(9600);
}

void loop() {
  potVal = analogRead(potPin);
  Serial.print("potVal: ");
  Serial.print(potVal);
  angle = map(potVal, 0, 1023, 0, 179); //changes values of 0-1023 to 0-179
  Serial.print(", angle: ");
  Serial.print(angle);

  myServo.write(angle);
  delay(15);
}
