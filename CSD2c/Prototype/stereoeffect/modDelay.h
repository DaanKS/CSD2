#include "sine.h"
#include "circbuffer.h"
//#include "squarelaw.h"

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
    float modOffset = 1;
    float modDepth = 5;
    float modSignal;
    float outputS = 0;

    CircBuffer* circ;
    Oscillator* osc;

};