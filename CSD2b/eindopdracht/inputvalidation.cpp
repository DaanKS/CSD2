#include "inputvalidation.h"

InputValidation::InputValidation(){}
InputValidation::~InputValidation(){}
//retrieveValueInRange is a method written by Ciska Vriezenga.
// I tried writing my own but it just didn't work. as of yet, unsure why.
//Code is altered -- slightly

float InputValidation::retrieveValueInRange(float min, float max) {
  std::string input;
  float value = 0;
  bool notInRange = true;

  while(notInRange) {
    // first capture input in input string
    std::cin >> input;
    // validate if input string can be transformed into a float
    try {
      value = std::stof(input);
      // validate range
      if(value >= min && value <= max) {
        notInRange = false;
      } else {
        // value not in range
        std::cout << "Incorrect range, please try again." << std::endl;
      }
    } catch (const std::exception& e) {
      // no float as input
      std::cout << tonyHawk[tonyIndex] << std::endl;
      tonyIndex++;
      if(tonyIndex > 4) tonyIndex = 0;
    }
  }

  return value;
}
