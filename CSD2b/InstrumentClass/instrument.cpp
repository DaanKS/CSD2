#include "instrument.h"

Instrument::Instrument(int instrumentType){ this->instrumentType = instrumentType;} Instrument::~Instrument(){} void Instrument::play(){ std::cout << sounds[instrumentType] <<std::endl;}
