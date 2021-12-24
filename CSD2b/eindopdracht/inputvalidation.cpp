#include "inputvalidation.h"

InputValidation::InputValidation(){}
InputValidation::~InputValidation(){}

int InputValidation::validateInt(int minInt, int maxInt, int inputInt){
  notInRange = true;
  while(notInRange){
  try{
    if(inputInt >= minInt && inputInt <= maxInt){
      notInRange = false;
    }
  }
  catch(const std::exception& e){
    std::cout << "Invalid Input. Try an INTEGER between " << minInt << " and "
    << maxInt << std::endl;
    std::cout << "One more mistake and I'm going to install a virus on the bootloader \n";
    }
  }
  return inputInt;
}

double InputValidation::validateDouble(double minDouble, double maxDouble, double inputDouble){
  notInRange = true;
  while(notInRange){
  try{
    if(inputDouble >= minDouble && inputDouble <= maxDouble){
      notInRange = false;
    }
  }
  catch(const std::exception& e){
    std::cout << "Invalid Input. Try an INTEGER between " << minInt << " and "
    << maxInt << std::endl;
    std::cout << "One more mistake and I'm going to install a virus on the bootloader \n";
    }
  }
  return inputDouble;
}
}
