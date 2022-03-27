//Base class for all filter objects (apart from biquad)

typedef unsigned int uint;

class Filter{
public:
    Filter(float samplerate);
    virtual ~Filter();

    virtual float output(float inputSample) = 0;

protected:
    inline float msToSamples(float delayMS){
        return static_cast<uint>((delayMS * (m_samplerate / 1000.0)));
    }
    float m_samplerate;
};