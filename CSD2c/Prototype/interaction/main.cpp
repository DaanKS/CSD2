#include <iostream>
#include "juce_audio.h"
#include <random>
#include <thread>
#include "userInput.h"

std::string help = "Instructions:\n- You are obligated to answer the following questions out loud\n- Choose between options using the arrow keys\n- Press the space bar at the beginning of your answer, press the spacebar again at the end of your answer\n- You have agreed to the requiered terms and conditions\n\nWelcome to Human Diagnostics, please choose one of the following options";
std::string initialQ [3] = {"recite your registration number", "recite your personal information", "recite your ssh-key"};
std::string secondQ [3] = {"do you dream", "do you feel", "do you think"};

struct TestCallback : AudioCallback
{
    void process (const float** input, float** output, int numInputChannels, int numOutputChannels, int numSamples) override
    {
      for (int channel = 0; channel < numOutputChannels; ++channel){
        for (int sample = 0; sample < numSamples; ++sample){
          userInput->separateLetter(help, sample, numSamples);
        }
      }
    }

    //std::vector<Hypertan> hypertans;
    UserInput* userInput;
};

int main(){
  std::cout<< "hoi" <<std::endl;

  TestCallback callback;
  AudioBackend audioBackend;

  audioBackend.registerCallback (&callback);
  audioBackend.openDefaultIODevice (1, 2);

  //keep the program running and listen for user input, q = quit
  std::cout << "\n\nPress 'q' when you want to quit the program.\n";
  bool running = true;
  while (running)
  {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
        audioBackend.closeDevice();
        break;
    }
  }
  return 0;
}