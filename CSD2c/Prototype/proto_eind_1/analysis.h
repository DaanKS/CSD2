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
#include <atomic>

#pragma once

typedef unsigned int uint;

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
    inline void wrapHeader(uint& index){
        if(index >= bufferSize){
            index -= bufferSize;
        }
    }

    uint bufferSize;
    uint writeIndex;
    std::atomic<int> controlValue;

    float threshold;
    float* buffer;

    float xHis_1;
    float xHis_2;
    float xHis_3;
};


