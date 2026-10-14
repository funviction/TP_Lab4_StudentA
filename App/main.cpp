#include <iostream>
#include <iomanip>
#include <cmath>
#include "NumericalIntegration.h"

double myFunction(double x) { return x * x; }

int main() {
    std::cout << "=== Numerical Integration DLL Test (C-ABI) ===\n";
    double a = 0.0, b = 3.0;
    int steps = 1000;
    double rectRes = rectangle(myFunction, a, b, steps);
    double trapRes = trapezoid(myFunction, a, b, steps);
    double simpRes = simpson(myFunction, a, b, steps);
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Rectangle method: " << rectRes << "\n";
    std::cout << "Trapezoid method: " << trapRes << "\n";
    std::cout << "Simpson method:   " << simpRes << "\n\n";
    std::cout << "=== Testing Edge Cases & Safety guarantees ===\n";
    double errNull = rectangle(nullptr, a, b, steps);
    double errSteps = trapezoid(myFunction, a, b, -10);
    std::cout << "Nullptr test result: " << errNull << " (Expected: nan)\n";
    std::cout << "Invalid steps test:  " << errSteps << " (Expected: nan)\n";
    return 0;
}
