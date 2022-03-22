#include <iostream>
#include <vector>
#include "energyDetect.h"
#include "envelope.h"
#include "generator.h"

unsigned int samplerate = 44;

int numberFX = 3;

// a vector because its convinient for an audio recording
// max size is 10 secsonds
int inputBufSize = samplerate * 10;
float* inputBuffer;
int recordedSamps;
int nFrames = inputBufSize;
int fxIndex = 2;

//vector met numFX
//make die envelopes, voor elke fx
//vector met env voor elk fx
//dus elke fx heeft zijn eigen gen + env
//gen heeft index in de fx vector nodig om te welk deel van
//de audio recording gechopped moet worden
//de env vector wordt op audio rate uitgelzen
//dus kan die index gebruiken

//fx vector
std::vector<int> effects = {1, 2, 3};
//std::vector<Envelope> envelopes = {env1, env2, env3};

int main(){
  std::cout<< "hoi" <<std::endl;
  inputBuffer = new float [inputBufSize];
  for (int i  = 0; i < nFrames; i++){
    float amp = i / 1000.0f;
    inputBuffer[i] = amp;
//    std::cout<< inputBuffer[i] <<std::endl;
    recordedSamps++ ;
  }
  std::cout<< "recorededSamps: " << recordedSamps <<std::endl;
  //recordedSamps becomes the new bufferSize within the EnergyDetect function
 Generator generator (inputBuffer, recordedSamps,
                    numberFX, fxIndex ,samplerate);

  return 0;
}
