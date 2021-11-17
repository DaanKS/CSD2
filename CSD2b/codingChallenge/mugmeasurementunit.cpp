#include "mugmeasurementunit.h"

MugMeasurement::MugMeasurement(){}
MugMeasurement::~MugMeasurement(){}

bool MugMeasurement::isMug(){
  std::cout << "Is there a mug?: "
  std::cin >> mug;
  return mug;
}

double MugMeasurement::volumeMug(){
  while(mug){
    mug = false;
    return getMugBase() * getMugHeight();
  }
}
