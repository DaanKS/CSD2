#include <iostream>
#include <juce_audio.h>
#include "datorro.h"
#include "generator.h"
#include "dualbiquad.h"
#include "waveshaper.h"
#define BUFFERLENGTH 410000
#define NUMBERENV 6

std::string questions[10] = {"Instructions:\n"
                             "- You are obligated to answer the following questions out loud\n"
                             "- Press the space bar at the beginning of your answer, "
                             "press the space bar again at the end of your answer\n- "
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
bool ampAtSamp = false;
bool envFirstTime = false;
int timesSwitched = 0;
float datorroDryWet = 0.0;
float ap1DelayTime = 0.0;
float ap2DelayTime = 0.0;
float biquadCutOff = 0.0;
float waveshape1DryWwt = 0.0;
float waveshape2DryWet = 0.0;

Generator* envelope;


int sampleCount = 0;

struct TestCallback : AudioCallback
{
    bool makeEnvelope = false;
    void process (const float** input, float** output, int numInputChannels, int numOutputChannels, int numSamples) override
    {

            for (int sample = 0; sample < numSamples; ++sample) {
              if (recordStartStop) {
                if (sampleCount < BUFFERLENGTH) {
                  inbuffer[sampleCount] = input[0][sample];
                  //  std::cout << "Mila: " << sampleCount << std::endl;
                  sampleCount++;
                  if (sampleCount >= BUFFERLENGTH - 1) { sampleCount -= BUFFERLENGTH - 1; }
                }
              }
                tempSample = inbuffer[sempleKount]; //+ input[0][sample];
                sempleKount++;
                if (sempleKount >= sampleCount) { sempleKount = 0; }
                float tempSample_1 = (waveshaper1.output(dualBiquad.outputHP(tempSample)));
                float tempSample_2 = (waveshaper2.output(dualBiquad.outputLP(tempSample)));
                float tempSample_3 = datorro.output(tempSample_1 + tempSample_2);
                output[0][sample] = ap1.output(datorro.outputL(tempSample_3));
                output[1][sample] = ap2.output(datorro.outputR(tempSample_3));
              if(envFirstTime){
                  datorroDryWet = envelope->envAtSamp(0);
//                  ap1DelayTime = envelope->envAtSamp(1);
//                  ap2DelayTime = envelope->envAtSamp(2);
//                  biquadCutOff = envelope->envAtSamp(3);
                  waveshape1DryWwt = envelope->envAtSamp(4);
                  waveshape2DryWet = envelope->envAtSamp(5);

                }

                datorro.setDryWet(datorroDryWet); // -1 tot 1
                ap1.setDelayTime(ap1DelayTime); // 1 tot 800
                ap2.setDelayTime(ap2DelayTime); // 1 tot 800 (wel anders dan ap1)

                dualBiquad.setCutoffFrequency(biquadCutOff); // 400 tot 1000

                waveshaper1.setDryWet(waveshape1DryWwt); // -1 tot 1
                waveshaper2.setDryWet(waveshape2DryWet); // -1 tot 1

            }
    }
    double samplerate = 44100;
    Allpass ap1 = Allpass(0.7, 400, samplerate);
    Allpass ap2 = Allpass(0.7, 400, 44100);
    Datorro datorro = Datorro(44100);
    DualBiquad dualBiquad = DualBiquad(44100);
    Waveshaper waveshaper1 = Waveshaper(44100, 80);
    Waveshaper waveshaper2 = Waveshaper(44100);
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
    audioBackend.openDefaultIODevice (1, 2);

    auto running = true;
    auto tempValue = 0.0f;
    auto pos = 0;


  askQuestion(pos);
    while(running){
        if(timesSwitched > 1){
          std::cout<< "created an env" <<std::endl;
          envelope = new Generator(inbuffer, sampleCount, NUMBERENV);
          envFirstTime = true;
          timesSwitched = 0;
        }
        switch (std::cin.get()) {
            case 'q':
                running = false;
                break;
            case 'w':

                break;
            case ' ':
                //start recording
                recordStartStop = boolswitcher(recordStartStop);
                timesSwitched++;
                std::cout<< "timesSwitched" << timesSwitched <<std::endl;
                if(recordStartStop) {
//                    if(pos >= 10){
////                      questions[]
//                    }
                    pos++;
                    askQuestion(pos);
                }

                break;
            }

    }

    audioBackend.closeDevice();

    return 0;
}
