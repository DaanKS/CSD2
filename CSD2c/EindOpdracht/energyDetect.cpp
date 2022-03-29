#include "energyDetect.h"

EnergyDetect::EnergyDetect(float inputBuffer[], int inputBufSize, int numberParams){
  //TODO: fit all that buffer shit in some nice ellegant function
  //instead of 632187691 million buffers
  //# sec audio same as sample count
  //+1 cuz envelope ends with a 0
  bufferSize = (inputBufSize / fraction);
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
  //the total buffer of energy values divided by the number of fx params
  //this way every fx param gets its own envelope piece
  envAmpBufferSize = bufferSize / numberParams;

  //create a 2d array, the number of rows = number of fx params
  //the number of columns = the number envelope points in a buffer
  envAmpBuffer = new float* [numberParams];
  for(int i = 0; i < numberParams; i++){
    envAmpBuffer[i] = new float [envAmpBufferSize];
  }

  //fill each row with a chunk of the envBuffer
  //depending on the number of fx params
  for (int i = 0; i < numberParams; i++){
    for (int j = 0; j < envAmpBufferSize; j++){
      envAmpBuffer[i][j] = envBuffer[j + envChunckForFx];
#if DEBUG > 2
      std::cout<< "envAmpBuffer [i]: " << envAmpBuffer[i] << " [j]: " <<  envAmpBuffer[i][j] <<std::endl;
#endif
    }
    envChunckForFx = envChunckForFx + envAmpBufferSize;
  }
}

EnergyDetect::~EnergyDetect() {
  //release them buffers
  delete [] envBuffer;
  envBuffer = nullptr;
  delete [] envAmpBuffer;
  envAmpBuffer = nullptr;
}

void EnergyDetect::averageEnvAmp(float inputBuffer[], int inputBufSize) {
  int sampleCount = 0;
  float inputBufSampVal = 0;
  int envBufferIndex = 0;

  //average the amp of each chunk
  for(int i = 0; i < inputBufSize; i++){
    //add all the amp values of a block together
    inputBufSampVal = inputBufSampVal + abs(inputBuffer[i]);
    sampleCount++;
    if(sampleCount >= fraction){
      //take the average of a sample chunk and write the average the EnvArray
      //for each fx param
      float averageAmp;
      averageAmp = (inputBufSampVal / fraction);
      //quick and dirty fix
      if(averageAmp > 1){
        averageAmp = 1;
      }
      envBuffer[envBufferIndex] = averageAmp;
      envBufferIndex++;
      //reset the counter for the if statement
      sampleCount = 0;
      //reset the averaging block
      inputBufSampVal = 0;
#if DEBUG > 2
      for(int i = 0; i < inputBufSize; i++){
        std::cout<< " envBuffer[i] " << envBuffer[i] <<std::endl;
      }
#endif
    }
  }
}