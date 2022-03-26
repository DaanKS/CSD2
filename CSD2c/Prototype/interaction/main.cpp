#include <iostream>
#include <vector>
#include "juce_audio.h"
#include <random>
#include <thread>
#include "userInput.h"
#include "node.h"



//Utility function to create a new tree node

/* Given a binary tree, print its nodes in preorder*/


int questionSelect;
std::vector<int> nodes;
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
std::string secondQ = "0: do you dream\n1: do you feel\n2: do you think\n";
std::string thirdQ = "0: describe your dreams\n1: describe what touch feels like\n"
                     "2: describe your thoughts\n";

std::string allQuestions[3] = {initialQ, secondQ, thirdQ};

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
            userInput->separateLetter(allQuestions[userInput->numAnswrdQues],
                                      sample, numSamples);

          }
        }
      }
    }
    UserInput* userInput;
};

int main(){
  TestCallback callback;
  AudioBackend audioBackend;

  audioBackend.registerCallback (&callback);
  audioBackend.openDefaultIODevice (1, 2);

//  Node* root = root->makeNewNode(0);
//  root->left = root->makeNewNode(0);
//  root->right = root->makeNewNode(1);
//
//  std::cout << "\nPreorder traversal of binary tree is \n";
//  root->printPreorder(root);

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