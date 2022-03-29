#include "waveshaper.h"

Waveshaper::Waveshaper(double samplerate): AudioEffect(samplerate),bufferSize(4096), kValue(10.0), m_drywet(0.0f), phase(0.0f) {
    mix = std::make_unique<Mix>();

    buffer = (float*)malloc(bufferSize * sizeof(float));
    memset(buffer, 0, bufferSize * sizeof(float));
    generateWaveTable();
}
Waveshaper::Waveshaper(double samplerate, float frequency): AudioEffect(samplerate), bufferSize(4096), kValue(10.0)
, m_drywet(0.0f), phase(0.0){
    mix = std::make_unique<Mix>();

    buffer = (float*)malloc(bufferSize * sizeof(float));
    memset(buffer, 0, bufferSize * sizeof(float));
    generateSawTable(frequency);
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
void Waveshaper::generateSawTable(float frequency) {
    //creates a wavetable with a saw wave with argument for frequency.
    const auto delta = frequency / m_samplerate;
    for(auto i = 0; i <bufferSize; i++) {
        phase += delta;
        if(phase >= 1.0) phase -= 1.0;
        buffer[i] = phase * 2.0 - 1.0;
    }
}

float Waveshaper::output(float inputSample){
    //Position in buffer is found by multiplying the unipolar (note not absolute) signal by the buffersize
    //The signal is not an int, so we use the truncated value to subtract a remainder from the original value
    //This remainder is then used to interpolate between the position in the buffer, and the next position.
    const auto tempSample = clipping(inputSample, 0.9f);
    const auto index = (tempSample + 1.0f) * (bufferSize / 2.0f);
    const auto i = static_cast<int>(index);
    const auto indexDecimal = index - static_cast<float>(i);
    const auto wetSample = linearMap(indexDecimal, buffer[i], buffer[i + 1]);
    return (wetSample * mix->getB(m_drywet)) + (inputSample * mix->getA(m_drywet));
}
//TODO make static class interpolation functions
float Waveshaper::mapInRange(float input, float xLow, float xHigh, float yLow, float yHigh){
    return ( yLow * (xHigh - input) + yHigh * (input - xLow)) / (xHigh - xLow);
}
float Waveshaper::linearMap(float input, float low, float high){
    return mapInRange(input, 0, 1, low, high);
}

void Waveshaper::setKvalue(float kValue){
    this->kValue = kValue;
    setBufferSize(bufferSize);
}
void Waveshaper::setBufferSize(int bufferSize) {
    this->bufferSize = bufferSize;
    free(buffer);
    buffer = (float *) malloc(bufferSize * sizeof(float));
    memset(buffer, 0, bufferSize * sizeof(float));
    //DEPRECATED -- With more wave options it is no longer useful to create an S-Curve automatically
    generateWaveTable();
}

void Waveshaper::setDryWet(float drywet) {
    this->m_drywet = drywet;
}

float Waveshaper::clipping(float inputSample, float c_threshold) {
    //Hardclipping function to prevent segmentation faults when reading from buffer
    if (inputSample >= c_threshold){
        return c_threshold;
    }else if (inputSample <= -c_threshold){
        return -c_threshold;
    } else {
        return inputSample;
    }
}