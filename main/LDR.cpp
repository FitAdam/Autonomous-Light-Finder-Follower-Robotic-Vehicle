#include "LDR.h"
/*************************************
  A Light Source Scanning program subroutine should be implemented at the beginning of the program execution to make
  sure the Robotic Vehicle detects and analyses
  several light sources surrounding the vehicle and creates a light intensity
  reference threshold in the process.
*************************************/

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
