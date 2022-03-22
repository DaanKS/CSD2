#include <iostream>
#include "generator.h"
#ifndef EINDOPDRACHT_ENVELOPE_H
#define EINDOPDRACHT_ENVELOPE_H


class Envelope : public Generator{
public:
    Envelope(float inputBuffer[], int inputBufSize, int numberFx,
             int fxIndex, unsigned int samplerate);
    ~Envelope();
    float* getEnvelopes();

protected:
    float attackTime = 0;
    float decayTime = 0;
    float sustainAmp = 0;
    float releaseTime = 0;
    float millisToSamps(float millis);

private:
    unsigned  int samplerate;
};

#endif //EINDOPDRACHT_ENVELOPE_H
