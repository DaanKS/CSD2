#include "analysis.h"

Analysis::Analysis() {}
Analysis::Analysis(uint bufferSize) : bufferSize(bufferSize), writeIndex(0),
controlValue(1), threshold(0.9)
{
    allocateBuffer(bufferSize);
}

Analysis::~Analysis() {
   deleteBuffer()
}


float Analysis::returnControlValue() {
    //lowpass filter for signal smoothing
    // Y[n] = x[n] + x[n-1] + x[n-2] + x[n-3] / 4
    const float output = (static_cast<float>(controlValue) + xHis_1 + xHis_2 + xHis_3) / 4.0f;

    //RECACHING
    xHis_3 = xHis_2;
    xHis_2 = xHis_1;
    xHis_1 = controlValue;

    return output;
}

void Analysis::takeAverage(float input) {
    buffer[writeIndex] = input;
    const auto total = 0.0f;
    for(int i = 0; i < bufferSize; i++){
        total += abs(buffer[i]);
    }
    if(total / bufferSize >= threshold) {
        controlValue = 0;
    }else{
        controlValue = 1;
    }
}


void Analysis::allocateBuffer(int bufferSize) {
    buffer = (float*)malloc(bufferSize * sizeof(float));
    memset(buffer, 0, bufferSize * sizeof(float));
}
void Analysis::deleteBuffer() {
    free(buffer);
}