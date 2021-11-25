#include "notebook.h"

Notebook::Notebook() : Notebook("DSP Notebook") {}

Notebook::Notebook(std::string subject) : Book("Ruitjes Papier"),
  subject(subject) {
    std::cout << "Opening Notebook \n";
  }

Notebook::~Notebook(){
  std::cout << "Notebook destructor\n";
}


void Notebook::setPenColour(float penColour){
  this->penColour=penColour;
}
float Notebook::getPenColour(){
  return penColour;
}

void Notebook::setSubject(std::string subject){
  this->subject=subject;
}
std::string Notebook::getSubject(){
  return subject;
}


void Notebook::write(std::string textToWrite){
  this->textToWrite=textToWrite;
}
