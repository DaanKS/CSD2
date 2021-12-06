#include "instrument.h"
#include <cstring>

#pragma once

class Strings : public Instrument{
public:
  Strings(std::string tuning, int numStrings);
  ~Strings();

  void makeSound() override;

  int getNumStrings();

  void setTuning(std::string tuning);
  std::string getTuning();

protected:
  int numStrings;
  std::string tuning;
};
