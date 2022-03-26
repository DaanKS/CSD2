//
// Created by Mila Louise Maria Philipsen on 24/03/2022.
//
#include <iostream>
#include <cstring>

#ifndef MAIN_CPP_USERINPUT_H
#define MAIN_CPP_USERINPUT_H


class UserInput {
public:
  UserInput();
  ~UserInput();
//  char printToConsole(std::string, int sample);
    void separateLetter(std::string sentence, int sample, int nframes);
private:
//    int interval = 250;
    int intervalsPassed = 0;
    int letterIndex = 0;
    void chooseQuestion();
    //questions
    int numberQuestions = 3;

};


#endif //MAIN_CPP_USERINPUT_H
