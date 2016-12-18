const int switchPin = 8; //name of pin the tilt switch is connected to
unsigned long previousTime = 0; //holds the value of how long the LED has been running

//used to compare the state of the switch from one loop to another (global value rather than local)
int switchState = 0;
int prevSwitchState = 0;

int led = 2; //used to count which LED will be the NEXT to get turned on

long interval = 3000; //6000,000 milliseconds is 10 minutes

void setup() {
  for(int x = 2; x < 8; x++){
    pinMode(x, OUTPUT);
  }

  pinMode(switchPin, INPUT);
}

void loop() {
  unsigned long currentTime = millis();
  if(currentTime - previousTime > interval){
    previousTime = currentTime;
    digitalWrite(led, HIGH);
    delay(200);
    led++;
    if(led == 7){
      }
    }
  switchState = digitalRead(switchPin);
 
  if(switchState != prevSwitchState){
    for(int x = 2; x< 8; x++){
      digitalWrite(x, LOW);
      }
      
    led = 2;
    previousTime = switchState;
  }
  prevSwitchState = switchState;
}
