#include "oversampler.h"

Oversampler::Oversampler(double samplerate) : m_samplerate(samplerate){
    initializeBuffers();
    initilizeFilters();
}

Oversampler::~Oversampler() = default;


 void Oversampler::input(float inputSample) {
    //the input buffer consists of 1 sample
    m_inputBuffer[0] = inputSample;
    //up samples the input buffer one time
    upSample(m_inputBuffer, m_oversampledBuffer, 1);
    //filters at the nyquist frequency
    filter(m_oversampledBuffer, m_tempOverSampledBuffer, 1 ,0);
    //up samples again on the buffer
    upSample(m_tempOverSampledBuffer, m_oversampledBuffer, 2);
    //filter again
    filter(m_oversampledBuffer, m_tempOverSampledBuffer, 2, 1);
    //non linear process nerdt.
    //m_oversampledbuffer = effect(m_tempOversampledBuffer);
}

//Changed to give index in main, would run into issues giving 4 samples while method expects one.
void Oversampler::setOverSampledBuffer(float inputSample, int index) {
     m_oversampledBuffer[index] = inputSample;
}
float Oversampler::getOverSampledBuffer(int index){
     return m_tempOverSampledBuffer[index];
}

float Oversampler::getOutputBuffer() {
   output();
   //outputbuffer should be 1 sample
  return m_outputBuffer[0];
}


void Oversampler::output(){
  //after non lieair process
  //donw sample first time
    downSample(m_tempDownSampledBuffer, m_oversampledBuffer, 2);

    filter(m_tempDownSampledBuffer, m_outputBuffer, 2, 2);

    downSample(m_tempDownSampledBuffer, m_outputBuffer, 1);

    filter(m_tempDownSampledBuffer, m_outputBuffer, 1, 3);
    //return outputbuffer

}

void Oversampler::initilizeFilters() {
    auto biquad = Biquad();
    for (auto i = 0; i < 4; i++){
      biquads.emplace_back (Biquad());
    }
    auto coefficients = biquad.makeLowPass(m_samplerate / 2.0, 1.0, m_samplerate * 2.0);
    biquads[0].setCoefficients(coefficients);
    biquads[3].setCoefficients(coefficients);
    auto coefficients2 = biquad.makeLowPass(m_samplerate / 2.0, 1.0, m_samplerate * 4.0);
    biquads[1].setCoefficients(coefficients2);
    biquads[2].setCoefficients(coefficients2);
    biquad.~Biquad();
}

void Oversampler::upSample(float* &inputBuffer, float* &oversampledBuffer, int numInputSamples ){
    for (auto i = 0; i < numInputSamples; ++i) {
        oversampledBuffer[i * 2] = inputBuffer[i];
        oversampledBuffer[i * 2 + 1] = 0.f;
    }
}
void Oversampler::downSample(float* &outputBuffer, float* &overSampledBuffer, int numOutputSamples ){
    for (int i = 0; i < numOutputSamples; ++i) {
      outputBuffer[i] = overSampledBuffer[i * 2];
    }
}

void Oversampler::filter(float* &overSampledBuffer, float* &tempOverSampledBuffer, int numInputSamples, int numFilter) {
    for (auto i = 0; i < numInputSamples; ++i) {
        tempOverSampledBuffer[i] = biquads[numFilter].output(overSampledBuffer[i]);
    }
}

