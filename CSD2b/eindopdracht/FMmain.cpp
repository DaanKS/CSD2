#include "fmsynth.h"
#include "jack_module.h"
#include "inputvalidation.h"

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

  //create jackModule and initiate jack
  JackModule jack;
  jack.init(argv[0]);
  double sampRate = jack.getSamplerate();
  //start inputvalidator
  InputValidation input;
  //startSynthesizer
  Fmsynth synth(sampRate);
  //Ask for what type of synth


  //Programme automagically starts midiprocess.
  //assign objects to multiple threads
  jackP = &jack;
  std::thread jackThread(jackWrapper);
  synthP = &synth;
  std::thread synthThread(midiWrapper);
  std::thread updateMidiThread(synthPitchUpdater);

  //make jackModule::onProcess
  jack.onProcess = [&synth](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
    for(unsigned int i = 0; i < nframes; i++){
      outBuf[i] = synth.output();
    }
    return 0;
  };


  return 0;
}