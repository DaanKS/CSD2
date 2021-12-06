#include "instrument.h"

#pragma once

class Keys : public Instrument{
public:
  Keys();
  ~Key();

  void makeSound() override;

  void setPolyphony(int numVoices);
  int getPolyphony();

protected:
  int numVoices;
};
