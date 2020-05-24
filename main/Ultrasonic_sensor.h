

class Ultrasonic{
  
  int _trigPin;
  int _echoPin;
  // Defines variables for maths needed for ultrasonic sensor:
  long duration;
  int distance;
  int new_distance;
  
  public:
    Ultrasonic(int trigPin, int echoPin){
      _trigPin = trigPin;
      _echoPin = echoPin;

      // pin modes for ultrasonic sensor:
      pinMode(_trigPin, OUTPUT); // Sets the trigPin as an Output
      pinMode(_echoPin, INPUT); // Sets the echoPin as an Input
      
      }
  // function for ultrasonic sensor, it returns a value of the distance needed for the measurement
  int Bubble()
  {
    // Clears the trigPin
    digitalWrite(_trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(_echoPin, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2;
  
    // Display 
    display.clearDisplay();  // Clear the display so we can refresh
    display.setFont(&FreeMono9pt7b);  // Set a custom font
    display.setTextSize(0);  // Set text size. We are using a custom font so you should always use the text size of 0
     // Print text:
    display.setCursor(0, 15);  // (x,y)
    display.println("Distance: ");  // Text or value to print
    // Print variable with left alignment:
    display.setCursor(75, 40);  // (x,y)
    display.println(distance);  // Text or value to print
    display.display();  // Print everything we set previously
  
    return distance;
  }
  
  };
