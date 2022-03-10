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

    float coefficient_1;
    float coefficient_2;
    std::cout << "enter first coefficient: ";
    std::cin >> coefficient_1;
    std::cout << "enter second coefficient: ";
    std::cin >> coefficient_2;

    std::cout << coefficient_1 << " * x[n] + " << coefficient_2 << " * x[n-1] " << std::endl;


    return 0;
}
