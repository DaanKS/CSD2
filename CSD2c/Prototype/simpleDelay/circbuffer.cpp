#include "circbuffer.h"

//dummy constructor, give it nothing  to start off
CircBuffer::CircBuffer() : CircBuffer(0){}

CircBuffer::CircBuffer(uint size) : size(size){
  std::cout << "Circ: Size " << size << std::endl;
  allocateBuffer();
}
CircBuffer::~CircBuffer(){
  deleteBuffer();
}

void CircBuffer::initialize(uint size){
  this->size = size;
  deleteBuffer();
  allocateBuffer();
}
void CircBuffer::allocateBuffer(){
  //reserve and clear buffer. Set 0 for entire size of buffer
  buffer = (float*)malloc(size * sizeof(float));
  memset(buffer, 0, size * sizeof(float));
}
void CircBuffer::deleteBuffer(){
  //using memset to release the reserved space
  free(buffer);
}

void CircBuffer::setDelayTimeSamps(uint delayTimeSamps){
  this->delayTimeSamps = delayTimeSamps;
  //TODO --- understand this
  readIndex = writeIndex - delayTimeSamps + size;
  wrapHeader(readIndex);
}
