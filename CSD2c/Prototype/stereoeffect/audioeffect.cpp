#include "audioeffect.h"

AudioEffect::AudioEffect() : drywet(0.0){
}
AudioEffect::~AudioEffect(){}

void AudioEffect::setDrywet(float drywet){
  this->drywet = drywet;
}
void AudioEffect::setSamplerate(float samplerate) {
    this->samplerate = samplerate;
}