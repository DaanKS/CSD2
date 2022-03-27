#include "datorro.h"
#include <iostream>

Datorro::Datorro(float samplerate) : m_dryWet(-0.5), m_samplerate(samplerate) {
    mix = std::make_unique<Mix>();

    filters[0] = new Onepole(3000, m_samplerate);
    filters[7] = new Onepole(4000, m_samplerate);
    filters[8] = new Onepole(4000, m_samplerate);

    filters[11] = new Onepole(m_samplerate);
    ((Onepole*)filters[11])->setCoefficinets(hiDamping_1->makeHighPass(200, m_samplerate));
    filters[12] = new Onepole(m_samplerate);
    ((Onepole*)filters[12])->setCoefficinets(hiDamping_2->makeHighPass(200, m_samplerate));

    filters[1] = new Allpass(0.75, 210, m_samplerate);
    filters[2] = new Allpass(0.75, 158, m_samplerate);
    filters[3] = new Allpass(0.625, 561, m_samplerate);
    filters[4] = new Allpass(0.625, 410, m_samplerate);
    filters[9] = new Allpass(0.5, 3931, m_samplerate);
    filters[10] = new Allpass(0.5, 2664, m_samplerate);

    filters[5] = new ModAllPass(0.7, 1343, m_samplerate, 0.1, 12);
    filters[6] = new ModAllPass(0.7, 995, m_samplerate, 0.3, 12);

    fixed_1 = new FixedDelay(m_samplerate, 6241);
    fixed_2 = new FixedDelay(m_samplerate, 6590);
    fixed_3 = new FixedDelay(m_samplerate, 4641);
    fixed_4 = new FixedDelay(m_samplerate, 5505);
    predel = new FixedDelay(m_samplerate, 441);

    filters[13] = new Comb(m_samplerate, 110, 1.0, 0.0, m_samplerate);
    filters[14] = new Comb(m_samplerate, 160, 1.0, 0.0, m_samplerate);
    filters[15] = new Comb(m_samplerate, 50, 1.0, 0.0, m_samplerate);
    filters[16] = new Comb(m_samplerate, 25, 1.0, 0.0, m_samplerate);
    filters[17] = new Comb(m_samplerate, 69, 1.0, 0.0, m_samplerate);
    filters[18] = new Comb(m_samplerate, 80, 1.0, 0.0, m_samplerate);
    filters[19] = new Comb(m_samplerate, 75, 1.0, 0.0, m_samplerate);

    filters[20] = new Comb(m_samplerate, 110, 1.0, 0.0, m_samplerate);
    filters[21] = new Comb(m_samplerate, 135, 1.0, 0.0, m_samplerate);
    filters[22] = new Comb(m_samplerate, 55, 1.0, 0.0, m_samplerate);
    filters[23] = new Comb(m_samplerate, 3, 1.0, 0.0, m_samplerate);
    filters[24] = new Comb(m_samplerate, 35, 1.0, 0.0, m_samplerate);
    filters[25] = new Comb(m_samplerate, 27, 1.0, 0.0, m_samplerate);
    filters[26] = new Comb(m_samplerate, 52, 1.0, 0.0, m_samplerate);
}

Datorro::~Datorro() {
    for(auto i = 0; i < NUMFILTERS; i++){
        delete filters[i];
        filters[i] = nullptr;
    }
}



float Datorro::output(float inputSample) {
    earlyTempSample = filters[4]->output(filters[3]->output(filters[2]->output(filters[1]->output(filters[0]->output(predel->output(inputSample))))));
    return (earlyTempSample * mix->getB(m_dryWet)) + (inputSample * mix->getA(m_dryWet));
}

//Modulated AP, fixed delay, onepole filter, AP, fixed delay
float Datorro::outputL(float inputSample) {
    feedSampleL1 = filters[5]->output(inputSample + (feedSampleR6 * 0.35));
    feedSampleL2 = fixed_1->output(feedSampleL1);
    feedSampleL3 = filters[7]->output(feedSampleL2);
    feedSampleL4 = filters[9]->output(feedSampleL3);
    feedSampleL5 = fixed_3->output(feedSampleL4);
    feedSampleL6 = filters[11]->output(feedSampleL5);

    tempSample_1 = (filters[13]->output(feedSampleL1) + filters[14]->output(feedSampleL1) + filters[16]->output(feedSampleL2) + ( -1 * (filters[15]->output(feedSampleL4) + filters[17]->output(feedSampleR1) + filters[18]->output(feedSampleR4) + filters[19]->output(feedSampleR3))) ) * 0.15;

    return (tempSample_1 * mix->getB(m_dryWet)) + (inputSample * mix->getA(m_dryWet));
    //return fixed_3->output(ap_5->output(damping_1->output(fixed_1->output(map_1->output(inputSample)))));
}
float Datorro::outputR(float inputSample) {
    feedSampleR1 = filters[6]->output(inputSample + (feedSampleL6 * 0.35));
    feedSampleR2 = fixed_2->output(feedSampleR1);
    feedSampleR3 = filters[8]->output(feedSampleR2);
    feedSampleR4 = filters[10]->output(feedSampleR3);
    feedSampleR5 = fixed_4->output(feedSampleR4);
    feedSampleR6 = filters[12]->output(feedSampleR5);

    tempSample_2 = (filters[20]->output(feedSampleR1) + filters[21]->output(feedSampleR1) + filters[23]->output(feedSampleR2) + ( -1 * (filters[22]->output(feedSampleR4) + filters[24]->output(feedSampleL1) + filters[25]->output(feedSampleL4) + filters[26]->output(feedSampleL3))) ) * 0.15;

    return (tempSample_2 * mix->getB(m_dryWet)) + (inputSample * mix->getA(m_dryWet));
    //return fixed_4->output(ap_6->output(damping_2->output(fixed_2->output(map_2->output(inputSample)))));
}

void Datorro::setPreDelay(float preDelay) {
    predel->setDelayTime(preDelay);
}
void Datorro::setDryWet(float drywet) {
    this->m_dryWet = drywet;
}
