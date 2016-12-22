/*
 */
 
int ledPin = 13;                // Using Arduino Uno's built in LED to test sensor
int inputPin = 3;               // PIR sensor PIN
int pirState = LOW;             // Motion detection starts at off
int val = 0;                    // Instantiate PIN reading
 
void setup() {
  pinMode(ledPin, OUTPUT);      // LED as Output
  pinMode(inputPin, INPUT);     // Sensor as Input

  Serial.begin(9600);
}
 
void loop(){
  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, HIGH);  // turn LED ON
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion detected!"); // open arduino IDE serial monitor
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW); // turn LED OFF
    if (pirState == HIGH){
      // we have just turned of
      Serial.println("Motion ended!"); // open arduino IDE serial monitor
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
}
