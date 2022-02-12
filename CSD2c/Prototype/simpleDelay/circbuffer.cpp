#include "circbuffer.h"

CircBuffer::CircBuffer(int size, int numSamplesDelay): size(size),
numSamplesDelay(numSamplesDelay), readIndex(size - numSamplesDelay), writeIndex(0){
  initialize();
  if(numSamplesDelay > size){
    throw ("CircBuffer::CircBuffernumSamplesDelay exceeds size");
  }

}
CircBuffer::~CircBuffer(){
  delete [] buffer;
}

void CircBuffer::initialize(){
  if(buffer != nullptr){
    delete [] buffer;
    buffer = nullptr;
  }
  buffer = new double[size];
  for(int i = 0; i < size; i++){
    buffer[i] = 0;
  }
}

void CircBuffer::writeToBuffer(double inputSample){
  buffer[writeIndex++] = inputSample;
  writeIndex = wrapHeader(writeIndex);
}
double CircBuffer::readFromBuffer(){
  double tempHeader = buffer[readIndex];
  readIndex = wrapHeader(readIndex);
  return tempHeader;
}

int CircBuffer::wrapHeader(int head){
if(head >= size) head -= size;
return head;
}

int CircBuffer::distanceReadWrite(){
  if(writeIndex < readIndex){
    int tempWH = writeIndex;
    tempWH += size;
    return tempWH - readIndex;
  }
  return writeIndex - readIndex;
}
