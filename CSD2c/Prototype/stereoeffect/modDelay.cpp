#include "modDelay.h"

ModDelay::ModDelay() : AudioEffect() {

}
ModDelay::~ModDelay() {
    delete circ;
    circ = nullptr;
    delete osc;
    osc = nullptr;
}
void ModDelay::assignWave() { //TODO -- RENAME TO INITIALIZE
    circ = new CircBuffer(samplerate * 2);
    osc = new Sine(samplerate);
}

float ModDelay::output(float input) {
    circ->writeToBuffer(input + (outputS * 0.1));
    outputS = circ->readFromBuffer();
    circ->incrementIndeces();
    modulateDelayTime();
    return outputS + input;
}
void ModDelay::modulateDelayTime() {
    //TODO -- ADD INTERPOLATION
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
    return (ms * (samplerate / 1000.0));
}
