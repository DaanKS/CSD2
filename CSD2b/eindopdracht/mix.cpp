#include "mix.h"

Mix::Mix(){}
Mix::~Mix(){}

float getA(float X){
  return 1 - 0.25 * pow((X + 1), 2);
}
float getB(float X){
  return 1 - pow((0.5X - 0.5), 2);
}

void setX(float X){
  if(X >= 0. && X <= 0.99){
    this-> X = X;
  }else{
    this-> X = 0.1;
  }
}
float getX(){
  return X;
}
