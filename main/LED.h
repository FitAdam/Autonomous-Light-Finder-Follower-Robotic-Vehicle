#ifndef LED_h
#define LED_h

#include <Arduino.h>

class Led {
  
   private:
    byte pin;
   

   public:
      Led(byte pin);
        void init();
        void on();
        void off();
        

        
  };
#endif