#include <iostream>

#pragma once

class Instrument{
public:
  Instrument();
  ~Instrument();

  void makeSound();

protected:
  int pitchRange[2] = {0, 1};

};
