#include <iostream>
#include <juce_audio.h>
#include "analysis.h"
#include "datorro.h"
#include "dualbiquad.h"
#include "waveshaper.h"


struct TestCallback : AudioCallback
{
    void process (const float** input, float** output, int numInputChannels, int numOutputChannels, int numSamples) override
    {
            for (int sample = 0; sample < numSamples; ++sample){

                float tempSample = input[0][sample] + input[1][sample];

                float tempSample_1 = (waveshaper1->output(dualBiquad->outputHP(tempSample)));
                float tempSample_2 = (waveshaper2->output(dualBiquad->outputLP(tempSample)));
                float tempSample_3 = datorro.output(tempSample_1 + tempSample_2);
                 output[0][sample] = ap1->output(datorro.outputL(tempSample_3));
                 output[1][sample] = ap2->output(datorro.outputR(tempSample_3));

            }
    }

    Allpass* ap1;
    Allpass* ap2;
    Datorro datorro = Datorro(44100);
    DualBiquad* dualBiquad;
    Waveshaper* waveshaper1;
    Waveshaper* waveshaper2;

};

int main()
{
    TestCallback callback;
    AudioBackend audioBackend;

    double samplerate = 44100;

    audioBackend.registerCallback (&callback);
    audioBackend.openDefaultIODevice (2, 2);

    /*auto torro = Datorro(samplerate);
    callback.datorro = &torro; */
    auto quad = DualBiquad(samplerate);
    quad.setDifference(-100);
    quad.makeFilters();
    callback.dualBiquad = &quad;

    auto shape = Waveshaper(samplerate);
    shape.generateSawTable(80.0);
    callback.waveshaper1 = &shape;
    auto shape_2 = Waveshaper(samplerate);
    shape_2.generateWaveTable();
    callback.waveshaper2 = &shape_2;

    auto anal = Analysis(10);
    callback.ysis = &anal;

    auto ap__1 = Allpass(0.7, 400, samplerate);
    callback.ap1 = &ap__1;
    auto ap__2 = Allpass(0.7, 400, samplerate);
    callback.ap2 = &ap__2;
    auto mok = Comb(samplerate, 100, 1.0, 0.0, samplerate);
    callback.kam = &mok;

    auto running = true;
    auto tempValue = 0.0f;

    while(running){
        switch (std::cin.get()) {
            case 'q':
                running = false;
                break;
            case 'w':
                std::cout << "set new value for delayTimeAP1: ";
                std::cin >> tempValue;
                ap__1.setDelayTime(tempValue);
                std::cout << "set new value for delayTimeAP2: ";
                std::cin >> tempValue;
                ap__2.setDelayTime(tempValue);
                break;
            case 'e':
                std::cout << "new value for cutoff: ";
                std::cin >> tempValue;
                quad.setCutoffFrequency(tempValue);
                quad.makeFilters();

            case ' ':
                break;
            }

    }

    audioBackend.closeDevice();

    return 0;
}
