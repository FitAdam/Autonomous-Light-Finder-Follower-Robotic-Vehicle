class Leds {
  
  int _right_led;
  int _left_led;

   public:
      Leds(int right_led, int left_led){
        _right_led = right_led;
        _left_led = left_led;
        // pin modes for LEDs
        pinMode(_right_led, OUTPUT);  // Set ledPin 
        pinMode(_left_led, OUTPUT);
        }

        void turn_on_both(){
          digitalWrite(_right_led, HIGH); //Turn led on
          digitalWrite(_left_led, HIGH); //Turn led on
        }
        void turn_on_right(){
          digitalWrite(_right_led, HIGH); //Turn led on
          digitalWrite(_left_led, LOW); //Turn led off
        }
        void turn_on_left(){
          digitalWrite(_right_led, LOW); //Turn led off
          digitalWrite(_left_led, HIGH); //Turn led on
        }
        void turn_off_both(){
          digitalWrite(_right_led, LOW); //Turn led off
          digitalWrite(_left_led, LOW); //Turn led off
        }
        
  };
