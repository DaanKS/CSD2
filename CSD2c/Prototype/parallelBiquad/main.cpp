#include "port_audio.h"
#include "waveshaper.h"
#include "biquad.h"
#include <iostream>
#include <stdexcept>
#include <exception>
#include <vector>



struct MyCallback : AudioIODeviceCallback {
    AudioEffect* wave_1;
    AudioEffect* wave_2;
    AudioEffect* biquad;
    //AudioEffect* biqhpf;
    AudioEffect* bandpass;


    auto prepareToPlay(int sampleRate, int numSamplesPerBlock) -> void override {

    }
    auto process(float* input, float* output, int numSamples, int numChannels) -> void override {
        for(auto sample = 0; sample < numSamples; ++ sample){
            auto tempSample = input[sample * 2];//bandpass->output(input[sample * 2]);
            //float tempSample = input[sample * 2];
            auto tempSample_1 = wave_1->output(biquad->output(tempSample));
           // auto tempSample_2 = wave_2->output(biqhpf->output(tempSample));

            output[sample * 2] = tempSample_1;
          //  output[sample * 2 + 1] = tempSample_2;
        }
    }
    auto releaseResources() -> void override {}

};

auto main() -> int {

    auto myCallback = MyCallback();
    auto portAudio = PortAudio(myCallback);

    auto samplerate = 44100.0f;
/*
    auto bandpass1 = Bandpass();
        bandpass1.setSamplerate(samplerate);
        bandpass1.setCutoffFreq(1000);
        bandpass1.setBandWidth(10.0);
        bandpass1.setQFactor(10.0);
        bandpass1.calculateOmega();
        bandpass1.calculateAlpha();
        bandpass1.calculateCoefficients();
    myCallback.bandpass = &bandpass1;
*/
    auto waveshaper = Waveshaper();
        waveshaper.setKvalue(100.0);
        waveshaper.setSamplerate(samplerate);
    myCallback.wave_1 = &waveshaper;
    auto waveshaper2 = Waveshaper();
        waveshaper2.setKvalue(100.0);
        waveshaper2.setSamplerate(samplerate);
    myCallback.wave_2 = &waveshaper2;
    auto biquad2 = Biquad();
        biquad2.setSamplerate(samplerate);
        biquad2.setCutoffFreq(500);
        biquad2.setQFactor(1.0);
        biquad2.calculateOmega();
        biquad2.calculateAlpha();
        biquad2.calculateCoefficients();
    myCallback.biquad = &biquad2;
 /*
    auto biquad3 = BiqHPF();
        biquad3.setSamplerate(samplerate);
        biquad3.setCutoffFreq(200);
        biquad3.setQFactor(1.0);
        biquad3.calculateOmega();
        biquad3.calculateAlpha();
        biquad3.calculateCoefficients();
    myCallback.biqhpf = &biquad3;
*/

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

                biquad2.setCutoffFreq(tempValue);
                biquad3.setCutoffFreq(tempValue + tempDistance);

                std::cout << "Enter New Value for Qfactor: ";
                std::cin >> tempValue;

                biquad2.setQFactor(tempValue);
                biquad2.calculateOmega();
                biquad2.calculateAlpha();
                biquad2.calculateCoefficients();

                biquad3.setQFactor(tempValue);
                biquad3.calculateOmega();
                biquad3.calculateAlpha();
                biquad3.calculateCoefficients();
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
