#include "audioeffect.h"

AudioEffect::AudioEffect(double samplerate) : samplerate(samplerate){
  std::cout << "Audio Effect Constructor" << std::endl;

}

float AudioEffect::setDrywet(float drywet){
  this->drywet = drywet;
}
