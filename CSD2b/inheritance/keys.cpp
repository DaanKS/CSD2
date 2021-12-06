#include "keys.h"

Keys::Keys(){
  std::cout << "keys constructor\n";
}
Keys::~Keys(){
  std::cout << "keys destructor\n";
}


void Keys::makeSound(){
  std::cout << "tunk \n";
}


void Key::setPolyphony(int numVoices){
  std::cout << "numVoices is now " << numVoices << "\n";
}
int Key::getPolyphony(){
  return numVoices;
}
