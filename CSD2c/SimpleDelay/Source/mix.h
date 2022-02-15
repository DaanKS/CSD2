/*
  ==============================================================================

    mix.h
    Created: 15 Feb 2022 11:26:08pm
    Author:  Dean

  ==============================================================================
*/

#pragma once

#include <cmath>

class Mix{
public:
  Mix();
  ~Mix();

  double getA(double eX);
  double getB(double eX);

  void setX(double eX);
  double getX();
private:
  double eX;
};
