#include "port_audio.h"
#include "waveshaper.h"
#include <iostream>
#include <stdexcept>
#include <exception>

struct MyCallback : AudioIODeviceCallback {
    Waveshaper* trem;
    float tempSample = 0.0f;


    void prepareToPlay(int sampleRate, int numSamplesPerBlock) override {}

    void process(float* input, float* output, int numSamples, int numChannels) override {
        for(int sample = 0; sample < numSamples; ++ sample){

            tempSample = trem->output(input[sample * 2]);

            output[sample * 2] = tempSample;
            output[sample * 2 + 1] = tempSample;
        }
    }
    void releaseResources() override {}


};

int main() {
    auto myCallback = MyCallback();
    auto portAudio = PortAudio(myCallback);

    auto sampleRate = 44100.0f;
    auto wave = Waveshaper(sampleRate);
    myCallback.trem = &wave;


    try {
        portAudio.setup(sampleRate, 512);
    }
    catch (std::runtime_error& e) {
        std::cerr << "error: " << e.what() << "\n";
    }

    bool running = true;
    float tempValue = 0.0f;
    /* waiting / control loop */
    while(running){
        while(running){
            switch (std::cin.get()) {
                case 'q':
                    running = false;
                    break;
                case 'w':
                    std::cout << "new value for K: ";
                    std::cin >> tempValue;
                    wave.setKvalue(tempValue);
                    break;
                case 'e':
                    std::cout << "new value for drywet: ";
                    std::cin >> tempValue;
                    wave.setDryWet(tempValue);
    }

    try {
        portAudio.teardown();
    }
    catch (std::runtime_error& e) {
        std::cerr << "error: " << e.what() << "\n";
        return -1;
    }

    return 0;
}
