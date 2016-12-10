#include "SD.h"
#define SD_ChipSelectPin 4
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;

char wave[] = "gwave.wav";

void setup(){
tmrpcm.speakerPin = 9;
Serial.begin(9600);
if (!SD.begin(SD_ChipSelectPin)) {
Serial.println("SD fail");
return;
}
tmrpcm.setVolume(6); // max volume is 7
tmrpcm.play(wave);
}

void loop(){  }
