#include "musicplayer.h"


Musicplayer::Musicplayer(){
  this->songNumber = 0;
  dbass = new Databass;
  this->totalSongs = 4; //dbass->songList.size(); -- TODO make proper size tool
  std::cout << "There are " << totalSongs << " songs \n";
}

Musicplayer::~Musicplayer(){}

void Musicplayer::playSong(){
  std::cout << "playing " << dbass->getSong(songNumber) << std::endl;
}
void Musicplayer::skipSong(){
  songNumber++;
  songNumber= songNumber % totalSongs;
  std::cout << "playing " << dbass->getSong(songNumber) << std::endl;
}
void Musicplayer::selectSong(){
  std::cout << "Select a Song ";
  std::cin >> songNumber;
  std::cout << "\n"<< "playing " << dbass->getSong(songNumber) << std::endl;
}

void Musicplayer::shuffleQueue(){
  std::cout << "Queue is shuffled \n";
  /*for(int i = 0; i < totalSongs; i++){
    currentQueue[i] = rand() % totalSongs;
  } */
}

void Musicplayer::volumeUp(){
  volume++;
  std::cout << "volume is " << volume << std::endl;
}
void Musicplayer::volumeDown(){
  volume--;
  std::cout << "volume is " << volume << std::endl;
}

void Musicplayer::dBaseAdd(){
  std::cout << "Add a new song: ";
  std::cin >> newSong;
  totalSongs++;
  dbass->addDatabase(newSong);
}
void Musicplayer::dBaseRemove(){
  std::cout << "Remove which position? ";
  std::cin >>  removeSong;
  totalSongs--;
  dbass->removeDatabase(removeSong);
}
void Musicplayer::dBaseShowSongList(){
  for(int i = 0; i > totalSongs; i++){
    std::cout << dbass->getSong(i) << std::endl;
  }
}
