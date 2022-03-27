#include <iostream>
#include <vector>
#include "juce_audio.h"
#include <random>
#include <thread>
#include "userInput.h"
#include "node.h"

std::string help = "Instructions:\n"
                   "- You are obligated to answer the following questions out loud\n"
                   "- Choose between options using the arrow keys\n"
                   "- Press the space bar at the beginning of your answer, "
                   "press the spacebar again at the end of your answer\n- "
                   "You have agreed to the requiered terms and conditions\n"
                   "\nWelcome to Human Diagnostics, please choose one of the "
                   "following options\n";
std::string initialQ = "0: recite your registration number\n"
                       "1: recite your personal information\n"
                       "2: recite your ssh-key\n";
std::string senseQ[3] = {"0: do you dream\n",
                          "1: do you feel\n",
                          "2: do you think\n"};
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

int questionSelect = 1;
//std::string allQuestions[3] = {initialQ, secondQ, thirdQ};
//std::string dreamsQ[3] = {dreamsQ1, dreamsQ2, dreamsQ3};
//std::string touchQ[3] = {touchQ1, touchQ2, touchQ3};
//std::string thoughtsQ[3] = {touchQ1, touchQ2, touchQ3};

//Node* dreamsNodes[3];
//Node* touchNodes[3];
//Node* thoughtsNodes[3];

void makeTrees(int questionSelect){
  //make treee for dreams
  if(questionSelect == 0){
    Node* dreams = dreams->makeNewNode(describeQ[0]);
    dreams->left = dreams->makeNewNode(dreamsQ1[0]);
    dreams->left->left = dreams->makeNewNode(dreamsQ2[0]);
    dreams->left->left->left = dreams->makeNewNode(dreamsQ3[0]);
    dreams->right = dreams->makeNewNode(dreamsQ1[1]);
    dreams->right->right = dreams->makeNewNode(dreamsQ2[1]);
    dreams->right->right->right = dreams->makeNewNode(dreamsQ3[1]);
    dreams->printPreorder(dreams);
  }
  //make tree for touch
  if(questionSelect == 1){
    Node* touch = touch->makeNewNode(describeQ[1]);
    touch->left = touch->makeNewNode(touchQ1[0]);
    touch->left->left = touch->makeNewNode(touchQ2[0]);
    touch->left->left->left = touch->makeNewNode(touchQ3[0]);
    touch->right = touch->makeNewNode(touchQ1[1]);
    touch->right->right = touch->makeNewNode(touchQ2[1]);
    touch->right->right->right = touch->makeNewNode(touchQ3[1]);
    touch->printPreorder(touch);
  }
  //make tree for thoughts
  if(questionSelect == 2){
    Node* toughts = toughts->makeNewNode(describeQ[2]);
    toughts->left = toughts->makeNewNode(thoughtQ1[0]);
    toughts->left->left = toughts->makeNewNode(thoughtQ2[0]);
    toughts->left->left->left = toughts->makeNewNode(thoughtQ3[0]);
    toughts->right = toughts->makeNewNode(thoughtQ1[1]);
    toughts->right->right = toughts->makeNewNode(thoughtQ2[1]);
    toughts->right->right->right = toughts->makeNewNode(thoughtQ3[1]);
    toughts->printPreorder(toughts);
  }
}



struct TestCallback : AudioCallback
{
    void process (const float** input, float** output, int numInputChannels, int numOutputChannels, int numSamples) override
    {
      for (int channel = 0; channel < numOutputChannels; ++channel){
        for (int sample = 0; sample < numSamples; ++sample){
          if(userInput->donePrinting == true) {
            questionSelect = std::cin.get();
            userInput->checkAnswer(questionSelect);
            std::cout<< "numAnsQues" << userInput->numAnswrdQues <<std::endl;
            //TODO: check if numeric, check in range of questions
          }else{
            //allQuestions[userInput->numAnswrdQues] lets program go to next
            //question after answer
//            userInput->separateLetter(allQuestions[userInput->numAnswrdQues],
//                                      sample, numSamples);

          }
        }
      }
    }
    UserInput* userInput;
};

int main(){
  makeTrees(2);
//  TestCallback callback;
//  AudioBackend audioBackend;
//
//  audioBackend.registerCallback (&callback);
//  audioBackend.openDefaultIODevice (1, 2);



  bool running = true;
  while (running)
  {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
//        audioBackend.closeDevice();
        break;
    }
  }
  return 0;
}