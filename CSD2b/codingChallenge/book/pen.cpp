#include "pen.h"

Pen::Pen();
Pen::~Pen();

void Pen::setColour(float red, float green, float blue, float alpha){
  this->red=red;
  this->green=green;
  this->blue=blue;
  this->alpha=alpha;
}
flaot getColour(){
  return RGBA
}

std::string Pen::writeText(){
  std::cout << "write: ";
  std::cin >> outPutText;

  return outPutText;
}
