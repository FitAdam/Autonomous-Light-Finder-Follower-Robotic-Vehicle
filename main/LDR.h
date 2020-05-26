#ifndef LDR_h
#define LDR_h

#include <Arduino.h>

class LDR{
  private:
    byte _photoresistor;
    int _value;          // Store value from photoresistor (0-1023)

  // calibration for the calibration_ligt_value done by potentiomiter
    int calibration_ligt_value = 0;
    
  public:
    LDR(byte _hotoresistor);
        void init();
        void indicate_light();
        
  
  
  };

#endif //this line ends the #ifndef preprocessor directive
