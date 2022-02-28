#include "waveshaper.h"

Waveshaper::Waveshaper(double samplerate){}
Waveshaper::~Waveshaper() = default

void Waveshaper::generateWaveTable(float* buffer){
    //Thanks ciska
    float normalizeFactor = 1.0f / atan(k);
    for(int i = 0; i < bufferSize; i++) {
        // calculate s-curve with arctangent
        // calculate x in range [-1.0f, 1.0f]
        float x = map((float)i, 0, bufSize, -1.0f, 1.0f);
        // formula: Pirkle 2013, "Designing Audio Effect Plug-ins in C++" p. 497
        buffer[i] = normalizeFactor * atan(k * x);
    }
}

float Waveshaper::output(float inputSample){

}

float Waveshaper::mapInRange(float input, float xLow, float xHigh, float yLow, float yHigh){
    return ( yLow * (xHigh - input) + yHigh * (input - xLow)) / (xHigh - xLow);
}
float Waveshaper::linearMap(float input, float low, float high){
    return mapInRange(input, 0, 1, low, high);
}