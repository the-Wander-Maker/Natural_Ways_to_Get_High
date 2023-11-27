#pragma once
#include <iostream>

//Find the solution of the prime equation with coefficients ax + b = 0.

class Equation {
public:
    // Default constructor
    Equation() {
        // Custom initialization logic, if needed
        std::cout << "Default constructor called." << std::endl;
        a = 0.0;
        b = 0.0;
        x = 0.0;
    }

    // Parameterized constructor
    Equation(double number1, double number2, double number3) {
        // Custom initialization logic, if needed
        std::cout << "Parameterized constructor called." << std::endl;
        a = number1;
        b = number2;
        x = number3;
    }

    // Member function to perform some equation operation
    void equation(double a_val, double b_val, double c_val);

    // Destructor
    ~Equation() {
        // Custom cleanup logic, if needed
        std::cout << "Destructor called." << std::endl;
        // No specific cleanup needed in this example
    }

private:
    double a;
    double b;
    double x;
};
