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

float Korus::outputL(float inputL) {
    circ_L->writeToBuffer(inputL);
    float output = circ_L->readFromBuffer() + inputL;
    circ_L->incrementIndeces();
    modulateDelayTimeL();
    return output;
}
void Korus::modulateDelayTimeL() {
    circ_L->setDelayTimeSamps(msToSamps(((sin_L->output() + 1) * 0.5 )* high + low ));
}
float Korus::outputR(float inputR) {
    circ_R->writeToBuffer(inputR);
    float output = circ_R->readFromBuffer() + inputR;
    circ_R->incrementIndeces();
    modulateDelayTimeR();
    return output;
}
void Korus::modulateDelayTimeR() {
    circ_R->setDelayTimeSamps(msToSamps(((sin_R->output() + 1) * 0.5 )* high + low ));
}

uint Korus::msToSamps(float ms){
    //ms = (samplerate / 1000.0) / timeInSamples
    // using + 0.5 and then casting to uint for rounding
    return uint((ms * (samplerate / 1000.0)) + 0.5);
}