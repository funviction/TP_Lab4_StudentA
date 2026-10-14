#include "NumericalIntegration.h"
#include <cmath>
#include <stdexcept>

namespace NumericalIntegration {
    double rectangle(MathFunction f, double a, double b, int n) {
        if (n <= 0) throw std::invalid_argument("n must be > 0");
        double h = (b - a) / n;
        double sum = 0.0;
        for (int i = 0; i < n; ++i) {
            double x_mid = a + (i + 0.5) * h;
            sum += f(x_mid);
        }
        return sum * h;
    }

    double trapezoid(MathFunction f, double a, double b, int n) {
        if (n <= 0) throw std::invalid_argument("n must be > 0");
        double h = (b - a) / n;
        double sum = 0.5 * (f(a) + f(b));
        for (int i = 1; i < n; ++i) {
            sum += f(a + i * h);
        }
        return sum * h;
    }

    double simpson(MathFunction f, double a, double b, int n) {
        if (n <= 0) throw std::invalid_argument("n must be > 0");
        if (n % 2 != 0) n += 1;
        double h = (b - a) / n;
        double sum = f(a) + f(b);
        for (int i = 1; i < n; ++i) {
            double x = a + i * h;
            if (i % 2 == 0) sum += 2 * f(x);
            else sum += 4 * f(x);
        }
        return sum * (h / 3.0);
    }

    double integrationError(MathFunction f, double a, double b, int n, double (*method)(MathFunction, double, double, int), int p) {
        double I_n = method(f, a, b, n);
        double I_2n = method(f, a, b, 2 * n);
        return std::abs(I_2n - I_n) / (std::pow(2, p) - 1.0);
    }
}
