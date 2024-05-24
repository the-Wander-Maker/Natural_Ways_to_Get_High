#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

// the program makes two vector, and sum them into a third one

class ContainersSort {
public:
	template <class T>
	void writeout(const std::vector<T>& vector);

	void bubblesort(std::vector<int>& vector);

	void quicksort(std::vector<int>& vector, int min, int max);

	void sortingProcedure();

private:
};

