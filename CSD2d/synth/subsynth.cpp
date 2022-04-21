#include "subsynth.h"

Subsynth::Subsynth() {}

Subsynth::Subsynth(double samplerate) : m_samplerate(samplerate),
 m_pitch(50),m_detune(-12){
  osc_1 = new Saw(m_samplerate);
  osc_2 = new Square(m_samplerate);
  over = new Oversampler(m_samplerate);
}
Subsynth::~Subsynth(){
  delete osc_1;
  delete osc_2;
  osc_1 = nullptr;
  osc_2 = nullptr;
}

void Subsynth::Initialize(double samplerate, float pitch, float detune, float cutoff){
   this->m_samplerate = samplerate;
    setPitch(pitch);
    setDetune(detune);
    setCutoff(cutoff);

    osc_1 = new Saw(m_samplerate);
    osc_2 = new Square(m_samplerate);
    over = new Oversampler(m_samplerate);
}


double Subsynth::output(){
    //filtering done here
    return lpf_2.output(lpf_1.output(calculate()));
}

double Subsynth::calculate() {
    //oversampling done here
    over->input((osc_1->output() + osc_2->output()) / 2.0f );
    for(auto i = 0; i < 4; ++i) {
        over->setOverSampledBuffer(over->getOverSampledBuffer(i), i);
    }
    return over->getOutputBuffer();
}

void Subsynth::setCutoff(float cutoff){
   const auto tempCoefficients = lpf_1.makeLowPass(cutoff ,m_samplerate);
   lpf_1.setCoefficinets(tempCoefficients);
   lpf_2.setCoefficinets(tempCoefficients);
}

void Subsynth::setDetune(float detune){
  this->m_detune = detune;
}
void Subsynth::setPitch(float pitch) {
    this->m_pitch = pitch;
}

void Subsynth::updatePitches(){
  const auto newPitch = getPitch();
  if(newPitch != oldPitch){
    osc_1->setDelta(mtof(getPitch()));
    osc_2->setDelta(mtof(getPitch() + m_detune));
    oldPitch = newPitch;
  }
}
