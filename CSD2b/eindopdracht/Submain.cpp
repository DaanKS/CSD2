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
  std::cout << "\n\n  Welcome \n";
  //create jackModule and initiate jack
  JackModule jack;
  jack.init(argv[0]);
  double sampRate = jack.getSamplerate();
  //start inputvalidator
  InputValidation input;
  //startSynthesizer
  Subsynth synth(sampRate);
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
  std::cout << "\n\nUse Midi device to play notes \n";
  std::cout << "Press 'q' ENTER when you want to quit the program.\n";
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
      synth.stopMidiListening();
      updateMidiThread.join();
      synthThread.join();
      jack.end();
      jackThread.join();
      break;
    case 'f':
      std::cout << "set new value for feedback ";
      userFeedback = input.retrieveValueInRange(0.1, 0.95);
      synth.setFeedback(userFeedback);
      break;
    case 'g':
      std::cout << "set a new value for detune ";
      userDetune = input.retrieveValueInRange(-24, 24);
      synth.setDetune(userDetune);
      break;
  }
}
  return 0;
}
