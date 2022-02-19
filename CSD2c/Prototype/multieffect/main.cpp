#include "simpledelay.h"
#include "tremolo.h"
#include "jack_module.h"
#include "biquad.h"
#include "bypass.h"
#include <iostream>

int main(int argc, char **argv){

  JackModule jack;
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();

  AudioEffect* effect_1;
  AudioEffect* effect_2;
  AudioEffect* effect_3;

//  effect_1 = new Delay(samplerate);
  effect_2 = new Biquad(samplerate);
  ((Biquad*)effect_2)->setCutoffFreq(500);
  ((Biquad*)effect_2)->setQFactor(1);
  ((Biquad*)effect_2)->calculateOmega();
  ((Biquad*)effect_2)->calculateAlpha();
  ((Biquad*)effect_2)->calculateCoefficients();

  jack.onProcess = [&effect_1, &effect_2, &effect_3](jack_default_audio_sample_t *inBuf,
  jack_default_audio_sample_t *outBuf, jack_nframes_t numFrames){
    for(unsigned int sample = 0; sample < numFrames; sample++){
      //outBuf[sample] = effect_3->output(effect_2->output(effect_1->output(inBuf[sample])));
      outBuf[sample] = effect_2->output(inBuf[sample]);
    }
    return 0;
  };

  jack.autoConnect();
  std::cout << "Press 'q' and hit ENTER to quit \n";
  bool running =true;
  while(running){
    switch (std::cin.get()) {
      case 'q':
        running = false;
        jack.end();
        break;
      }
  }

  return 0;

}
