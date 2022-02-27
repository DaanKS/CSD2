#include "chorus.h"
#include "port_audio.h"

struct MyCallback : AudioIODeviceCallback {

    Korus* korus;

    void prepareToPlay(int sampleRate, int numSamplesPerBlock) override {
        korus = new Korus(sampleRate);
    }
    void process(float* input, float* output, int numSamples, int numChannels) override {
        for(int sample = 0; sample < numSamples; ++ sample){
            output[sample * 2] = korus->outputL(input[sample * 2]);
            output[sample * 2 + 1] = korus->outputR(input[sample * 2]);
        }
    }
    void releaseResources() override {
        delete korus;
        korus = nullptr;
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

