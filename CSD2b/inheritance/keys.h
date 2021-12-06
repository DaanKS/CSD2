#include "instrument.h"

#pragma once

class Keys : public Instrument{
public:
  Keys();
  ~Keys();

  void makeSound() override;

  void setPolyphony(int numVoices);
  int getPolyphony();

protected:
  int numVoices;
};
