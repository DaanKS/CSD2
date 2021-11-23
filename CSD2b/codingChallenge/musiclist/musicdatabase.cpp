#include "musicdatabase.h"

Databass::Databass(){}
Databass::~Databass(){}

void Databass::addDatabase(std::string songID){
  songList.push_back(songID);
}
void Databass::removeDatabase(int songListPosition){
  songList.erase(songListPosition);
}
std::string Databass::getSong(int songListPosition){
  return songList[songListPosition];
}
