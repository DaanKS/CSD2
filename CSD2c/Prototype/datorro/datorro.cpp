#include "datorro.h"

Datorro::Datorro(float samplerate) : m_samplerate(samplerate)  {
    bandWidth = Onepole(0.5);
    damping_1 = Onepole(0.5);
    damping_2 = Onepole(0.5);

    ap_1 = Allpass(0.75, 210, m_samplerate);
    ap_2 = Allpass(0.75, 158, m_samplerate);
    ap_3 = Allpass(0.625, 561, m_samplerate);
    ap_4 = Allpass(0.625, 410, m_samplerate);
    ap_5 = Allpass(0.5, 3931, m_samplerate);
    ap_6 = Allpass(0.5, 2664, m_samplerate);

    map_1 = ModAllPass(0.7, 1343, m_samplerate, 0.01, 12);
    map_2 = ModAllPass(0.7, 995, m_samplerate, 0.03, 12);

    fixed_1 = PreDelay(m_samplerate, 6241);
    fixed_2 = PreDelay(m_samplerate, 6590);
    fixed_3 = PreDelay(m_samplerate, 4641);
    fixed_4 = PreDelay(m_samplerate, 5505);
    predel = PreDelay(m_samplerate, (m_samplerate / 1000.0));

}

Datorro::~Datorro() {}


float Datorro::output(float inputSample) {
    //Predelay - Onepole - 4 * allpass filter
   return ap_4.output(ap_3.output(ap_2.output(ap_1.output(bandWidth.output(predel.output(inputSample))))));
}
//Modulated AP, fixed delay, onepole filter, AP, fixe delay
float Datorro::outputL(float inputSample) {
    return fixed_3.output(ap_5.output(damping_1.output(fixed_1.output(map_1.output(inputSample)))));
}
float Datorro::outputR(float inputSample) {
    return fixed_4.output(ap_6.output(damping_2.output(fixed_2.output(map_2.output(inputSample)))));
}