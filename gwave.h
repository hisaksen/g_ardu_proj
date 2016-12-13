#include "SD.h"
#define SD_ChipSelectPin 4
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm audio;

char wave[] = "gwave.wav";

void setup(){
  audio.speakerPin = 10; //5,6,11 or 46 on Mega, 9 on Uno, Nano, etc  
  Serial.begin(9600);
  
if (!SD.begin(SD_ChipSelectPin)) {
  Serial.println("SD fail");
return;
}
audio.setVolume(6);
audio.play(wave);
}

void loop(){  }
