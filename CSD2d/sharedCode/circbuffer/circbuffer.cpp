#include "circbuffer.h"

//dummy constructor, give it nothing  to start off
CircBuffer::CircBuffer(){}

CircBuffer::CircBuffer(uint size) : m_size(size),writeIndex(0), readIndex(0){
  allocateBuffer();
}
CircBuffer::~CircBuffer(){
  deleteBuffer();
}

void CircBuffer::initialize(uint size){
  m_size = size;
  deleteBuffer();
  allocateBuffer();
}
void CircBuffer::allocateBuffer(){
  //std::cout << "buffer allocation " << std::endl;
  //reserve and clear buffer. Set 0 for entire size of buffer
  buffer = (float*)malloc(m_size * sizeof(float));
  memset(buffer, 0, m_size * sizeof(float));
}
void CircBuffer::deleteBuffer(){
  //using memset to release the reserved space
  free(buffer);
}

void CircBuffer::setDelayTimeSamps(uint delayTimeSamps){
  this->m_delayTimeSamps = delayTimeSamps;
  //std::cout << "delayTime Samps " << m_delayTimeSamps << std::endl;
  //TODO --- understand this
  readIndex = writeIndex - m_delayTimeSamps + m_size;
  wrapHeader(readIndex);
}
