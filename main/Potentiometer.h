

class Potentiometer{
  
  int _potentiometer;

  public:
    Potentiometer(int potentiometer){
      _potentiometer = potentiometer;
      //analogRead(_potentiometer);
      }
  
    int get_value_for_speed(){
      // this function control the speed of DC motors by the potentiometer
      int tempo = analogRead(_potentiometer); //declaring and reading value from the pin
      tempo = tempo / 2.6471; // doing calibration to change range from 0-675 to 0-255 the number
      delay(100);
      return tempo;
    }
  
  };
