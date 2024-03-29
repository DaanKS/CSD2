#include "synth.h"

Synth::Synth(double samplerate){
  this->samplerate = samplerate;
  midi = new Midicontrol;
}
Synth::~Synth(){}

double Synth::mtof(double pitch){
  //TODO replace with lookup table
  //https://www.music.mcgill.ca/~gary/307/week1/node28.html
   return 440.0 * pow(2.0 , ((pitch-57.0)/12.0));
}

void Synth::setPitch(double pitch){
  this->pitch=pitch;
}
double Synth::getPitch(){
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
  midi->startMidiListening();
}

void Synth::stopMidiListening(){
  this->updatingPitches = false;
  midi->switchOffListening();
}


void Synth::passMessageFromMidiToSynth(){
    setPitch(midi->getMidiNoteNumber());
}

void Synth::updatePitchesFromMidi(){
  updatingPitches = true;
  while(updatingPitches){
    passMessageFromMidiToSynth();
    updatePitches();
  }
}
