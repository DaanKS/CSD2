//This code is intellectual property of Ciska Vriezenga.
//I altered some of the naamgeving for my own understanding.

#include <iostream>
#pragma once

typedef unsigned int uint;

class CircBuffer{
public:
  CircBuffer(); //we use an empty constructor so we can reserve the object before knowing the samplerate
  CircBuffer(uint size);
  ~CircBuffer();

  void initialize(uint size);
  void setDelayTimeSamps(uint delayTimeSamps);

  inline float tick(float inputSample){writeToBuffer(inputSample);return readFromBuffer();}
  inline void writeToBuffer(float inputSample){buffer[(uint)writeIndex] = inputSample;}
  inline float readFromBuffer(){

      const float temp_High = buffer[(uint)(readIndex + 0.5)];
      const float temp_Low = buffer[(uint)readIndex];
      const float temp_input = (uint)(readIndex + 0.5) - readIndex;

      const float outputSample = linearMap(temp_input, temp_Low, temp_High);
      return outputSample;
  }

  inline void incrementIndeces(){
    incrementWriteIndex();
    incrementReadIndex();
  }

  inline float mapInRange(float input, float xLow, float xHigh, float yLow, float yHigh){
      return (yLow * (xHigh - input) + yHigh * (input - xLow)) / (xHigh - xLow);
  }
  inline float linearMap(float input, float low, float high){
      return mapInRange(input, 0, 1, low, high);
  }

private:
//Define incrementmethods. We make them private because we don't want anything
//external to accidently mess with the header positions seperately.
  inline void incrementWriteIndex(){
    writeIndex++;
    wrapHeader(writeIndex);
  }
  inline void incrementReadIndex(){
    readIndex++;
    wrapHeader(readIndex);
  }
//wrapping function. Using pointers, wow this is super smart @ciska.
//By giving the index as a pointer we are able to handle it as if we are changing
//the index as if it was an object. "index" is replaced by "readIndex" or "writeIndex"
  inline void wrapHeader(float& index){
    if(index >= m_size){
       index -= m_size;
    }
  }

void allocateBuffer();
void deleteBuffer();

  float* buffer;
  uint m_size;
  uint delayTimeSamps;
    float writeIndex;
    float readIndex;
};
