#include <iostream>
#include <vector>
#include "energyDetect.h"
#include "envelope.h"
#include "generator.h"
#include "jack_module.h"

//unsigned int samplerate = 44;

int numberFX = 3;
//int inputBufSize = samplerate * 10;
//float* inputBuffer;
int recordedSamps;
//int nFrames = inputBufSize;
int fxIndex;

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


#include "port_audio.h"

struct MyCallback : AudioIODeviceCallback {

    Generator* generator;

    void prepareToPlay(int sampleRate, int numSamplesPerBlock) override {
      generator = new Generator()
      korus_L->setRate(0.1);
      korus_R->setRate(0.15);
    }
    void process(float* input, float* output, int numSamples, int numChannels) override {
      for(int sample = 0; sample < numSamples; ++ sample){
        output[sample * 2] = korus_L->output(input[sample * 2 + 1]);
        output[sample * 2 + 1] = korus_R->output(input[sample * 2 + 1]);
      }
    }
    void releaseResources() override {
      delete korus_L;
      korus_L = nullptr;
      delete korus_R;
      korus_R = nullptr;
    }


};

int main(){

  std::cout<< "hoi" <<std::endl;
//  inputBuffer = new float [inputBufSize];
//  for (int i  = 0; i < nFrames; i++){
//    float amp = i / 1000.0f;
//    inputBuffer[i] = amp;
//   std::cout<< inputBuffer[i] <<std::endl;
//    recordedSamps++ ;
//  };
//
//  Generator generator(inputBuffer, recordedSamps, numberFX, fxIndex, samplerate);
//
//  for(int i = 0; i < recordedSamps; i++){
//    generator.envAtSamp(2);
//  };
    auto myCallback = MyCallback();
    auto portAudio = PortAudio(myCallback);

    try {
      portAudio.setup(44100, 512);
    }
    catch (std::runtime_error& e) {
      std::cerr << "error: " << e.what() << "\n";
    }

    /* waiting / control loop */
    std::cin.get();

    try {
      portAudio.teardown();
    }
    catch (std::runtime_error& e) {
      std::cerr << "error: " << e.what() << "\n";
      return -1;
    }

    return 0;
}
