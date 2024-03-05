#include "ConstructorTest.h"

void Test::constructorTestExec() {
    for (unsigned i = 0; i < 3; i++) {
        std::cout << "for beginning" << std::endl;
        Test test("test1");
        std::cout << "for middle" << std::endl;
        Test test2("test1-1");
        std::cout << "for end" << std::endl;
    }

    std::cout << "\n\n\n\n\n\n\n\n";


    Test test("test2");
    for (unsigned i = 0; i < 3; i++) {
        std::cout << "for" << std::endl;
    }
}