#include "audioeffect.h"

AudioEffect::AudioEffect(double samplerate) : samplerate(samplerate), drywet(0.0){
}
AudioEffect::~AudioEffect(){}

void AudioEffect::setDrywet(float drywet){
  this->drywet = drywet;
}
