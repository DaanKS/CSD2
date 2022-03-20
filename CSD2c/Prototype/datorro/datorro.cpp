#include "datorro.h"

Datorro::Datorro(float samplerate) : m_samplerate(samplerate)  {
    bandWidth = new Onepole();
    damping_1 = new Onepole();
    damping_2 = new Onepole();

    ap_1 = new Allpass(0.75, 210, m_samplerate);
    ap_2 = new Allpass(0.75, 158, m_samplerate);
    ap_3 = new Allpass(0.625, 561, m_samplerate);
    ap_4 = new Allpass(0.625, 410, m_samplerate);
    ap_5 = new Allpass(0.5, 3931, m_samplerate);
    ap_6 = new Allpass(0.5, 2664, m_samplerate);

    map_1 = new ModAllPass(0.7, 1343, m_samplerate, 0.01, 12);
    map_2 = new ModAllPass(0.7, 995, m_samplerate, 0.03, 12);

    fixed_1 = new PreDelay(m_samplerate, 6241);
    fixed_2 = new PreDelay(m_samplerate, 6590);
    fixed_3 = new PreDelay(m_samplerate, 4641);
    fixed_4 = new PreDelay(m_samplerate, 5505);
    predel = new PreDelay(m_samplerate, (m_samplerate / 1000.0));

}

Datorro::~Datorro() {}

