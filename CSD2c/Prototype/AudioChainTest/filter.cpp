#include "filter.h"

Filter::Filter(double samplerate) : m_samplerate(samplerate) {}
Filter::~Filter() = default;

uint Filter::msToSamples(float delayMS){
    return static_cast<uint>((delayMS * (m_samplerate / 1000.0)));
}