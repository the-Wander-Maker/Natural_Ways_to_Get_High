#include "FutarErettsegi.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <math.h>

void fileReading(std::ifstream& inputFile, const std::string& filename) {
    std::cout << "1. feladat: " << std::endl << std::endl;
    try {
        inputFile.open(filename);

        if (!inputFile.is_open()) {
            throw std::runtime_error("File could not open: ");
        }
    }
    catch (std::runtime_error) {
        std::cout << "File could not open: " << filename << std::endl;
    }

    std::cout << "File reading success" << std::endl;
}

void Futar::futarExec() {
    std::ifstream inputFile;
    fileReading(inputFile, "tavok.txt");

    std::vector<fuvarAdatok> hetiFuvarok;

    fuvarAdatok egyFuvar;

    while (!inputFile.eof()) {
        inputFile >> egyFuvar.melyikNap >> egyFuvar.fuvarokSzama >> egyFuvar.megtettKm;
        hetiFuvarok.push_back(egyFuvar);
    }

    fuvarAdatok swap;
    int min;
    for (int i = 0; i < (hetiFuvarok.size() - 1); ++i)
    {
        min = i;
        for (int j = i + 1; j < (hetiFuvarok.size()); ++j)
        {
            if ((hetiFuvarok[j].melyikNap < hetiFuvarok[min].melyikNap) || (hetiFuvarok[j].melyikNap == hetiFuvarok[min].melyikNap && hetiFuvarok[j].fuvarokSzama < hetiFuvarok[min].fuvarokSzama))
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap = hetiFuvarok[i];
            hetiFuvarok[i] = hetiFuvarok[min];
            hetiFuvarok[min] = swap;
        }

    }
    for (int i = 0; i < hetiFuvarok.size(); ++i) {
        std::cout << hetiFuvarok[i].melyikNap << ", " << hetiFuvarok[i].fuvarokSzama << ", " << hetiFuvarok[i].megtettKm << std::endl;
    }

    /* Írja ki a képernyõre, hogy mekkora volt a hét legelsõ útja kilométerben! Figyeljen arra,
        hogy olyan állomány esetén is helyes értéket adjon,
        amiben például a hét elsõ napján a futár nem dolgozott! */
    std::cout << std::endl << "2. feladat: " << std::endl << std::endl;

    std::cout << hetiFuvarok[0].megtettKm << std::endl;

    // Írja ki a képernyõre, hogy mekkora volt a hét utolsó útja kilométerben!
    std::cout << std::endl << "3. feladat: " << std::endl << std::endl;

    std::cout << hetiFuvarok.back().megtettKm << std::endl;

    // Tudjuk, hogy a futár minden héten tart legalább egy szabadnapot. Írja ki a képernyõre,
    // hogy a hét hányadik napjain nem dolgozott a futár!
    std::cout << std::endl << "4. feladat: " << std::endl << std::endl;

    bool dolgozik[7] = { false, false, false, false, false, false, false };

    for (int i = 0; i < hetiFuvarok.size(); ++i) {
        dolgozik[hetiFuvarok[i].melyikNap - 1] = true;
    }
    for (int i = 0; i < 7; ++i) {
        if (dolgozik[i] == false) {
            std::cout << i + 1 << std::endl;
        }
    }

    // Írja ki a képernyõre, hogy a hét melyik napján volt a legtöbb fuvar! Amennyiben több nap
    // is azonos, maximális számú fuvar volt, elegendõ ezek egyikét kiírnia.
    std::cout << std::endl << "5. feladat: " << std::endl << std::endl;

    std::vector<int> fuvarokMax;

    for (int i = 0; i < hetiFuvarok.size() - 1; ++i) {
        if (hetiFuvarok[i].melyikNap != (hetiFuvarok[i + 1].melyikNap)) {
            fuvarokMax.push_back(hetiFuvarok[i].fuvarokSzama);
        }
    }
    fuvarokMax.push_back(hetiFuvarok.back().fuvarokSzama);
    for (int i = 0; i < fuvarokMax.size(); ++i) {
        std::cout << fuvarokMax[i] << std::endl;
    }

    /*Számítsa ki és írja a képernyõre a mintának megfelelõen, hogy az egyes napokon hány
    kilométert kellett tekerni!
    1. nap: 124 km
    2. nap: 0 km
    3. nap: 75 km
    */
    //std::cout << std::endl << "6. feladat: " << std::endl << std::endl;

    std::cout << std::endl << "6. feladat: " << std::endl << std::endl;

    std::vector<int> napok{ 0, 0, 0, 0, 0, 0, 0 };

    for (int i = 0; i < hetiFuvarok.size(); ++i) {
        napok[hetiFuvarok[i].melyikNap - 1] += hetiFuvarok[i].megtettKm;
    }
    for (int i = 0; i < 7; ++i) {
        std::cout << i + 1 << ". nap " << napok[i] << " km" << std::endl;
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
    std::cout << std::endl << "7. feladat: " << std::endl << std::endl;

    std::cout << "Adjon meg egy tetszoleges tavolsagot: " << std::endl;

    int tavolsag = 0;
    std::cin >> tavolsag;
    std::cout << std::endl;

    if (1 <= tavolsag && tavolsag <= 2) {
        std::cout << "500 Ft" << std::endl;
    }
    else if (3 <= tavolsag && tavolsag <= 5) {
        std::cout << "700 Ft" << std::endl;
    }
    else if (6 <= tavolsag && tavolsag <= 10) {
        std::cout << "900 Ft" << std::endl;
    }
    else if (11 <= tavolsag && tavolsag <= 20) {
        std::cout << "1400 Ft" << std::endl;
    }
    else if (21 <= tavolsag && tavolsag <= 30) {
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
    std::cout << std::endl << "8. feladat: " << std::endl << std::endl;

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
    std::cout << std::endl << "9. feladat: " << std::endl << std::endl;
}