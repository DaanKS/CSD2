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

    void setRateL(float rate);
    void setRateR(float rate);

    uint msToSamps(float ms);

private:
    double samplerate;
    float m_rateL;
    float m_rateR;
    float low = 0;
    float high = 10;

    CircBuffer* circ_L;
    CircBuffer* circ_R;

    Oscillator* sin_L;
    Oscillator* sin_R;
};