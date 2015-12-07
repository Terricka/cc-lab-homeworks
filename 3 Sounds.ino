 int potPin = A0;
 int potVal = 0;
 int toneOne;
 
 int photoPin = A1;
 int photoVal = 0;
 
 const int buttonPin = 9;
 int buttonState = 0;
 


void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(buttonPin, INPUT);
  
}

void loop() {
  buttonState = digitalRead(buttonPin);
  digitalWrite(3, LOW);
  
  if( analogRead(potPin) > 600){
     digitalWrite(3, HIGH);
    tone(1, 30);
  } else if  ( analogRead(photoPin) > 300){
     digitalWrite(3, HIGH);
    tone(7, 80);
  } else {
    digitalWrite(3, LOW);
  }
  
  
  
  if (buttonState == HIGH) {
     digitalWrite(3, HIGH);
     tone(4, 20);
  } else {
    // turn LED off:
    digitalWrite(3, LOW);
  }
  
  digitalWrite(3, LOW);
 
 
    

}
