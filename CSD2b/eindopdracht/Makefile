CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++1z
LDFLAGS = -L/usr/local/lib -lportmidi -lpthread -lm -llo -ljack
SUBSYNTH = inputvalidation.o fmsynth.o history.o jack_module.o midi_io.o synth.o midicontrol.o mix.o oscillator.o onepole.o saw.o sine.o square.o subsynth.o userinput.o Submain.o
FMSYNTH = inputvalidation.o fmsynth.o history.o jack_module.o midi_io.o synth.o midicontrol.o mix.o oscillator.o onepole.o saw.o sine.o square.o subsynth.o userinput.o FMmain.o

all: fmsynth subsynth

subsynth : $(SUBSYNTH)
				$(CC) -o $@ $(CFLAGS) $(SUBSYNTH) $(LDFLAGS)

fmsynth : $(FMSYNTH)
				$(CC) -o $@ $(CFLAGS) $(FMSYNTH) $(LDFLAGS)

.cpp.o:
				$(CC) -c $< $(CFLAGS)

clean:
				rm -f *.o
				rm -f fmsynth subsynth
