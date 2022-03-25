
#include <iostream>
#include "juce_audio.h"
#include <random>
#include <thread>
#include "hypertan.h"

struct TestCallback : AudioCallback
{
    void process (const float** input, float** output, int numInputChannels, int numOutputChannels, int numSamples) override
    {
        for (int channel = 0; channel < numOutputChannels; ++channel)
        {
            for (int sample = 0; sample < numSamples; ++sample)
            {
                output[channel][sample] = tAnh->output(input[channel][sample]);
            }
        }
    }


    Hypertan* tAnh;
};


int main()
{
    TestCallback callback;
    AudioBackend audioBackend;

    auto hyperTan = Hypertan();
    callback.tAnh = &hyperTan;

    audioBackend.registerCallback (&callback);
    audioBackend.openDefaultIODevice (0, 2);

    std::cin.get();

    audioBackend.closeDevice();

    return 0;
}
