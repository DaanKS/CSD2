#include "simpledelay.h"
#include "tremolo.h"
#include "jack_module.h"

int main(int argc, char **argv){

  JackModule jack;
  jack.init(argv[0]);

  AudioEffect* effect_1;
  AudioEffect* effect_2;
  AudioEffect* effect_3;


  jack.onProcess = [&effect_1, &effect_2, &effect_3](jack_default_audio_sample_t *inBuf,
  jack_default_audio_sample_t *outBuf, jack_nframes_t numFrames){
    for(unsigned int sample = 0; sample < numFrames; sample++){
      outBuf[sample] = effect_3->output(effect_2->output(effect_1->output(inBuf[sample])));
    }
    return 0;
  };


  return 0;
}
