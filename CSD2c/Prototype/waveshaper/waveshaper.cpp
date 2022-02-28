#include "waveshaper.h"

Waveshaper::Waveshaper(double samplerate){}
Waveshaper::~Waveshaper() = default

void Waveshaper::generateWaveTable(float* buffer, int bufferSize, float kValue){
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
