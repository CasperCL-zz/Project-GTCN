// Resources for the melody
#include "pitches.h"

// Variables
long waitPressDelay = 5000; // Delay to touch button
long preceiveDelay = 2000; // Delay to preceive the interaction or faillure
//int box = 2;
int speakerPin = 2;
int maxButtons = 4; // The buttons that are used. Zero is included, thus 0,1,2 etc.
long lastRandom = 0;
// LEDs
int ledPin1 = 3;
int ledPin2 = 4;
int ledPin3 = 5;
int ledPin4 = 6;
//int waitPin = 7;
//int sendPin = 8;

int val = 0;         // variable to store the value read from the sensor pin
int MINVAL = 100;  // threshold value to decide when the detected sound is a knock or not
int MAXVAL = 800;

// Buttons
int switchPinOne = 0;
int switchPinTwo = 1;
int switchPinThree = 2;
int switchPinFour = 3;


// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_C4,NOTE_G4, NOTE_G4, NOTE_A4,NOTE_A4, NOTE_G4,0  , NOTE_F4,NOTE_F4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_D4,NOTE_D4,NOTE_C4};
int melody2[] = {
  NOTE_FS6, NOTE_G6,NOTE_G3, NOTE_AS6, NOTE_DS7,0, NOTE_G4, NOTE_B4};
int melody3[] = {
  NOTE_FS6, NOTE_G6,NOTE_G3, NOTE_G3, NOTE_DS7,0, NOTE_G4, NOTE_C4};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 4, 4, 4,4,4,4,16,8,8,8,8,8,4,4,4,4 };

int noteDurations2[] = {
  4, 4, 4, 4,4,4,4,16,8,8,8,8,8,4,4,4,4 };

int noteDurations3[] = {
  4, 4, 4, 4,4,4,4,16,8,8,8,8,8,4,4,4,4 };

int breakbetweennotes[] = {
  4,4,4,4,4,4,4,4,2,4,4,4,4,4,4,4,4,4 };

int breakbetweennotes2[] = {
  4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 };

int breakbetweennotes3[] = {
  4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 };

// Setup the I/O
void setup(){
  Serial.begin(9600);

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);

}

// Do this all the time
void loop(){
  long currentTime;
  long waitingTime;

  switch(randomSelect()){
  case 0:
    // Arrange the stopping time
    currentTime = millis();
    waitingTime = millis() + waitPressDelay;

    // Display the led from the button
    digitalWrite(ledPin1, HIGH);

    // Wait for the user to interact... If time is over stop waiting.
    while(waitingTime >= currentTime) {
      val = analogRead(switchPinOne);            // read the sensor and store it in the variable "val"

      Serial.println(val);
      if(val < 200){
        val = analogRead(switchPinOne);  
      }

      if(val > MINVAL && val < MAXVAL) { // Check if pressed. If pressed play the sound(s).
        Serial.println("pressed");
        playMelodyOne();
        delay(1000);
        digitalWrite(ledPin1, LOW);
        return; // Everything is done! Return to loop().
      } 
      currentTime = millis(); // update the current time
    }
    break;

  case 1:
    // Arrange the stopping time
    currentTime = millis();
    waitingTime = millis() + waitPressDelay;

    // Display the led from the button
    digitalWrite(ledPin2, HIGH);

    // Wait for the user to interact... If time is over stop waiting.
    while((waitingTime >= currentTime)) {
      val = analogRead(switchPinTwo);            // read the sensor and store it in the variable "val"

      Serial.println(val);
      if(val < 200){
        val = analogRead(switchPinTwo);  
      }

      if(val > MINVAL && val < MAXVAL) { // Check if pressed. If pressed play the sound(s).
        Serial.println("pressed");
        playMelodyTwo(); // play the tune
        delay(1000);
        digitalWrite(ledPin2, LOW); // set the led low

        return; // Everything is done! Return to loop().
      } 
      currentTime = millis(); // update the current time
    }
    break;

  case 2:
    // Arrange the stopping time
    currentTime = millis();
    waitingTime = millis() + waitPressDelay;

    // Display the led from the button
    digitalWrite(ledPin3, HIGH);

    // Wait for the user to interact... If time is over stop waiting.
    while((waitingTime >= currentTime)) {
      val = analogRead(switchPinThree);            // read the sensor and store it in the variable "val"

      Serial.println(val);
      if(val < 200){
        val = analogRead(switchPinThree);  
      }

      if(val > MINVAL && val < MAXVAL) { // Check if pressed. If pressed play the sound(s).
        Serial.println("pressed");
        playMelodyThree(); // play the tune
        delay(1000);
        digitalWrite(ledPin3, LOW); // set the led low

        return; // Everything is done! Return to loop().
      } 
      currentTime = millis(); // update the current time
    }
    break;
  case 3:
    // Arrange the stopping time
    currentTime = millis();
    waitingTime = millis() + waitPressDelay;

    // Display the led from the button
    digitalWrite(ledPin4, HIGH);

    // Wait for the user to interact... If time is over stop waiting.
    while((waitingTime >= currentTime)) {
      val = analogRead(switchPinFour);            // read the sensor and store it in the variable "val"

      Serial.println(val);
      if(val < 200){
        val = analogRead(switchPinFour);  
      }

      if(val > MINVAL && val < MAXVAL) { // Check if pressed. If pressed play the sound(s).
        Serial.println("pressed");
        playMelodyThree(); // play the tune
        delay(1000);
        digitalWrite(ledPin4, LOW); // set the led low

        return; // Everything is done! Return to loop().
      } 
      currentTime = millis(); // update the current time
    }
    break;


  }

  // Set all the LEDs off again. Also the speaker
  digitalWrite(ledPin1, LOW); 
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW); 
    digitalWrite(ledPin4, LOW); 
  //digitalWrite(box, LOW);
  // Wait for the user to perceive the interaction.
  delay(preceiveDelay);	
}


long randomSelect(){
  long randNumber  = 0; // The number to return.
  randNumber  = random(maxButtons);

  // Do not choose the same button
  while(lastRandom == randNumber){
    randNumber  = random(maxButtons);
  }

  lastRandom =  randNumber;
  return randNumber;
}



// Melodies
void playMelodyOne(){
  for (int thisNote = 0; thisNote < 15; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    tone(speakerPin, melody[thisNote],noteDuration);

    int breakbetweennote = 1000/breakbetweennotes[thisNote];


    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:

    delay(breakbetweennote);
    // stop the tone playing:
    noTone(speakerPin);
  }
  delay(1000);
}

void playMelodyTwo(){
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration2 = 1000/noteDurations2[thisNote];
    tone(speakerPin, melody2[thisNote], noteDuration2);

    int breakbetweennote2 = 1000/breakbetweennotes2[thisNote];


    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:

    delay(breakbetweennote2);
    // stop the tone playing:
    noTone(speakerPin);
  }
  delay(1000);
}


void playMelodyThree(){
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration3 = 1000/noteDurations3[thisNote];
    tone(speakerPin, melody3[thisNote],noteDuration3);
    int breakbetweennote3 = 1000/breakbetweennotes3[thisNote];


    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:

    delay(breakbetweennote3);
    // stop the tone playing:
    noTone(speakerPin);
  }
  delay(1000);
}


















