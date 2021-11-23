#include "musicdatabase.h"

Databass::Databass(){}
Databass::~Databass(){}

void Databass::addDatabase(std::string songID){
  songList.append(songID);
}
void Databass::removeDatabase(int songListPosition){
  songList.pop(songListPosition);
}
std::string Databass::getSong(int songListPosition){
  return songList[songListPosition];
}
