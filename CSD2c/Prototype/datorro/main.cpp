#include "port_audio.h"
#include "datorro.h"
#include <iostream>
#include <stdexcept>
#include <exception>
#include <vector>



struct MyCallback : AudioIODeviceCallback {
    Datorro* datorro;


    auto prepareToPlay(int sampleRate, int numSamplesPerBlock) -> void override {

    }
    auto process(float* input, float* output, int numSamples, int numChannels) -> void override {
        for(auto sample = 0; sample < numSamples; ++ sample){
            auto tempSample = datorro->output(input[sample * 2]);

            auto tempSample_1 = datorro->outputL(tempSample + (tempSample_2 * 0.5));
            auto tempSample_2 = datorro->outputR(tempSample + (tempSample_1 * 0.5));

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

    auto datorro_1 = Datorro(samplerate);
    myCallback.datorro = &datorro_1;

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
