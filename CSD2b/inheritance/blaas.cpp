#include "blaas.h"

Blaas::Blaas(){
  std::cout << "Blaas constructor\n";
}
Blaas::~Blaas(){
  std::cout << "Blaas destructor\n";
}


void Blaas::makeSound(){
  std::cout << "tut";
}


void Blaas::setHornLength(float hornLength){
  std::cout << "the hornlength is now " << hornLength << "\n";
}
float Blaas::getHornLength(){
  return hornLength;
}
