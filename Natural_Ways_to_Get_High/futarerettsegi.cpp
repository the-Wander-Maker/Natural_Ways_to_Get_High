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

    /* Írja ki a képernyõre, hogy mekkora volt a hét legelsõ útja kilométerben! Figyeljen arra,
        hogy olyan állomány esetén is helyes értéket adjon,
        amiben például a hét elsõ napján a futár nem dolgozott! */
    std::cout << std::endl << "2. task: " << std::endl << std::endl;

    std::cout << weaklyCouriages[0].kmDone << std::endl;

    // Írja ki a képernyõre, hogy mekkora volt a hét utolsó útja kilométerben!
    std::cout << std::endl << "3. task: " << std::endl << std::endl;

    std::cout << weaklyCouriages.back().kmDone << std::endl;

    // Tudjuk, hogy a futár minden héten tart legalább egy szabadnapot. Írja ki a képernyõre,
    // hogy a hét hányadik napjain nem dolgozott a futár!
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

    // Írja ki a képernyõre, hogy a hét melyik napján volt a legtöbb fuvar! Amennyiben több nap
    // is azonos, maximális számú fuvar volt, elegendõ ezek egyikét kiírnia.
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

    /*Számítsa ki és írja a képernyõre a mintának megfelelõen, hogy az egyes napokon hány
    kilométert kellett tekerni!
    1. nap: 124 km
    2. nap: 0 km
    3. nap: 75 km
    */
    //std::cout << std::endl << "6. feladat: " << std::endl << std::endl;

    std::cout << std::endl << "6. task: " << std::endl << std::endl;

    std::vector<int> days{ 0, 0, 0, 0, 0, 0, 0 };

    for (int i = 0; i < weaklyCouriages.size(); ++i) {
        days[weaklyCouriages[i].whichDay - 1] += weaklyCouriages[i].kmDone;
    }
    for (int i = 0; i < 7; ++i) {
        std::cout << i + 1 << ". day " << days[i] << " km" << std::endl;
    }

    /*A futár az egyes utakra az út hosszától függõen kap fizetést az alábbi táblázatnak
    megfelelõen:ll
    1 – 2 km 500 Ft
    3 – 5 km 700 Ft
    6 – 10 km 900 Ft
    11 – 20 km 1 400 Ft
    21 – 30 km 2 000 Ft
    Kérjen be a felhasználótól egy tetszõleges távolságot, és határozza meg, hogy mekkora
    díjazás jár érte! Ezt írja a képernyõre!*/
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


    /*Határozza meg az összes rögzített út ellenértékét! Ezeket az értékeket írja ki
    a dijazas.txt állományba nap szerint, azon belül pedig az út sorszáma szerinti
    növekvõ sorrendben az alábbi formátumban:
    1. nap 1. út: 700 Ft
    1. nap 2. út: 900 Ft
    1. nap 3. út: 2000 Ft
    …*/

    //TODO
    std::cout << std::endl << "8. task: " << std::endl << std::endl;

    // Create and open a text file
    std::ofstream MyFile("dijazas.txt");

    /* 1, 1, 3
     1, 2, 3
     1, 3, 1
     1, 4, 9
     1, 5, 5
     1, 6, 2 */
     // Write to the file
    MyFile << "Files can be tricky, but it is fun enough!";

    // Close the file
    MyFile.close();

    /*Határozza meg, és írja ki a képernyõre, hogy a futár mekkora összeget kap a heti
    munkájáért!*/
    std::cout << std::endl << "9. task: " << std::endl << std::endl;
}