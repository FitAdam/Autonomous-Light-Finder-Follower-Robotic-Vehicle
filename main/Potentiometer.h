/*************************************
The potentiometer should be implemented to control the values of
DC motors, temperature and humidity during the
calibration procedures.
*************************************/

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
    int get_value_for_temp(){
      // this function control the speed of DC motors by the potentiometer
      int temp = analogRead(_potentiometer); //declaring and reading value from the pin
      temp = temp/ 2.6471; // doing calibration to change range from 0-675 to 0-255 the number
      delay(100);
      return temp;
    }
    int get_value_for_hum(){
      // this function control the speed of DC motors by the potentiometer
      int hum = analogRead(_potentiometer); //declaring and reading value from the pin
      delay(100);
      return hum;
    }
    int get_value_for_threshold(){
      // this function control the speed of DC motors by the potentiometer
      int light_threshold = analogRead(_potentiometer); //declaring and reading value from the pin
      light_threshold = light_threshold * 1.35;
      delay(100);
      return light_threshold;
    }
  
  };
