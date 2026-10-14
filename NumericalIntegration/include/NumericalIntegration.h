#ifndef NUMERICAL_INTEGRATION_H
#define NUMERICAL_INTEGRATION_H

#include <functional>

namespace NumericalIntegration {
    using MathFunction = std::function<double(double)>;

    double rectangle(MathFunction f, double a, double b, int n);
    double trapezoid(MathFunction f, double a, double b, int n);
    double simpson(MathFunction f, double a, double b, int n);
    double integrationError(MathFunction f, double a, double b, int n, double (*method)(MathFunction, double, double, int), int p);
}

#endif // NUMERICAL_INTEGRATION_H
