

#ifndef _BUZZER_H
#define _BUZZER_H
#include "NiceSong.h"

class Passive_Piezo_Buzzer {
    int _buzzerPin;


  public:
    Passive_Piezo_Buzzer(int buzzerPin) {
      _buzzerPin = buzzerPin;

      pinMode(_buzzerPin, OUTPUT);
    }

    void Buzz() {
      tone(_buzzerPin, 1000);
      delay(1000);
      noTone(_buzzerPin);
      delay(1000);
    }

    void PlayMusic() {
// Change melody.h, and this function if you want different song, picked from arduino.songs
//https://github.com/robsoncouto/arduino-songs
      int noteDurations[] = {4, 8, 4, 4, 4, 4, 4, 4};
      int tempo = 144;
      int melody[] = {REST, 2, NOTE_D4, 4,
                      NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,
                      NOTE_G4, 2, NOTE_D5, 4,
                      NOTE_C5, -2,
                      NOTE_A4, -2,
                      NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,
                      NOTE_F4, 2, NOTE_GS4, 4,
                      NOTE_D4, -1,
                      NOTE_D4, 4,

                      NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4, //10
                      NOTE_G4, 2, NOTE_D5, 4,
                      NOTE_F5, 2, NOTE_E5, 4,
                      NOTE_DS5, 2, NOTE_B4, 4,
                      NOTE_DS5, -4, NOTE_D5, 8, NOTE_CS5, 4,
                      NOTE_CS4, 2, NOTE_B4, 4,
                      NOTE_G4, -1,
                      NOTE_AS4, 4,

                      NOTE_D5, 2, NOTE_AS4, 4,//18
                      NOTE_D5, 2, NOTE_AS4, 4,
                      NOTE_DS5, 2, NOTE_D5, 4,
                      NOTE_CS5, 2, NOTE_A4, 4,
                      NOTE_AS4, -4, NOTE_D5, 8, NOTE_CS5, 4,
                      NOTE_CS4, 2, NOTE_D4, 4,
                      NOTE_D5, -1,
                      REST, 4, NOTE_AS4, 4,

                      NOTE_D5, 2, NOTE_AS4, 4,//26
                      NOTE_D5, 2, NOTE_AS4, 4,
                      NOTE_F5, 2, NOTE_E5, 4,
                      NOTE_DS5, 2, NOTE_B4, 4,
                      NOTE_DS5, -4, NOTE_D5, 8, NOTE_CS5, 4,
                      NOTE_CS4, 2, NOTE_AS4, 4,
                      NOTE_G4, -1,
                     };
      int notes = sizeof(melody) / sizeof(melody[0]) / 2;
      int wholenote = (60000 * 4) / tempo;
      int divider = 0, noteDuration = 0;
      for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
        divider = melody[thisNote + 1];
        if (divider > 0) {
          noteDuration = (wholenote) / divider;
        } else if (divider < 0) {
          noteDuration = (wholenote) / abs(divider);
          noteDuration *= 1.5; // increases the duration in half for dotted notes
        }
        tone(_buzzerPin, melody[thisNote], noteDuration * 0.9);
        delay(noteDuration);
        noTone(_buzzerPin);
      }
    }


};

#endif // _BUZZER_H
