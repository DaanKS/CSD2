//
// Created by Dean on 16/05/2022.
//
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>

#pragma once

class GarbageClass {
public:
    GarbageClass();
    GarbageClass(double samplerate);
    ~GarbageClass();

    /*
    GarbageClass(const GarbageClass& other) : bufferSize(other.bufferSize),
                                            buffer(new float[bufferSize]),
                                            m_samplerate(other.m_samplerate){
        std::copy(other.buffer, other.buffer + bufferSize, buffer);
        poep = other.poep;
        pis = other.pis;
    } */
    /*
    GarbageClass& operator = (const GarbageClass& other){
        bufferSize = other.bufferSize;
        delete[] buffer;
        buffer = new float [bufferSize];
        std::copy(other.buffer, other.buffer + bufferSize, buffer);
        poep = other.poep;
        pis = other.pis;
        return *this;
    } */

    void method();
    void method(float argument);
    float getValue(int index);

private:
    unsigned int bufferSize;
    float* buffer;

    double m_samplerate;
    float poep;
    std::string pis;
};

