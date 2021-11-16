#include <iostream>
#include <cstring>

class Instrument{public:Instrument(int instrumentType);~Instrument();void play();private:int instrumentType;std::string sounds[3] = {"pwa", "fyo", "deng"};};
