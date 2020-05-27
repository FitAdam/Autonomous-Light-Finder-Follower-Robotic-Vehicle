

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
    delay(100);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(_trigPin, HIGH);
    delay(100);
    digitalWrite(_trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(_echoPin, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2;
  
    return distance;
  }
  
  };
