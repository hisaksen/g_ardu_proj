#include "SD.h"
#define SD_ChipSelectPin 4
#include "TMRpcm.h"             //Audio Library
#include "SPI.h"

TMRpcm tmrpcm;                  //instantiate audio lib as _____
char wave[] = "gwave.wav";      // change this to name of audio file on SD shield

int ledPin = 13;                // Using Arduino Uno's built in LED to test sensor
int inputPin = 2;               // PIR sensor PIN
int pirState = LOW;             // Motion detection starts at off
int val = 0;                    // Instantiate PIN reading

 
void setup() {
  pinMode(ledPin, OUTPUT);      // LED as Output
  pinMode(inputPin, INPUT);     // Sensor as Input

  tmrpcm.speakerPin = 9;        //Set speaker pin

  if (!SD.begin(SD_ChipSelectPin)) {
    Serial.println("SD fail");
  return;
  }
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
      tmrpcm.setVolume(6);     // Set volume for speaker(Max 7)
      tmrpcm.play(wave);       // Play wav file
      Serial.println("Motion ended!"); // open arduino IDE serial monitor
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
}
