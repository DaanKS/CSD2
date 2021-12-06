#include "instrument.h"

#pragma once

class Blaas : public Instrument{
public:
  Blaas();
  ~Blaas();

  void makeSound() override;

  void setHornLength(float hornLength);
  float getHornLength();

protected:
  float hornLength;

};
