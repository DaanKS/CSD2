#include "midicontrol.h"

Midicontrol::Midicontrol(){
  midi_io.initialise();
}
Midicontrol::~Midicontrol(){}

int Midicontrol::displayDevices(){
  std::cout << "Available Devices: \n";
  return midi_io.list_devices();
}

void Midicontrol::setDevices(){
  std::cout << "Select Your Device: \n";

  std::cout << "Input: ";
  std::cin >> device;
  midi_io.set_input_device(device);

  std::cout << "Output: ";
  std::cin >> device;
  midi_io.set_output_device(device);
}

int Midicontrol::receiveMessage(){
  result = (int)Pm_MessageStatus(event.message)&0xf0;
  std::cout << "Message Received: " << result << std::endl;
  return result;
}
