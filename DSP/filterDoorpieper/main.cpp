#include <iostream>
#include <complex>
#include <cmath>
#include <numbers>

int main() {
    std::cout << "\n\nWelcome! \n\n";

    //std::complex< float / double / long double> NAME (Real, Imaginary) -- Cartesian
     std::complex<float> complexNumber1  (2.0f, 5.0f);
     std::complex<double> complexNumber2  (complexNumber1);
     std::complex<long double> complexNumber3  (complexNumber2);
     std::cout << "Complex Number = " << complexNumber3 << std::endl;
     std::cout << "Complex Imaginary = " << complexNumber3.imag() << std::endl;
     std::cout << "Complex Real = " << complexNumber3.real() << std::endl;

    //std::polar(Magnitude , Angle) -- Polar to cartesian conversion
    std::cout << "The complex whose magnitude is " << 2.0;
    std::cout << " and phase angle is " << 0.5;
    std::cout << " is " << std::polar (2.0, 0.5) << '\n';

    std::cout << "pi: " << std::numbers::pi << std::endl;
    std::cout << "Euler's constant ^ 1: " << exp(1) << std::endl; //Euler's constant raised to the number inside the brackets
    std::cout << "Euler's constant ^ 0: " << exp(0) << std::endl;

    //Y[n] = (X[n] + X[n-1]) / 2.0
    //X[n] = e^(i * n * omega)
    //Y[n] = (e^(i * n * omega) + e^(i * (n - 1) * omega)) / 2.0
    //Y[n] = (e^(i * n * omega) + (e^(i * n * omega) * e^(-i * omega)) / 2)
    const std::complex<double> i(0.0, 1.0);
    const double Pie = std::numbers::pi; // pi = nyquist frequency
    for(int j = 0; j < 1001; j++){
        double omega = (j / 1000) * Pie;
        std::cout << "Index: " << j << " " << (exp(i * omega) + (exp(i * omega) * exp(-i * omega))) / 2.0 << std::endl;
    }



    return 0;
}
