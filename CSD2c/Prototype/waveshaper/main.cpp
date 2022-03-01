#include "port_audio.h"
#include "waveshaper.h"
#include <iostream>
#include <stdexcept>
#include <exception>

struct MyCallback : AudioIODeviceCallback {
    Waveshaper* trem;
    Waveshaper* trem_2;


    void prepareToPlay(int sampleRate, int numSamplesPerBlock) override {
        trem = new Waveshaper(sampleRate);
        trem_2 = new Waveshaper(sampleRate);
        trem->generateWaveTable();
        trem_2->generateWaveTable();
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
