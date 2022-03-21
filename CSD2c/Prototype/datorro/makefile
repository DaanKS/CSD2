CXX= g++
CXXFLAGS = -I/usr/local/include -Wall -std=c++20
LDFLAGS=-lportaudio -ljack
# the cpp files from the current project to include
SRC_PROJECT = allpass.cpp circbuffer.cpp modallpass.cpp onepole.cpp predelay.cpp comb.cpp datorro.cpp main.cpp
# the directory to the folder with the shared modules
SHAREDCODE_PATH = ../../../CSD2c/sharedCode/
# the modules to include
MODULES = oscillators utilities panners


# append shared code path prefix to modules
MODULE_PATHS = $(addprefix $(SHAREDCODE_PATH),$(MODULES))
# module .mk files
MODULE_MK = $(patsubst %,%/module.mk,$(MODULE_PATHS))
# include the description for each module
SRC_MODULES =
include $(MODULE_MK)
# create src list for all .cpp files
SRC = $(addprefix $(SHAREDCODE_PATH),$(SRC_MODULES))
SRC+= $(SRC_PROJECT)
# look for include files in
# each of the modules
CXXFLAGS += $(patsubst %,-I%,./$(MODULE_PATHS))
# determine the object files --> replace all .cpp in SRC with .o
OBJ := $(patsubst %.cpp,%.o, $(filter %.cpp,$(SRC)))
# log OBJ
$(info $$OBJ is [${OBJ}])

TARGET=test.cate
# link the program
$(TARGET):$(OBJ)
	$(CXX) -o $@ $(OBJ) $(LDFLAGS)

# -o $*.o --> write .o file to the directory of the current target
.cpp.o:
	$(CXX) -c $< $(CXXFLAGS) -o $*.o

clean:
	rm $(OBJ)
	rm $(TARGET)
