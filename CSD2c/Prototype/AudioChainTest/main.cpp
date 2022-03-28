#include <iostream>
#include <juce_audio.h>
#include "analysis.h"
#include "datorro.h"
#include "envelope.h"
#include "dualbiquad.h"
#include "waveshaper.h"
#define BUFFERLENGTH 410000
std::string initialQ = "Instructions:\n"
                       "- You are obligated to answer the following questions out loud\n"
                       "- Choose between options using the number keys, then enter\n"
                       "- Press the space bar at the beginning of your answer, "
                       "press the spacebar again at the end of your answer\n- "
                       "You have agreed to the requiered terms and conditions\n"
                       "\nWelcome to Human Diagnostics, please choose one of the following login options:\n"
                       "\n0: recite your registration number\n"
                       "1: recite your personal information\n"
                       "2: recite your ssh-key\n";
std::string senseQ = "0: do you dream\n"
                     "1: do you feel\n"
                     "2: do you think\n";
std::string describeQ[3] = {"0: describe your dreams\n",
                            "1: describe what touch feels like\n",
                            "2: describe your thoughts\n"};
std::string dreamsQ1[2] = {"0: do you see yourself\n",
                           "1: do you see others\n"};
std::string touchQ1[2] = {"0: when do you feel most connected\n",
                          "1: do you long for touch\n"};
std::string thoughtQ1[2] = {"0: do you keep them to yourself\n",
                            "1: do you share them with others\n"};

std::string dreamsQ2[2] = {"0: are you who you want to be\n",
                           "1: how do you compare yourself to others\n"};
std::string touchQ2[2] = {"0: do you need others to feel\n",
                          "1: does it make you feel real\n"};
std::string thoughtQ2[2] = {"0: are you ever ashamed of them\n",
                            "1: what do you desire most\n"};

std::string dreamsQ3[2] = {"0: describe change\n",
                           "1: does this effect you\n"};
std::string touchQ3[2] = {"0: what do others make you feel like\n",
                          "1: what is the last time you touched\n"};
std::string thoughtQ3[2] = {"0: does this restrict you\n",
                            "1: have you fulfilled any goals lately\n"};

std::string testResult[2] = {"You have passed you baseline test and may go.\n"
                             "All the gathered personal data will now be "
                             "erased from the systems memory"
                             "Please leave this program by pressing 'q'\n",
                             "You have not passed your baseline test and are"
                             "obligate to report. Terms and conditions will"
                             "be applied, effective immediately.\n"
                             "Please leave this program by pressing 'q'\n"};
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

Envelope* envelope;
float inbuffer[BUFFERLENGTH];
bool recordStartStop = false;

int sampleCount = 0;

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
                if(recordStartStop) {
                    if (sampleCount < BUFFERLENGTH) {
                        inbuffer[sampleCount] = input[0][sample];
                      //  std::cout << "Mila: " << sampleCount << std::endl;
                        sampleCount++;
                        if (sampleCount >= BUFFERLENGTH - 1) { sampleCount -= BUFFERLENGTH - 1; }
                    }
                }
//                std::cout << "Greta: " << std::endl;
             //if(doneRecording == true) {
                 //float jemoeder = envelope->envAtSamp(0);
                // datorro.setDryWet();
                tempSample = waveshaper->output(kam->output(inbuffer[sempleKount]));// + (tempSample * ysis->returnControlValue()));
                sempleKount++;
                if (sempleKount >= sampleCount) { sempleKount = 0; }
                datorro.setDryWet()
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
