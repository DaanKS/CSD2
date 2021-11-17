#include <iostream>
#include <cstring>
#include "mugmeasurementunit.h"

class Coffeemachine{
public:
  Coffeemachine();
  ~Coffeemachine();

  void setMilkLevel(double milkLevel);
  double getMilkLevel();
  void setBeansLevel(double beansLevel);
  double getMilkLevel();
  void setWaterLevel(double waterLevel);
  double getWaterLevel();

  void setCoffeeType(std::string coffeeType);
  std::string getCofeeType();

  void prepMilk();
  void pourMilk();
  void boilWater();
  void makeCoffee();

private:
  std::string coffeeType; //nespresso... what else?
  double waterLevel;
  double necessaryCoffeeAmount;

  double beansLevel;
  double milkLevel;

  double mugPercentage = 0.87; //Ideal mugPercentage Usage.

  MugMeasurement* mugmeasurementunit;
};
