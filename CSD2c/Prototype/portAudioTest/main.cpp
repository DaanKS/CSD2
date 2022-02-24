#include "port_audio.h"
#include "tremolo.h"
#include <iostream>
#include <stdexcept>
#include <exception>

struct MyCallback : AudioIODeviceCallback {

  Tremolo* trem;

  void prepareToPlay(int sampleRate, int numSamplesPerBlock) override {
    trem = new Tremolo(sampleRate);
    trem->setRate(1.0);
    trem->setAmplitude(1.0);
  }
  void process(float* input, float* output, int numSamples, int numChannels) override {
    for(int sample = 0; sample < numSamples; ++ sample){
      output[sample * 2] = trem->output(input[sample]);
      output[sample * 2 + 1] = trem->output(input[sample]);
    }
  }
  void releaseResources() override {
    delete trem;
    trem = nullptr;
  }


};

int main() {
  auto myCallback = MyCallback();
  auto portAudio = PortAudio(myCallback);

  try {
    portAudio.setup(44100, 512);
  }
  catch (std::runtime_error& e) {
    std::cerr << "error: " << e.what() << "\n";
  }

  /* waiting / control loop */

  try {
    portAudio.teardown();
  }
  catch (std::runtime_error& e) {
    std::cerr << "error: " << e.what() << "\n";
    return -1;
  }

  return 0;
}
