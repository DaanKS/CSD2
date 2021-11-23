#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>

class Databass{
public:
  Databass();
  ~Databass();

  void addDatabase(std::string songID);
  void removeDatabase(int songListPosition);

  std::string getSong(int songListPosition);

private:
  int songListPosition;
  std::vector<std::string> songList
  songList = {"Cosmic Soul", "Sláinte", "Izé", "Surge"};
};
