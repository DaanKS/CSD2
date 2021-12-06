#include "keys.h"

Keys::Keys(int numKeys): Instrument(), numKeys(numKeys) {
  this->numKeys = numKeys;
  std::cout << "keys constructor\n";
}
Keys::~Keys(){
  std::cout << "keys destructor\n";
}


void Keys::makeSound(){
  std::cout << "tunk \n";
}

int Keys::getNumKeys(){
  return numKeys;
}

void Keys::setPolyphony(int numVoices){
  std::cout << "numVoices is now " << numVoices << "\n";
}
int Keys::getPolyphony(){
  return numVoices;
}
