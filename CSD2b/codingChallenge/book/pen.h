#include <iostream>
#include <cstring>

class Pen{
public:
  Pen();
  ~Pen();

  void setColour(float red, float green, float blue, float alpha);
  float getColour();

  std::string writeText();

protected:
  float red = 0.0;
  float green = 0.0;
  float blue = 0.0;
  float alpha = 1;
  float RGBA[4] = {red, green, blue, alpha}
  std::string outPutText;
};
