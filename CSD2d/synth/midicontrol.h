#include "midi_io.h"
#include <vector>
#include <iostream>

class Midicontrol{
public:
  Midicontrol();
  ~Midicontrol();

  void startMidiListening();
  void switchOffListening();

  int displayDevices();
  void setDevices();

  int getMidiNoteNumber();



protected:
  MIDI_io midi_io;
  PmEvent event;
  vector<PmEvent> eventlist;
  vector<PmEvent>::iterator event_iterator;
  int result;
  int device;
  bool event_read;
  bool listening;
  unsigned char cmd;

  int input_device=0,output_device=0;
};
