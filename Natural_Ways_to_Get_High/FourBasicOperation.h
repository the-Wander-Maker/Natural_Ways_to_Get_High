#pragma once
#include <iostream>

//A program read in two integers, then perform the four basic mathematical operations on them and write them out.

class FourBasicOperation {
public:
	FourBasicOperation() {
		//it is important to set it to double right at the beginning,
		//or the division will not return a fraction, even if the double is the decimal!
		std::cout << "Default constructor called." << std::endl;
		num_one = 0.0; 
		num_two = 0.0;
	}

	// Destructor
	~FourBasicOperation() {
		// Custom cleanup logic, if needed
		std::cout << "Destructor called." << std::endl;
		// No specific cleanup needed in this example
	}

	FourBasicOperation(double a_val, double b_val) {
		num_one = a_val;
		num_two = b_val;
	}

	void get_user_input();

private:
	double num_one = 0.0;
	double num_two = 0.0;
};