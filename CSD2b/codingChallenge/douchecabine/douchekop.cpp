#include "douchekop.h"

Douchekop::Douchekop(){}
Douchekop::~Douchekop(){}

void Douchekop::setHeadHeight(int showerHeadHeight){
  this->showerHeadHeight=showerHeadHeight;
}
int Douchekop::getHeadHeight(){
  return showerHeadHeight;
}

void Douchekop::setHeadAngle(float showerHeadAngle){
  this->showerHeadAngle=showerHeadAngle;
}
float Douchekop::getHeadAngle(){
  return showerHeadAngle;
}

void changeSprayType(std::string sprayType){
  this->sprayType=sprayType;
}
std::string getSprayType(){
  return sprayType;
}
