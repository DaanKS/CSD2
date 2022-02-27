#include "circbuffer.h"
#include "sine.h"

class Korus{
public:
    Korus(double samplerate);
    ~Korus();

    float outputL(float inputL);
    float outputR(float inputR);

    void modulateDelayTimeL();
    void modulateDelayTimeR();

    void setRateL(float rate) = 0;
    void setRateR(float rate) = 0;

    uint msToSamps(float ms);

private:
    double samplerate;
    float m_rateL;
    float m_rateR;
    float low = 5;
    float high = 95;

    CircBuffer* circ_L;
    CircBuffer* circ_R;

    Oscillator* sin_L;
    Oscillator* sin_R;
};