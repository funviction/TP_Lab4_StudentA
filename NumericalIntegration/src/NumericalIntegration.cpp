#include "NumericalIntegration.h"
#include <cmath>
#include <limits>
#include <algorithm>

static bool isValidInput(MathFunc f, double a, double b, int steps) {
    if (f == nullptr) return false;
    if (steps <= 0) return false;
    if (std::isnan(a) || std::isnan(b)) return false;
    return true;
}

double rectangle(MathFunc f, double a, double b, int steps) {
    if (!isValidInput(f, a, b, steps)) return std::numeric_limits<double>::quiet_NaN();
    double h = (b - a) / steps;
    double sum = 0.0;
    for (int i = 0; i < steps; ++i) {
        double x = a + (i + 0.5) * h;
        sum += f(x);
    }
    return sum * h;
}

double trapezoid(MathFunc f, double a, double b, int steps) {
    if (!isValidInput(f, a, b, steps)) return std::numeric_limits<double>::quiet_NaN();
    double h = (b - a) / steps;
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1; i < steps; ++i) {
        double x = a + i * h;
        sum += f(x);
    }
    return sum * h;
}

double simpson(MathFunc f, double a, double b, int steps) {
    if (!isValidInput(f, a, b, steps)) return std::numeric_limits<double>::quiet_NaN();
    if (steps % 2 != 0) steps++;
    double h = (b - a) / steps;
    double sum = f(a) + f(b);
    for (int i = 1; i < steps; ++i) {
        double x = a + i * h;
        if (i % 2 == 0) sum += 2.0 * f(x);
        else sum += 4.0 * f(x);
    }
    return sum * (h / 3.0);
}

double integrationError(double coarseValue, double fineValue, int orderOfAccuracy) {
    if (orderOfAccuracy <= 0) return std::numeric_limits<double>::quiet_NaN();
    double denominator = std::pow(2.0, orderOfAccuracy) - 1.0;
    return std::abs(fineValue - coarseValue) / denominator;
}
