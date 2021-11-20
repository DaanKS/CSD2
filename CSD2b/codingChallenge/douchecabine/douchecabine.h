#include "douchekop.h"

#pragma once

class Douche{
public:
  Douche();
  ~Douche();

  void changeSprayType();
  void adjustShowerHead();

  void setWaterTemp(float waterTemp);
  float getWaterTemp();


private:
  float waterTemp;

};
