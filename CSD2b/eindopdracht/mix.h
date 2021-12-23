// Equal Power Mixing.
// I am going to make a simple OnePole lowpass filter
// It's a IIR system described by the equation:
// Y[n] = aX[n] + bY[n-1]
// a and b will be decided by an equal power (square law)
//panning equation:
//A = 1 - 0.25(x + 1)^2
//B = 1-(0.5x -0.5)^2
// panning equation stolen from Will Pirkle
#include <cmath>

#pragma once

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
