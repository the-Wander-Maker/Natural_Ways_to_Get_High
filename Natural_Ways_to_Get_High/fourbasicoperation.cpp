#include "FourBasicOperation.h"

void FourBasicOperation::get_user_input() {
    std::cout << std::endl << "Can you please enter two numbers?: " << std::endl;

    std::cin >> num_one;
    std::cin >> num_two;

    // Addition
    double sum = num_one + num_two;
    std::cout << "Total of the two numbers: " << sum << std::endl;

    // Subtraction
    double difference = (num_one > num_two) ? num_one - num_two : num_two - num_one;
    std::cout << "The difference between the two numbers: " << difference << std::endl;

    // Multiplication
    double multiplication = num_one * num_two;
    std::cout << "Multiplication of the two numbers: " << multiplication << std::endl;

    // Division
    if (num_two == 0) {
        std::cout << "You can't divide by zero. Please run the program again with a non-zero divisor." << std::endl;
    }
    else {
        double quotient = num_one / num_two;
        std::cout << "The result of the division (num_one / num_two): " << quotient << std::endl;
    }
}
