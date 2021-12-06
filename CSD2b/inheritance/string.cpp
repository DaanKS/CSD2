#include "string.h"

Strings::Strings(std::string tuning, int numStrings) : Instrument(),
tuning(tuning), numStrings(numStrings){
  std::cout << "String Constructor \n"
  << "Tuning is" << tuning << "\n";
}
Strings::~Strings(){
  std::cout << "string Destructor\n";
}


void Strings::makeSound(){
  std::cout << "waw\n";
}


int Strings::getNumStrings(){
  return numStrings;
}
void Strings::setTuning(std::string tuning){
  this->tuning = tuning;
  std::cout << "tuning is now " << tuning << "\n";
}
std::string Strings::getTuning(){
  return tuning;
}
