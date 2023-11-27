#pragma once

#include <iostream>

class Exponentiation {
public:
	Exponentiation(){
		std::cout << "Default constructor called." << std::endl;
		number_1 = 0;
		number_2 = 0;
	}

	Exponentiation(int first_number, int second_number) {
		std::cout << "Parameterized constructor called." << std::endl;
		number_1 = first_number;
		number_2 = second_number;
	}

	~Exponentiation(){
		std::cout << "Destructor called." << std::endl;
	}
	
	unsigned long long int exponentiation(const int a, const int b);
	void run_exponentiation_procedure(int& num_1, int& num_2);

private:
	int number_1;
	int number_2;
};