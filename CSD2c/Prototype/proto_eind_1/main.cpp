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
                //tempSample = waveshaper->output(kam->output(input[0][sample]));// + (tempSample * ysis->returnControlValue()));
                //ysis->takeAverage(tempSample);
                //std::cout << ysis->returnControlValue() << std::endl;
                /*
                output[0][sample] = ap1->output(tempSample);
                output[1][sample] = ap2->output(tempSample);
                */

                float tempSample_2 = datorro->output(input[0][sample]);
                output[0][sample] = datorro->outputL(tempSample_2);
                output[1][sample] = datorro->outputR(tempSample_2);



            }
    }
    Comb* kam;
    /*Allpass* ap1;
    Allpass* ap2; */
    Analysis* ysis;

    Datorro* datorro;
    DualBiquad* dualBiquad;
    Waveshaper* waveshaper;
    float tempSample;

};


int main()
{
    TestCallback callback;
    AudioBackend audioBackend;

    double samplerate = 44100;

    audioBackend.registerCallback (&callback);
    audioBackend.openDefaultIODevice (2, 2);

    auto torro = Datorro(samplerate);
    callback.datorro = &torro;
    auto quad = DualBiquad(samplerate);
    callback.dualBiquad = &quad;
    auto shape = Waveshaper(samplerate);
    shape.generateSawTable(20.0);
    callback.waveshaper = &shape;

    auto anal = Analysis(10);
    callback.ysis = &anal;
/*
    auto ap__1 = Allpass(0.7, 400, samplerate);
    callback.ap1 = &ap__1;
    auto ap__2 = Allpass(0.7, 400, samplerate);
    callback.ap2 = &ap__2; */
    auto mok = Comb(samplerate, 10, 1.0, 0.0, samplerate);
    callback.kam = &mok;

    auto running = true;
    auto tempValue = 0.0f;

    while(running){
        switch (std::cin.get()) {
            case 'q':
                running = false;
                break;
            case 'w':
                std::cout << "new value for drywet: ";
                std::cin >> tempValue;
                torro.setDryWet(tempValue);

                /*
                std::cout << "set new value for delayTimeAP1: ";
                std::cin >> tempValue;
                ap__1.setDelayTime(tempValue);
                std::cout << "set new value for delayTimeAP2: ";
                std::cin >> tempValue;
                ap__2.setDelayTime(tempValue);
                 */
                break;
            case 'e':

                break;
            }

    }

    audioBackend.closeDevice();

    return 0;
}
