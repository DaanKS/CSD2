#include "chorus.h"

Korus::Korus(double samplerate) : samplerate(samplerate) {
    circ_L = new CircBuffer(samplerate * 2.0);
    circ_R = new CircBuffer(samplerate * 2.0);

    sin_L = new Sine(samplerate);
    sin_L->setDelta(0.2);
    sin_R = new Sine(samplerate);
    sin_R->setDelta(0.25);
}
Korus::~Korus(){
    delete circ_L;
    circ_L = nullptr;
    delete circ_R;
    circ_R = nullptr;

    delete sin_L;
    sin_L = nullptr;
    delete sin_R;
    sin_R = nullptr;
}


