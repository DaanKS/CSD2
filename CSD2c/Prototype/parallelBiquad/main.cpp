#include "port_audio.h"
#include "waveshaper.h"
#include "biquad.h"
#include "modDelay.h"
#include "tremolo.h"
#include "waveshaper.h"

#include <iostream>
#include <stdexcept>
#include <exception>
#include <vector>



struct MyCallback : AudioIODeviceCallback {
    AudioEffect* wave;
    AudioEffect* biquad;


    void prepareToPlay(int sampleRate, int numSamplesPerBlock) override {

    }
    void process(float* input, float* output, int numSamples, int numChannels) override {
        for(int sample = 0; sample < numSamples; ++ sample){
            float tempSample = biquad->output(wave->output(input[sample * 2]));

            output[sample * 2] = tempSample;
            output[sample * 2 + 1] = tempSample;
        }
    }
    void releaseResources() override {}

};

int main() {

    auto myCallback = MyCallback();
    auto portAudio = PortAudio(myCallback);

    float samplerate = 44100;

    Waveshaper waveshaper;
        waveshaper.setKvalue(1.0);
        waveshaper.setSamplerate(samplerate);
    myCallback.wave = &waveshaper;
    Biquad biquad2;
        biquad2.setSamplerate(samplerate);
        biquad2.setCutoffFreq(1000);
        biquad2.setQFactor(1.0);
        biquad2.calculateOmega();
        biquad2.calculateAlpha();
        biquad2.calculateCoefficients();
    myCallback.biquad = &biquad2;

    try {
        portAudio.setup(44100, 512);
    }
    catch (std::runtime_error& e) {
        std::cerr << "error: " << e.what() << "\n";
    }

    /* waiting / control loop */
    float tempValue;
    bool running = true;
    while(running) {
        switch (std::cin.get()) {
            case 'q':
                running = false;
                break;
            case 'w':
                std::cout << "Enter New Value for K value: ";
                std::cin >> tempValue;
                waveshaper.setKvalue(tempValue);
                break;
            case 'e':
                std::cout << "Enter New Value for Cutoff: ";
                std::cin >> tempValue;
                biquad2.setCutoffFreq(tempValue);
                std::cout << "Enter New Value for Qfactor: ";
                std::cin >> tempValue;
                biquad2.setQFactor(tempValue);
                biquad2.calculateOmega();
                biquad2.calculateAlpha();
                biquad2.calculateCoefficients();
                break;
            

        }
    }
    //std::cin.get();

    try {
        portAudio.teardown();
    }
    catch (std::runtime_error& e) {
        std::cerr << "error: " << e.what() << "\n";
        return -1;
    }

    return 0;
}
