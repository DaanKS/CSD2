//
// Created by Mila Louise Maria Philipsen on 24/03/2022.
//
#include <iostream>
#include <cstring>
#include <vector>
#include "node.h"

#ifndef MAIN_CPP_USERINPUT_H
#define MAIN_CPP_USERINPUT_H


class UserInput {
public:
  UserInput();
  ~UserInput();
//  char printToConsole(std::string, int sample);
    void separateLetter(std::string sentence, int sample, int nframes);
    void checkAnswer(int questionSelect);

    bool donePrinting = false; //false = printing, true = done
    int numAnswrdQues = 0;
    std::vector<Node*> nodes;

protected:
private:
    int intervalsPassed = 0;
    int letterIndex = 0;
};


#endif //MAIN_CPP_USERINPUT_H
