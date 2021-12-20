#include "midi_io.h"

class Midicontrol{
public:
  Midicontrol();
  ~Midicontrol();

  int displayDevices();

protected:
  MIDI_io midi_io;  
};
