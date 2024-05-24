#include "GodrokErettsegi.h"


void GodrokErettsegi::godrokErettsegiExec() {
    //1. task Read in and store the melyseg.txt file data! Write to the screend that the file contains how many data.
    // Open file
    const std::string filename_godrok = "melyseg.txt";
    std::ifstream inputFile(filename_godrok);
    if (!inputFile.is_open()) {
        std::cout << "Can not open the input file: " << filename_godrok << std::endl;
        return;
    }

    // Data read in
    std::vector<unsigned char> datas;
    int x;
    while (inputFile >> x) {
        datas.push_back(static_cast<unsigned char>(x));
    }
    inputFile.close();

    // 1. task
    std::cout << "1. task" << std::endl;
    std::cout << "Number of datas in the input file: " << datas.size() << std::endl;

    // 2. task Read in a distance value and write to the screen how deep is the pit at that point. Use this value to task 6.
    std::cout << std::endl;
    std::cout << "2. task" << std::endl;

    int read_in_distance_temp;
    std::cin >> read_in_distance_temp;
    const int read_in_distance = read_in_distance_temp;

    std::cout << "At this place the pit is " << static_cast<int>(datas[read_in_distance - 1]) << " meter deep. " << std::endl;

    // 3. task Write to the screen that how many percent of the ground is untouched. 0.00 precise value is needed
    std::cout << std::endl;
    std::cout << "3. task" << std::endl;

    int count_zero = 0;
    for (int i = 0; i < datas.size(); i++) {
        if (datas[i] == 0) {
            count_zero++;
        }
    }

    float untouched_ground_percent = (static_cast<float>(count_zero) / static_cast<float>(datas.size())) * 100;
    std::cout << "The average of the untouched ground: " << std::fixed << std::setprecision(2) << static_cast<float>(untouched_ground_percent) << "% " << std::endl; // MATE: iomanipulációt kell csinálni, hogy a formázása az adatnak olyan legyen, amit elvárunk. Ilyenkor vagy Google, vagy cppref-en iomanip header-ben keresel.

    // 4. task Write into godrok.txt file the pits description, so all the numbers which describe ones pit deepness in meter.
    // All pits description should be written in one line. The file has to contain precisely the same amount of line than the pits number.
    std::cout << std::endl;
    std::cout << "4. task" << std::endl;

    const std::string filename2 = "godrok.txt";
    std::ofstream outputFile(filename2);
    if (!outputFile.is_open()) {
        std::cout << "Can not open the input file: " << filename2 << std::endl;
        return;
    }
    // Write out data
    std::ofstream ostrm(filename2);
    unsigned char prev_data = 0;
    for (auto data : datas) {
        if (data != 0) {
            ostrm << static_cast<int>(data) << " ";
        }
        if (prev_data != 0 && data == 0) {
            ostrm << std::endl;
        }
        prev_data = data;
    }

    //5. task
    std::cout << std::endl << "5. task" << std::endl;

    int number_of_pits = 0;
    prev_data = 0;
    for (int i = 0; i < datas.size(); i++) {
        if (prev_data != 0 && datas[i] == 0) {
            number_of_pits += 1;
        }
        prev_data = datas[i];
    }
    std::cout << "The number of pits: " << number_of_pits << std::endl;

    //6. task 
    //a.

    std::cout << std::endl << "6. task" << std::endl;
    std::cout << "a)" << std::endl;


    int start_of_pit = 0;
    int end_of_pit = 0;
    if (datas[read_in_distance - 1] == 0) {
        std::cout << "At the given place there is not any pit." << std::endl;
    }
    else {
        start_of_pit = read_in_distance;
        while (datas[start_of_pit - 1] != 0) {
            start_of_pit--;
        }

        end_of_pit = read_in_distance;
        while (datas[end_of_pit - 1] != 0) {
            end_of_pit++;
        }
        end_of_pit--;

        std::cout << "The start of the pit: " << (start_of_pit + 1) << " meter, the end of the pit: " << end_of_pit << " meter." << std::endl;

        //b.
        int max_deep = 0;
        for (int i = start_of_pit; i < end_of_pit; i++) {
            if (datas[i] > datas[max_deep]) {
                max_deep = i;
            }
        }

        // left, so closer to start
        int left = max_deep - 1;
        while (left >= start_of_pit && datas[left] >= datas[left + 1]) {
            left--;
        }

        int right = max_deep + 1;
        while (right <= end_of_pit && datas[right] >= datas[right - 1]) {
            right++;
        }
        std::cout << "b)" << std::endl;
        if (left == start_of_pit && right == end_of_pit) {
            std::cout << "Continously getting deeper.";
        }
        else {
            std::cout << "Not continously getting deeper.";
        }

        //c.
        std::cout << std::endl;
        std::cout << "c)" << std::endl;

        std::cout << "The lowest point in the pit a: " << max_deep << " at meter, the deepnes: " << static_cast<int>(datas[max_deep]) << " meter." << std::endl;

        //d.
        std::cout << std::endl;
        std::cout << "d)" << std::endl;

        int pit_volumetric_sum = 0;
        for (int i = start_of_pit; i < end_of_pit; i++) {
            pit_volumetric_sum += datas[i] * 10;
        }
        std::cout << "The volumetric is: " << pit_volumetric_sum << " m^3." << std::endl;

        //e.
        std::cout << std::endl;
        std::cout << "e)" << std::endl;


        int water_volumetric_sum = (end_of_pit - start_of_pit) * 10;
        std::cout << "The amount of water: " << pit_volumetric_sum - water_volumetric_sum << " m^3." << std::endl;
    }
}