#include "modDelay.h"
#include "port_audio.h"

struct MyCallback : AudioIODeviceCallback {

    ModDelay* korus_L;
    ModDelay* korus_R;

    void prepareToPlay(int sampleRate, int numSamplesPerBlock) override {
        korus_L = new ModDelay(sampleRate);
        korus_R = new ModDelay(sampleRate);
        korus_L->setRate(0.1);
        korus_R->setRate(0.15);
    }
    void process(float* input, float* output, int numSamples, int numChannels) override {
        for(int sample = 0; sample < numSamples; ++ sample){
            output[sample * 2] = korus_L->output(input[sample * 2 + 1]);
            output[sample * 2 + 1] = korus_R->output(input[sample * 2 + 1]);
        }
    }
    void releaseResources() override {
        delete korus_L;
        korus_L = nullptr;
        delete korus_R;
        korus_R = nullptr;
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

