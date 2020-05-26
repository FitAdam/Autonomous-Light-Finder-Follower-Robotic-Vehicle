

class Button{
  int _button;
  int buttonState = 0;         // variable for reading the pushbutton status
  int button_counter = 0; // counter for the button to implement switch cases

  int state_s1 = 0;                   //The actual ~state~ of the state machine
  int state_prev_s1 = 0;              //Remembers the previous state (useful to know when the state has changed)
  int val_s1 = 0;                     //Value of the switch ("HIGH" or "LOW")
  unsigned long t_s1 = 0;             //Typically represents the current time of the switch
  unsigned long t_0_s1 = 0;           //The time that we last passed through an interesting state
  unsigned long bounce_delay_s1 = 10; //The delay to list for bouncing
  unsigned long hold_delay_s1 = 1000; //The time required to register a long press (a.k.a. "hold")
  
  public:
    Button(byte button){
      _button = button;
      pinMode(_button, INPUT_PULLUP);
    }
 int StateMachine_s1() {
  
  //Almost every state needs these lines, so I'll put it outside the State Machine
  val_s1 = digitalRead(_button);
  state_prev_s1 = state_s1;

  //State Machine Section
  switch (state_s1) {
    case 0: //RESET!
      //Catch all "home base" for the State Machine
      state_s1 = 1;
    return 0;

    case 1: //WAIT
      //Wait for the switch to go low
      if (val_s1 == LOW) {state_s1 = 2;}
    return 0;

    case 2: //ARMING!
      //Record the time and proceed to ARMED
      t_0_s1 = millis();
      state_s1 = 3;
    return 0;

    case 3: //ARMED
      //Check to see if the proper has delay has passed.  If a bounce occures then RESET
      t_s1 = millis();
      if (t_s1 - t_0_s1 > bounce_delay_s1) {state_s1 = 4;}
      if (val_s1 == HIGH) {state_s1 = 0;}
    return 0;

    case 4: //DRAWN
      //If switch goes HIGH, then TRIGGER. Also check timer for a "Long Pess"
      t_s1 = millis();
      if (val_s1 == HIGH) {state_s1 = 5;}
      if (t_s1 - t_0_s1 > hold_delay_s1) {state_s1 = 6;}
    return 0;

    case 5: //TRIGGERED!
      //reset the State Machine
      Serial.println("TRIGGERED!!");
      state_s1 = 0;
    return 1;

    case 6: //HOLD!
      //proceed to LOW WAIT
      Serial.println("HOLDED!!");
      state_s1 = 7;
    return 1;

    case 7: //LOW WAIT
      //wait for switch to go back HIGH, then reset
      if (val_s1 == HIGH) {state_s1 = 0;}
    return 0;
  }
 }
    int get_button_counter_value(int value_x) {
    if (value_x == 1) {
      button_counter = 1 + button_counter;
      if (button_counter == 5){
        // after achieving the limit, the counter is assigned to zero.
        button_counter = 0;
      }
    } 
    return button_counter;
    }
    
};
