//
// Created by Dean on 16/05/2022.
//

#include "GarbageClass.h"

GarbageClass::GarbageClass() : bufferSize(5), buffer(new float[bufferSize]),
m_samplerate(4) {}
GarbageClass::GarbageClass(double samplerate) : bufferSize(5), buffer(new float[bufferSize]),
                                                m_samplerate(4) {}
GarbageClass::~GarbageClass() {
    free(buffer);
}


void GarbageClass::method(){
    std::cout << "Did the thing" << std::endl;
}

void GarbageClass::method(float argument) {
    auto value = 0;
    for(auto i = 0; i < bufferSize; i++){
        buffer[i] =  tanh(argument * i);
    }
}

float GarbageClass::getValue(int index) {
    return buffer[index];
}

