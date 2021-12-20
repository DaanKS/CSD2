#include "midicontrol.h"

Midicontrol::Midicontrol(){}
Midicontrol::~Midicontrol(){}

int Midicontrol::displayDevices(){
  std::cout << "Available Devices: \n";
  return midi_io.list_devices();
}

void Midicontrol::setDevices(){
  std::cout << "Select Your Device: \n";
  
  std::cout << "Input: ";
  std::cin >> int device;
  midi_io.set_input_device(device);

  std::cout << "Output: ";
  std::cin >> int device;
  midi_io.set_output_device(device);

}
