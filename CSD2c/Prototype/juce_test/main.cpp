
#include <iostream>
#include "juce_audio.h"
#include <random>
#include <thread>
#include "hypertan.h"
#include <vector>

struct TestCallback : AudioCallback
{
    void process (const float** input, float** output, int numInputChannels, int numOutputChannels, int numSamples) override
    {
        for (int channel = 0; channel < numOutputChannels; ++channel){
            for (int sample = 0; sample < numSamples; ++sample){
                output[channel][sample] = hypertans->output(input[0][sample]);
            }
        }
    }

    //std::vector<Hypertan> hypertans;
    Hypertan* hypertans;
};


int main()
{
    TestCallback callback;
    AudioBackend audioBackend;


    audioBackend.registerCallback (&callback);
    audioBackend.openDefaultIODevice (1, 2);

    std::cin.get();

    audioBackend.closeDevice();

    return 0;
}
