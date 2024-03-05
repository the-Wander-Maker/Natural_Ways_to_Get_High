#pragma once
#include <iostream>
#include <vector>


template <class T>
void kiir(const std::vector<T>& tomb) {
    for (int i = 0; i < tomb.size(); ++i) {
        std::cout << tomb[i] << " ";
    }
    std::cout << std::endl;
}

class VectorManager {
public:
	void vectorManagerExec();
private:
};