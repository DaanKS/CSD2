#include "coffeemachine.h"

Coffeemachine::Coffeemachine(){
  mugmeasurementunit = new MugMeasurement;
}
Coffeemachine::~Coffeemachine(){}


void Coffeemachine::setMilkLevel(double milkLevel){
  this->milkLevel = milkLevel;
}
double Coffeemachine::getMilkLevel(){
  return milkLevel;
}


void Coffeemachine::setBeansLevel(double beansLevel){
  this->beansLevel = beansLevel;
}
double Coffeemachine::getBeansLevel(){
  return beansLevel;
}


void Coffeemachine::setWaterLevel(double waterLevel){
  this->waterLevel = waterLevel;
}
double Coffeemachine::getWaterLevel(){
  return waterLevel;
}


void Coffeemachine::setCoffeeType(std::string coffeeType){
  this->coffeeType = coffeeType;
}
std::string Coffeemachine::getCoffeeType(){
  return coffeeType;
}


void Coffeemachine::prepMilk(){
  std::cout << "Preparing Milk" << std::endl;
}
void Coffeemachine::pourMilk(){
  std::cout << "Pouring Milk" << std::endl;
}
void Coffeemachine::boiWater(){
  std::cout << "Boiling Water" << std::endl;
}
void Coffeemachine::makeCoffee(){
  necessaryCoffeeAmount = mugmeasurementunit->volumeMug() * mugPercentage;
}
