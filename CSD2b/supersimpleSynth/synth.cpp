#include "synth.h"

Synth::Synth(double samplerate){
  midi = new Midicontrol;
}
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
  midi->displayDevices();
  midi->setDevices();
}
void Synth::startMidiListening(){
  std::cout << "Synth Start Midi" << std::endl;
  midi->startMidiListening();

}

void Synth::passMessageFromMidiToSynth(){
    setPitch(midi->getMidiNoteNumber());
}
