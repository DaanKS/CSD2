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

JackModule* jackP = nullptr;
void jackWrapper(){
  if(jackP != nullptr){
    jackP->autoConnect();
  }
}






int main(int argc, char **argv){

  return 0;
}
