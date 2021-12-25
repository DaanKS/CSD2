#include "midicontrol.h"

Midicontrol::Midicontrol(){
  displayDevices();
  setDevices();
  midi_io.initialise();
  midi_io.set_input_filter(0);
}
Midicontrol::~Midicontrol(){}

void Midicontrol::startMidiListening(){
  listening = true;
  while(listening){
    event_read = midi_io.read_event(event);
    if(event_read){
      //filter out everything apart from noteOn
      unsigned char noteOn=Pm_MessageStatus(event.message)&0xf0;
      if((int)noteOn == 144){
        //midi note number
        cmd=Pm_MessageData1(event.message);
      }
    }
    else usleep(10000);
  }
}

void Midicontrol::switchOffListening(){
  this->listening = false;
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
