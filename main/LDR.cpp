#include "LDR.h"


LDR::LDR(byte _photoresistor) {
  this->_photoresistor;
  init();
}

void LDR::init() {
  pinMode(_photoresistor, INPUT);
}
// function for Two Light-Emitting Diodes (LED’s) to indicate the direction of the light source and its intensity.
int LDR::indicate_light() {
  int _value = analogRead(_photoresistor);
  return _value;
}
