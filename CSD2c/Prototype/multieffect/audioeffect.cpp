#include "audioeffect.h"

AudioEffect::AudioEffect(double samplerate){
  std::cout << "Audio Effect Constructor" << std::endl;
  this->samplerate = samplerate;
}

float AudioEffect::setDrywet(float drywet){
  this->drywet = drywet;
}
