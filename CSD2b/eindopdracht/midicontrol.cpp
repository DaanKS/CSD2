#include "midicontrol.h"

Midicontrol::Midicontrol() : runningMidi(true){
  displayDevices();
  setDevices();
  midi_io.initialise();
  midi_io.set_input_filter(0);
}
Midicontrol::~Midicontrol(){}

void Midicontrol::startMidiListening(){
  std::cout << "Midicontrol = " << std::endl;
  while(true){
    event_read = midi_io.read_event(event);
    if(event_read){
      cmd=Pm_MessageData1(event.message);
    }
    else usleep(10000);

  }
}

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

int Midicontrol::getMidiNoteNumber(){
  return (int)cmd;
}
