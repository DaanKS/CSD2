#include "port_audio.h"
#include "waveshaper.h"
#include "biquad.h"
#include "modDelay.h"
#include "tremolo.h"
#include "waveshaper.h"

#include <iostream>
#include <stdexcept>
#include <exception>

struct MyCallback : AudioIODeviceCallback {
    AudioEffect* wave;
    AudioEffect* biquad;
    AudioEffect* mod_L;
    AudioEffect* mod_R;
    AudioEffect* trem;

    void prepareToPlay(int sampleRate, int numSamplesPerBlock) override {
        wave = new Waveshaper(sampleRate);
            ((Waveshaper*)wave)->setKvalue = 10;
        biquad = new Biquad(sampleRate);
            ((Biquad*)biquad)->setCutoffFreq(500);
            ((Biquad*)biquad)->setQFactor(0.01);
            ((Biquad*)biquad)->calculateOmega();
            ((Biquad*)biquad)->calculateAlpha();
            ((Biquad*)biquad)->calculateCoefficients();
        mod_L = new ModDelay(sampleRate);
            ((ModDelay*)mod_L)->setRate(0.1);
        mod_R = new ModDelay(sampleRate);
            (ModDelay*)mod_R)->setRate(0.13);
        trem = new Tremolo(sampleRate);
            ((Tremolo*)trem)->setRate(1.0);
            ((Tremolo*)trem)->setAmplitude(0.0);
    }
    void process(float* input, float* output, int numSamples, int numChannels) override {
        for(int sample = 0; sample < numSamples; ++ sample){
            float tempSample = biquad->(wave->output(input[sample * 2])))

            output[sample * 2] = mod_L->output(tempSample);
            output[sample * 2 + 1] = mod_R->output(tempSample);
        }
    }
    void releaseResources() override {
        delete trem;
        trem = nullptr;
        delete biquad;
        biquad = nullptr;
        delete mod_R;
        mod_R = nullptr;
        delete mod_L;
        mod_L = nullptr;
        delete wave;
        wave = nullptr;
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
