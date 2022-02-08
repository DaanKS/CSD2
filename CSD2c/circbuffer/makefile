CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++1z
LDFLAGS = -L/usr/local/lib -lportmidi -lpthread -lm -llo -ljack
SOURCE = circbuffer.o main.o
TARGET = circbuffer.blanchette

all: $(TARGET)

$(TARGET) : $(SOURCE)
				$(CC) -o $@ $(CFLAGS) $(SOURCE) $(LDFLAGS)

.cpp.o:
				$(CC) -c $< $(CFLAGS)

clean:
				rm -f *.o
				rm -f $(TARGET)
