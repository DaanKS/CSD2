#include <iostream>

#pragma once

typedef unsigned int uint;

//y(n) = x(n-D) + (fb*y)

class CircBuffer{
public:
  CircBuffer(int size, int numSamplesDelay);
  ~CircBuffer();

  void initialize();

  void writeToBuffer(double inputSample);
  double readFromBuffer();

  int wrapHeader(int head);
  int distanceReadWrite();

  void incrementPointers();

protected:
  int readIndex = 0;
  int writeIndex = 0;

  int size, numSamplesDelay;
  int sampleRate;

  double* buffertje;

};
