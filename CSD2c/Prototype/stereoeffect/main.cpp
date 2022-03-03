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
    AudioEffect* mod_L;
    AudioEffect* mod_R;
    AudioEffect* trem;

    void prepareToPlay(int sampleRate, int numSamplesPerBlock) override {
   /*     wave = new Waveshaper(sampleRate);
            ((Waveshaper*)wave)->setKvalue(50);
            ((Waveshaper*)wave)->generateWaveTable();
        biquad = new Biquad(sampleRate);
            ((Biquad*)biquad)->setCutoffFreq(500);
            ((Biquad*)biquad)->setQFactor(0.01);
            ((Biquad*)biquad)->calculateOmega();
            ((Biquad*)biquad)->calculateAlpha();
            ((Biquad*)biquad)->calculateCoefficients();
        mod_L = new ModDelay(sampleRate);
            ((ModDelay*)mod_L)->setRate(0.1);
        mod_R = new ModDelay(sampleRate);
            ((ModDelay*)mod_R)->setRate(0.13);
        trem = new Tremolo(sampleRate);
            ((Tremolo*)trem)->setRate(1.0);
            ((Tremolo*)trem)->setAmplitude(0.0); */
    }
    void process(float* input, float* output, int numSamples, int numChannels) override {
        for(int sample = 0; sample < numSamples; ++ sample){
            float tempSample = biquad->output(wave->output(input[sample * 2]));

            output[sample * 2] = mod_L->output(tempSample);
            output[sample * 2 + 1] = mod_R->output(tempSample);
        }
    }
    void releaseResources() override {}

};

int main() {

    auto myCallback = MyCallback();
    auto portAudio = PortAudio(myCallback);

    float samplerate = 44100;

    Waveshaper waveshaper(samplerate);
        waveshaper.setKvalue(50);
    myCallback.wave = &waveshaper;
    Biquad biquad2(samplerate);
        biquad2.setCutoffFreq(500);
        biquad2.setQFactor(0.1);
        biquad2.calculateOmega();
        biquad2.calculateAlpha();
        biquad2.calculateCoefficients();
    myCallback.biquad = &biquad2;
    ModDelay modDelay_L(samplerate);
        modDelay_L.setRate(0.1);
    myCallback.mod_L = &modDelay_L;
    ModDelay modDelay_R(samplerate);
        modDelay_R.setRate(0.2);
    myCallback.mod_R = &modDelay_R;
    Tremolo tremo(samplerate);
    myCallback.trem = &tremo;

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
