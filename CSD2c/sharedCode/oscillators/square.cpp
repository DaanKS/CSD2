#include "square.h"

Square::Square(double samplerate) : Oscillator(samplerate){}
Square::~Square(){}

double Square::calculate(){
    return phase >= 0.5f ? 1.0f : -1.0f;
}
