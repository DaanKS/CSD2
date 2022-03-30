#include <iostream>
#include <complex>
#include <cmath>
#include <numbers>

int main() {
    std::cout << "\n\nWelcome! \n\n";

    /*
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

    */
    /*Y[n] = (X[n] + X[n-1]) / 2.0
    X[n] = e^(i * n * omega)
    Y[n] = (e^(i * n * omega) + e^(i * (n - 1) * omega)) / 2.0
    Y[n] = (e^(i * n * omega) + (e^(i * n * omega) * e^(-i * omega)) / 2)
        */

    const std::complex<double> i(0.0, 1.0);
    std::complex<double> coeff_1(0.0, 0.0);
    std::complex<double> coeff_2(0.0, 0.0);
    std::complex<double> coeff_3(0.0, 0.0);
    //const std::complex<double> o(1.0, 0.0);
    const double Pie = std::numbers::pi; // pi = nyquist frequency
    std::complex<double> H[1001];
    //auto numDelayLines = 2;
    auto tempValue = 0.0;
    auto running = true;

    while(running){
        std::cout << "Enter amount of delay lines / Press T for Pi in quarters: ";
        switch(std::cin.get()) {
            case 'q':
                running = false;
                break;
            case '2':
                std::cout << "Give the first coefficient: ";
                std::cin >> tempValue;
                coeff_1.real(tempValue);
                std::cout << "Give the second coefficient: ";
                std::cin >> tempValue;
                coeff_2.real(tempValue);

                for (int j = 0; j < 1001; j++) {
                    double omega = ((double) j / 1000.0) * (Pie);
                    H[j] = coeff_1 + (coeff_2 * exp(-i * omega));
                    std::cout << abs(H[j]) << std::endl;
                }
                break;
            case '3':
                std::cout << "Give the first coefficient: ";
                std::cin >> tempValue;
                coeff_1.real(tempValue);
                std::cout << "Give the second coefficient: ";
                std::cin >> tempValue;
                coeff_2.real(tempValue);
                std::cout << "Give the third coefficient: ";
                std::cin >> tempValue;
                coeff_3.real(tempValue);

                for (int j = 0; j < 1001; j++) {
                    double omega = ((double) j / 1000.0) * (Pie);
                    H[j] = coeff_1 + (coeff_2 * exp(-i * omega)) + (coeff_3 * exp(-i * 2.0 * omega));
                    std::cout << abs(H[j]) << std::endl;
                }
                break;
            case 'T':
                std::cout << "Give the first coefficient: ";
                std::cin >> tempValue;
                coeff_1.real(tempValue);
                std::cout << "Give the second Coefficient: ";
                std::cin >> tempValue;
                coeff_2.real(tempValue);
                std::complex<double>negativeTwo(-2.0, 0.0);

                for (int j = 0; j < 5; j++){
                    double omega = ((double) j / 4.0) * (Pie);
                    H[j] = coeff_1 + (coeff_2 * exp(negativeTwo * i * omega));
                    std::cout << abs(H[j]) << std::endl;
                }
                break;
        }
    }



    return 0;
}
