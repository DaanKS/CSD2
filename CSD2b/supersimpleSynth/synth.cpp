#include "synth.h"

Synth::Synth(double samplerate){}
Synth::~Synth(){}

double Synth::MTOF(int pitch){
  //TODO replace with lookup table?
  //https://www.music.mcgill.ca/~gary/307/week1/node28.html
   return 440.0 * pow(2.0 , ((pitch-57.0)/12.0));
}

void Synth::setPitch(int pitch){
  this->pitch=pitch;
}
int Synth::getPitch(){
  return pitch;
}

void Synth::setAmplitude(double amplitude){
  this->amplitude=amplitude;
}
double Synth::getAmplitude(){
  return amplitude;
}

void Synth::initMidi(){
  MIDI_io midi_io;
  PmEvent event;
  vector<PmEvent> eventlist;
  vector<PmEvent>::iterator event_iterator;
  bool event_read;
  int input_device=0, output_device=0;
  bool use_default_devices=false;
  bool recording=false;
  bool looping=false;
  unsigned char cmd, channel, data1;

    midi_io.list_devices();
}
