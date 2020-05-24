

class LDRs{
  int _left_Photoresistor;
  int _right_Photoresistor;

  // leds 
  int _left_ledPin;
  int _right_ledPin;

  // Defines variables for photoresistor's math:
  int value_l;          // Store value from photoresistor (0-1023)
  int value_r;

  // calibration for the calibration_ligt_value done by potentiomiter
  int calibration_ligt_value = 0;

  public:
    LDRs(int left_Photoresistor,int right_Photoresistor, int left_ledPin, int right_ledPin){
      _left_Photoresistor = left_Photoresistor;
      _right_Photoresistor = right_Photoresistor;
      _left_ledPin = left_ledPin;
      _right_ledPin = right_ledPin;
    
          // pin modes for LEDs
      pinMode(_right_ledPin, OUTPUT);  // Set ledPin 
      pinMode(_left_ledPin, OUTPUT);
      // pin modes for photoresistors
      pinMode(_left_Photoresistor, INPUT);// Set pResistor 
      pinMode(_right_Photoresistor, INPUT);
    }
    // function for Two Light-Emitting Diodes (LED’s) to indicate the direction of the light source and its intensity.
    void indicate_light()
    {
      //TODO potentiometer class
      calibration_ligt_value = 100;//analogRead(A6);
      calibration_ligt_value = calibration_ligt_value * 1.35;

      
      Serial.println("calibration_ligt_value:");
      Serial.println(calibration_ligt_value);
      value_l = analogRead(_left_Photoresistor);
      value_r = analogRead(_right_Photoresistor);
      Serial.println("value_l is ");
      Serial.println(value_l);
    
      // if value from read is more than 250 then turn on the light
      if (value_r > calibration_ligt_value && value_l > calibration_ligt_value) {
        digitalWrite(_right_ledPin, HIGH); //Turn led on
        digitalWrite(_left_ledPin, HIGH); //Turn led on
      }
      else if (value_r > calibration_ligt_value) {
        digitalWrite(_right_ledPin, HIGH); //Turn led on
      }
      else if (value_l > calibration_ligt_value) {
        digitalWrite(_left_ledPin, HIGH); //Turn led on
      }
      else {
        digitalWrite(_right_ledPin, LOW);  //Turn led off
        digitalWrite(_left_ledPin, LOW);  //Turn led off
      }
    
      delay(1000); //Small delay
    }
  };
