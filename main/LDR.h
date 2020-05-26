#ifndef LDR_h
#define LDR_h


#include <arduino.h>

class LDR{
  private:
    byte _photoresistor;
    
    
  public:
    LDR(byte _photoresistor);
        void init();
        int indicate_light();
        
        
        
  
  
  };
  #endif
