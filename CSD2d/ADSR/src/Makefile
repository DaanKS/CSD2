CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++1z
LDFLAGS= -ljack

all: example

example : HardClip.o clock.o envelope.o generator.o oscillator.o sine.o synthesizer.o jack_module.o main.o
				$(CC) -o $@ $(CFLAGS) HardClip.o clock.o envelope.o generator.o oscillator.o sine.o synthesizer.o jack_module.o main.o $(LDFLAGS)

.cpp.o:
				$(CC) -c $< $(CFLAGS)

clean:
				rm -f *.o
				rm -f example
