#include <iostream>
#include <iomanip>
#include <cmath>
#include "NumericalIntegration.h"

int main() {
    auto f = [](double x) { return x * x; };
    double a = 0.0, b = 3.0;
    int n = 10;
    double exact_value = 9.0;

    std::cout << "===================================================\n";
    std::cout << "  NUMERICAL INTEGRATION METHODS TESTING\n";
    std::cout << "  Function: f(x) = x^2 on [" << a << ", " << b << "]\n";
    std::cout << "  Exact value: " << exact_value << "\n";
    std::cout << "===================================================\n\n";

    double res_rect = NumericalIntegration::rectangle(f, a, b, n);
    double err_rect = NumericalIntegration::integrationError(f, a, b, n, NumericalIntegration::rectangle, 2);

    double res_trap = NumericalIntegration::trapezoid(f, a, b, n);
    double err_trap = NumericalIntegration::integrationError(f, a, b, n, NumericalIntegration::trapezoid, 2);

    double res_simp = NumericalIntegration::simpson(f, a, b, n);
    double err_simp = NumericalIntegration::integrationError(f, a, b, n, NumericalIntegration::simpson, 4);

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "1. Rectangle method (n=" << n << "):\n";
    std::cout << "   - Result:             " << res_rect << "\n";
    std::cout << "   - Absolute error:     " << std::abs(exact_value - res_rect) << "\n";
    std::cout << "   - Runge estimate:     " << err_rect << "\n\n";

    std::cout << "2. Trapezoid method (n=" << n << "):\n";
    std::cout << "   - Result:             " << res_trap << "\n";
    std::cout << "   - Absolute error:     " << std::abs(exact_value - res_trap) << "\n";
    std::cout << "   - Runge estimate:     " << err_trap << "\n\n";

    std::cout << "3. Simpson method (n=" << n << "):\n";
    std::cout << "   - Result:             " << res_simp << "\n";
    std::cout << "   - Absolute error:     " << std::abs(exact_value - res_simp) << "\n";
    std::cout << "   - Runge estimate:     " << err_simp << "\n";
    std::cout << "===================================================\n";
    return 0;
}
