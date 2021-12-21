#include "midi_io.h"
#include <vector>
#include <iostream>

class Midicontrol{
public:
  Midicontrol();
  ~Midicontrol();

  int displayDevices();
  void setDevices();
  int receiveMessage();

protected:
  MIDI_io midi_io;
  PmEvent event;
  vector<PmEvent> eventlist;
  vector<PmEvent>::iterator event_iterator;
  int result;
  int device;

  int input_device=0,output_device=0;
};
