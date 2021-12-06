#include "keys.h"
#include "blaas.h"
#include "string.h"

int main(){

  // Keys newKey;
  // Blaas newBlaas;
  //
  // newBlaas.makeSound();
  // newKey.makeSound();
  //
  // newBlaas.setHornLength(6.34);
  // newKey.setPolyphony(5);
  // newKey.setPolyphony(6);

  Strings newStr("E Open", 17);

  newStr.makeSound();
  std::cout << newStr.getNumStrings() << " is the amount of strings\n";
  newStr.setTuning("Double Drop A");
  newStr.makeSound();



  return 0;
}
