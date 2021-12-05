CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++1z
# LDFLAGS= -ljack
SOURCE = musicdatabase.o musicplayer.o main.o

all: musicplayer

musicplayer : $(SOURCE)
				$(CC) -o $@ $(CFLAGS) $(SOURCE) # $(LDFLAGS)

.cpp.o:
				$(CC) -c $< $(CFLAGS)

clean:
				rm -f *.o
				rm -f musicplayer
