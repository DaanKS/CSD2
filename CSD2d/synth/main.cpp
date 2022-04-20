#include <iostream>
#include <juce_audio.h>
#include "subsynth.h"

struct TestCallback : AudioCallback
{
    void process (const float** input, float** output, int numInputChannels, int numOutputChannels, int numSamples) override
    {
        for(int channel = 0; channel < numOutputChannels; ++channel) {
            for (int sample = 0; sample < numSamples; ++sample) {
                output[channel][sample] = synth[channel]->output();
                synth[channel]->updatePitches();
            }
        }
    }
    Subsynth* synth[2];
};

auto main() -> int{

    TestCallback callback;
    AudioBackend audioBackend;

    double samplerate = 44100;

    auto subby = Subsynth(samplerate);
    for(auto i = 0; i < 2; ++i)
        callback.synth[i] = &subby;

    subby.setPitch(25);


    audioBackend.registerCallback (&callback);
    audioBackend.openDefaultIODevice (2, 2);


    std::cin.get();


    audioBackend.closeDevice();

    return 0;
}