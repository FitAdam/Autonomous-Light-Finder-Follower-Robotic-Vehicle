/*************************************
    ADAM'S ROBOT 2020
    STUDENT NUMBER 1712807
 *************************************/
// Libraries needed
#include <dht.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>

#include <Adafruit_SSD1306.h>
#include <splash.h>
#include <Adafruit_GFX.h>  // Include core graphics library for the display
#include <Adafruit_SSD1306.h>  // Include Adafruit_SSD1306 library to drive the display


Adafruit_SSD1306 display(128, 64);  // Create display


#include <Fonts/FreeMonoBold12pt7b.h>  // Add a custom font
#include <Fonts/FreeMono9pt7b.h>  // Add a custom font
// import classes
#include "Ultrasonic_sensor.h"
#include "DC_Motors.h"
#include "LDRs.h"
dht DHT;

// Variables
const int buzzer = 4; //buzzer to arduino pin 4
const int DHT11_PIN = A2; //  Analog pin for humidity sensor
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

//-----------------

void setup()
{
  // initialize serial communication:
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 4 as an output
  // set up for the screen
  delay(100);  // This delay is needed to let the display to initialize

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Initialize display with the I2C address of 0x3C

  display.clearDisplay();  // Clear the buffer

  display.setTextColor(WHITE);  // Set color of the text

  display.setRotation(0);  // Set orientation. Goes from 0, 1, 2 or 3

  display.setTextWrap(false);  // By default, long lines of text are set to automatically “wrap” back to the leftmost column.
  // To override this behavior (so text will run off the right side of the display - useful for
  // scrolling marquee effects), use setTextWrap(false). The normal wrapping behavior is restored
  // with setTextWrap(true).

  display.dim(0);  //Set brightness (0 is maximun and 1 is a little dim)
  // ---------------------------------------------------------------------------------------
  // pin mode for humidity sensor
  pinMode(DHT11_PIN, INPUT); //hum
  

  display_hum_temp(); // Display the
  Buzz(); // Gives signal that the set up is finished



}



void loop()
{
  // CURRENT TESTING
  switch (0){
    case 0:    // your hand is on the sensor
      Serial.println("indicate_light()");
      ldrs.indicate_light();
      break;
    case 1:    // your hand is close to the sensor
      Serial.println("first display_hum_temp");
      display_hum_temp();
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


// function for display and detection of values from One Temperature and Humidity Sensor
void display_hum_temp()
{
  delay(3000);
  int chk = DHT.read11(DHT11_PIN);
  //delay(3000);
  display.clearDisplay();  // Clear the display so we can refresh


  display.setFont(&FreeMono9pt7b);  // Set a custom font
  display.setTextSize(0);  // Set text size. We are using a custom font so you should always use the text size of 0


  // Print text:
  display.setCursor(0, 15);  // (x,y)
  display.println("Temp=");  // Text or value to print
  //delay(3000);

  // Draw rectangle:
  display.drawRoundRect(79, 0, 49, 27, 8, WHITE);  // Draw rectangle (x,y,width,height,color)
  // It draws from the location to down-right


  // Print variable with left alignment:
  display.setCursor(83, 20);  // (x,y)
  //delay(3000);
  display.println(DHT.temperature);  // Text or value to print
  //delay(3000);

  display.setCursor(0, 50);  // (x,y)
  display.println("Hum=");


  // Draw rounded rectangle:
  display.drawRoundRect(79, 37, 49, 27, 8, WHITE);  // Draw rounded rectangle (x,y,width,height,radius,color)
  // It draws from the location to down-right

  // Print variable with right alignment:
  display.setCursor(83, 57);  // (x,y)
  //delay(3000);
  display.println(DHT.humidity);  // Text or value to print
  //delay(3000);
  display.display();  // Print everything we set previously
}

// function for the buzzer
void Buzz()
{
  tone(buzzer, 1000); // Send sound signal...
  delay(100);        // ...for sec
  noTone(buzzer);     // Stop sound...
  delay(1000);        // ...for 1sec
}
