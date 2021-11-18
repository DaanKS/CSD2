#include <iostream>
#include <cstring>

class Telefoon{
public:
  Telefoon();
  ~Telefoon();

  // tel nummer input forloop
  void inputNumber();
  // dialtone while loop
  void dialTone();
  // connection
  void connectToLine();
  // close connection
  void closeConnection();
  //ring function
  void receiveCall();
  inline void makeSound(int typeSound){
    std::cout << sounds[typeSound];
  }

private:
  int ownNumber[7] = {5, 5, 5, 0, 1, 2, 3};
  int typeSound;
  std::string sounds[3] = {"Ring!" , "Dial", "connection closed"};
  int callNumber[7];
  int phoneNumberLength = 7;
  bool dialing;
  bool ringing;
};
