#include "SD.h"
#define SD_ChipSelectPin 4
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm audio;

char wave[] = "gwave.wav";

int ledPin = 13;                // Using Arduino Uno's built in LED to test sensor
int inputPin = 2;               // PIR sensor PIN
int pirState = LOW;             // Motion detection starts at off
int val = 0;                    // Instantiate PIN reading
 
void setup() {
  pinMode(ledPin, OUTPUT);      // LED as Output
  pinMode(inputPin, INPUT);     // Sensor as Input
  audio.speakerPin = 10; //5,6,11 or 46 on Mega, 9 on Uno, Nano, etc
  audio.setVolume(6);
  Serial.begin(9600);
}

void loop(){
  val = digitalRead(inputPin);
  if (val == HIGH && audio.isPlaying() == 0) {
      // Check to see if PIR picks up on motion and song is not playing
      Serial.println("Motion detected!");
      audio.play(wave);
  }
}
