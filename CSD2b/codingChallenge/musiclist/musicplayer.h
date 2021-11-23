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
  int currentQueue[];
  int songNumber;
  int totalSongs;
};
