#include "fmsynth.h"
#include "subsynth.h"
#include "jack_module.h"
#include "userinput.h"

#include <iostream>
#include <thread>

Synth* synthP = nullptr;
void midiWrapper(){
  if(synthP != nullptr){
    synthP->startMidiListening();
  }
}
void synthPitchUpdater(){
  if(synthP != nullptr){
  synthP->updatePitchesFromMidi();
  }
}

JackModule* jackP = nullptr;
void jackWrapper(){
  if(jackP != nullptr){
    jackP->autoConnect();
  }
}


int main(int argc, char **argv){
  JackModule jack;
  jack.init(argv[0]);



  return 0;
}
