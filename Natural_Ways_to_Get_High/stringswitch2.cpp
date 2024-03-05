#include "StringSwitch2.h"

bool charequals(const char aktualis, const char keresett) {
	return aktualis == keresett;
}

bool stringequals(const std::string& szoveg, const int pozicio, const std::string& keresett) {
	if (szoveg.length() - keresett.length() < pozicio) {
		return false;
	}
	for (int i = 0; i < keresett.length(); i++) {
		if (!charequals(szoveg[pozicio + i], keresett[i])) {
			return false;
		}
	}
	return true;
}

void StringSwitch2::stringSwitch2Exec() {
	std::string szoveg;
	std::string keresett;
	std::string ujszoveg;

	std::cout << "Kerlek add meg a hasznalni kivant szoveged: ";
	std::getline(std::cin, szoveg);

	std::cout << "Kerlek ird be a keresett karaktert: ";
	std::cin >> keresett;

	std::cout << "Adj meg egy uj karaktert a keresett helyere: ";
	std::cin >> ujszoveg;

	int meret = szoveg.length();
	for (int i = 0; i < meret; i++) {
		if (stringequals(szoveg, i, keresett)) {
			for (int k = 0; k < ujszoveg.length(); k++) {
				szoveg[i + k] = ujszoveg[k];
			}
		}
	}
	std::cout << "A keresed szerint modositott szoveg a kovetkezo: " << szoveg << std::endl;
}