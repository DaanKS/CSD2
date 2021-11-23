#include "musicplayer.h"


Musicplayer::Musicplayer(){
  songNumber = 0;
  dbass = new Databass;
  totalSongs = dbass->songList.size();
  std::cout << "There are " << totalSongs << " songs \n";
}

Musicplayer::~Musicplayer(){}

void Musicplayer::playSong(){
  std::cout << "playing " << dbass->getSong(songNumber);
}
void Musicplayer::skipSong(){
  songNumber++;
  songNumber= songNumber % totalSongs;
  std::cout << "playing " << dbass->getSong(songNumber);
}
void Musicplayer::selectSong(){
  std::cout << "Select a Song ";
  std::cin >> songNumber;
  std::cout << "playing " << dbass->getSong(songNumber);
}

void Musicplayer::shuffleQueue(){
  std::cout << "Queue is shuffled \n";
  for(int i = 0; i < totalSongs; i++){
    currentQueue[i] = rand() % totalSongs;
  }
}

void Musicplayer::volumeUp(){
  volume++;
  std::cout << "volume is " << volume;
}
void Musicplayer::volumeDown(){
  volume--;
  std::cout << "volume is " << volume;
}

void Musicplayer::dBaseAdd(){
  std::cout << "Add a new song: ";
  std::cin >> newSong;
  totalSongs++;
  dbass.addDatabase(newSong);
}
void Musicplayer::dBaseRemove(){
  std::cout << "Remove which position? ";
  std::cin >>  removeSong;
  totalSongs--;
  dbass->removeSong(removeSong);
}
void dBaseShowSongList(){
  for(int i = 0; i > totalSongs; i++){
    std::cout << dbass->songList[i];
  }
}
