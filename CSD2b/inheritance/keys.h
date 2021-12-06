#include "instrument.h"

#pragma once

class Keys : public Instrument{
public:
  Keys(int numKeys);
  ~Keys();

  void makeSound() override;

  int getNumKeys();

  void setPolyphony(int numVoices);
  int getPolyphony();

protected:
  int numVoices;
  int numKeys;
};
