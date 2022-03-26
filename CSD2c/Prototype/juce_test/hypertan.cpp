#include "hypertan.h"

Hypertan::Hypertan() {
    std::cout << "made hypertan" << std::endl;
}
Hypertan::~Hypertan() = default;

float Hypertan::output(float inputSample) {
    return tanh(inputSample * 10);
}