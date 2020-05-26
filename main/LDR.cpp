#include "LDR.h"

LDR::LDR(byte _photoresistor){
      this->_photoresistor;
      init();
}

void LDR::init(){
  pinMode(_photoresistor, OUTPUT);
}
// function for Two Light-Emitting Diodes (LED’s) to indicate the direction of the light source and its intensity.
    void LDR::indicate_light()
    {
      //TODO potentiometer class
      calibration_ligt_value = 100;//analogRead(A6);
      calibration_ligt_value = calibration_ligt_value * 1.35;

      
      Serial.println("calibration_ligt_value:");
      Serial.println(calibration_ligt_value);
      _value = analogRead(_photoresistor);
      
      Serial.println("_value is ");
      Serial.println(_value);
    
      // if value from read is more than calibration_ligt_value then turn on the light
      if (_value > calibration_ligt_value) {
        Serial.println("Strong light detected!");
      }
      else {
        
      }
    
      delay(1000); //Small delay
    }
