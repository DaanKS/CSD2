#include <iostream>
#incldue <cstring>

#pragma once

class Douchekop{
public:
  Douchekop();
  ~Douchekop();

  void setHeadHeight(int showerHeadHeight);
  int getHeadHeight();

  void setHeadAngle(float showerHeadAngle);
  float getHeadAngle();

  void setSprayType(std::string sprayType);
  std::string getSprayType();

private:

  int showerHeadHeight;
  float showerHeadAngle;
  std::string sprayType;
};
