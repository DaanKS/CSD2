//
// Created by Mila Louise Maria Philipsen on 24/03/2022.
//

#include "userInput.h"

UserInput::UserInput(){
  std::cout<< "constructor UserInput" <<std::endl;
}

UserInput::~UserInput() {
  std::cout<< "~destructor UserInput" <<std::endl;
}

void UserInput::chooseQuestion() {

}

void UserInput::separateLetter(std::string sentence, int sample, int nframes) {
  //sample = same as the amount of passed samples
  //when printing donePrinting is always false
  //makes the program wait untill all the letters are printed
  donePrinting = false;
  if(sample >= nframes - 1) {
    intervalsPassed++;
    if (intervalsPassed >= 1) {
      if(letterIndex < sentence.length()) {
        std::cout << sentence[letterIndex] << std::flush;
        intervalsPassed = 0;
        letterIndex++;
      }
      if(letterIndex >= sentence.length()){
        //when all the letters are reached retrun true so we can get an answer
        donePrinting = true;
        letterIndex = 0;
        std::cout << "doneprinting: " << donePrinting <<std::endl;
      }
    }
  }
}

void UserInput::checkAnswer(int questionSelect) {
  std::cout<< "questionSelect: " << questionSelect <<std::endl;
  //get audio Input make envelope
  numAnswrdQues++;
  //when we've got our answer
  //set to false so the seprateLetter function can get excecuted agian
  donePrinting = false;
}

void UserInput::makeNewNode(std::string data) {
//  Node* root = root->makeNewNode(questionSelect);
//  root->left = root->makeNewNode(0);
//  root->right = root->makeNewNode(1);
//
//  std::cout << "\nPreorder traversal of binary tree is \n";
//  root->printPreorder(root);
}