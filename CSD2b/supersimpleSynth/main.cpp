#include "supersynth.h"
#include "jack_module.h"
#include <iostream>
#include <thread>

Synth* synthP = nullptr;
void wrapper() {
  std::cout << "Wrapper Midi Start " << std::endl;
  if(synthP != nullptr) {
    synthP->startMidiListening();
  }
}

int main(int argc, char **argv){
  //Create JackModule
  JackModule jack;
  //initiate jack
  jack.init(argv[0]);

  //start simplesynth
  Supersynth synth(44100);//jack.getSamplerate());
  synth.setPitch(36);
  synth.setAmplitude(0.25);
  synth.setPitches();
  //synth.initMidi();


  synthP = &synth;
  std::thread midiThread (wrapper);

  //make JackModule::onProces
  jack.onProcess = [&synth](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++){
      synth.accumulateOutput();
      outBuf[i] = synth.tick();
    }
    return 0;
  };

  jack.autoConnect();

  std::cout << "\n\nPress 'q' ENTER when you want to quit the program.\n";
  bool running = true;
  while (running)
  {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
    //    jack.end();
        break;
    }
  }
  midiThread.join();

  return 0;
}
