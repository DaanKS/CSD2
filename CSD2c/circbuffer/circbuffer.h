//This code is intellectual property of Ciska Vriezenga.
//I altered some of the naamgeving for my own understanding.

#include <iostream>
#pragma once

typedef unsigned int uint;

class CircBuffer{
public:
  CircBuffer(); //we use an empty construtor so we can reserve the object before knowing the samplerate
  CircBuffer(uint size);
  ~CircBuffer();

  void initialize(uint size);
  void setDelayTimeSamps(uint delayTimeSamps);

  inline void writeToBuffer(float inputSample){buffer[writeIndex] = inputSample;}
  inline double readFromBuffer(){return buffer[readIndex];}

  inline void incrementHeaders(){
    incrementWriteIndex();
    incrementReadIndex();
  }

private:
  int wrapHeader(int head);

  int readIndex = 0;
  int writeIndex = 0;

  int size, numSamplesDelay;
  int sampleRate;

  double* buffertje;

};
