#include "fmsynth.h"
#include "subsynth.h"
#include "jack_module.h"
#include "inputvalidation.h"

#include <iostream>
#include <thread>

//NOTE: synthP at global level _ tidy up in future renditions
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

  //Ask for what type of synth
  std::cout << "Hi \n" << "Pick a Synth: 1. FMsynth, 2. Subsynth ";
  int type = static_cast<int>(input.retrieveValueInRange(1, 2));
  std::cout << "Type : " << type << std::endl;
  if (type == 1){
    synthP = new Fmsynth(sampRate);
  }else{
    synthP = new Subsynth(sampRate);
  }

  //Programme automagically starts midiprocess.
  //assign objects to multiple threads
  jackP = &jack;
  std::thread jackThread(jackWrapper);
  std::thread synthThread(midiWrapper);
  std::thread updateMidiThread(synthPitchUpdater);

  //make jackModule::onProcess
  jack.onProcess = [](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
    for(unsigned int i = 0; i < nframes; i++){
      outBuf[i] = synthP->output();
    }
    return 0;
  };

  std::cout << "\n\nUse Midi device to play notes \n";
  std::cout << "Press 'q' ENTER when you want to quit the program.\n";

if(type == 1){
  std::cout << "hit 'g' ENTER to change the Ratio (0.0 to 12.0) \n"
  << "hit 'f' ENTER to change the mod depth(0.0 to 100.0) \n"
  << "hit 'r' ENTER to change Carrier Wave \n"
  << "hit 't' ENTER to change Modulator Wave \n";

  bool running = true;
  float userModDepth;
  float userRatio;
  while (running)
  {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
        synthP->stopMidiListening();
        updateMidiThread.join();
        synthThread.join();
        jack.end();
        jackThread.join();
        break;
      case 'f':
        std::cout << "set new value for Ratio ";
        userRatio = input.retrieveValueInRange(0, 12);
        synthP->setRatio(userRatio);
        break;
      case 'g':
        std::cout << "set a new value for ModDepth ";
        userModDepth = input.retrieveValueInRange(0, 100);
        synthP->setModDepth(userModDepth);
        break;
      case 'r':
        synthP->changeWaveCar();
        break;
      case 't':
        synthP->changeWaveMod();
        break;
    }
  }
}else{
  std::cout << "hit 'g' ENTER to change the Detune (-24 to 24) \n"
  << "hit 'f' ENTER to change the Feedback amount (0.1 to 0.95) \n";
  bool running = true;
  float userDetune;
  float userFeedback;
  while (running)
  {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
        synthP->stopMidiListening();
        updateMidiThread.join();
        synthThread.join();
        jack.end();
        jackThread.join();
        break;
      case 'f':
        std::cout << "set new value for feedback ";
        userFeedback = input.retrieveValueInRange(0.1, 0.95);
        synthP->setFeedback(userFeedback);
        break;
      case 'g':
        std::cout << "set a new value for detune ";
        userDetune = input.retrieveValueInRange(-24, 24);
        synthP->setDetune(userDetune);
        break;
    }
  }
}

  delete synthP;
  synthP = nullptr;

  return 0;
}
