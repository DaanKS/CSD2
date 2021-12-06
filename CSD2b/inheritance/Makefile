CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++1z
SOURCE = instrument.o keys.o blaas.o string.o main.o

all: Instrument

Instrument : $(SOURCE)
				$(CC) -o $@ $(CFLAGS) $(SOURCE)

.cpp.o:
				$(CC) -c $< $(CFLAGS)

clean:
				rm -f *.o
				rm -f Instrument
