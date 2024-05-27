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

    /* �rja ki a k�perny�re, hogy mekkora volt a h�t legels� �tja kilom�terben! Figyeljen arra,
        hogy olyan �llom�ny eset�n is helyes �rt�ket adjon,
        amiben p�ld�ul a h�t els� napj�n a fut�r nem dolgozott! */
    std::cout << std::endl << "2. task: " << std::endl << std::endl;

    std::cout << weaklyCouriages[0].kmDone << std::endl;

    // �rja ki a k�perny�re, hogy mekkora volt a h�t utols� �tja kilom�terben!
    std::cout << std::endl << "3. task: " << std::endl << std::endl;

    std::cout << weaklyCouriages.back().kmDone << std::endl;

    // Tudjuk, hogy a fut�r minden h�ten tart legal�bb egy szabadnapot. �rja ki a k�perny�re,
    // hogy a h�t h�nyadik napjain nem dolgozott a fut�r!
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

    // �rja ki a k�perny�re, hogy a h�t melyik napj�n volt a legt�bb fuvar! Amennyiben t�bb nap
    // is azonos, maxim�lis sz�m� fuvar volt, elegend� ezek egyik�t ki�rnia.
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

    /*Sz�m�tsa ki �s �rja a k�perny�re a mint�nak megfelel�en, hogy az egyes napokon h�ny
    kilom�tert kellett tekerni!
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

    /*A fut�r az egyes utakra az �t hossz�t�l f�gg�en kap fizet�st az al�bbi t�bl�zatnak
    megfelel�en:ll
    1 � 2 km 500 Ft
    3 � 5 km 700 Ft
    6 � 10 km 900 Ft
    11 � 20 km 1 400 Ft
    21 � 30 km 2 000 Ft
    K�rjen be a felhaszn�l�t�l egy tetsz�leges t�vols�got, �s hat�rozza meg, hogy mekkora
    d�jaz�s j�r �rte! Ezt �rja a k�perny�re!*/
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


    /*Hat�rozza meg az �sszes r�gz�tett �t ellen�rt�k�t! Ezeket az �rt�keket �rja ki
    a dijazas.txt �llom�nyba nap szerint, azon bel�l pedig az �t sorsz�ma szerinti
    n�vekv� sorrendben az al�bbi form�tumban:
    1. nap 1. �t: 700 Ft
    1. nap 2. �t: 900 Ft
    1. nap 3. �t: 2000 Ft
    �*/

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

    /*Hat�rozza meg, �s �rja ki a k�perny�re, hogy a fut�r mekkora �sszeget kap a heti
    munk�j��rt!*/
    std::cout << std::endl << "9. task: " << std::endl << std::endl;
}