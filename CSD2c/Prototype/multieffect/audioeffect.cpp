#include "audioeffect.h"

AudioEffect::AudioEffect(double samplerate) : samplerate(samplerate), drywet(0.5){
  std::cout << "Audio Effect Constructor" << std::endl;
}
AudioEffect::~AudioEffect(){}

void AudioEffect::setDrywet(float drywet){
  this->drywet = drywet;
}
