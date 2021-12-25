#include "mix.h"

Mix::Mix(){}
Mix::~Mix(){}

double Mix::getA(double eX){
  return 1 - 0.25 * pow((eX + 1), 2);
}
double Mix::getB(double eX){
  return 1 - pow(((0.5 * eX) - 0.5), 2);
}

void Mix::setX(double eX){
  this->eX = eX;
}
double Mix::getX(){
  return eX;
}
