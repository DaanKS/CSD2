#include "biquad.h"

class Bandpass : public Biquad{
public:
    Bandpass();
    ~Bandpass();

    void setBandWidth(float bandwidth);
    void calculateAlpha() override;

protected:
    void calculateBzero() override;
    void calculateBone() override;
    void calculateBtwo() override;
    void calculateAzero() override;
    void calculateAone() override;
    void calculateAtwo() override;

    float m_bandwidth;
};