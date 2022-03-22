CXX= g++
CXXFLAGS = -I/usr/local/include -Wall -std=c++1z
LDFLAGS= -ljack
SOURCE= energyDetect.o main.o
TARGET=cate

$(TARGET) : $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:a
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f $(TARGET) *.o
