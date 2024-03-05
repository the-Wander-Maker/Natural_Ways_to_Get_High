#include "VectorManager.h"
#include <random>
#include <algorithm>


void rendez(std::vector<int>& tomb) {
    for (long long i = 1; i < tomb.size(); ++i) {
        long long j = i - 1;
        while (j >= 0 && tomb[j] > tomb[j + 1]) {
            int k = tomb[j];
            tomb[j] = tomb[j + 1];
            tomb[j + 1] = k;
            j--;
        }
    }
}


void VectorManager::vectorManagerExec() {
    std::vector<int> A1;
    std::vector<int> A2;
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, 15);

    for (int i = 0; i < 10; ++i) {
        A1.push_back(uniform_dist(e1));
    }

    for (int i = 0; i < 15; ++i) {
        A2.push_back(uniform_dist(e1));
    }

    kiir<int>(A1);
    kiir<int>(A2);

    rendez(A1);
    rendez(A2);

    kiir<int>(A1);
    kiir<int>(A2);

    std::vector<int> A3;
    int k = 0;
    int l = 0;
    for (int i = 0; i < A1.size() + A2.size(); ++i) {
        if (k < A1.size() && (l >= A2.size() || A1[k] < A2[l])) {
            A3.push_back(A1[k]);
            ++k;
        }
        else {
            A3.push_back(A2[l]);
            ++l;
        }
    }
    kiir<int>(A3);
}