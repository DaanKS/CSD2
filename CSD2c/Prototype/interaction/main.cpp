#include <iostream>
#include <vector>
#include "juce_audio.h"
#include <random>
#include <thread>
#include "userInput.h"
#include "node.h"

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

//make a tree depending on chosen path
Node* node;


void makeTrees(int questionSelect){
  //make tree for dreams
  if(questionSelect == 0){
    node = node->makeNewNode(describeQ[0]);
    node->left = node->makeNewNode(dreamsQ1[0]);
    node->left->left = node->makeNewNode(dreamsQ2[0]);
    node->left->left->left = node->makeNewNode(dreamsQ3[0]);
    node->right = node->makeNewNode(dreamsQ1[1]);
    node->right->right = node->makeNewNode(dreamsQ2[1]);
    node->right->right->right = node->makeNewNode(dreamsQ3[1]);
//    node->printPreorder(node);
  }
  //make tree for touch
  if(questionSelect == 1){
    node = node->makeNewNode(describeQ[1]);
    node->left = node->makeNewNode(touchQ1[0]);
    node->left->left = node->makeNewNode(touchQ2[0]);
    node->left->left->left = node->makeNewNode(touchQ3[0]);
    node->right = node->makeNewNode(touchQ1[1]);
    node->right->right = node->makeNewNode(touchQ2[1]);
    node->right->right->right = node->makeNewNode(touchQ3[1]);
//    node->printPreorder(node);
  }
  //make tree for thoughts
  if(questionSelect == 2){
    node = node->makeNewNode(describeQ[2]);
    node->left = node->makeNewNode(thoughtQ1[0]);
    node->left->left = node->makeNewNode(thoughtQ2[0]);
    node->left->left->left = node->makeNewNode(thoughtQ3[0]);
    node->right = node->makeNewNode(thoughtQ1[1]);
    node->right->right = node->makeNewNode(thoughtQ2[1]);
    node->right->right->right = node->makeNewNode(thoughtQ3[1]);
//    node->printPreorder(node);
  }
}

void turnLeftRight(int questionSelect){
  //0 = left
  //1 = right
  if(questionSelect == 0){
    node
  }else{

  }
}

/*
 * instructions
 *question flow:
 * 3 identification questions
 * 3 sense questions (build trees depending on choice)
 * 2 questions
 * 2 questions
 * 2 questions
 * result
 */


UserInput userInput;
int questionSelect;
bool initialQSwitch = true;
bool treeChoice  = false;

/*
 * Flow of userInput
 * wait for initial questions to print -> get a user login choice
 * wait for the sense questions print -> get a choice -> make a tree -> check the question at root
 * wait for the first question to print -> get a choice -> check the question at root
 */

struct TestCallback : AudioCallback
{
    void process (const float** input, float** output, int numInputChannels, int numOutputChannels, int numSamples) override
    {
      for (int channel = 0; channel < numOutputChannels; ++channel){
        for (int sample = 0; sample < numSamples; ++sample){
          //wait for sperateletter() to finish
          //then get an input
          if(userInput.donePrinting == true) {
            if(initialQSwitch == true){
              std::cin>> questionSelect;
              userInput.checkAnswer(questionSelect);
              treeChoice = true;
              initialQSwitch = false;
            }else{
              if(treeChoice == true){
                std::cin>> questionSelect;
                userInput.checkAnswer(questionSelect);
                makeTrees(questionSelect);
                treeChoice = false;
              }else{
                std::cin>> questionSelect;
                userInput.checkAnswer(questionSelect);
              }
            }
            //TODO: check if numeric, check in range of questions
          }else{
            if(initialQSwitch == true) {
              //print intialquestions
              userInput.separateLetter(initialQ, sample, numSamples);
            }
            if(treeChoice == true){
              userInput.separateLetter(senseQ, sample, numSamples);
            }else{
              turnLeftRight(questionSelect);
//              userInput.separateLetter()
            }
          }
        }
      }
    }
};



int main(){
//  makeTrees(0);
  TestCallback callback;
  AudioBackend audioBackend;

  audioBackend.registerCallback (&callback);
  audioBackend.openDefaultIODevice (1, 2);



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