#include "musicdatabase.h"
#include <random>

#pragma once

class Musicplayer{
public:
  Musicplayer();
  ~Musicplayer();

  void playSong();
  void skipSong();
  void selectSong();

  void shuffleQueue();

  void volumeUp();
  void volumeDown();

  void dBaseAdd();
  void dBaseRemove();
  void dBaseShowSongList();

private:
  int volume;
  std::vector<int> currentQueue;
  int songNumber;
  int totalSongs;
  int removeSong;
  std::string newSong;
};
