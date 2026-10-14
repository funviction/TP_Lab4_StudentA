#include <iostream>
#include <cmath>
#include <iomanip>
#include <windows.h>
typedef double (*MathFunc)(double);
typedef double (*DiffFunc)(MathFunc, double, double);
double cubeFunction(double x) { return x * x * x; }
int main() {
    HMODULE hLib = LoadLibraryA("NumericalDiff.dll");
    if (!hLib) { std::cerr << "Failed to load DLL\n"; return 1; }
    DiffFunc pForward = (DiffFunc)GetProcAddress(hLib, "forwardDifference");
    DiffFunc pBackward = (DiffFunc)GetProcAddress(hLib, "backwardDifference");
    DiffFunc pCentral = (DiffFunc)GetProcAddress(hLib, "centralDifference");
    DiffFunc pSecond = (DiffFunc)GetProcAddress(hLib, "secondDerivative");
    std::cout << std::fixed << std::setprecision(6);
    double x = 2.0; double h = 0.001;
    std::cout << "Forward Diff : " << pForward(cubeFunction, x, h) << "\n";
    std::cout << "Backward Diff: " << pBackward(cubeFunction, x, h) << "\n";
    std::cout << "Central Diff : " << pCentral(cubeFunction, x, h) << "\n";
    std::cout << "Second Deriv : " << pSecond(cubeFunction, x, h) << "\n";
    FreeLibrary(hLib);
    return 0;
}
