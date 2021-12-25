#include <iostream>

#pragma once

class InputValidation{
public:
  InputValidation();
  ~InputValidation();

  float retrieveValueInRange(float min, float max);

protected:
  float min, max;
  //In tony hawk proskater, you receive similar messages when you reach "illegal" locations
  int tonyIndex;
  std::string tonyHawk[5] = {"stay in school", "say no to drugs", "touch grass","when's the last time you showered?", "noooooooooooo"};
};
