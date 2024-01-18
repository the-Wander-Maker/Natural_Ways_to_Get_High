#include "ContainersSort.h"

template <class T>
void ContainersSort::writeout(const std::vector<T>& vector) {
	for (int i = 0; i < vector.size(); i++) {
		std::cout << vector[i] << " ";
	}
	std::cout << std::endl;
}


// buborékalgoritmus(buublesort)
void ContainersSort::bubblesort(std::vector<int>& vector) {
	for (int i = 1; i < vector.size(); i++) {
		int j = i - 1;
		while (j >= 0 && vector[j] > vector[j + 1]) {
			int k = vector[j];
			vector[j] = vector[j + 1];
			vector[j + 1] = k;
			j--;
		}
	}
}



// logaritmikus(quicksort) rendezéssel
void ContainersSort::quicksort(std::vector<int>& vector, int min, int max) {
	double vezer = vector[(min + max) / 2]; // vezérelem: középsõ
	int i = min, j = max;
	while (i <= j) {                  // válogatás
		while (vector[i] < vezer) ++i;
		while (vector[j] > vezer) --j;
		if (i <= j) {
			std::swap(i, j);
			++i;
			--j;
		}
	}

	if (min < j) quicksort(vector, min, j); // rekurzió
	if (i < max) quicksort(vector, i, max);
}

void ContainersSort::sortingProcedure() {
	std::cout << std::endl << "----------------- Containers Sort Task ------------------" << std::endl;

	std::vector<int> A1;
	std::vector<int> A2;
	std::random_device r;
	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist(1, 10);
	

	for (int i = 0; i < 10; i++) {
		A1.push_back(uniform_dist(e1));
	}

	for (int i = 0; i < 15; i++) {
		A2.push_back(uniform_dist(e1));
	}

	std::cout << "The A1 vector starts here: " << std::endl;
	writeout<int>(A1);

	std::cout << "The A2 vector starts here: " << std::endl;
	writeout<int>(A2);

	//std::sort(A1.begin(), A1.end()); C++ saját függvénye a rendezésre!
	//std::sort(A2.begin(), A2.end());

	bubblesort(A2);
	bubblesort(A1);

	std::cout << std::endl << "The A1 vector BUBBLESORTED starts here: " << std::endl;
	writeout<int>(A1);
	
	std::cout << "The A2 vector BUBBLESORTED starts here: " << std::endl;
	writeout<int>(A2);

	/*//Az A1 és A2 rendezett összefûzése egy A3 vektorba
	std::vector<int> A3;
	int k = 0;
	int l = 0;
	for (int i = 0; i < A1.size() + A2.size(); i++) {
		if (l >= A2.size() || A1[k] < A2[l]) {
			A3.push_back(A1[k]);
			k++;
		}
		else {
			A3.push_back(A2[l]);
			l++;
		}
	}
	std::cout << std::endl << "The A1 + A2 vectors BUBBLESORTED here: " << std::endl;
	kiir<int>(A3);
	std::cout << std::endl;

	//az elõzõ megvalósítható a c++ saját függvényeivel
	/*std::vector<int> A3(A1);
	A3.insert(A3.end(), A2.begin(), A2.end());

	kiir<int>(A3);

	std::cout << std::endl;
	*/


	//quicksort, logaritmikus
	std::vector<int> A4(A1);
	A4.insert(A4.end(), A2.begin(), A2.end());

	std::cout << "The A4 vector starts here: " << std::endl;
	writeout<int>(A4);

	std::cout << "The A4 vector QUICKSORTED starts here: " << std::endl;
	quicksort(A4, 0, A4.size() - 1);
	writeout<int>(A4);

	//std::sort
	std::vector<int> A5;
	std::uniform_int_distribution<int> uniform_dist2(1, 10000);

	for (int i = 0; i < 10; i++) {
		A5.push_back(uniform_dist2(e1));
	}

	for (int i = 0; i < 15
		; i++) {
		A5.push_back(uniform_dist2(e1));
	}


	std::cout << std::endl << "The A5 vector starts here: " << std::endl;


	if (A5.empty()) {
		std::cout << "hiba: nincs eleme A5-nek" << std::endl;
	}
	else {

		writeout<int>(A5);

		std::cout << "The A5 vector sorted with STD::SORT starts here: " << std::endl;
		std::sort(A5.begin(), A5.end());
		writeout<int>(A5);
	}
	system("pause");
}