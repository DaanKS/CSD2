
#include <iostream>
#include <juce_audio.h>
#include <squarelaw.h>
#include "tremolo.h"


struct TestCallback : AudioCallback
{
    void process (const float** input, float** output, int numInputChannels, int numOutputChannels, int numSamples) override
    {
        for (int channel = 0; channel < numOutputChannels; ++channel){
            for (int sample = 0; sample < numSamples; ++sample){
                output[channel][sample] = tremolo->output(input[0][sample]);
            }
        }
    }

    //std::vector<Hypertan> hypertans;
    Tremolo* tremolo;
};


int main()
{
    TestCallback callback;
    AudioBackend audioBackend;

    auto trem = Tremolo(44100);
    trem.setRate(1.0);
    callback.tremolo = &trem;


    audioBackend.registerCallback (&callback);
    audioBackend.openDefaultIODevice (1, 2);

    std::cin.get();

    audioBackend.closeDevice();

    return 0;
}
