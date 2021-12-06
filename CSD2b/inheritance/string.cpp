#include "string.h"

String::String(std::string tuning, int numStrings) : Instrument(),
tuning(tuning), numStrings(numStrings){
  std::cout << "String Constructor \n"
  << "Tuning is" << tuning << "\n";
}
String::~String(){
  std::cout << "string Destructor\n";
}


void String::makeSound(){
  std::cout << "waw\n";
}


int String::getNumStrings(){
  return numStrings;
}
void String::setTuning(std::string tuning){
  this->tuning = tuning;
  std::cout << "tuning is now " << tuning << "\n";
}
std::string String::getTuning(){
  return tuning;
}
