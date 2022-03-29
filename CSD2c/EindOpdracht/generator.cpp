#include "generator.h"

Generator::Generator(float inputBuffer[], int inputBufSize, int numberParams) :
                     inputBufSize(inputBufSize){
#if DEBUG > 0
  std::cout<< "constructor Generator" <<std::endl;
#endif
  //detect the energy of a chunk (read more in EnergyDetect class)
  energyDetect = new EnergyDetect(inputBuffer, inputBufSize, numberParams);
  //stretch the chunk back over the input bufferSize
  calcSampsBetweenAmps();
}

Generator::~Generator() {
   //release the buffers
  delete energyDetect;
  energyDetect = nullptr;

#if DEBUG > 0
  std::cout<< "~destructor Generator" <<std::endl;
#endif
}

void Generator::calcSampsBetweenAmps() {
  //the length of the total envelope should be stretched back over the inputBufSize
  //the amount of time between amps is divided depending on the length of
  //the input and the size of the envAmpBuffer
  sampsBetweenAmps = inputBufSize / energyDetect->envAmpBufferSize;

#if DEBUG > 2
  std::cout<< "smapBtweenAmps " << sampsBetweenAmps << std::endl;
  std::cout<< "inputBufsize " << inputBufSize <<std::endl;
  std::cout<< "nvAmpBufferSize" << energyDetect->envAmpBufferSize <<std::endl;
#endif
}

void Generator::calcSlopeIncrement(int paramNumber) {
  //calculate slope from point 1 to point 2 in a given amount of samples
  //if check so the index of envSlope2 stays in range of the envAmpBufferSize
  if (envPoint2 < energyDetect->envAmpBufferSize){
    ampEnvPoint1 = energyDetect->envAmpBuffer[paramNumber][envPoint1];
    ampEnvPoint2 = energyDetect->envAmpBuffer[paramNumber][envPoint2];
    slopeIncrement = (ampEnvPoint2 - ampEnvPoint1) / sampsBetweenAmps;
#if DEBUG > 2
    std::cout<< "slopeIncrement: " << slopeIncrement <<std::endl;
#endif
  }else{
    //if the envBuffer reached its end, reset index to 0
    envPoint1 = 0;
    envPoint2 = 1;
    slope = 0;
  }
}

float Generator::envAtSamp(int paramNumber) {
  //this function get executed at audio rate
  //and returns the amp value for each effect
  timesExecuted++;
  float ampAtSamp;
    //calculate in how many steps the first envPoint should go
    //to the second enPoint depending on the buffer size

    //TODO: 0 at beginning and 0 at ending of each envelope
    //TODO: duration of each envelope depending on the length of the inputBuffer
    //with some nice algorithm

    if (timesExecuted < sampsBetweenAmps) {

      //slope starts at 0 cuz all envelopes start at ampEnvPoint1
      //after it has been added to the first envelope value
      //the slope gets incrementally bigger depending on the sampsBetweenAmps
      //ampEnvPoint1 + 0,001 in case 0
      //otherwise the audio feedback system stops
      ampAtSamp = (ampEnvPoint1 + 0.001) + slope;
      slope = slope + slopeIncrement;
#if DEBUG > 2
      std::cout<< "envPoint1" << ampEnvPoint1 <<std::endl;
      std::cout<< "envPoint2" << ampEnvPoint2 <<std::endl;
      std::cout<< "ampAtSamp: " << ampAtSamp <<std::endl;
#endif
    } else {
      envPoint1++;
      envPoint2++;
      //slope gets reset to 0 zo the original amp value is the envbuffer
      slope = 0;
      calcSlopeIncrement(paramNumber);
      ampAtSamp = ampEnvPoint1;
    }
  return ampAtSamp;
}