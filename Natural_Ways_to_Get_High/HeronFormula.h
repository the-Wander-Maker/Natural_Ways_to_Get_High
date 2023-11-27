#pragma once

#include <iostream>
#include <cmath>

class HeronFormula {
public:
	HeronFormula(){
		std::cout << "Default constructor called." << std::endl;
	}
	~HeronFormula(){
		std::cout << "Destructor called." << std::endl;
	}

	void heron_formula_process();

private:
};