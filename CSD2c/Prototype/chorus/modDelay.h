#include "oscillator.h"
#include "circbuffer.h"

class ModDelay{
public:
    ModDelay(double samplerate);
    ~ModDelay();

    float output(float input);

    void modulateDelayTime();
    void setRate(float rate);

    uint msToSamps(float ms);

protected:
    double samplerate;
    float m_rate;
    float modOffset;
    float modDepth;
    float modSignal;

    CircBuffer* circ;
    Oscillator* osc;

};