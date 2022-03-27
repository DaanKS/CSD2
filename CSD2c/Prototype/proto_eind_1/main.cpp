#include <iostream>
#include <juce_audio.h>
#include "datorro.h"
#include "dualbiquad.h"


struct TestCallback : AudioCallback
{
    void process (const float** input, float** output, int numInputChannels, int numOutputChannels, int numSamples) override
    {

            for (int sample = 0; sample < numSamples; ++sample){
                float tempSample = datorro->output(input[0][sample]);
                output[0][sample] = dualBiquad->outputLP(datorro->outputL(tempSample));
                output[1][sample] = dualBiquad->outputHP(datorro->outputR(tempSample));
            }
    }

    Datorro* datorro;
    DualBiquad* dualBiquad;

};


int main()
{
    TestCallback callback;
    AudioBackend audioBackend;

    double samplerate = 44100;

    audioBackend.registerCallback (&callback);
    audioBackend.openDefaultIODevice (1, 2);

    auto torro = Datorro(samplerate);
    callback.datorro = &torro;
    auto quad = DualBiquad(samplerate);
    callback.dualBiquad = &quad;

    std::cin.get();

    audioBackend.closeDevice();

    return 0;
}
