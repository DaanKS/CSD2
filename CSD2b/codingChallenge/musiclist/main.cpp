#include "musicplayer.h"

int main(){
  Musicplayer music;

  music.playSong();
  music.skipSong();
  music.selectSong();
  music.shuffleQueue();

  music.volumeUp();
  music.volumeDown();

  music.dBaseShowSongList();
  music.dBaseAdd();
  music.dBaseShowSongList();
  music.dBaseRemove();
  music.dBaseShowSongList();
}
