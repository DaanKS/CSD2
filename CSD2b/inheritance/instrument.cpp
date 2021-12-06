#include "instrument.h"

Instrument::Instrument(){
  std::cout << "Instrument Constructor \n";
}

Instrument::~Instrument(){
  std::cout << "Instrument Destructor \n";
}

void Instrument::makeSound(){}
