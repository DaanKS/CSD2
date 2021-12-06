#include "blaas.h"

Blaas::Blaas() : Instrument() {
  std::cout << "Blaas constructor\n";
}
Blaas::~Blaas(){
  std::cout << "Blaas destructor\n";
}


void Blaas::makeSound(){
  std::cout << "tut\n";
}


void Blaas::setHornLength(float hornLength){
  this->hornLength = hornLength;
  std::cout << "the hornlength is now " << hornLength << "\n";
}
float Blaas::getHornLength(){
  return hornLength;
}
