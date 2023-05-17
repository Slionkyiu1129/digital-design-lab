#include "pitches.h"
#define BUTTON 6

int melody1[] = {
  NOTE_B4, NOTE_B4, NOTE_E5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_E5
};
int melody2[] = {
  NOTE_B4, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 4, 4, 4, 4, 8, 4,
};

void setup() {
  // iterate over the notes of the melody:
   pinMode(6, INPUT_PULLUP);  
   for(int i=2;i<=8;i++){
    pinMode(i,OUTPUT);
   }
}

byte present=1,previous=1,num=0;

void loop() {
  
  if(num==0){
    for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody1[thisNote], noteDuration);
    
    //LED BAR
    if(melody1[thisNote]==NOTE_B4){
      digitalWrite(2,HIGH);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      digitalWrite(2,LOW);
    }
    else if(melody1[thisNote]==NOTE_E5){
      digitalWrite(5,HIGH);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      digitalWrite(5,LOW);
    }
    else if(melody1[thisNote]==NOTE_D5){
      digitalWrite(4,HIGH);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      digitalWrite(4,LOW);
    }
    noTone(8);
    present = digitalRead(BUTTON);
    if(present==1&&previous==0){
      num++;
      if(num>1)num=0;
      thisNote=8;
    }
    previous=present;
    //present=digitalRead(BUTTON);if(present==0)break;
    }
  }

  else if(num==1){
    for (int thisNote = 0; thisNote < 8; thisNote++) {
       int noteDuration = 1000 / noteDurations[thisNote];
       tone(8, melody2[thisNote], noteDuration);
       
    //LED BAR
    if(melody2[thisNote]==NOTE_B4){
      digitalWrite(2,HIGH);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      digitalWrite(2,LOW);
    }
    else if(melody2[thisNote]==NOTE_E5){
      digitalWrite(5,HIGH);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      digitalWrite(5,LOW);
    }
    else if(melody2[thisNote]==NOTE_D5){
      digitalWrite(4,HIGH);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      digitalWrite(4,LOW);
    }
    else if(melody2[thisNote]==NOTE_C5){
      digitalWrite(3,HIGH);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      digitalWrite(3,LOW);
    }
    else if(melody2[thisNote]==NOTE_F5){
      digitalWrite(9,HIGH);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      digitalWrite(9,LOW);
    }
    noTone(8);
    present = digitalRead(BUTTON);
    if(present==1&&previous==0){
      num++;
      if(num>1)num=0;
      thisNote=8;
    }
    previous=present;
    // present=digitalRead(BUTTON);if(present==0)break;
    }
  }

  delay(200);
  
}
