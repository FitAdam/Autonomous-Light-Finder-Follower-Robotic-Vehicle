/*************************************
    ADAM'S ROBOT 2020
    STUDENT NUMBER 1712807
 *************************************/
// Libraries needed


// import classes
#include "Ultrasonic_sensor.h"
#include "DC_Motors.h"
#include "Display.h"
#include "Humidity_sensor.h"
#include "Buzzer.h"
#include "Potentiometer.h"
#include "Button.h"

#include "LED.h"
#include "LDR.h"

int POTENTIOMETER = A6;
Potentiometer new_potentiometer(POTENTIOMETER);

// Variables
const int BUZZER_PIN = 4; //buzzer to arduino pin 4
Passive_Piezo_Buzzer new_buzzer(BUZZER_PIN);

// Humidity_sensor
const int DHT11_PIN = A2; //  Analog pin for humidity sensor
Humidity_sensor humidity_sensor(DHT11_PIN);

const byte BUTTON_PIN = 3; //  pin for button
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

// Pins for photoresistors:
const int LEFT_PHOTORES = A1; // Photoresistor at Arduino analog pin A1
const int RIGHT_PHOTORES = A0;
//-------------------

// Pins for LEDs
const int RIGHT_LEDPIN = 6;      // Led pin at Arduino pin 6
const int LEFT_LEDPIN = 5;

Led left_led(LEFT_LEDPIN);
Led right_led(RIGHT_LEDPIN);

//LDR left_photo(LEFT_PHOTORES);
//LDR right_photo(RIGHT_PHOTORES);

Screen new_display;
//-----------------
int new_tempo;
int new_light_threshold;
int right_value_of_light;
int left_value_of_light;

void setup()
{
  // initialize serial communication:
  Serial.begin(9600);
  new_display.init();
  pinMode(LEFT_PHOTORES, INPUT);// Set pResistor - A1 pin as an input
  pinMode(RIGHT_PHOTORES, INPUT);
  new_buzzer.Buzz(); // Gives signal that the set up is finished
  new_display.display_hello();
  
}



void loop()
{
  int x = 3;
  if (x == 1) {
    Serial.println("Hello, I am a Robot!");
    // TO DO
    // say hello on screen
    // play welcome music
    // say press button to calibrate
    // move to the next stage
  }
  else if ( x == 2) {
    Serial.println("Calibrate my speed");
    int new_tempo = new_potentiometer.get_value_for_speed();
    Serial.println("tempo");
    Serial.println(new_tempo);
    dc_motors.Forward(new_tempo);
    delay(2000);
  }
  else if ( x == 3) {
    Serial.println("Calibrate my light");
    int new_light_threshold = new_potentiometer.get_value_for_threshold();
    int right_value_of_light = indicate_light_right();
    int left_value_of_light = indicate_light_left();
    Serial.println("left_value_of_light");
    Serial.println(left_value_of_light);
    Serial.println("right_value_of_light");
    Serial.println(right_value_of_light);
    delay(2000);
  }
  else if ( x == 4) {
    Serial.println("Follow the light!");
    int distance = ultrasonic.Bubble();
    int new_light_threshold = new_potentiometer.get_value_for_threshold();
    int right_value_of_light = indicate_light_right();
    int left_value_of_light = indicate_light_left();
    Serial.println("left_value_of_light");
    Serial.println(left_value_of_light);
    Serial.println("right_value_of_light");
    Serial.println(right_value_of_light);
    Serial.println("Value to pass:");
    Serial.println(new_light_threshold);
    delay(5000);

    new_tempo = 100;
    int goal_light_threshold = new_light_threshold;

    if (distance < 4 && right_value_of_light > new_light_threshold && left_value_of_light > new_light_threshold ) {
      Serial.println("You got the light!");
      new_buzzer.Buzz();
      dc_motors.Stop();
      left_led.on();
      right_led.on();
      delay(3000);
      left_led.off();
      right_led.off();
    }
    else {
        Serial.println("New light threshold, level to follow.");
        Serial.println(new_light_threshold);
        if (right_value_of_light > new_light_threshold) {
          dc_motors.Right(new_tempo);
          Serial.println("Going right.");
          Serial.println(right_value_of_light);
          delay(2000);
          dc_motors.Stop();
        }
        else if (left_value_of_light > new_light_threshold) {
          dc_motors.Left(new_tempo);
          Serial.println("Going left.");
          //Serial.println(right_value_of_light);
          delay(2000);
          dc_motors.Stop();
        }
        else if (right_value_of_light > new_light_threshold && left_value_of_light > new_light_threshold) {
          dc_motors.Forward(new_tempo);
          Serial.println("Going forward.");
          //Serial.println(right_value_of_light);
          delay(2000);
        }
        else{
            Serial.println("STOP");
            //Serial.println(right_value_of_light);
            delay(2000);
            dc_motors.Stop();
          }
      }
    }
}

int indicate_light_left(){
  int value_l = analogRead(LEFT_PHOTORES);
  return value_l;
  }

int indicate_light_right(){
  int value_r = analogRead(RIGHT_PHOTORES);
  return value_r;
  }
