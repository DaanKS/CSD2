#include "instrument.h"
#include <cstring>

#pragma once

class String : public Instrument{
public:
  String(std::string tuning, int numStrings);
  ~String();

  void makeSound() override;

  int getNumStrings();

  void setTuning(std::string tuning);
  std::string getTuning();

protected:
  int numStrings;
  std::string tuning;
}
