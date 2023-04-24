// Define the pins
#include "pitches.h" 
int speakerPin = 11;



int BlueLED = 10;
int RedLED = 5;
int GreenLED = 9;
int YellowLED = 3;

const int buttonPin = 1;
const int buttonPin2 = 4;
const int buttonPin3 = 8;
const int buttonPin4 = 12;
const int buttonPin5 = 13;


// Define the melody
int melody[] = {
  // Super Mario Bros theme
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,
  
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
  
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,
  
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
  
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};

// Define the note durations
int noteDuration[] = {
  // Super Mario Bros theme
  120, 120, 120, 120,
  120, 120, 120, 120,
  120, 120, 120, 120,
  120, 120, 120, 120,
  
  120, 120, 120, 120,
  120, 120, 120, 120,
  120, 120, 120, 120,
  120, 120, 120, 120,
  
  120, 120, 120,
  120, 120, 120, 120,
  120, 120, 120, 120,
  120, 120, 120, 120,
  
  120, 120, 120, 120,
  120, 120, 120, 120,
  120, 120, 120, 120,
  120, 120, 120, 120,
  
  120, 120, 120,
  120, 120, 120, 120,
  120, 120, 120, 120,
  120, 120, 120, 120
};

void setup() {
  // Set the speaker pin as an output
  pinMode(speakerPin, OUTPUT);
  pinMode(BlueLED, OUTPUT);
  pinMode(RedLED, OUTPUT);
  pinMode(GreenLED, OUTPUT);
  pinMode(YellowLED, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(buttonPin5, INPUT_PULLUP);
}

void loop() {
  // Loop through the melody and play each note
  if (digitalRead(buttonPin)== LOW){
    tone(speakerPin, NOTE_E7, 10); // Play the note on the piezo
    digitalWrite(YellowLED, HIGH);
    }
    else{
      digitalWrite(YellowLED, LOW);
      }

  if (digitalRead(buttonPin2)== LOW){
    tone(speakerPin, NOTE_C7, 10); // Play the note on the piezo
    digitalWrite(RedLED, HIGH);
    }
    else{
      digitalWrite(RedLED, LOW);
      }

  if (digitalRead(buttonPin3)== LOW){
    tone(speakerPin, NOTE_G7, 10); // Play the note on the piezo
    digitalWrite(GreenLED, HIGH);
    }
    else{
      digitalWrite(GreenLED, LOW);
      }
  if (digitalRead(buttonPin4)== LOW){
    tone(speakerPin, NOTE_G6, 10); // Play the note on the piezo
    digitalWrite(BlueLED, HIGH);
    }
    else{
      digitalWrite(BlueLED, LOW);
      }

  if (digitalRead(buttonPin5)== LOW){
    for (int i = 0; i < sizeof(melody) / sizeof(int); i++) {
      if (melody[i] != 0) {
        tone(speakerPin, melody[i], noteDuration[i]); // Play the note on the piezo
  
        // Turn on the corresponding LED
        switch (i % 4) {
          case 0:
            digitalWrite(BlueLED, HIGH);
            delay(noteDuration[i]);
            digitalWrite(BlueLED, LOW);
            break;
          case 1:
            digitalWrite(RedLED, HIGH);
            delay(noteDuration[i]);
            digitalWrite(RedLED, LOW);
            break;
          case 2:
            digitalWrite(GreenLED, HIGH);
            delay(noteDuration[i]);
            digitalWrite(GreenLED, LOW);
            break;
          case 3:
            digitalWrite(YellowLED, HIGH);
            delay(noteDuration[i]);
            digitalWrite(YellowLED, LOW);
            break;
        }
      }
      else {
        // Add a small delay between notes for a smoother sound
        delay(noteDuration[i] * 1.3);
      }
    }
  }
}
