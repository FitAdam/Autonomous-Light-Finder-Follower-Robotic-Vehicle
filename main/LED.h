#ifndef LED_h
#define LED_h

#include <Arduino.h>

class Led {
  
   private:
    byte pin;
    int _value;
   

   public:
      Led(byte pin);
        void init();
        void on();
        void off();
        void on_with_value(int value);
       

        
  };
#endif
