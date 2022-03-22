#include <iostream>
#include "energyDetect.h"

unsigned int samplerate = 40;
int inputBufSize = samplerate * 10;
float* inputBuffer;

int main(){
  std::cout<< "hoi" <<std::endl;
  //10 secs audio
  inputBuffer = new float [inputBufSize];
  //make a fake input buffer
  for (int i = 0; i < inputBufSize; i++){
    inputBuffer[i] = float(i) / 1000.0f;
    std::cout<< "inputBuf: " << inputBuffer[i] <<std::endl;
  };

  EnergyDetect ed(inputBuffer, inputBufSize, samplerate);

  delete [] inputBuffer;
  inputBuffer = nullptr;
  return 0;
}