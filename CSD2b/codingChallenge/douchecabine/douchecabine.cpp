#include "douchecabine.h"

Douche::Douche(){
  Douchekop douchekop;
}
Douche::~Douche(){}

void Douche::changeSprayType(){
  std::cout << "enter spraytype: ";
  std::cin >> std::string sprayType;
  douchekop.setSprayType(sprayType);
}

void Douche::adjustShowerHead(){
  std::cout << "enter height of showerhead: ";
  std::cin >> int showerHeadHeight;
  douchekop.setHeadHeight(showerHeadHeight);
  std::cout << "enter angle of showerhead: ";
  std::cin >> float showerHeadAngle;
  douchekop.setHeadAngle(showerHeadAngle);
}

void Douche::setWaterTemp(float waterTemp){
  this->waterTemp=waterTemp;
}
float getWaterTemp(){
  return waterTemp;
}
