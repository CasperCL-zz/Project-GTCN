// Resources for the melody (the notes frequences)
#include "pitches.h"

/**
 * This little program runs the Arduino UNO. It can also be applied to the Arduino Duemilanove with certain messures.
 * This program is designed to play sounds, after one of the four available buttons is pressed. Note that it doesn't
 * matter now which buttons is pressed as it did in version 2 of 'MelodyGame'.
 *
 * For this program to run you need:
 *   - One Arduino board. Type doesn't really matter, however 14 DI/O and 6AIN is required
 *   - A minimum of 4 LEDs connected to the Digital I/O pins
 *   - A number of 4 buttons connected to the Analog Input (AIN)
 *   - A number of 4 resistors for every GND of the buttons.
 * NOTE: NO SHIELDS ARE INVOLVED.
 *
 * @author Casper, Rik, Ilona, Robin, Jurgen
 * @version 3.0
 */


/** 
 * Variables declarations
 */
//// Pin Variables
// LEDs (On Digital I/O)
int ledPin1 = 3;
int ledPin2 = 4;
int ledPin3 = 5;
int ledPin4 = 6;

// Buttons (On Analog Input)
int switchPinOne = 0;
int switchPinTwo = 1;
int switchPinThree = 2;
int switchPinFour = 3;
int maxButtons = 4; // The buttons that are used. Zero is excluded, thus 1,2,3 etc. Make sure that this variable is updated!

// Speaker (On Digital I/O)
int speakerPin = 2;  // The pin of the speakers

// Communication (On Digital I/O)
int waitPin = 7;
int sendPin = 8;

//// Missalanious variables
long currentTime;
long waitingTime;
long waitPressDelay = 5000; // Delay to touch button
long preceiveDelay = 2000; // Delay to preceive the interaction or faillure
long lastRandom = 0;   // The last random value is stored here.
int val = 0;         // variable to store the value read from the sensor pin
int MINVAL = 100;  // This is the variable that defines on what signal of the button it should do something.
int MAXVAL = 800;  // This is the variable that defines on what signal of the button it should NOT do something.


//// Tone and Note variables
// Notes of the melodies. NOTE_G4 e.g. is a frequency that can be found in the file called: "pitches.h"
int melody[] = {
  NOTE_C4, NOTE_C4,NOTE_G4, NOTE_G4, NOTE_A4,NOTE_A4, NOTE_G4,0  , NOTE_F4,NOTE_F4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_D4,NOTE_D4,NOTE_C4};
int melody2[] = {
  NOTE_FS6, NOTE_G6,NOTE_G3, NOTE_AS6, NOTE_DS7,0, NOTE_G4, NOTE_B4};
int melody3[] = {
  NOTE_FS6, NOTE_G6,NOTE_G3, NOTE_G3, NOTE_DS7,0, NOTE_G4, NOTE_C4};

// Note durations  
// For every Meldoy there is a specific note duration array.
// Definition: 4 = quarter note, 8 = eighth note, etc.:
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
/**
 *  End of variables declaration 
 */


// Setup the I/O pins
void setup(){
  // 9600 is the number of reads/writes that are involved to the PC.
  // This is not really important, but 9600 is used in many situations.
  Serial.begin(9600);

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
}

// This is the code where all the stuff happens. This code is checked every time and is a loop.
void loop(){
  // Pick a number
  long choice = randomSelect();

  // Select randomly a LED (group) to flash.
  switch(choice){
  case 0:
    // Display the led from the button
    digitalWrite(ledPin1, HIGH);
    break;

  case 1:
    // Display the led from the button
    digitalWrite(ledPin2, HIGH);
    break;

  case 2:
    // Display the led from the button
    digitalWrite(ledPin3, HIGH);
    break;
  case 3:
    // Display the led from the button
    digitalWrite(ledPin4, HIGH);
    break;
  }
  // Determine if there is something pressed.
  // Arrange the stopping time
  currentTime = millis();
  waitingTime = millis() + waitPressDelay;


  // Wait for the user to interact... If time is over stop waiting.
  while(waitingTime >= currentTime) {
    // Read the sensors and store it in the variable "val". As soon the variable is high enough to be seen
    // as a push from the user... 
    // The variable must maintain its value. This is accompliced by skipping out of the loop with the break keyword.
    do{
      val = analogRead(switchPinOne);
      if(val > MINVAL)break;      
      val = analogRead(switchPinTwo);
      if(val > MINVAL)break;   
      val = analogRead(switchPinThree);
      if(val > MINVAL)break;   
      val = analogRead(switchPinFour);  
    }
    while(false);

    if(val > MINVAL && val < MAXVAL) { // Check if pressed. If pressed play the sound(s).
      Serial.println("pressed"); // Display that it's pressed.

      // Pick the right melody to play in the list connected with the choice.
      switch(choice){
      case 0:
        playMelodyOne();
        break;
      case 1:
        playMelodyTwo();
        break;
      case 2:
        playMelodyThree();
        break;
      case 3:
        playMelodyFour();
        break;
      }         
      delay(1000);
      return; // Everything is done! Return to loop().
    } 
    currentTime = millis(); // update the current time
  }


  // Set all the LEDs off again. Also the speaker
  digitalWrite(ledPin1, LOW); 
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW); 
  digitalWrite(ledPin4, LOW); 
  // Wait for the user to perceive the failure or succes.
  delay(preceiveDelay);	
}

/**
 * Get a random selection of the available buttons
 */
long randomSelect(){
  long randNumber  = 0; // The number to return.
  randNumber  = random(maxButtons);

  // Do not choose the same button after a choosing a new one.
  while(lastRandom == randNumber){
    randNumber  = random(maxButtons);
  }

  lastRandom =  randNumber;
  return randNumber;
}

/**
 * Available melodies.
 */
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

void playMelodyFour(){
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


















