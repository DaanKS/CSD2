#include "generator.h"

Generator::Generator(float inputBuffer[], int inputBufSize, int numberFx,
                     int fxIndex, unsigned int samplerate) :
                     inputBufSize(inputBufSize), samplerate(samplerate) {
#if DEBUG > 0
  std::cout<< "constructor Generator" <<std::endl;
#endif
  //detect the energy of a sampleblock
 energyDetect = new EnergyDetect(inputBuffer, inputBufSize, numberFx, samplerate);



  calcSampsBetweenAmps();
  calcSlopeIncrement(fxIndex);
  for (int i = 0; i < inputBufSize; i++){
    envAtSamp(fxIndex);
  }
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
  //the length of the total envelope = number of inputBuffer samps (inputBufSize)
  //the amount of time between amps is devided depending on the lenth of
  //the input and the size of the envAmpBuffer
  sampsBetweenAmps = inputBufSize / energyDetect->envAmpBufferSize;
#if DEBUG > 2
  std::cout<< "sampsBetweenAmps: " << sampsBetweenAmps <<std::endl;
#endif
}

void Generator::calcSlopeIncrement(int fxIndex) {
  //point 1 to point 2 in a given amount of samples
  //if check so the index od envSlope2 stays in range of the envAmpBufferSize
  if (envPoint2 < energyDetect->envAmpBufferSize){
    ampEnvPoint1 = energyDetect->envAmpBuffer[fxIndex][envPoint1];
    ampEnvPoint2 = energyDetect->envAmpBuffer[fxIndex][envPoint2];
    slopeIncrement = (ampEnvPoint2 - ampEnvPoint1) / sampsBetweenAmps;
#if DEBUG > 2
    std::cout<< "slopeIncrement: " << slopeIncrement <<std::endl;
#endif
  }else{
    //if the envBuffer reached its, reset index to 0
    envPoint1 = 0;
    envPoint2 = 0;
  }
}

float Generator::envAtSamp(int fxIndex) {
  //this function get excecuted at audio rate
  //and returns the amp value for each effect

  //TODO: 0 at beginning and 0 at ending of each envelope
  //TODO: duration of each envelope depending on the length of the inputBuffer
  //with some nice algoritm
  float ampAtSamp;
  if(slope < ampEnvPoint2) {
    //slope starts at 0 cuz all envelopes start at 0
    //after it has been added to the first envelope value
    //the slope get increangily bigger depending on de sampsBetweenAmps

    ampAtSamp = ampEnvPoint1 + slope;
    slope = slope + slopeIncrement;
#if DEBUG > 2
    std::cout<< "envPoint1" << ampEnvPoint1 <<std::endl;
    std::cout<< "envPoint2" << ampEnvPoint2 <<std::endl;
    std::cout<< "ampAtSamp: " << ampAtSamp <<std::endl;
#endif
  }else{
    envPoint1++;
    envPoint2++;
    //slope gets reset to 0 zo the origanl amp value is the env
    slope = 0;
    calcSlopeIncrement(fxIndex);
  }
  return ampAtSamp;
}