

class Button{
  int _button;
  int buttonState = 0;         // variable for reading the pushbutton status
  int button_counter = 0; // counter for the button to implement switch cases

  public:
    Button(int button){
      _button = button;
      pinMode(_button, INPUT_PULLUP);
    }
    
    int get_button_counter_value() {
    delay(1000);
    // read the state of the pushbutton value:
    buttonState = digitalRead(_button);
    // Show the state of pushbutton on serial monitor
    //Serial.println(buttonState);
    // check if the pushbutton is pressed.
    // if it is, the buttonState is not HIGH:
    if (buttonState != HIGH) {
      button_counter = 1 + button_counter;
      if (button_counter == 7){
        // after achieving the limit, the counter is assigned to zero.
        button_counter = 0;
      }
    } else {
      // do something
    }
    // Added the delay so that we can see the output of button
    delay(3000);
    return button_counter;
    }
    
};
