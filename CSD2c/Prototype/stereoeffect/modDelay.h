#include "sine.h"
#include "audioeffect.h"
#include "circbuffer.h"
#include "squarelaw.h"

class ModDelay : public AudioEffect{
public:
    ModDelay();
    ~ModDelay();

    float output(float input) override;
    void assignWave();

    void modulateDelayTime();
    void setRate(float rate);

    uint msToSamps(float ms);

protected:

    float m_rate;
    float modOffset = 1;
    float modDepth = 20;
    float modSignal;
    float outputS = 0;

    CircBuffer* circ;
    Oscillator* osc;

};