#include "jack_module.h"
#include "simpledelay.h"
#include <iostream>

int main(int argc, char **argv){

  JackModule jack;
  jack.init(argv[0]);

  Delay del(jack.getSamplerate());
  del.setFeedback(0.5);

  jack.onProcess = [&del](jack_default_audio_sample_t *inBuf,
  jack_default_audio_sample_t *outBuf, jack_nframes_t numFrames){
    for(unsigned int sample = 0; sample < 10; sample++){

      outBuf[sample] = del.output(inBuf[sample]);
    //  del.incrementIndeces();
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
