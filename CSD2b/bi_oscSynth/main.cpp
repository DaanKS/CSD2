#include "bisynth.h"
#include "jack_module.h"
#include <iostream>

int main(int argc, char **argv){
  //Create JackModule
  JackModule jack;
  //initiate jack
  jack.init(argv[0]);
  //start bisynth
  Bisynth bisynth(1.0, jack.getSamplerate());
  bisynth.setPitch(40);
  bisynth.setDetune(0.25)
  bisynth.setFrequencies();
  //make JackModule::onProces
  jack.onProcess = [&bisynth](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++){
      outBuf[i] = bisynth.tick();
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
