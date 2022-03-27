#include <iostream>
#include <juce_audio.h>
#include "datorro.h"
#include "dualbiquad.h"
#include "waveshaper.h"

struct TestCallback : AudioCallback
{
    void process (const float** input, float** output, int numInputChannels, int numOutputChannels, int numSamples) override
    {

            for (int sample = 0; sample < numSamples; ++sample){
                float tempSample = datorro->output(waveshaper->output(input[0][sample]));
                output[0][sample] = (datorro->outputL(tempSample));
                output[1][sample] = (datorro->outputR(tempSample));
            }
    }

    Datorro* datorro;
    DualBiquad* dualBiquad;
    Waveshaper* waveshaper;

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
    auto shape = Waveshaper(samplerate);
    shape.generateSawTable(20);
    callback.waveshaper = &shape;

    std::cin.get();

    audioBackend.closeDevice();

    return 0;
}
