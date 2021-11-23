#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>

#pragma once

class Databass{
public:
  Databass();
  ~Databass();

  void addDatabase(std::string songID);
  void removeDatabase(int songListPosition);

  std::string getSong(int songListPosition);

  std::vector<std::string> songList = {"Cosmic Soul", "Sláinte", "Izé", "Surge"};
private:
  int songListPosition;

};
