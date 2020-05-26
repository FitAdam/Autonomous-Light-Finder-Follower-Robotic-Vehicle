/*************************************
    ADAM'S ROBOT 2020
    STUDENT NUMBER 1712807
 *************************************/
// Libraries needed


// import classes
#include "Ultrasonic_sensor.h"
#include "DC_Motors.h"
//#include "LDRs.h"
#include "Display.h"
#include "Humidity_sensor.h"
#include "Buzzer.h"
//#include "LEDs.h"
#include "Potentiometer.h"
#include "Button.h"

#include "LED.h"
#include "LDR.h"

int POTENTIOMETER = A6;
Potentiometer new_potentiometer(POTENTIOMETER);

// Variables
const int BUZZER_PIN = 4; //buzzer to arduino pin 4
Passive_Piezo_Buzzer new_buzzer(BUZZER_PIN);

// Humidity_senosor
const int DHT11_PIN = A2; //  Analog pin for humidity sensor
Humidity_sensor humidity_sensor(DHT11_PIN);

const int BUTTON_PIN = 3; //  pin for button
Button new_button(BUTTON_PIN);

// enigne variables:

int PIN_IN1 = 12;
int PIN_IN2 = 11;
int PIN_IN3 = 9;
int PIN_IN4 = 10;
DCMotors dc_motors(PIN_IN1, PIN_IN2, PIN_IN3, PIN_IN4);
//-------------------
// Pins for ultrasonic sensor:
const int PIN_TRIG = 8;
const int PIN_ECHO = 7;

Ultrasonic ultrasonic(PIN_TRIG, PIN_ECHO);

//-------------------



// Pins for photoresistors:
const int LEFT_PHOTORES = A1; // Photoresistor at Arduino analog pin A1
const int RIGHT_PHOTORES = A0;
//-------------------

// Pins for LEDs
const int RIGHT_LEDPIN = 6;      // Led pin at Arduino pin 6
const int LEFT_LEDPIN = 5;

//LDRs ldrs(LEFT_PHOTORES,RIGHT_PHOTORES);

//Leds leds(LEFT_LEDPIN,RIGHT_LEDPIN);

Led left_led(LEFT_LEDPIN);
Led right_led(RIGHT_LEDPIN);
LDR left_photo(LEFT_PHOTORES);
LDR right_photo(LEFT_PHOTORES);

Screen new_display;
//-----------------

void setup()
{
  // initialize serial communication:
  Serial.begin(9600);
  new_display.init();
  new_buzzer.Buzz(); // Gives signal that the set up is finished
  //leds.turn_on_both();
  new_display.display_hello();
}



void loop()
{ 
  //new_button.test_button();
  // CURRENT TESTING
  switch (1){
    case 0:    
      Serial.println("left_led");
      left_led.on();
      break;
    case 1:    
      //Serial.println("StateMachine_s1()");
      new_button.StateMachine_s1();
      break;
    case 2:    
      Serial.println("Case 2");
      Serial.println("right_led");
      right_photo.indicate_light();
      right_led.on();
      break;
    case 3:    // your hand is nowhere near the sensor
      Serial.println("third-last Forward()");
      int new_tempo = new_potentiometer.get_value_for_speed();
      Serial.println("tempo");
      Serial.println(new_tempo);
      dc_motors.Forward(new_tempo);
      break;
    }
   delay(100);

}
