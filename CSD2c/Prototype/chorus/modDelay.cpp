#include "modDelay.h"

ModDelay::ModDelay(double samplerate) : samplerate(samplerate) {
    circ = new CircBuffer(samplerate * 2);
    osc = new Sine(samplerate);
}
ModDelay::~ModDelay() {
    delete circ;
    circ = nullptr;
    delete osc;
    osc = nullptr;
}

float ModDelay::output(float input) {
    circ->writeToBuffer(input + (outputS * 0.8));
    outputS = circ->readFromBuffer();
    circ->incrementIndeces();
    modulateDelayTime();
    return outputS + input;
}
void ModDelay::modulateDelayTime() {
    modSignal = ((osc->output() + 1) * 0.5) * modDepth;
    circ->setDelayTimeSamps(msToSamps(modSignal + modOffset));
}

void ModDelay::setRate(float rate){
    m_rate = rate;
    osc->setDelta(m_rate);
}

uint ModDelay::msToSamps(float ms){
    //ms = (samplerate / 1000.0) / timeInSamples
    // using + 0.5 and then casting to uint for rounding
    return uint((ms * (samplerate / 1000.0)) + 0.5);
}
