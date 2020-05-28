/*************************************
    ADAM'S ROBOT 2020
    STUDENT NUMBER ****807
 *************************************/

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


const int BUZZER_PIN = 4;
Passive_Piezo_Buzzer new_buzzer(BUZZER_PIN);


const int DHT11_PIN = A2;
Humidity_sensor humidity_sensor(DHT11_PIN);

const byte BUTTON_PIN = 3;
Button new_button(BUTTON_PIN);



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
const int LEFT_PHOTORES = A1;
const int RIGHT_PHOTORES = A0;
//-------------------

// Pins for LEDs
const int RIGHT_LEDPIN = 6;
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
int distance;

int SensorLeft;
int SensorRight;
int SensorDifference;


void setup()

{

  new_display.init();
  pinMode(LEFT_PHOTORES, INPUT);
  pinMode(RIGHT_PHOTORES, INPUT);
  new_buzzer.Buzz(); // Gives signal that the set up is finished

}

void loop()
{

  int b_pressed = new_button.StateMachine_s1();
  int x = new_button.get_button_counter_value(b_pressed);
  int y = 0;
  switch (x) {
    case 0:

      distance = ultrasonic.Bubble();
      new_tempo = 80;
      new_display.display_distance(distance);
      right_value_of_light = indicate_light_right();
      left_value_of_light = indicate_light_left();

      SensorLeft = 1023 - left_value_of_light;

      SensorRight = 1023 - right_value_of_light;

      SensorDifference = abs(SensorLeft - SensorRight); // This calculates the difference between the two sensors and then saves it to an integer.


      // This section of the sketch is what actually interperets the data and then runs the motors accordingly.
      // Firstly, it checks the distance if it is bigger than 4 cm
      if (distance > 4) {
        left_led.on();
        right_led.on();
        if (SensorLeft < 500 && SensorRight < 500) {
          left_led.off();
          right_led.off();
          dc_motors.Stop();
          new_buzzer.Buzz();
          left_led.on();
          right_led.on();


        }

        if (SensorLeft > SensorRight && SensorDifference > 200 && SensorLeft > 500 && SensorRight > 500) { // This is interpreted as if the Left sensor reads more light than the Right Sensor, Do this:

          dc_motors.Right(250);



        }

        if (SensorLeft < SensorRight && SensorDifference > 200 && SensorLeft > 500 && SensorRight > 500) { // This is interpreted as if the Left sensor reads less light than the Right Sensor, Do this:

          dc_motors.Left(250);



        }

        else if (SensorLeft > 500 && SensorRight > 500 && SensorDifference < 75) { // This is interpreted as if the difference between the two sensors is under 125 (Experiment to suit our sensors), Do this:

          dc_motors.Forward(new_tempo);


        }
      }
      else {
        dc_motors.Stop();
        left_led.off();
        right_led.off();
      }

      break;
    case 1:
      new_tempo = new_potentiometer.get_value_for_speed();
      new_display.speed_calibration(new_tempo);
      dc_motors.Forward(new_tempo);
      break;
    case 2:
      new_light_threshold = new_potentiometer.get_value_for_threshold();
      right_value_of_light = indicate_light_right();
      left_value_of_light = indicate_light_left();
      new_display.light_calibration(new_light_threshold);
      break;
    case 3:
      int hum = humidity_sensor.get_humidity();

      int temp = humidity_sensor.get_temperature();

      new_display.display_hum_temp(56, 23);
      break;
  }
  // loop ends
}


// TO DO 
// The class for LDR's returns same value for the same photoresistors
// Bug to fix (!)
int indicate_light_left() {
  int value_l = analogRead(LEFT_PHOTORES);
  return value_l;
}

int indicate_light_right() {
  int value_r = analogRead(RIGHT_PHOTORES);
  return value_r;
}
