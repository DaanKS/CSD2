#include "envelope.h"

Envelope::Envelope(float inputBuffer[], int inputBufSize, int numberFx,
                   int fxIndex, unsigned int samplerate) :
                   Generator(inputBuffer, inputBufSize, numberFx, fxIndex,
                             samplerate){
#if DEBUG > 0
  std::cout<< "constructor Envelope" <<std::endl;
#endif

//  for (int i = 0; i < numberFx; i++){
//    for (int j = 0; j < envAmpBufferSize; j++){
//      std::cout<< "envAmpBuffer [i]: " << envAmpBuffer[i] << " [j]: " <<  envAmpBuffer[j] <<std::endl;
//    }
//  }
}

Envelope::~Envelope() {
#if DEBUG > 0
  std::cout<< "~destructor Envelope" <<std::endl;
#endif
}

float Envelope::millisToSamps(float millis) {
  float samps = millis * (samplerate / 1000.0f);
  return samps;
#if DEBUG > 1
  std::cout<< "Envelope millisToSamps millis: " << millis <<std::endl;
  std::cout<< "Envelope millisToSamps samps: " << samps <<std::endl;
#endif
}


