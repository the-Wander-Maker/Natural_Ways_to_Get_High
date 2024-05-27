#include "RandomDice.h"
#include <iostream>
#include <random>

void RandomDice::randomDiceExec() {
    unsigned cointoss_sum;
    std::cout << "Please give the number of flings: " << std::endl;
    std::cin >> cointoss_sum;

    std::random_device r;

    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, 2);

    int cointoss;
    unsigned head_count = 0;
    unsigned tail_count = 0;
    for (unsigned i = 0; i < cointoss_sum; i++) {
        cointoss = uniform_dist(e1);
        if (cointoss == 1) {
            head_count++;
        }
        else {
            tail_count += 1;
        }
    }

    std::cout << "The number of head flings : " << head_count << '\n';
    std::cout << "The number of tail flings : " << tail_count << '\n';

    std::cout << "Coindtoss head in percentage : " << (static_cast<double>(head_count) / cointoss_sum) * 100 << "%" << std::endl;
    std::cout << "Cointoss tail in percentage : " << (static_cast<double>(tail_count) / cointoss_sum) * 100 << "%" << std::endl;
}