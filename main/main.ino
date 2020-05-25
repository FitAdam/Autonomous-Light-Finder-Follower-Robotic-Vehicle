/*************************************
    ADAM'S ROBOT 2020
    STUDENT NUMBER 1712807
 *************************************/
// Libraries needed


// import classes
#include "Ultrasonic_sensor.h"
#include "DC_Motors.h"
#include "LDRs.h"
#include "Display.h"
#include "Humidity_sensor.h"
#include "Buzzer.h"


// Variables
const int BUZZER_PIN = 4; //buzzer to arduino pin 4
Passive_Piezo_Buzzer new_buzzer(BUZZER_PIN);

// Humidity_senosor
const int DHT11_PIN = A2; //  Analog pin for humidity sensor
Humidity_sensor humidity_sensor(DHT11_PIN);

const int buttonPin = 3; //  pin for button

int buttonState = 0;         // variable for reading the pushbutton status

// enigne variables:
int tempo;

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
// counter for the button to implement switch cases
int button_counter = 0;


// Pins for photoresistors:
const int LEFT_PHOTORES = A1; // Photoresistor at Arduino analog pin A1
const int RIGHT_PHOTORES = A0;
//-------------------

// Pins for LEDs
const int RIGHT_LEDPIN = 6;      // Led pin at Arduino pin 6
const int LEFT_LEDPIN = 5;

LDRs ldrs(LEFT_PHOTORES,RIGHT_PHOTORES,LEFT_LEDPIN,RIGHT_LEDPIN);

Screen new_display;
//-----------------

void setup()
{
  // initialize serial communication:
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  new_display.init();
  new_buzzer.Buzz(); // Gives signal that the set up is finished
  
}



void loop()
{ 
  humidity_sensor.get_humidity();
  new_display.display_hello();
  // CURRENT TESTING
  switch (1){
    case 0:    // your hand is on the sensor
      Serial.println("indicate_light()");
      ldrs.indicate_light();
      break;
    case 1:    // your hand is close to the sensor
      Serial.println("first display_hello()");
      new_display.display_hello();
      break;
    case 2:    // your hand is a few inches from the sensor
      Serial.println("second Bubble()");
      ultrasonic.Bubble();
      break;
    case 3:    // your hand is nowhere near the sensor
      Serial.println("third-last Forward()");
      tempo = speedControl();
      dc_motors.Forward(tempo);
      break;
    }
   delay(100);

}

int test_button() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  // Show the state of pushbutton on serial monitor
  //Serial.println(buttonState);
  // check if the pushbutton is pressed.
  // if it is, the buttonState is not HIGH:
  if (buttonState != HIGH) {
    // turn LED on:
    //digitalWrite(right_ledPin, HIGH);
    //digitalWrite(left_ledPin, HIGH);
    // counter to get options for switch statement in main loop
    button_counter = 1 + button_counter;
    if (button_counter == 4){
      // after achieving the limit, the counter is assigned to zero.
      button_counter = 0;
    }
  } else {
    // turn LED off:
    //digitalWrite(right_ledPin, LOW);
    //digitalWrite(left_ledPin, LOW);
  }
  // Added the delay so that we can see the output of button
  return button_counter;
  }

// this function control the speed of DC motors by the potentiometer
int speedControl() {

  int tempo = analogRead(A6); //declaring and reading value from the pin
  tempo = tempo / 2.6471; // doing calibration to change range from 0-675 to 0-255 the number
  //Serial.println(tempo);
  delay(100);
  
  return tempo;
}
