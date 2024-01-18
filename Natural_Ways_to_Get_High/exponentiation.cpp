#include "Exponentiation.h"

unsigned long long int Exponentiation::exponentiation(const int a, const int b) {
	unsigned long long int result = 1UL;
	for (int i = 0; i < b; i++) {
		result *= a;
	}
	return result;
}

void Exponentiation::run_exponentiation_procedure(int& num_1, int& num_2) {
	std::cout << std::endl << "----------------- Exponentiation task ------------------" << std::endl;

	Exponentiation exponentiation;
	std::cout << std::endl << std::endl << "Please give me the first number for exponentiation: " << std::endl;
	std::cin >> num_1;
	std::cout << "Please give me the second number: " << std::endl;
	std::cin >> num_2;
	std::cout << "The result is: " << exponentiation.exponentiation(num_1, num_2) << std::endl;
}