#include "Crosswords.h"

void Crosswords::crosswordsExec() {
    // Input
    std::string words;
    std::getline(std::cin, words);

    // Splitting the input into two words
    size_t spacePos = words.find(' ');
    std::string word1 = words.substr(0, spacePos);
    std::string word2 = words.substr(spacePos + 1);

    // Finding the first matching character
    char commonChar = '\0';
    for (char ch : word1) {
        if (word2.find(ch) != std::string::npos) {
            commonChar = ch;
            break;
        }
    }

    // If no common character found, output and exit
    if (commonChar == '\0') {
        std::cout << "NO COMMON CHARACTER" << std::endl;
        return;
    }

    // Outputting the crossword
    transform(word1.begin(), word1.end(), word1.begin(), ::toupper);
    transform(word2.begin(), word2.end(), word2.begin(), ::toupper);

    // Outputting horizontally
    if (word1.find(commonChar) < word2.find(commonChar)) {
        std::cout << word2 << std::endl;
        for (char ch : word1) {
            std::cout << (ch == commonChar ? ' ' : ch) << ' ';
        }
        std::cout << std::endl;
    }
    else {
        for (char ch : word1) {
            std::cout << (ch == commonChar ? ' ' : ch) << ' ';
        }
        std::cout << std::endl;
        std::cout << word2 << std::endl;
    }
}