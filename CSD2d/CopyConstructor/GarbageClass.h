//
// Created by Dean on 16/05/2022.
//
#include <cstring>
#include <cmath>
#include <iostream>

#pragma once

class GarbageClass {
public:
    GarbageClass();
    GarbageClass(double samplerate);
    ~GarbageClass();

/*
    GarbageClass(const GarbageClass& other) : bufferSize(other.bufferSize),
    buffer(new float[bufferSize]), m_samplerate(other.m_samplerate){
        std::cout << "Copy Constructor" << std::endl;
        ciska = other.ciska;
        marc = other.marc;
    } */

    void method();
    void method(float argument);
    float getValue(int index);

private:
    unsigned int bufferSize;
    float* buffer;

    double m_samplerate;
    float ciska;
    std::string marc;
};

