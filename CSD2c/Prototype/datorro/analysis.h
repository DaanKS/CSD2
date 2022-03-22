//
/*
 * Analysis Class
 *
 * picks up audio and calculates the average amplitude (abs)
 * Returns 1 when below 1, and 0 when above 1
 *
 */
//
#include <iostream>

#pragma once

#define unsigned int uint

class Analysis{
public:
    Analysis();
    Analysis(uint bufferSize);
    ~Analysis();

    float returnControlValue();
    void takeAverage(float input);
    void allocateBuffer(uint bufferSize);
    void deleteBuffer();


private:
    //the following inline methods taken from circBuffer by Ciska Vriezenga
    inline void incrementWriteIndex(){
        writeIndex++;
        wrapHeader(writeIndex);
    }
    inline void wrapHeader(float& index){
        if(index >= m_size){
            index -= m_size;
        }
    }

    uint bufferSize;
    uint writeIndex;
    int controlValue;

    float threshold;
    float* buffer;

    float xHis_1;
    float xHis_2;
    float xHis_3;
};


