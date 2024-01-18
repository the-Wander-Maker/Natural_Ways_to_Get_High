#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

// program l�trehoz k�t t�mb�t, rendezi �ket,
// majd egy harmadikba rendezetten �sszef�zi mindkett�t

class ContainersSort {
public:
	template <class T>
	void writeout(const std::vector<T>& vector);

	void bubblesort(std::vector<int>& vector);

	void quicksort(std::vector<int>& vector, int min, int max);

	void sortingProcedure();

private:
};

