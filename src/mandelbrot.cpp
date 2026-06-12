#include "mandelbrot.hpp"
#include <complex>

int mandelbrot(double real, double imag, int maxIter) {
    std::complex<double> c(real, imag);
    std::complex<double> z(0.0, 0.0);

    int iter = 0;
    
    // While z doesn't go beyond the range of 2 for our max amount of iterations
    while(std::abs(z) <= 2.0 && iter < maxIter) {
        z = z * z + c;
        iter++;
    }

    return iter;
}
