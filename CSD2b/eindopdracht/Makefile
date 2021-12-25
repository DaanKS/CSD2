CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++1z
LDFLAGS = -L/usr/local/lib -lportmidi -lpthread -lm -llo -ljack
SOURCE = inputvalidation.o fmsynth.o history.o jack_module.o midi_io.o synth.o midicontrol.o mix.o oscillator.o onepole.o saw.o sine.o square.o subsynth.o userinput.o main.o
TARGET = synth.dexe

all: $(TARGET)

$(TARGET) : $(SOURCE)
				$(CC) -o $@ $(CFLAGS) $(SOURCE) $(LDFLAGS)

.cpp.o:
				$(CC) -c $< $(CFLAGS)

clean:
				rm -f *.o
				rm -f $(TARGET)
