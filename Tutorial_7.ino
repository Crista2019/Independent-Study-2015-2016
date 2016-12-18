int buttons[] = {2, 3, 4, 5, 6, 7}; //sets up an array containing 6 integers

int notes[] = {262, 330, 400, 550}; //array of frequencies, 4 notes

void setup() {
  Serial.begin(9600); //communication w/ computer at a baud of 9600 bps
}

void loop() {
  int keyVal = analogRead(A0); //holds value of Input A0
  Serial.print(keyVal); //prints

  //ASSIGNS VALUE TO EACH INDIVIDUAL TONE
  if(keyVal == 1023){ 
    tone(8, notes[0]);  
  }
  else if(keyVal >= 990 && keyVal <= 1010) {
    tone(8, notes[1]);
  }
  else if(keyVal >= 505 && keyVal <= 515){
    tone(8, notes[2]);
  }
  else if(keyVal >= 5 && keyVal <= 10){
    tone(8, notes[3]);
  }
   else{
      noTone(8);
   }
}
