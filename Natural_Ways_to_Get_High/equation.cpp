#include "Equation.h"

void Equation::equation(double a_val, double b_val, double c_val) {
    std::cout << std::endl << "----------------- Equation ax + b = 0 task  ------------------" << std::endl;

    std::cout << "Determine the solution of the first equation of the format ax + b = 0 given by unity, type to number please: " << std::endl;

    std::cin >> a_val;
    std::cin >> b_val;

    x = -(b_val / a_val);

    std::cout << "Solving the equation: " << x << std::endl;
}