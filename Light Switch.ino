const int  buttonPin = 3;    // the pin that the pushbutton is attached to
const int ledPin = 13;       // the pin that the LED is attached to

// Variables will change:
int buttonState = 0;         // current state of the button ** unpressed 
int buttonSwitch = 0; // previous state of the button * will track moment button is pressed
int buttonCounter = 0;
int ledState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); 
} 

void loop() {
//  // put your main code here, to run repeatedly:
//
//   buttonState = digitalRead(buttonPin); // stores read of buttonPin
//   
//   if (buttonState != lastButtonState) {
//    // if the state has changed, increment the counter
//    if (buttonState == HIGH) {
//      // if the current state is HIGH then the button
//      // wend from off to on:
//      buttonPushCounter++;
//      Serial.println("on");
//      Serial.print("number of button pushes:  ");
//      Serial.println(buttonPushCounter);
//    } else {
//      // if the current state is LOW then the button
//      // wend from on to off:
//      Serial.println("off");
//    }
//    // Delay a little bit to avoid bouncing
// //   delay(50);
//  }
//  // save the current state as the last state,
//  //for next time through the loop
//  lastButtonState = buttonState;

  buttonState = digitalRead(buttonPin);
 
  ledState = digitalRead(ledPin);
  
  if (buttonState != buttonSwitch ) {
        if (buttonState != HIGH) {
          digitalWrite(ledPin, HIGH);
          buttonCounter++;
          if (buttonCounter == 2) {
             digitalWrite(ledPin, LOW);
          }
          
          if (ledState == HIGH) {
           buttonCounter = 0; 
        }
        }
         Serial.println(buttonCounter);
        
        
             
  } 
  buttonSwitch = buttonState;
}


