#include "port_audio.h"
#include "waveshaper.h"
#include "biquad.h"
#include "bibiquad.h"
#include <iostream>
#include <stdexcept>
#include <exception>
#include <vector>



struct MyCallback : AudioIODeviceCallback {
    AudioEffect* wave_1;
    AudioEffect* wave_2;
    AudioEffect* dualbiquad;
    //AudioEffect* hipass;
    AudioEffect* bandpass;


    auto prepareToPlay(int sampleRate, int numSamplesPerBlock) -> void override {

    }
    auto process(float* input, float* output, int numSamples, int numChannels) -> void override {
        for(auto sample = 0; sample < numSamples; ++ sample){
            auto tempSample = input[sample * 2];//bandpass->output(input[sample * 2]);

            auto tempSample_1 = wave_1->output(dualbiquad->outputLP(tempSample));
            auto tempSample_2 = wave_2->output(dualbiquad->outputHP(tempSample));

            output[sample * 2] = tempSample_1;
            output[sample * 2 + 1] = tempSample_2;
        }
    }
    auto releaseResources() -> void override {}

};

auto main() -> int {

    auto myCallback = MyCallback();
    auto portAudio = PortAudio(myCallback);

    auto samplerate = 44100.0f;

    auto waveshaper = Waveshaper();
        waveshaper.setKvalue(100.0);
        myCallback.wave_1 = &waveshaper;
    auto waveshaper2 = Waveshaper();
        waveshaper2.setKvalue(100.0);
        myCallback.wave_2 = &waveshaper2;

    auto dualBiquad = Bibiquad(samplerate);
        myCallback.dualbiquad = &dualBiquad;
/*
    auto biquad_1 = Biquad();
        biquad_1.setCoefficients(biquad_1.makeLowPass(500, 3.0, samplerate));
        myCallback.biquad = &biquad_1;
    auto biquad_2 = Biquad();
        biquad_2.setCoefficients(biquad_2.makeHighPass(700, 3.0, samplerate));
        myCallback.biqhpf = &biquad_2;
*/


    auto biquad_3 = Biquad();
        biquad_3.setCoefficients(biquad_3.makeBandPass(600, 3.0, samplerate, 2.0));
        myCallback.bandpass = &biquad_3;

    try {
        portAudio.setup(44100, 512);
    }
    catch (std::runtime_error& e) {
        std::cerr << "error: " << e.what() << "\n";
    }

    /* waiting / control loop */
    auto  tempValue = 0.0f;
    auto running = true;
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
                auto tempDistance = 0.0f;
                std::cout << "Enter New Value for Distance between the two filters: ";
                std::cin >> tempDistance;


                std::cout << "Enter New Value for Qfactor: ";
                std::cin >> tempValue;


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
