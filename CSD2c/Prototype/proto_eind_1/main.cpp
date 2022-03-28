#include <iostream>
#include <juce_audio.h>
#include "analysis.h"
#include "datorro.h"
#include "generator.h"
#include "dualbiquad.h"
#include "waveshaper.h"
#define BUFFERLENGTH 410000
#define NUMBERENV 5

std::string questions[10] = {"Instructions:\n"
                             "- You are obligated to answer the following questions out loud\n"
                             "- Choose between options using the number keys, then enter\n"
                             "- Press the space bar at the beginning of your answer, "
                             "press the spacebar again at the end of your answer\n- "
                             "You have agreed to the requiered terms and conditions\n"
                             "\nWelcome to Human Diagnostics, please choose one of the following login options:\n"
                             "\n0: recite your registration number\n"
                             "1: recite your personal information\n"
                             "2: recite your ssh-key\n",
                             "describe your dreams\n",
                             "describe what touch feels like\n",
                             "when do you feel most connected\n",
                             "describe your thoughts\n",
                             "do you keep them to yourself\n",
                             "how do you compare yourself to others\n",
                             "do you long for touch\n",
                             "describe change\n",
                             "have you fulfilled any goals lately\n"
                             };

float inbuffer[BUFFERLENGTH];
bool recordStartStop = false;
bool createEnv = false;

int sampleCount = 0;

struct TestCallback : AudioCallback
{
    bool makeEnvelope = false;
    void process (const float** input, float** output, int numInputChannels, int numOutputChannels, int numSamples) override
    {

            for (int sample = 0; sample < numSamples; ++sample) {
              // tempSample = waveshaper->output(kam->output(input[0][sample]));// + (tempSample * ysis->returnControlValue()));
              //ysis->takeAverage(tempSample);
              //std::cout << ysis->returnControlValue() << std::endl;
              /*
              output[0][sample] = ap1->output(tempSample);
              output[1][sample] = ap2->output(tempSample);
              */
              if (recordStartStop) {
                if (sampleCount < BUFFERLENGTH) {
                  inbuffer[sampleCount] = input[0][sample];
                  //  std::cout << "Mila: " << sampleCount << std::endl;
                  sampleCount++;
                  if (sampleCount >= BUFFERLENGTH - 1) { sampleCount -= BUFFERLENGTH - 1; }
                }
              }else{
                if(createEnv){
                  //if the recoring is done, create an envelope
                  std::cout<< "we zijn hier geraakt" <<std::endl;
                  envelope = new Generator(inbuffer, sampleCount, NUMBERENV);
                  createEnv = false;
                }
              }

                  envelope->envAtSamp(0);
                          tempSample = inbuffer[sempleKount] + input[1][sample];
                sempleKount++;
                if (sempleKount >= sampleCount) { sempleKount = 0; }

                float tempSample_1 = (waveshaper1.output(dualBiquad.outputHP(tempSample)));
                float tempSample_2 = (waveshaper2.output(dualBiquad.outputLP(tempSample)));
                float tempSample_3 = datorro.output(tempSample_1 + tempSample_2);
                output[0][sample] = ap1.output(datorro.outputL(tempSample_3));
                output[1][sample] = ap2.output(datorro.outputR(tempSample_3));

                datorro.setDryWet(0.0); // -1 tot 1
                ap1.setDelayTime(0.0); // 1 tot 800
                ap2.setDelayTime(0.0); // 1 tot 800 (wel anders dan ap1)

                dualBiquad.setCutoffFrequency(0.0); // 400 tot 1000

                waveshaper1.setDryWet(0.0); // -1 tot 1
                waveshaper2.setDryWet(0.0); // -1 tot 1
//
//            }







            }
    }
    Comb* kam;
    /*Allpass* ap1;
    Allpass* ap2; */
    Analysis* ysis;

    Datorro datorro = Datorro(44100);
    DualBiquad* dualBiquad;
    Waveshaper* waveshaper;
    Generator* envelope;
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
                    createEnv = true;
                }

                break;
            }

    }

    audioBackend.closeDevice();

    return 0;
}
