#include <iostream>

#pragma once

class InputValidation{
public:
  InputValidation();
  ~InputValidation();

  int validateInt(int minInt, int maxInt, int inputInt);
  double validateDouble(double minDouble, double maxDouble, double inputDouble);


protected:
  bool notInRange;
  int minInt, maxInt, inputInt;
  double minDouble, maxDouble, inputDouble;
};
