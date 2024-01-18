#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

// program létrehoz két tömböt, rendezi õket,
// majd egy harmadikba rendezetten összefûzi mindkettõt

class ContainersSort {
public:
	template <class T>
	void writeout(const std::vector<T>& vector);

	void bubblesort(std::vector<int>& vector);

	void quicksort(std::vector<int>& vector, int min, int max);

	void sortingProcedure();

private:
};

