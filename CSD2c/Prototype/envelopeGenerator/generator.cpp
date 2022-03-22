#include "generator.h"

Generator::Generator(float inputBuffer[], int inputBufSize, int numberFx,
                     int fxIndex, unsigned int samplerate) :
                     inputBufSize(inputBufSize), samplerate(samplerate) {
#if DEBUG > 0
  std::cout<< "constructor Generator" <<std::endl;
#endif
  //detect the energy of a sampleblock
 energyDetect = new EnergyDetect(inputBuffer, inputBufSize, numberFx, samplerate);
  envPerFx(0);

}

Generator::~Generator() {
   //release the buffers
  delete energyDetect;
  energyDetect = nullptr;

#if DEBUG > 0
  std::cout<< "~destructor Generator" <<std::endl;
#endif
}

void Generator::envPerFx(int fxIndex) {
  //this function get excecuted at audio rate
  //and returns the amp value for each effect

  //TODO: 0 at beginning and 0 at ending of each envelope
  //TODO: duration of each envelope depending on the length of the inputBuffer
  //with some nice algoritm

  //the length of the total envelope = number of inputBuffer samps (inputBufSize)
  //the amount of time between amps is devided depending on the lenth of
  //the input and the size of the envAmpBuffer
  int sampsBetweenAmps = inputBufSize / energyDetect->envAmpBufferSize;
  //point 1 to point 2 in a given amount of samples
  float ampEnvPoint1 = energyDetect->envAmpBuffer[fxIndex][envPoint1];
  float ampEnvPoint2 = energyDetect->envAmpBuffer[fxIndex][envPoint2];
  float slope = (envPoint2 - envPoint1) / sampsBetweenAmps;
  std::cout<< "slope: " << slope <<std::endl;
  float ampAtSamp = envPoint1 + slope;
  if(slope >= ampEnvPoint2) {
    //go to the next pair of amps
    envPoint1++;
    envPoint2++;
  }
  std::cout<< "ampAtSamp: " << ampAtSamp <<std::endl;

}