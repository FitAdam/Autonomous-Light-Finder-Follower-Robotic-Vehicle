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
  pinMode(LEFT_PHOTORES, INPUT);
  pinMode(RIGHT_PHOTORES, INPUT);
  new_buzzer.Buzz(); // Gives signal that the set up is finished

}

void loop()
{
  //int b_pressed = new_button.StateMachine_s1();
  //int x = new_button.get_button_counter_value(b_pressed);
  int x = 4;
  if (x == 1) {
    Serial.println("Hello, I am a Robot!");
    // TO DO
    new_display.display_hello();
    //new_buzzer.Ode_to_Joy();
    // play welcome music
    // say press button to calibrate
    // move to the next stage
  }
  else if (x == 2) {
    Serial.println("Calibrate my speed");
    int new_tempo = new_potentiometer.get_value_for_speed();
    new_display.speed_calibration(new_tempo);
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
    new_display.light_calibration(new_light_threshold);
    Serial.println("left_value_of_light");
    Serial.println(left_value_of_light);
    Serial.println("right_value_of_light");
    Serial.println(right_value_of_light);
    delay(2000);
  }
  else if (x == 4) {
    int hum = humidity_sensor.get_humidity();
    int temp = humidity_sensor.get_temperature();
    new_display.display_hum_temp(hum, temp);
  }
  else if ( x == 5) {
    Serial.println("Follow the light!");
    int distance = ultrasonic.Bubble();
    new_display.display_distance(distance);
    // goal_light_threshold = 500;
    int goal_light_threshold = new_potentiometer.get_value_for_threshold();
    int right_value_of_light = indicate_light_right();
    int left_value_of_light = indicate_light_left();
    Serial.println(goal_light_threshold);

    new_tempo = 100;

    int SensorLeft = 1023 - left_value_of_light; // This reads the value of the sensor, then saves it to the corresponding integer.

    int SensorRight = 1023 - right_value_of_light; // This reads the value of the sensor, then saves it to the corresponding integer.

    int SensorDifference = abs(SensorLeft - SensorRight); // This calculates the difference between the two sensors and then saves it to an integer.

    // This section of the sketch is used to print the values of the

    // sensors through Serial to the computer. Useful for determining

    // if the sensors are working and if the code is also functioning properly.

    Serial.print("Left Sensor = "); // Prints the text inside the quotes.

    Serial.print(left_value_of_light); // Prints the value of the Left Sensor.

    Serial.print("\t"); // Prints a tab (space).

    Serial.print("Right Sensor = "); // Prints the text inside the quotes.

    Serial.print(right_value_of_light); // Prints the value of the Right Sensor.

    Serial.print("\t"); // Prints a tab (space).

    // This section of the sketch is what actually interperets the data and then runs the motors accordingly.

    if (SensorLeft < 500 && SensorRight < 500) {
      dc_motors.Stop();

      Serial.println("Stop");
    }

    if (SensorLeft > SensorRight && SensorDifference > 200 && SensorLeft > 500 && SensorRight > 500) { // This is interpreted as if the Left sensor reads more light than the Right Sensor, Do this:

      dc_motors.Right(255);

      Serial.println("Left"); // This prints Left when the robot would actually turn Left.

    }

    if (SensorLeft < SensorRight && SensorDifference > 200 && SensorLeft > 500 && SensorRight > 500) { // This is interpreted as if the Left sensor reads less light than the Right Sensor, Do this:

      dc_motors.Left(255);

      Serial.println("Right"); // This prints Right when the robot would actually turn Right.

    }

    else if (SensorLeft > 500 && SensorRight > 500 && SensorDifference < 75) { // This is interpreted as if the difference between the two sensors is under 125 (Experiment to suit our sensors), Do this:

      dc_motors.Forward(new_tempo);

      Serial.println("Forward"); // This prints Forward when the robot would actually go forward.

    }

    Serial.print("\n");

  }
  // loop ends
}

int indicate_light_left() {
  int value_l = analogRead(LEFT_PHOTORES);
  return value_l;
}

int indicate_light_right() {
  int value_r = analogRead(RIGHT_PHOTORES);
  return value_r;
}
