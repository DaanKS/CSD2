#include "waveshaper.h"

Waveshaper::Waveshaper(double samplerate): bufferSize(4096), kValue(10.0), m_drywet(0.0f) {
    mix = std::make_unique<Mix>();

    buffer = (float*)malloc(bufferSize * sizeof(float));
    memset(buffer, 0, bufferSize * sizeof(float));
}
Waveshaper::~Waveshaper(){
    free(buffer);
}

void Waveshaper::generateWaveTable(){
    //Thanks ciska
    float normalizeFactor = 1.0f / atan(kValue);
    for(int i = 0; i < bufferSize; i++) {
        // calculate s-curve with arctangent
        // calculate x in range [-1.0f, 1.0f]
        float x = mapInRange((float)i, 0, bufferSize, -1.0f, 1.0f);
        // formula: Pirkle 2013, "Designing Audio Effect Plug-ins in C++" p. 497
        buffer[i] = normalizeFactor * atan(kValue * x);
    }
}

float Waveshaper::output(float inputSample){
    float index = (inputSample + 1) * (bufferSize / 2.0);
    int i = (int) index;
    float indexDecimal = index - float(i);
    auto wetSample = linearMap(indexDecimal, buffer[i], buffer[i + 1]);
    return (wetSample * mix->getB(m_drywet)) + (inputSample * mix->getA(m_drywet));
}
float Waveshaper::mapInRange(float input, float xLow, float xHigh, float yLow, float yHigh){
    return ( yLow * (xHigh - input) + yHigh * (input - xLow)) / (xHigh - xLow);
}
float Waveshaper::linearMap(float input, float low, float high){
    return mapInRange(input, 0, 1, low, high);
}

void Waveshaper::setKvalue(float kValue){
    this->kValue = kValue;
}
void Waveshaper::setBufferSize(int bufferSize) {
    this->bufferSize = bufferSize;
    free(buffer);
    buffer = (float*)malloc(bufferSize * sizeof(float));
    memset(buffer, 0, bufferSize * sizeof(float));
}

void Waveshaper::setDryWet(float drywet) {
    this->m_drywet = drywet;
}