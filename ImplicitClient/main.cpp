#include <iostream>
#include <cmath>
#include <iomanip>
#include "NumericalDiff.h"
double cubeFunction(double x) { return x * x * x; }
double sineFunction(double x) { return std::sin(x); }
int main() {
    std::cout << std::fixed << std::setprecision(6);
    double x1 = 2.0; double h = 0.001;
    std::cout << "--- Testing f(x) = x^3 at x = " << x1 << "\n";
    std::cout << "Forward Diff : " << forwardDifference(cubeFunction, x1, h) << "\n";
    std::cout << "Backward Diff: " << backwardDifference(cubeFunction, x1, h) << "\n";
    std::cout << "Central Diff : " << centralDifference(cubeFunction, x1, h) << "\n";
    std::cout << "Second Deriv : " << secondDerivative(cubeFunction, x1, h) << "\n";
    double null_res = forwardDifference(nullptr, x1, h);
    std::cout << "nullptr test : " << null_res << "\n";
    return 0;
}
