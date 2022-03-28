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

void UserInput::separateLetter(std::string sentence) {

  std::cout << sentence[letterIndex] << std::flush;
  letterIndex++;
    if(letterIndex >= sentence.length()){
      //when all the letters are reached retrun true so we can get an answer
      printedALetter = false;
      letterIndex = 0;
    }
}

void UserInput::checkAnswer(int questionSelect) {
//  std::cout<< "questionSelect: " << questionSelect <<std::endl;
//  //get audio Input make envelope
//  numAnswrdQues++;
//  //when we've got our answer
//  //set to false so the seprateLetter function can get excecuted agian
//  donePrinting = false;
}