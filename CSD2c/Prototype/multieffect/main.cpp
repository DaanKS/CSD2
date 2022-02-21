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

  effect_1 = new Delay(samplerate);
  ((Delay*)effect_1)->setDelayTime(250);
  ((Delay*)effect_1)->setFeedback(0.7);
  effect_2 = new Tremolo(samplerate);
  ((Tremolo*)effect_2)->setRate(1.5);
  ((Tremolo*)effect_2)->setAmplitude(1.0);
  effect_3 = new Tremolo(samplerate);
  ((Tremolo*)effect_3)->setRate(20.0);
  ((Tremolo*)effect_3)->setAmplitude(1.0);
/*  effect_2 = new Biquad(samplerate);
  ((Biquad*)effect_2)->setCutoffFreq(500);
  ((Biquad*)effect_2)->setQFactor(1);
  ((Biquad*)effect_2)->calculateOmega();
  ((Biquad*)effect_2)->calculateAlpha();
  ((Biquad*)effect_2)->calculateCoefficients(); */

  jack.onProcess = [&effect_1, &effect_2, &effect_3](jack_default_audio_sample_t *inBuf,
  jack_default_audio_sample_t *outBuf, jack_nframes_t numFrames){
    for(unsigned int sample = 0; sample < numFrames; sample++){
      outBuf[sample] = effect_3->output(effect_2->output(effect_1->output(inBuf[sample])));
    //  outBuf[sample] = effect_2->output(inBuf[sample]);
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
        delete effect_1;
        effect_1 = nullptr;
        delete effect_2;
        effect_2 = nullptr;
        delete effect_3;
        effect_3 = nullptr;
        break;
      }
  }

  return 0;

}
