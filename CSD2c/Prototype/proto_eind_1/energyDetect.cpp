#include "energyDetect.h"

EnergyDetect::EnergyDetect() {}

EnergyDetect::EnergyDetect(float inputBuffer[], int inputBufSize, int numberParams){
  std::cout<< "constructor EnergyDetect" <<std::endl;
  //TODO: fit all that buffer shit in some nice ellegant function
  //10 seconds of audio
  //+1 cuz envelope ends with a 0
  bufferSize = (inputBufSize / fraction);
//  std::cout<< "bufferSize: " << bufferSize <<std::endl;
  //allocate the envBuffer
  envBuffer = new float [bufferSize];
  for(int i = 0; i < bufferSize; i++){
    envBuffer[i] = 0;
  };

  averageEnvAmp(inputBuffer, inputBufSize);

#if DEBUG > 2
  for(int i = 0; i < bufferSize; i++){
    std::cout<< envBuffer[i] <<std::endl;
  };
#endif
  //the total buffer of energy values devided by the number of fx
  //this way every fx gets its own envelope piece
  envAmpBufferSize = bufferSize / numberParams;

  //create a 2d array, the number of rows = number of fx
  //the number of collums = the number envelope points in a buffer
  envAmpBuffer = new float* [numberParams];
  for(int i = 0; i < numberParams; i++){
    envAmpBuffer[i] = new float [envAmpBufferSize];
  }

  //fill each row with a chunck of the envBuffer
  //depending on the number of fx
  for (int i = 0; i < numberParams; i++){
    for (int j = 0; j < envAmpBufferSize; j++){
      envAmpBuffer[i][j] = envBuffer[j + envChunckForFx];
      std::cout<< "envAmpBuffer[i][j]"<< envAmpBuffer[0][j]<<std::endl;
#if DEBUG > 2
      std::cout<< "envAmpBuffer [i]: " << envAmpBuffer[i] << " [j]: " <<  envAmpBuffer[i][j] <<std::endl;
#endif
    }
    envChunckForFx = envChunckForFx + envAmpBufferSize;
  }
}

EnergyDetect::~EnergyDetect() {
  std::cout<< "~detsructor EnergyDetect" <<std::endl;
  delete [] envBuffer;
  envBuffer = nullptr;
  delete [] envAmpBuffer;
  envAmpBuffer = nullptr;
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
//      std::cout<< "inputBufSampVal: " << inputBufSampVal <<std::endl;
      float averageAmp = inputBufSampVal / fraction;
      envBuffer[envBufferIndex] = averageAmp;
      envBufferIndex++;
      //reset the counter for the if statement
      sampleCount = 0;
      //reset the averaging block
      inputBufSampVal = 0;
    }
  }
}