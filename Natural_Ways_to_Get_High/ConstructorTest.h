#pragma once

#include <iostream>
#include <string>

class Test {
public:
    Test(){}

    Test(std::string txt) : _name(txt) {
        std::cout << "created " << txt << std::endl;
    }

    ~Test() {
        std::cout << "deleted " << _name << std::endl;
    }

    void constructorTestExec();

private:
    std::string _name;
};
