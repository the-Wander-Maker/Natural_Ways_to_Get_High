#include "GodrokErettsegi.h"

// TODO Refactor

void GodrokErettsegi::godrokErettsegiExec() {
    //1.feladat Olvassa be és tárolja el a melyseg.txt fájl tartalmát! Írja ki a képernyõre, hogy az
    //adatforrás hány adatot tartalmaz!
    // A fájl megnyitása
    const std::string filename = "melyseg.txt";
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cout << "Nem sikerult megnyitni a fajlt: " << filename << std::endl;
        return;
    }

    // Adatok beolvasása
    std::vector<unsigned char> adatok;
    int x;
    while (inputFile >> x) {
        adatok.push_back(static_cast<unsigned char>(x));
    }
    inputFile.close();

    std::cout << "1.feladat" << std::endl;


    /*for (unsigned char i : adatok) {
        std::cout << static_cast<int>(i) << ' ';
    }*/
    std::cout << "A fajl adatainak a szama: " << adatok.size() << std::endl;

    //2. feladat Olvasson be egy távolságértéket, majd írja a képernyõre, hogy milyen mélyen van a gödör
    //alja azon a helyen!Ezt a távolságértéket használja majd a 6. feladat megoldása során is!

    std::cout << std::endl;
    std::cout << "2. feladat" << std::endl;


    int temp; // MATE: hülye egy változónév, fogalmam sincs, hogy mit tárolsz benne, ha nem nézem meg, hogy hol tárolsz el benne dolgot
    std::cout << "Adjon meg egy tavolsagerteket: ";
    std::cin >> temp;
    const int beolvasottTavolsag = temp;

    std::cout << "Ezen a helyen a felszin " << static_cast<int>(adatok[beolvasottTavolsag - 1]) << " meter melyen van. " << std::endl;

    //3.feladat Határozza meg, hogy a felszín hány százaléka maradt érintetlen és jelenítse meg 2 tizedes
    //pontossággal!

    std::cout << std::endl;
    std::cout << "3. feladat" << std::endl;


    int darabNulla = 0;
    for (int i = 0; i < adatok.size(); i++) {
        if (adatok[i] == 0) {
            darabNulla++;
        }
    }
    //std::cout << "Ennyi darab 0-as hely van: " << static_cast<int>(szazalekosszeg.size());
    float felszinszazalek = (static_cast<float>(darabNulla) / static_cast<float>(adatok.size())) * 100;
    std::cout << "Az erintetlen terulet aranya: " << std::fixed << std::setprecision(2) << static_cast<float>(felszinszazalek) << "% " << std::endl; // MATE: iomanipulációt kell csinálni, hogy a formázása az adatnak olyan legyen, amit elvárunk. Ilyenkor vagy Google, vagy cppref-en iomanip header-ben keresel.

    //4. feladat Írja ki a godrok.txt fájlba a gödrök leírását, azaz azokat a számsorokat, amelyek egy-egy
    // gödör méterenkénti mélységét adják meg!Minden gödör leírása külön sorba kerüljön!Az
    //  állomány pontosan a gödrök számával egyezõ számú sort tartalmazzon!

    // MATE: ez nem a feladat része. Azt mondja, hogy csak olyankor írj ki, amikor kell mit kiírni. A mintában sincs. Ilyenkor vagy kérdezz, hogy mit akar ezzel, vagy hagyjad ki, mert nem volt a spec-ben.

    const std::string filename2 = "godrok.txt";
    std::ofstream outputFile(filename2);
    if (!outputFile.is_open()) {
        std::cout << "Nem sikerult megnyitni a fajlt: " << filename2 << std::endl;
        return;
    }
    // Adatok kiírása
    std::ofstream ostrm(filename2);
    unsigned char elozoAdat = 0;
    for (auto adat : adatok) {
        if (adat != 0) {
            ostrm << static_cast<int>(adat) << " ";
        }
        if (elozoAdat != 0 && adat == 0) {
            ostrm << std::endl;
        }
        elozoAdat = adat;
    }

    //5. feladat
    std::cout << std::endl << "5. feladat" << std::endl;

    int darabGodrok = 0;
    elozoAdat = 0;
    for (int i = 0; i < adatok.size(); i++) {
        if (elozoAdat != 0 && adatok[i] == 0) {
            darabGodrok += 1;
        }
        elozoAdat = adatok[i];
    }
    std::cout << "A godrok szama: " << darabGodrok << std::endl;

    //6. feladat 
    //a.

    std::cout << std::endl << "6. feladat" << std::endl;
    std::cout << "a)" << std::endl;


    int start = 0; //ezekre késõbb még szükség lesz, azért itt deklarálom
    int end = 0;   // MATE: ez jó, de az elnevezés lehetne még erősebb, sok minden kezdődhet meg zárulhat
    if (adatok[beolvasottTavolsag - 1] == 0) {
        std::cout << "Az adott helyen nincs godor." << std::endl;
    }
    else {
        start = beolvasottTavolsag;
        while (adatok[start - 1] != 0) {
            start--;
        }

        end = beolvasottTavolsag;
        while (adatok[end - 1] != 0) {
            end++;
        }
        end--;

        std::cout << "A godor kezdete: " << (start + 1) << " meter, a godor vege : " << end << " meter." << std::endl;

        //b.
        int maxMely = 0;
        for (int i = start; i < end; i++) {
            if (adatok[i] > adatok[maxMely]) {
                maxMely = i;
            }
        }

        // balra, azaz a start fele
        int balra = maxMely - 1;
        while (balra >= start && adatok[balra] >= adatok[balra + 1]) {
            balra--;
        }

        int jobbra = maxMely + 1;
        while (jobbra <= end && adatok[jobbra] >= adatok[jobbra - 1]) {
            jobbra++;
        }
        std::cout << "b)" << std::endl;
        if (balra == start && jobbra == end) {
            std::cout << "Folyamatosan melyul.";
        }
        else {
            std::cout << "Nem melyul folyamatosan.";
        }

        //c.

        std::cout << std::endl;
        std::cout << "c)" << std::endl;

        std::cout << "A godor legnagyobb melysege a: " << maxMely << "-ik meternel van, melysege pedig: " << static_cast<int>(adatok[maxMely]) << " m." << std::endl;

        //d.
        /*Az elsõ gödör a 7. méteren kezdõdik. Az elsõ gödör 16 méter hosszan tart, legnagyobb
      mélysége 4 méter, térfogata 440 m3. A második gödör a 26. méternél kezdõdik, 3 méter hosszan
      tart, térfogata 60 m3.*/

        std::cout << std::endl;
        std::cout << "d)" << std::endl;


        //V = a x b x c

        int godorterfSum = 0;
        for (int i = start; i < end; i++) {
            godorterfSum += adatok[i] * 10;
        }
        std::cout << "A terfogata: " << godorterfSum << " m^3." << std::endl;

        //e. ki kell számolni az 1 méter mélyre esõ térfogatot, majd kivonni a már kiszámolt térfogatból

        std::cout << std::endl;
        std::cout << "e)" << std::endl;


        int vizterfSum = (end - start) * 10;
        std::cout << "A vizmennyiseg: " << godorterfSum - vizterfSum << " m^3." << std::endl;

        //int sum = std::accumulate(terfogat.begin(), terfogat.end(), 0);

        /*std::vector<char> path;
      // ...
      for (char i: path)
          std::cout << i << ' ';*/
          /* int sum = 1;
           for (int i : terfogat) {
               sum += terfogat[i-1];
           }*/
    }
}