#include "coffeemachine.h"

Coffeemachine::Coffeemachine(){
  mugmeasurementunit = new MugMeasurement;
}
Coffeemachine::~Coffeemachine(){}

  void setMilkLevel(double milkLevel){
    this->milkLevel = milkLevel;
  }
  double getMilkLevel(){
    return milkLevel;
  }

  void setBeansLevel(double beansLevel){
    this->beansLevel = beansLevel;
  }
  double getBeansLevel(){
    return beansLevel;
  }

  void setWaterLevel(double waterLevel){
    this->waterLevel = waterLevel;
  }
  double getWaterLevel(){
    return waterLevel;
  }

  void setCoffeeType(std::string coffeeType){
    this->coffeeType = coffeeType;
  }
  std::string getCoffeeType(){
    return coffeeType;
  }


void prepMilk(){
  std::cout << "Preparing Milk" << std::endl;
}
void pourMilk(){
  std::cout << "Pouring Milk" << std::endl;
}

void boiWater(){
  std::cout << "Boiling Water" << std::endl;
}

void makeCoffee(){
  necessaryCoffeeAmount = mugmeasurementunit->volumeMug() * mugPercentage;
}
