#include "jack_module.h"
#include "tremolo.h"
#include <iostream>

int main(int argc, char **argv){
  //create jack_module
  JackModule jack;
  jack.init(argv[0]);

  //start Tremolo
  Tremolo trem(jack.getSamplerate());

  //make JackModule::onProcess
  jack.onProcess = [&trem](jack_default_audio_sample_t *inBuf,
  jack_default_audio_sample_t *outBuf, jack_nframes_t nframes){
    for(unsigned int sample = 0; sample < nframes; sample++){
      outBuf[sample] = trem.outputSample(inBuf[sample]);
    }
    return 0;
  };

  jack.autoConnect();

  std::cout << "Press 'q' and hit ENTER to quit\n";
  bool running = true;
  while(running){
    switch (std::cin.get()){
      case 'q':
        running = false;
        jack.end();
        break;
      case 'w':
        std::cout << "enter new rate: ";
        double tempRate;
        std::cin >> tempRate;
        trem.setRate(tempRate);
        break;
      case 'e':
        std::cout << "enter new amplitude: ";
        double tempAmp;
        std::cin >> tempAmp;
        trem.setAmplitude(tempAmp);
        break;
    }

  }
  return 0;
}
