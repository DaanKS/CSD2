#include "midicontrol.h"

Midicontrol::Midicontrol() : runningMidi(true){
  displayDevices();
  setDevices();
  midi_io.initialise();
  midi_io.set_input_filter(0);
}
Midicontrol::~Midicontrol(){}

void Midicontrol::startMidiListening(){
  while(true){
    event_read = midi_io.read_event(event);
    if(event_read){
      //midi_io.write_event(&event); // copy to output
      cmd=(int)Pm_MessageStatus(event.message)&0xf0;
      std::cout << "Message Received : " << cmd << std::endl;
  /*    channel=Pm_MessageStatus(event.message)&0xf;
      data1=Pm_MessageData1(event.message);
      std::cout << (int) cmd << " " << (int) channel << " " << (int)
              data1 << " " << (int) data1 << endl;
      // only store note_on and note_off
      if(recording && (cmd == 0x90 || cmd == 0x80)) eventlist.push_back(event);
      if(cmd & 0x80) {
        std::cout << "Now recording\n";
	recording=true;
        midi_io.reset_timebase();
      }
      if(cmd == 0xb0 && data1 == 0x76) {
        std::cout << "Now recording\n";
	recording=true;
        midi_io.reset_timebase();
      }
      if(cmd == 0xb0 && data1 == 0x75) break;
      if(cmd == 0xb0 && data1 == 0x74) break;
      if(cmd == 0xb0 && data1 == 0x71){
        looping=true;
        break;
      } */
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

int Midicontrol::receiveMessage(){
  if(event_read){
    result = (int)Pm_MessageStatus(event.message)&0xf0;
    std::cout << "Message Received: " << result << std::endl;
    return result;
  }
  return -1;
}
