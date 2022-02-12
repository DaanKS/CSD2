#include <iostream>

#pragma once

class CircBuffer{
public:
  CircBuffer(int size, int numSamplesDelay);
  ~CircBuffer();

  void initialize();

  void writeToBuffer(double inputSample);
  double readFromBuffer();

  int distanceReadWrite();

protected:
  int wrapHeader(int head);

  int readIndex = 0;
  int writeIndex = 0;

  int size, numSamplesDelay;
  int sampleRate;

  double* buffer;

};
