#include "midicontrol.h"

Midicontrol::Midicontrol(){}
Midicontrol::~Midicontrol(){}

int Midicontrol::displayDevices(){
  return midi_io.list_devices();
}
