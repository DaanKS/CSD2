#include "datorro.h"
#include <iostream>

Datorro::Datorro(float samplerate) : m_samplerate(samplerate)  {
    bandWidth = new Onepole(0.3);
    damping_1 = new Onepole(0.5);
    damping_2 = new Onepole(0.5);

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

    std::cout << "\nif count to 16 then datorro constructor is a succes\n" << std::endl;

}

Datorro::~Datorro() {}


float Datorro::output(float inputSample) {
    //Predelay - Onepole - 4 * allpass filter
   return ap_4->output(ap_3->output(ap_2->output(ap_1->output(bandWidth->output(predel->output(inputSample))))));
}
//Modulated AP, fixed delay, onepole filter, AP, fixe delay
float Datorro::outputL(float inputSample) {
    return fixed_3->output(ap_5->output(damping_1->output(fixed_1->output(map_1->output(inputSample)))));
}
float Datorro::outputR(float inputSample) {
    return fixed_4->output(ap_6->output(damping_2->output(fixed_2->output(map_2->output(inputSample)))));
}