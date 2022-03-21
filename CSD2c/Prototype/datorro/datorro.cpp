#include "datorro.h"
#include <iostream>

Datorro::Datorro(float samplerate) : m_samplerate(samplerate)  {
    std::cout << "Datorro Constructor" << std::endl;
    bandWidth = Onepole(0.5);
    std::cout << "1" << std::endl;
    damping_1 = Onepole(0.5);
    std::cout << "2" << std::endl;
    damping_2 = Onepole(0.5);
    std::cout << "3" << std::endl;

    ap_1 = Allpass(0.75, 210, m_samplerate);
    std::cout << "4" << std::endl;
    ap_2 = Allpass(0.75, 158, m_samplerate);
    std::cout << "5" << std::endl;
    ap_3 = Allpass(0.625, 561, m_samplerate);
    std::cout << "6" << std::endl;
    ap_4 = Allpass(0.625, 410, m_samplerate);
    std::cout << "7" << std::endl;
    ap_5 = Allpass(0.5, 3931, m_samplerate);
    std::cout << "8" << std::endl;
    ap_6 = Allpass(0.5, 2664, m_samplerate);
    std::cout << "9" << std::endl;

    map_1 = ModAllPass(0.7, 1343, m_samplerate, 0.01, 12);
    std::cout << "10" << std::endl;
    map_2 = ModAllPass(0.7, 995, m_samplerate, 0.03, 12);
    std::cout << "11" << std::endl;

    fixed_1 = PreDelay(m_samplerate, 6241);
    std::cout << "12" << std::endl;
    fixed_2 = PreDelay(m_samplerate, 6590);
    std::cout << "13" << std::endl;
    fixed_3 = PreDelay(m_samplerate, 4641);
    std::cout << "14" << std::endl;
    fixed_4 = PreDelay(m_samplerate, 5505);
    std::cout << "15" << std::endl;
    predel = PreDelay(m_samplerate, (m_samplerate / 1000.0));
    std::cout << "16" << std::endl;

    std::cout << "\nif count to 16 then datorro constructor is a succes\n" << std::endl;

}

Datorro::~Datorro() {}


float Datorro::output(float inputSample) {
    std::cout << "output" << std::endl;
    //Predelay - Onepole - 4 * allpass filter
   return ap_4.output(ap_3.output(ap_2.output(ap_1.output(bandWidth.output(predel.output(inputSample))))));
}
//Modulated AP, fixed delay, onepole filter, AP, fixe delay
float Datorro::outputL(float inputSample) {
    std::cout << "outputL" << std::endl;
    return fixed_3.output(ap_5.output(damping_1.output(fixed_1.output(map_1.output(inputSample)))));
}
float Datorro::outputR(float inputSample) {
    std::cout << "outputR" << std::endl;
    return fixed_4.output(ap_6.output(damping_2.output(fixed_2.output(map_2.output(inputSample)))));
}