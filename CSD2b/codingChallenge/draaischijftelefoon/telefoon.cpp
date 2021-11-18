#include "telefoon.h"

Telefoon::Telefoon();
Telefoon::~Telefoon();

void Telefoon::inputNumber(){
  std::cout << "Enter Phone Number to call: "
  for(i = 0; i < phoneNumberLength; i++){
    std::cin >> int numBer;
    callNumber[i] = numBer;
  }
  ringing = true;
}
void Telefoon::dialTone(){
  while dialing{
    makeSound(1);
    //TODO add sequencer functionality (16th note to timestamps so it plays in proper rhythm
  }
}
void Telefoon::connectToLine(){
  std::cout << "Connected to " << for(i=0; i < phoneNumberLength; i++){
    callNumber[i];
  } << std::endl;
  std::cout << "You may start talking: "
}
void closeConnection(){
  std::cout << "Connction Closed";
  makeSound(2);
}
void receiveCall(){
  ringing = true;
  while ringing{
    makeSound(0);
  }
}
