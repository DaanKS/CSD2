#include "datorro.h"
#include <iostream>

Datorro::Datorro(float samplerate) : m_samplerate(samplerate)  {
    bandWidth = new Onepole(0.7);
    damping_1 = new Onepole(0.5);
    damping_2 = new Onepole(0.5);

    hiDamping_1 = new Highpass(0.9);
    hiDamping_2 = new Highpass(0.9);

    ap_1 = new Allpass(0.75, 210, m_samplerate);
    ap_2 = new Allpass(0.75, 158, m_samplerate);
    ap_3 = new Allpass(0.625, 561, m_samplerate);
    ap_4 = new Allpass(0.625, 410, m_samplerate);
    ap_5 = new Allpass(0.5, 3931, m_samplerate);
    ap_6 = new Allpass(0.5, 2664, m_samplerate);

    map_1 = new ModAllPass(0.7, 1343, m_samplerate, 0.1, 12);
    map_2 = new ModAllPass(0.7, 995, m_samplerate, 0.3, 12);

    fixed_1 = new PreDelay(m_samplerate, 6241);
    fixed_2 = new PreDelay(m_samplerate, 6590);
    fixed_3 = new PreDelay(m_samplerate, 4641);
    fixed_4 = new PreDelay(m_samplerate, 5505);
    predel = new PreDelay(m_samplerate, 441);

    combL_1 = new Comb(m_samplerate, 110, 1.0, 0.0);
    combL_2 = new Comb(m_samplerate, 160, 1.0, 0.0);
    combL_3 = new Comb(m_samplerate, 50, 1.0, 0.0);
    combL_4 = new Comb(m_samplerate, 25, 1.0, 0.0);
    combL_5 = new Comb(m_samplerate, 69, 1.0, 0.0);
    combL_6 = new Comb(m_samplerate, 80, 1.0, 0.0);
    combL_7 = new Comb(m_samplerate, 75, 1.0, 0.0);

    combR_1 = new Comb(m_samplerate, 110, 1.0, 0.0);
    combR_2 = new Comb(m_samplerate, 135, 1.0, 0.0);
    combR_3 = new Comb(m_samplerate, 55, 1.0, 0.0);
    combR_4 = new Comb(m_samplerate, 3, 1.0, 0.0);
    combR_5 = new Comb(m_samplerate, 35, 1.0, 0.0);
    combR_6 = new Comb(m_samplerate, 27, 1.0, 0.0);
    combR_7 = new Comb(m_samplerate, 52, 1.0, 0.0);

    std::cout << "\ndatorro constructor is a succes\n" << std::endl;

}

Datorro::~Datorro() {}



float Datorro::output(float inputSample) {
    //Predelay - Onepole - 4 * allpass filter
   return ap_4->output(ap_3->output(ap_2->output(ap_1->output(bandWidth->output(predel->output(inputSample))))));
}

//Modulated AP, fixed delay, onepole filter, AP, fixed delay
float Datorro::outputL(float inputSample) {
    feedSampleL1 = map_1->output(inputSample + (feedSampleR6 * 0.35));
    feedSampleL2 = fixed_1->output(feedSampleL1);
    feedSampleL3 = damping_1->output(feedSampleL2);
    feedSampleL4 = ap_5->output(feedSampleL3);
    feedSampleL5 = fixed_3->output(feedSampleL4);
    feedSampleL6 = hiDamping_1->output(feedSampleL5);

    return (combL_1->output(feedSampleL1) + combL_2->output(feedSampleL1) + combL_4->output(feedSampleL2) + ( -1 * (combL_3->output(feedSampleL4) + combL_5->output(feedSampleR1) + combL_6->output(feedSampleR4) + combL_7->output(feedSampleR3))) ) * 0.15;
    //return fixed_3->output(ap_5->output(damping_1->output(fixed_1->output(map_1->output(inputSample)))));
}
float Datorro::outputR(float inputSample) {
    feedSampleR1 = map_2->output(inputSample + (feedSampleL6 * 0.35));
    feedSampleR2 = fixed_2->output(feedSampleR1);
    feedSampleR3 = damping_2->output(feedSampleR2);
    feedSampleR4 = ap_6->output(feedSampleR3);
    feedSampleR5 = fixed_4->output(feedSampleR4);
    feedSampleR6 = hiDamping_2->output(feedSampleR5);

    return (combR_1->output(feedSampleR1) + combR_2->output(feedSampleR1) + combR_4->output(feedSampleR2) + ( -1 * (combR_3->output(feedSampleR4) + combR_5->output(feedSampleL1) + combR_6->output(feedSampleL4) + combR_7->output(feedSampleL3))) ) * 0.15;
    //return fixed_4->output(ap_6->output(damping_2->output(fixed_2->output(map_2->output(inputSample)))));
}