#include <iostream>
#include <cmath>

class MugMeasurement{
public:
  MugMeasurement();
  ~MugMeasurement();

  bool isMug();

  double volumeMug();
  inline double getMugBase(){
    return PI * pow(getMugRadius(), 2);
  }
  inline double getMugHeight(){
    std::cout << "measuring height..."
    return 6.7;
  }
  inline double getMugRadius(){
      std::cout << "measuring radius..."
      return 1.1;
  }

private:
  bool mug;
};
