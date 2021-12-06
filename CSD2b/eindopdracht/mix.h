// Equal Power Mixing.
// I am going to make a simple OnePole lowpass filter
// It's a IIR system described by the equation:
// Y[n] = aX[n] + bY[n-1]
// a and b will be decided by an equal power (square law)
//panning equation:
//A = 1 - 0.25(x + 1)^2
//B = 1-(0.5x -0.5)^2
// Equation stolen from Will Pirkle

class Mix{
public:
  Mix();
  ~Mix();

  float getA(float X);
  float getB(float X);

  void setX(float X);
  float getX();
private:
  float X;
};
