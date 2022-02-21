#include <iostream>
#include "biquad.h"


int main() {
    float samplerate = 44100;
    Biquad biq(samplerate);

    biq.setCutoffFreq(500);
    biq.setQFactor(0.001);
    biq.calculateOmega();
    biq.calculateAlpha();
    biq.calculateCoefficients();

    float phase = 0;
    float delta = 500 / samplerate;
    float buffer[(int)samplerate];

    for(int i = 0; i < (int)samplerate; i++){
        phase += delta;
        if(phase > 1.0) phase -= 1.0;
        buffer[i] = phase >= 0.5 ? -1 : 1;
    }

    for(int i = 0; i < (int)samplerate; i++){
        std::cout << biq.output(buffer[i]) << std::endl;
    }

    return 0;
}
