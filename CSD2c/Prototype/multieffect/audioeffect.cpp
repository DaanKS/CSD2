#include "audioeffect.h"

AudioEffect::AudioEffect(double samplerate) : samplerate(samplerate){
  std::cout << "Audio Effect Constructor" << std::endl;
}
AudioEffect::~AudioEffect(){}
void AudioEffect::setDrywet(float drywet){
  this->drywet = drywet;
}
