

class Passive_Piezo_Buzzer {
  int _buzzer;

  public:
    Passive_Piezo_Buzzer(int buzzer){
      _buzzer = buzzer;

      
      pinMode(_buzzer, OUTPUT); // Set buzzer as output
      }
      
      void Buzz(){
        Serial.println("buzzer");
        tone(_buzzer, 1000); // Send sound signal...
        delay(1000);        // ...for sec
        noTone(_buzzer);     // Stop sound...
        delay(1000);        // ...for 1sec
      }
  };
