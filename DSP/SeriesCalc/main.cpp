#include <iostream>
#include <cmath>
#include <complex>

int main() {
    std::cout << "\nHello, Motherfucker!" << std::endl;
    auto minimum = 0;
    auto maximum = 8;
    auto result = 0.0f;

    std::complex<double> complexResult(0.0, 0.0);
    std::complex<double> complexPi(M_PI, 0.0);
    std::complex<double> i(0.0, 1.0);
    std::complex<double> two(2.0, 0.0);
    std::complex<double> four(4.0, 0.0);
    std::complex<double> nn(0.0, 0.0);

    for(auto n = minimum; n < maximum; n++ ){
        //result += 2 * n;
        //result += cos(n - (M_PI / 2.0));
        nn.real(n);
        complexResult += (exp(i * nn * complexPi / four) + exp(-i * nn * complexPi / four) / two);
    }
    //std::cout << "\nThe Answer is: " << result << std::endl;
    std::cout << "\nThe Answer is: " << complexResult << std::endl;


    return 0;
}
