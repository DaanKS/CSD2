#include "FMsynth.h"
#include "jack_module.h"
#include <iostream>

int main(int argc, char **argv){
  //Create JackModule
  JackModule jack;
  //initiate jack
  jack.init(argv[0]);

  //start simplesynth
  Fmsynth fmsynth(jack.getSamplerate());
  fmsynth.resetPhase();
  fmsynth.setPitch(22);
  fmsynth.setRatio(1.07);
  fmsynth.setModulationIndex(fmsynth.getRatio(), fmsynth.MTOF(fmsynth.getPitch()));
  fmsynth.setFrequencies();

  //make JackModule::onProces
  jack.onProcess = [&fmsynth](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++){
      outBuf[i] = fmsynth.tick();
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
        jack.end();
        break;
    }
  }

  return 0;
}
