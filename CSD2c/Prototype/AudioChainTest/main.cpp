#include <iostream>
#include <juce_audio.h>
#include "analysis.h"
#include "datorro.h"
#include "dualbiquad.h"
#include "waveshaper.h"


struct TestCallback : AudioCallback
{
    bool doneRecording = false;
    void process (const float** input, float** output, int numInputChannels, int numOutputChannels, int numSamples) override
    {

            for (int sample = 0; sample < numSamples; ++sample){
               // tempSample = waveshaper->output(kam->output(input[0][sample]));// + (tempSample * ysis->returnControlValue()));
                //ysis->takeAverage(tempSample);
                //std::cout << ysis->returnControlValue() << std::endl;
                /*
                output[0][sample] = ap1->output(tempSample);
                output[1][sample] = ap2->output(tempSample);
                */

//                std::cout << "Greta: " << std::endl;
             //if(doneRecording == true) {
                 //float jemoeder = envelope->envAtSamp(0);
                // datorro.setDryWet();
                tempSample = waveshaper->output(kam->output(input[0][sample]));// + (tempSample * ysis->returnControlValue()));

                float tempSample_2 = datorro.output(tempSample);
                 output[0][sample] = datorro.outputL(tempSample_2);
                 output[1][sample] = datorro.outputR(tempSample_2);







            }
    }
    Comb* kam;
    /*Allpass* ap1;
    Allpass* ap2; */
    Analysis* ysis;

    Datorro datorro = Datorro(44100);
    DualBiquad* dualBiquad;
    Waveshaper* waveshaper;
    float tempSample;
    int recordedSamps = 0;
    int sempleKount = 0;

};
int questionIndex = 0;
void askQuestion(int position){
    std::cout<< questions[position] <<std::endl;
}
bool boolswitcher(bool recordSwitch){
    if(recordSwitch){
        return false;
    }else{
        return true;
    }
}

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
    auto pos = 0;

    askQuestion(pos);
    while(running){
        switch (std::cin.get()) {
            case 'q':
                running = false;
                break;
            case 'w':
                std::cout << "new value for drywet: ";
                std::cin >> tempValue;
                //torro.setDryWet(tempValue);

                /*
                std::cout << "set new value for delayTimeAP1: ";
                std::cin >> tempValue;
                ap__1.setDelayTime(tempValue);
                std::cout << "set new value for delayTimeAP2: ";
                std::cin >> tempValue;
                ap__2.setDelayTime(tempValue);
                 */
                break;
            case ' ':
                //start recording
                recordStartStop = boolswitcher(recordStartStop);
                if(recordStartStop) {
                    sampleCount = 1;
                    pos++;
                    askQuestion(pos);
                }

                break;
            }

    }

    audioBackend.closeDevice();

    return 0;
}
