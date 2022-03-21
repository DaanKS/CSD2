#include "port_audio.h"
#include "datorro.h"
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
    float tempSample_1 = 0.0f;
    float tempSample_2 = 0.0f;
    float tempSample = 0.0f;

    auto prepareToPlay(int sampleRate, int numSamplesPerBlock) -> void override {

    }
    auto process(float* input, float* output, int numSamples, int numChannels) -> void override {
        for(auto sample = 0; sample < numSamples; ++ sample){
            tempSample = datorro->output(input[sample * 2]);

            //tempSample_1 = datorro->outputL(tempSample + (tempSample_2 * 0.3));
            //tempSample_2 = datorro->outputR(tempSample + (tempSample_1 * 0.3));

            output[sample * 2] = tempSample;//(tempSample_1 / 4.0) + input[sample * 2];
            output[sample * 2 + 1] = tempSample;//(tempSample_2 / 4.0) + input[sample * 2];
        }
    }
    auto releaseResources() -> void override {}

};

auto main() -> int {

    auto myCallback = MyCallback();
    auto portAudio = PortAudio(myCallback);

    auto samplerate = 44100.0f;

    auto datorro_1 = Comb(samplerate, 160, 1.0, 0.0);
    myCallback.datorro = &datorro_1;

  /*  auto modder_1 = ModAllPass(0.75, 1343, samplerate, 1.0, 12);
    //modder_1.setDelayTime(700);
    myCallback.mod_1 = &modder_1; */

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
