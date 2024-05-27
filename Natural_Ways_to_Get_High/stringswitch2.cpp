#include "StringSwitch2.h"

bool charequals(const char actual, const char searched) {
	return actual == searched;
}

bool stringequals(const std::string& text, const int position, const std::string& searched) {
	if (text.length() - searched.length() < position) {
		return false;
	}
	for (int i = 0; i < searched.length(); i++) {
		if (!charequals(text[position + i], searched[i])) {
			return false;
		}
	}
	return true;
}

void StringSwitch2::stringSwitch2Exec() {
	std::string text;
	std::string searched_text;
	std::string new_text;

	std::cout << "Please give the text you wish to use: ";
	std::getline(std::cin, text);

	std::cout << "Please give the character you are looking for: ";
	std::cin >> searched_text;

	std::cout << "Please give a new character to replace the one you looked for: ";
	std::cin >> new_text;

	int meret = text.length();
	for (int i = 0; i < meret; i++) {
		if (stringequals(text, i, searched_text)) {
			for (int k = 0; k < new_text.length(); k++) {
				text[i + k] = new_text[k];
			}
		}
	}
	std::cout << "The text modified by your wish is: " << text << std::endl;
}