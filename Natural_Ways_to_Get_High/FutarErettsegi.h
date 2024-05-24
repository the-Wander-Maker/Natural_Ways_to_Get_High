#pragma once

// TODO refactor
struct fuvarAdatok {
    int melyikNap;
    int fuvarokSzama;
    int megtettKm;
};

class Futar {
public:
    Futar(){}
    ~Futar(){}

    void futarExec();
};
