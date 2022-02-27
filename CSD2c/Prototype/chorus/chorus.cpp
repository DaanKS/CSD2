#include "chorus.h"

Korus::Korus(double samplerate) : samplerate(samplerate) {
    circ_L = new CircBuffer(samplerate * 2.0);
    circ_R = new CircBuffer(samplerate * 2.0);

    sin_L = new Sine(samplerate);
    sin_L->setDelta(1.0);
    sin_R = new Sine(samplerate);
    sin_R->setDelta(1.5);
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

float Korus::outputL(float inputL) {
    circ_L->writeToBuffer(inputL);
    circ_L->incrementIndeces();
    return circ_L->readFromBuffer();
}
void Korus::modulateDelayTimeL() {
    circ_L->setDelayTimeSamps(msToSamps(((sin_L->output() + 1) * 0.5 )* high + low ));
}
float Korus::outputR(float inputR) {
    circ_R->writeToBuffer(inputR);
    circ_R->incrementIndeces();
    return circ_R->readFromBuffer();
}
void Korus::modulateDelayTimeR() {
    circ_R->setDelayTimeSamps(msToSamps(((sin_R->output() + 1) * 0.5 )* high + low ));
}

uint Korus::msToSamps(float ms){
    //ms = (samplerate / 1000.0) / timeInSamples
    // using + 0.5 and then casting to uint for rounding
    return uint((ms * (samplerate / 1000.0)) + 0.5);
}