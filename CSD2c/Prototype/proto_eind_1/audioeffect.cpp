#include "audioeffect.h"

AudioEffect::AudioEffect(double samplerate) : m_samplerate(samplerate), drywet(0.0){
}
AudioEffect::~AudioEffect(){}

void AudioEffect::setDrywet(float drywet){
  this->drywet = drywet;
}
void AudioEffect::setSamplerate(float samplerate) {
    this->m_samplerate = samplerate;
}