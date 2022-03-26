#include "onepole.h"


Onepole::Onepole() : xHistory_1(0.0f){}
Onepole::Onepole(float cutoff) : xHistory_1(0.0f){

}
Onepole::~Onepole() = default;

float Onepole::output(float inputSample) {
    const auto [Aone, Atwo] = currentCoefficients.load();
    xHistory_1 = (Aone * inputSample) + (Atwo * xHistory_1);
    return xHistory_1;
}

void Onepole::setCoefficinets(OnepoleCoefficients coefficients) {
    currentCoefficients.store(coefficients);
}

OnepoleCoefficients Onepole::makeLowPass(float cutoff, float samplerate) noexcept {
    const auto omega = 2 * M_PI * (cutoff / samplerate);
    const auto y = 1 - cos(omega);
    return {
        .Aone = (-1 * y) + sqrt( pow(y , 2) + (2 * y) ),
        .Atwo = 1 - ((-1 * y) + sqrt( pow(y , 2) + (2 * y) ))
    };
}

OnepoleCoefficients Onepole::makeHighPass(float cutoff, float samplerate) noexcept {
    const auto omega = 2 * M_PI * (cutoff / samplerate);
    const auto y = 1 - cos(omega);
    return{
            .Aone = (-1 * y) + sqrt( pow(y , 2) + (2 * y) ),
            .Atwo = -1 * (1 - ((-1 * y) + sqrt( pow(y , 2) + (2 * y) )))
    };
}