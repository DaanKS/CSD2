#include "datorro.h"
#include <iostream>

Datorro::Datorro(float samplerate) : m_dryWet(0.0), m_samplerate(samplerate) {
    mix = std::make_unique<Mix>();

    bandWidth = new Onepole(3000, m_samplerate);
    filters[0] = new Onepole(3000, m_samplerate);
    damping_1 = new Onepole(4000, m_samplerate);
    damping_2 = new Onepole(4000, m_samplerate);

    hiDamping_1 = new Onepole(m_samplerate);
    hiDamping_1->setCoefficinets(hiDamping_1->makeHighPass(200, m_samplerate));
    hiDamping_2 = new Onepole(m_samplerate);
    hiDamping_2->setCoefficinets(hiDamping_2->makeHighPass(200, m_samplerate));

    filters[1] = new Allpass(0.75, 210, m_samplerate);
    filters[2] = new Allpass(0.75, 158, m_samplerate);
    filters[3] = new Allpass(0.625, 561, m_samplerate);
    filters[4] = new Allpass(0.625, 410, m_samplerate);
    ap_5 = new Allpass(0.5, 3931, m_samplerate);
    ap_6 = new Allpass(0.5, 2664, m_samplerate);

    map_1 = new ModAllPass(0.7, 1343, m_samplerate, 0.1, 12);
    map_2 = new ModAllPass(0.7, 995, m_samplerate, 0.3, 12);

    fixed_1 = new FixedDelay(m_samplerate, 6241);
    fixed_2 = new FixedDelay(m_samplerate, 6590);
    fixed_3 = new FixedDelay(m_samplerate, 4641);
    fixed_4 = new FixedDelay(m_samplerate, 5505);
    predel = new FixedDelay(m_samplerate, 441);

    combL_1 = new Comb(m_samplerate, 110, 1.0, 0.0, m_samplerate);
    combL_2 = new Comb(m_samplerate, 160, 1.0, 0.0, m_samplerate);
    combL_3 = new Comb(m_samplerate, 50, 1.0, 0.0, m_samplerate);
    combL_4 = new Comb(m_samplerate, 25, 1.0, 0.0, m_samplerate);
    combL_5 = new Comb(m_samplerate, 69, 1.0, 0.0, m_samplerate);
    combL_6 = new Comb(m_samplerate, 80, 1.0, 0.0, m_samplerate);
    combL_7 = new Comb(m_samplerate, 75, 1.0, 0.0, m_samplerate);

    combR_1 = new Comb(m_samplerate, 110, 1.0, 0.0, m_samplerate);
    combR_2 = new Comb(m_samplerate, 135, 1.0, 0.0, m_samplerate);
    combR_3 = new Comb(m_samplerate, 55, 1.0, 0.0, m_samplerate);
    combR_4 = new Comb(m_samplerate, 3, 1.0, 0.0, m_samplerate);
    combR_5 = new Comb(m_samplerate, 35, 1.0, 0.0, m_samplerate);
    combR_6 = new Comb(m_samplerate, 27, 1.0, 0.0, m_samplerate);
    combR_7 = new Comb(m_samplerate, 52, 1.0, 0.0, m_samplerate);
}

Datorro::~Datorro() {

}



float Datorro::output(float inputSample) {
    earlyTempSample = filters[4]->output(filters[3]->output(filters[2]->output(filters[1]->output(filters[0]->output(predel->output(inputSample))))));
    return (earlyTempSample * mix->getB(m_dryWet)) + (inputSample * mix->getA(m_dryWet));
}

//Modulated AP, fixed delay, onepole filter, AP, fixed delay
float Datorro::outputL(float inputSample) {
    feedSampleL1 = map_1->output(inputSample + (feedSampleR6 * 0.35));
    feedSampleL2 = fixed_1->output(feedSampleL1);
    feedSampleL3 = damping_1->output(feedSampleL2);
    feedSampleL4 = ap_5->output(feedSampleL3);
    feedSampleL5 = fixed_3->output(feedSampleL4);
    feedSampleL6 = hiDamping_1->output(feedSampleL5);

    tempSample_1 = (combL_1->output(feedSampleL1) + combL_2->output(feedSampleL1) + combL_4->output(feedSampleL2) + ( -1 * (combL_3->output(feedSampleL4) + combL_5->output(feedSampleR1) + combL_6->output(feedSampleR4) + combL_7->output(feedSampleR3))) ) * 0.15;

    return (tempSample_1 * mix->getB(m_dryWet)) + (inputSample * mix->getA(m_dryWet));
    //return fixed_3->output(ap_5->output(damping_1->output(fixed_1->output(map_1->output(inputSample)))));
}
float Datorro::outputR(float inputSample) {
    feedSampleR1 = map_2->output(inputSample + (feedSampleL6 * 0.35));
    feedSampleR2 = fixed_2->output(feedSampleR1);
    feedSampleR3 = damping_2->output(feedSampleR2);
    feedSampleR4 = ap_6->output(feedSampleR3);
    feedSampleR5 = fixed_4->output(feedSampleR4);
    feedSampleR6 = hiDamping_2->output(feedSampleR5);

    tempSample_2 = (combR_1->output(feedSampleR1) + combR_2->output(feedSampleR1) + combR_4->output(feedSampleR2) + ( -1 * (combR_3->output(feedSampleR4) + combR_5->output(feedSampleL1) + combR_6->output(feedSampleL4) + combR_7->output(feedSampleL3))) ) * 0.15;

    return (tempSample_2 * mix->getB(m_dryWet)) + (inputSample * mix->getA(m_dryWet));
    //return fixed_4->output(ap_6->output(damping_2->output(fixed_2->output(map_2->output(inputSample)))));
}

void Datorro::setPreDelay(float preDelay) {
    predel->setDelayTime(preDelay);
}
void Datorro::setDryWet(float drywet) {
    this->m_dryWet = drywet;
}
