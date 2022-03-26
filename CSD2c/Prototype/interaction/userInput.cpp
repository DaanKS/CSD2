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
  if(sample >= nframes - 1) {
    intervalsPassed++;
//    std::cout << "intervalPassed" << intervalsPassed << std::endl;
//    std::cout << "letterIndex" << letterIndex <<std::endl;
    if (intervalsPassed >= 8) {
      if(letterIndex < sentence.length()) {
        std::cout << sentence[letterIndex] << std::flush;
        intervalsPassed = 0;
        letterIndex++;
      }
//      if(letterIndex == sentence.length()){
//        std::cout << "" <<std::endl;
//      }
    }
  }
}


//char UserInput::printToConsole(int questionNumber, int sample) {
//
//}
