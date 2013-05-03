// Resources for the melody
#include "pitches.h"

// Variables
long waitPressDelay = 5000; // Delay to touch button
long preceiveDelay = 2000; // Delay to preceive the interaction or faillure
int box = 4;
int speakerPin = 4;
int maxButtons = 2; // The buttons that are used. Zero is included, thus 0,1,2 etc.
long lastRandom = 0;
// LEDs
int ledPin1 = 2;
int ledPin2 = 3;

// Buttons
int switchPinOne = 11;
int switchPinTwo = 12;
boolean lastButtonStateOne = LOW;
boolean lastButtonStateTwo = LOW;
boolean newButtonStateOne;
boolean newButtonStateTwo;

// notes in the melody
int melody[] = {
  NOTE_B4, NOTE_G4,0, NOTE_A3, NOTE_DS7,NOTE_AS6, NOTE_G3  , NOTE_C4};
int melody2[] = {
  NOTE_FS6, NOTE_G6,NOTE_G3, NOTE_AS6, NOTE_DS7,0, NOTE_G4, NOTE_B4};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4,4,4,4,4 };

// Setup the I/O
void setup(){
  Serial.begin(9600);
  pinMode(switchPinOne,INPUT);
  pinMode(switchPinTwo,INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

// Do this all the time
void loop(){
  long currentTime;
  long waitingTime;

  // Here is where the Game Element starts.
  switch(randomSelect()){
  case 0:
    // Arrange the stopping time
    currentTime = millis();
    waitingTime = millis() + waitPressDelay;

    // Display the led from the button
    digitalWrite(ledPin1, HIGH);

    // Wait for the user to interact... If time is over stop waiting.
    while(waitingTime >= currentTime) {
      newButtonStateOne = debounce(lastButtonStateOne, switchPinOne); //Read and debounce

        if(newButtonStateOne == HIGH ) { // Check if pressed. If pressed play the sound(s).
        playMelodyOne();
        delay(1000);
        digitalWrite(ledPin1, LOW);
        newButtonStateOne = LOW; // Set the button value back
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
      newButtonStateTwo = debounce(lastButtonStateTwo, switchPinTwo); //Read and debounce

      if(newButtonStateTwo == HIGH ) { // Check if pressed. If pressed play the sound(s).
        playMelodyTwo(); // play the tune
        delay(1000);
        digitalWrite(ledPin2, LOW); // set the led low
        newButtonStateTwo = LOW; // Set the button value back
        return; // Everything is done! Return to loop().
      } 
      currentTime = millis(); // update the current time
    }
    break;
  }

  // Set all the LEDs off again. Also the speaker
  digitalWrite(ledPin1, LOW); 
  digitalWrite(ledPin2, LOW); 
  digitalWrite(box, LOW);
  // Wait for the user to perceive the interaction.
  delay(preceiveDelay);	
}



boolean debounce(boolean last, int pin){
  boolean current = digitalRead(pin);

  if(current != last){
    delay(5);
    boolean current = digitalRead(pin);
  }
  return current;
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
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    tone(speakerPin, melody[thisNote],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
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
    int noteDuration = 1000/noteDurations[thisNote];
    tone(speakerPin, melody2[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(speakerPin);
  }
  delay(1000);
}








