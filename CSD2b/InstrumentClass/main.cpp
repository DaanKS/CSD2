#include "instrument.h"
#include <iostream>
#include <vector>
#include <cmath>

std::vector<Instrument>instruments; int main(){ for (int i = 0; i < 14; i++){ instruments.emplace_back(Instrument(i % 3));} for (auto& instr : instruments){instr.play();}return 0;}
