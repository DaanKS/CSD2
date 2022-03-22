#include "port_audio.h"
#include "datorro.h"
#include "analysis.h"
#include <iostream>
#include <stdexcept>
#include <exception>
#include <vector>



struct MyCallback : AudioIODeviceCallback {
    //Datorro* datorro;
    //ModAllPass* mod_1;
    //Allpass* mod_1;
    //Onepole* mod_1;
    //PreDelay* mod_1;
    Comb* datorro;
    Analysis* analysis;

    float tempSample_1 = 0.0f;
    float tempSample_2 = 0.0f;
    float tempSample = 0.0f;

    auto prepareToPlay(int sampleRate, int numSamplesPerBlock) -> void override {

    }
    auto process(float* input, float* output, int numSamples, int numChannels) -> void override {
        for(auto sample = 0; sample < numSamples; ++ sample){
            tempSample = datorro->output(input[sample * 2] + (tempSample * analysis->returnControlValue()));

            //tempSample_1 = datorro->outputL(tempSample);
            //tempSample_2 = datorro->outputR(tempSample);

            analysis->takeAverage(tempSample);
            std::cout << "output of average: " << analysis->returnControlValue() << std::endl;

            output[sample * 2] = tempSample / 4.0;//(tempSample_1 / 4.0) + input[sample * 2];
            output[sample * 2 + 1] = tempSample / 4.0;//(tempSample_2 / 4.0) + input[sample * 2];
        }
    }
    auto releaseResources() -> void override {}

};

auto main() -> int {

    auto myCallback = MyCallback();
    auto portAudio = PortAudio(myCallback);

    auto samplerate = 44100.0f;


    auto datorro_1 = Comb(samplerate, 100, 1.0, 0.0);
    myCallback.datorro = &datorro_1;


    auto anal = Analysis(10);
    myCallback.analysis = &anal;

    try {
        portAudio.setup(44100, 512);
        std::cout << "Started PortAudio" << std::endl;
    }
    catch (std::runtime_error& e) {
        std::cerr << "error: " << e.what() << "\n";
    }

    /* waiting / control loop */
    //auto  tempValue = 0.0f;
    auto running = true;
    while(running) {
        switch (std::cin.get()) {
            case 'q':
                running = false;
                break;
            case 'w':

                break;
            case 'e':

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
