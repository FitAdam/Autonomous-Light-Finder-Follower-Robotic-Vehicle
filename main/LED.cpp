#include "Led.h"
/*************************************
  The LED’s should be used to show the relative proximity distance and direction of the main light source, also they should
  be used as indicators of several events taking place such as: 
  calibration procedures, light source scanning, end of the
  program, etc.
 *************************************/

Led::Led(byte pin){
      this->pin = pin;
      init();
}

void Led::init(){
  pinMode(pin, OUTPUT);
  off();
}

void Led::on(){
  digitalWrite(pin, HIGH);
  }
void Led::off(){
  digitalWrite(pin, LOW);
}
void Led::on_with_value(int _value){
  digitalWrite(pin, _value);
  }
