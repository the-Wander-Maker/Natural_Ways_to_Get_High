#include <iostream>
#include "PrimeNum.h"


void PrimeNum::primeExec() {
	int p, d;
	bool isPrime;

	for (p = 2; p <= 100000; p++) {
		isPrime = true;
		for (d = 2; d < p; d++)
			if (p % d == 0)
				isPrime = false;
		if (isPrime == true)
			std::cout << p << std::endl;
	}
}