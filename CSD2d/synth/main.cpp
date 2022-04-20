#include <iostream>
#include <saw.h>
#include <juce_audio.h>


struct TestCallback : AudioCallback
{
    void process (const float** input, float** output, int numInputChannels, int numOutputChannels, int numSamples) override
    {
        for (int sample = 0; sample < numSamples; ++sample){
            overL.input(input[0][sample]);
            overR.input(input[0][sample]);

            for(auto i = 0; i < 4; ++i){
                overL.setOverSampledBuffer(shaperL->output(overL.getOverSampledBuffer(i)), i);
                overR.setOverSampledBuffer(shaperR->output(overR.getOverSampledBuffer(i)), i);
            }
            output[0][sample] = overL.getOutputBuffer();
            output[1][sample] = overR.getOutputBuffer();
        }
    }

};

auto main() -> int{

    TestCallback callback;
    AudioBackend audioBackend;

    double samplerate = 44100;

    audioBackend.registerCallback (&callback);
    audioBackend.openDefaultIODevice (2, 2);


    std::cin.get();


    audioBackend.closeDevice();

    return 0;
}