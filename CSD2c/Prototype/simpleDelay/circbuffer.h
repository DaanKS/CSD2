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
  inline float readFromBuffer(){return buffer[readIndex];}

  inline void incrementIndeces(){
    incrementWriteIndex();
    incrementReadIndex();
  }

private:
//Define incrementmethods. We make them private because we don't want anything
//external to accidently mess with the header positions seperately.
  inline void incrementWriteIndex(){
    writeIndex++;
    //std::cout << "writeIndex: " << writeIndex << std::endl;
    wrapHeader(writeIndex);
  }
  inline void incrementReadIndex(){
    //std::cout << "readIndex: " << readIndex << std::endl;
    readIndex++;
    wrapHeader(readIndex);
  }
//wrapping function. Using pointers, wow this is super smart @ciska.
//By giving the index as a pointer we are able to handle it as if we are changing
//the index as if it was an object. "index" is replaced by "readIndex" or "writeIndex"
  inline void wrapHeader(uint& index){
    std::cout << "size: " << m_size << std::endl;
    if(index >= m_size){
       index -= m_size;
       std::cout << "wrapped" << std::endl;
    }
  }

void allocateBuffer();
void deleteBuffer();


  uint readIndex;
  uint writeIndex;
  uint m_size, delayTimeSamps;
  float* buffer;

};
