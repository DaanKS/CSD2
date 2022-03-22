#include "energyDetect.h"

EnergyDetect::EnergyDetect(float inputBuffer[], int inputBufSize,
                           unsigned int samplerate) : m_samplerate(samplerate){
  std::cout<< "contructor EnergyDetect" <<std::endl;
  //10 seconds of audio
  bufferSize = (inputBufSize / fraction) + 1;
  std::cout<< "bufferSize: " << bufferSize <<std::endl;
  //allocate the envBuffer
  envBuffer = new float [bufferSize];
  for(int i = 0; i < bufferSize; i++){
    envBuffer[i] = 0;
  };

  averageEnvAmp(inputBuffer, inputBufSize);

  for(int i = 0; i < bufferSize; i++){
    std::cout<< envBuffer[i] <<std::endl;
  };
}

EnergyDetect::~EnergyDetect() {
  std::cout<< "~detsructor EnergyDetect" <<std::endl;
  delete [] envBuffer;
  envBuffer = nullptr;
}

void EnergyDetect::averageEnvAmp(float inputBuffer[], int inputBufSize) {
  int sampleCount = 0;
  float inputBufSampVal = 0;
  int envBufferIndex = 0;
  //average the amp of each block
  for(int i = 0; i < inputBufSize; i++){
    //add all the amp values of a block together
    inputBufSampVal = inputBufSampVal + inputBuffer[i];
    sampleCount++;
    if(sampleCount >= fraction){
      //take the average of a sample block and write the to the EnvArray
      float averageAmp = inputBufSampVal / fraction;
      std::cout<< "average Amp: " << averageAmp <<std::endl;
      envBuffer[envBufferIndex] = averageAmp;
      envBufferIndex++;
      sampleCount = 0;
    }
  }
}