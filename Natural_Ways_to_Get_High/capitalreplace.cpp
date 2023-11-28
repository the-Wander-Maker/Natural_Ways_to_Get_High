#include "CapitalReplace.h"
#include <stdexcept>

bool CapitalReplace::isCapital(const char karakter) {
	return (karakter >= 'A' && karakter <= 'Z');
}

bool CapitalReplace::isWhitespace(const char karakter) {
	return karakter == ' ' || karakter == '\t';
}

void CapitalReplace::swapper(std::string& szoveg, const int mettol, const int meddig) {
	for (int i = mettol; i < meddig; i++) {
		if (isCapital(szoveg[i])) {
			szoveg[i] += 32;
		}
	}
}

void CapitalReplace::capital_replace_process() {
	try {
		std::string input_text;
		std::cout << std::endl << "Please enter the text you wish to use for the capital letter replacement. Please enter all uppercase text: " << std::endl;
		
		// important to use this, because without it cin stores previous data, and that will cause problems with the getline
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

		
		std::getline(std::cin, input_text);

		if (input_text.empty()) {
			throw std::runtime_error("ERROR! The input text is empty!");
		}

		int previous_text = 0;
		char response;
		input_text.push_back(' ');
		for (int i = 0; i < input_text.length(); ++i) {
			if (isWhitespace(input_text[i])) {
				if (i - previous_text != 1) {
					std::cout << "Would you like to do the replacement process? Type Y,y if yes: " << input_text.substr(previous_text == 0 ? 0 : previous_text + 1, i - previous_text) << std::endl;
					std::cin >> response;
					if (response == 'Y' || response == 'y') {
						swapper(input_text, previous_text, i);
					}
				}
				//maintenance, I've found a new word, you have to drop this variable in the current location, or it will take itself and delete the previous one
				previous_text = i;
			}
		}
		std::cout << input_text;
	}
	catch (const std::exception& e) {
		// Catch and handle the exception
		std::cerr << "ERROR! The input text is empty!" << e.what() << std::endl;
	}
}