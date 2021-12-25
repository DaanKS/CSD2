#include "fmsynth.h"
#include "subsynth.h"
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
  Synth* synth;

  //Ask for what type of synth
  std::cout << "Hi \n" << "Pick a Synth: 1. FMsynth, 2. Subsynth ";
  int type = static_cast<int>(input.retrieveValueInRange(1, 2));
  std::cout << "Type : " << type << std::endl;
  if (type == 1){
    synth = new Fmsynth(sampRate);
  }else{
    synth = new Subsynth(sampRate);
  }
  //Programme automagically starts midiprocess.
  //assign objects to multiple threads
  jackP = &jack;
  std::thread jackThread(jackWrapper);
  synthP = synth;
  std::thread synthThread(midiWrapper);
//  std::thread updateMidiThread(updatePitchesFromMidi);

  //make jackModule::OffProcess
  jack.offProcess = [&synth](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
    for(unsigned int i = 0; i < nframes; i++){
      outBuf[i] = synth->output();
    }
    return 0;
  };


  return 0;
}
