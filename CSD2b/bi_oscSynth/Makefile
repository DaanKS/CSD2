CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++1z
LDFLAGS = -ljack
SOURCE = jack_module.o oscillator.o simplesynth.o sine.o bisynth.o synth.o main.o
TARGET = BiSynth

all: $(TARGET)

$(TARGET) : $(SOURCE)
				$(CC) -o $@ $(CFLAGS) $(SOURCE) $(LDFLAGS)

.cpp.o:
				$(CC) -c $< $(CFLAGS)

clean:
				rm -f *.o
				rm -f $(TARGET)
