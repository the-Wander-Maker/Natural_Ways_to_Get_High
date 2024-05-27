#pragma once

// TODO refactor
struct carriageDatas {
    int whichDay;
    int numofCarriage;
    int kmDone;
};

class Courier {
public:
    Courier(){}
    ~Courier(){}

    void courierExec();
};
