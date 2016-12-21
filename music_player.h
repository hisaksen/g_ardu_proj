#include "SD.h"
#define SD_ChipSelectPin 4
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm audio;

char wave[] = "gwave.wav";

int inputPin = 2;               // PIR sensor PIN
int pirState = LOW;             // Motion detection starts at off
int val = 0;                    // Instantiate PIN reading
 
void setup() {
  audio.speakerPin = 10; //5,6,11 or 46 on Mega, 9 on Uno, Nano, etc
  pinMode(inputPin, INPUT);     // Sensor as Input
  if (!SD.begin(SD_ChipSelectPin)) {
    Serial.println("SD fail");
    return;
  }
  audio.setVolume(6);
  Serial.begin(9600);
  
}

void loop(){
  val = digitalRead(inputPin);
  int personDetected = 1;
  int audioInProgress = 0;
  Serial.println(val);
  if (val == personDetected && audio.isPlaying() == audioInProgress) {
      // Check to see if PIR picks up on motion and song is not playing
      Serial.println("Motion detected!");
      audio.play(wave);
  }
}