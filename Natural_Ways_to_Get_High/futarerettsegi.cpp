#include "FutarErettsegi.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <math.h>

void fileReading(std::ifstream& inputFile, const std::string& filename) {
    std::cout << "1. task: " << std::endl << std::endl;
    try {
        inputFile.open(filename);

        if (!inputFile.is_open()) {
            throw std::runtime_error("File could not be opened: ");
        }
    }
    catch (std::runtime_error) {
        std::cout << "File could not be opened: " << filename << std::endl;
    }

    std::cout << "File reading success" << std::endl;
}

void Courier::courierExec() {
    std::ifstream inputFile;
    fileReading(inputFile, "tavok.txt");

    std::vector<carriageDatas> weaklyCouriages;

    carriageDatas oneCouriage;

    while (!inputFile.eof()) {
        inputFile >> oneCouriage.whichDay >> oneCouriage.numofCarriage >> oneCouriage.kmDone;
        weaklyCouriages.push_back(oneCouriage);
    }

    carriageDatas swap;
    int min;
    for (int i = 0; i < (weaklyCouriages.size() - 1); ++i)
    {
        min = i;
        for (int j = i + 1; j < (weaklyCouriages.size()); ++j)
        {
            if ((weaklyCouriages[j].whichDay < weaklyCouriages[min].whichDay) || (weaklyCouriages[j].whichDay == weaklyCouriages[min].whichDay && weaklyCouriages[j].numofCarriage < weaklyCouriages[min].numofCarriage))
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap = weaklyCouriages[i];
            weaklyCouriages[i] = weaklyCouriages[min];
            weaklyCouriages[min] = swap;
        }

    }
    for (int i = 0; i < weaklyCouriages.size(); ++i) {
        std::cout << weaklyCouriages[i].whichDay << ", " << weaklyCouriages[i].numofCarriage << ", " << weaklyCouriages[i].kmDone << std::endl;
    }

    // 2. task
    std::cout << std::endl << "2. task: " << std::endl << std::endl;

    std::cout << weaklyCouriages[0].kmDone << std::endl;

    // 3. task
    std::cout << std::endl << "3. task: " << std::endl << std::endl;

    std::cout << weaklyCouriages.back().kmDone << std::endl;

    // 4. task
    std::cout << std::endl << "4. task: " << std::endl << std::endl;

    bool working[7] = { false, false, false, false, false, false, false };

    for (int i = 0; i < weaklyCouriages.size(); ++i) {
        working[weaklyCouriages[i].whichDay - 1] = true;
    }
    for (int i = 0; i < 7; ++i) {
        if (working[i] == false) {
            std::cout << i + 1 << std::endl;
        }
    }

    // 5. task
    std::cout << std::endl << "5. task: " << std::endl << std::endl;

    std::vector<int> couriagesMax;

    for (int i = 0; i < weaklyCouriages.size() - 1; ++i) {
        if (weaklyCouriages[i].whichDay != (weaklyCouriages[i + 1].whichDay)) {
            couriagesMax.push_back(weaklyCouriages[i].numofCarriage);
        }
    }
    couriagesMax.push_back(weaklyCouriages.back().numofCarriage);
    for (int i = 0; i < couriagesMax.size(); ++i) {
        std::cout << couriagesMax[i] << std::endl;
    }

    // 6. task
    std::cout << std::endl << "6. task: " << std::endl << std::endl;

    std::vector<int> days{ 0, 0, 0, 0, 0, 0, 0 };

    for (int i = 0; i < weaklyCouriages.size(); ++i) {
        days[weaklyCouriages[i].whichDay - 1] += weaklyCouriages[i].kmDone;
    }
    for (int i = 0; i < 7; ++i) {
        std::cout << i + 1 << ". day " << days[i] << " km" << std::endl;
    }

    // 7. task
    std::cout << std::endl << "7. task: " << std::endl << std::endl;

    std::cout << "Give an optional distance data: " << std::endl;

    int distance = 0;
    std::cin >> distance;
    std::cout << std::endl;

    if (1 <= distance && distance <= 2) {
        std::cout << "500 Ft" << std::endl;
    }
    else if (3 <= distance && distance <= 5) {
        std::cout << "700 Ft" << std::endl;
    }
    else if (6 <= distance && distance <= 10) {
        std::cout << "900 Ft" << std::endl;
    }
    else if (11 <= distance && distance <= 20) {
        std::cout << "1400 Ft" << std::endl;
    }
    else if (21 <= distance && distance <= 30) {
        std::cout << "2000 Ft" << std::endl;
    }


    // 8. task
    //TODO end the task
    std::cout << std::endl << "8. task: " << std::endl << std::endl;

    // Create and open a text file
    std::ofstream MyFile("dijazas.txt");


    MyFile << "Files can be tricky, but it is fun enough!";

    // Close the file
    MyFile.close();

    // 9. task
    std::cout << std::endl << "9. task: " << std::endl << std::endl;
}