#include "RandomDice.h"
#include <iostream>
#include <random>

void RandomDice::randomDiceExec() {
    unsigned dobasosszes;
    std::cout << "Kerem adja meg a dobasok szamat!" << std::endl;
    std::cin >> dobasosszes;

    std::random_device r;

    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, 2);

    int feldobas;
    unsigned fejdarab = 0;
    unsigned irasdarab = 0;
    for (unsigned i = 0; i < dobasosszes; i++) {
        feldobas = uniform_dist(e1);
        if (feldobas == 1) {
            fejdarab++;
        }
        else {
            irasdarab += 1;
        }
    }

    std::cout << "Ennyiszer volt fej a dobas: " << fejdarab << '\n';
    std::cout << "Ennyiszer volt iras a dobas: " << irasdarab << '\n';

    std::cout << "A fejdobasok szazalekos aranya: " << (static_cast<double>(fejdarab) / dobasosszes) * 100 << "%" << std::endl;
    std::cout << "A irasdobasok szazalekos aranya: " << (static_cast<double>(irasdarab) / dobasosszes) * 100 << "%" << std::endl;
}