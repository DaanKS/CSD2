//
// Created by Mila Louise Maria Philipsen on 24/03/2022.
//
#include <iostream>
#include <cstring>
#include <vector>
#include "node.h"
#include <unistd.h>
#ifndef MAIN_CPP_USERINPUT_H
#define MAIN_CPP_USERINPUT_H


class UserInput {
public:
  UserInput();
  ~UserInput();
//  char printToConsole(std::string, int sample);
    void separateLetter(std::string sentence);
    void checkAnswer(int questionSelect);

    bool printedALetter = true;
    int numAnswrdQues = 0;
    std::vector<Node*> nodes;

protected:
private:
    int intervalsPassed = 0;
    int letterIndex = 0;
};


#endif //MAIN_CPP_USERINPUT_H
