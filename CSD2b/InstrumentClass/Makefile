CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++1z
# LDFLAGS= -ljack

all: instrument

instrument : instrument.o main.o
				$(CC) -o $@ $(CFLAGS) instrument.o main.o # $(LDFLAGS)

.cpp.o:
				$(CC) -c $< $(CFLAGS)

clean:
				rm -f *.o
				rm -f instrumentClass
