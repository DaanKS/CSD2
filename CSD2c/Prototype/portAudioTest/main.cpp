#include "port_audio.h"
#include "tremolo.h"
#include <iostream>
#include <stdexcept>
#include <exception>

struct MyCallback : AudioIODeviceCallback {

  Tremolo* trem;
  Tremolo* trem_2;

  void prepareToPlay(int sampleRate, int numSamplesPerBlock) override {
    trem = new Tremolo(sampleRate);
    trem->setRate(1.0);
    trem->setAmplitude(1.0);
    trem_2 = new Tremolo(sampleRate);
    trem_2->setRate(1.5);
    trem_2->setAmplitude(1.0);
  }
  void process(float* input, float* output, int numSamples, int numChannels) override {
    for(int sample = 0; sample < numSamples; ++ sample){
      output[sample * 2] = trem->output(input[sample * 2]);
      output[sample * 2 + 1] = trem_2->output(input[sample * 2]);
    }
  }
  void releaseResources() override {
    delete trem;
    trem = nullptr;
    delete trem_2;
    trem_2 = nullptr;
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
