#include "StringSwitch.h"

#include <iostream>
#include <string>


bool isCapital(const char karakter) {
	return (karakter >= 'A' && karakter <= 'Z');
}

bool isLower(const char karakter) {
	return (karakter >= 'a' && karakter <= 'z');
}

bool isWhitespace(const char karakter) {
	return karakter == ' ' || karakter == '\t';
}

void csere1(std::string& szoveg, const int mettol, const int meddig) {
	for (int i = mettol; i < meddig; i++) {
		if (isCapital(szoveg[i])) {
			szoveg[i] += 32;
		}
	}
}

void csere2(std::string& szoveg, const int mettol, const int meddig) {
	for (int i = mettol; i < meddig; i++) {
		if (isLower(szoveg[i])) {
			szoveg[i] -= 32;
		}
	}
}

void StringSwitch::stringSwitchExec() {
	std::string szoveg;
	std::cout << "Kerem a hasznalni kivant szoveget: " << std::endl;
	std::cin.ignore();
	std::getline(std::cin, szoveg);

	if (szoveg.empty()) {
		std::cout << "The text is empty. ERROR" << std::endl;
		return;
	}

	int elozoszovege = 0;
	char response;
	szoveg.push_back(' ');
	for (int i = 0; i < szoveg.length(); ++i) {
		if (isWhitespace(szoveg[i])) {
			if (i - elozoszovege != 1) {//valahogy ide be kell �gyeskedni a csere2-t, �s fel kell tudnia ismerni, hogy kicsi vagy nagybet�s-e a sz�
				std::cout << "Szeretne a szot kisbetusre cserelni? " << szoveg.substr(elozoszovege == 0 ? 0 : elozoszovege + 1, i - elozoszovege) << std::endl;
				std::cin >> response;
				//AZ ELEJE �S A V�GE NAGYON FONTOS �S NECCES!
				if (response == 'Y' || response == 'y') {
					csere1(szoveg, elozoszovege, i);
				}
			}
			//karbantart�s, tal�ltam egy �j sz�t, akkor az aktu�lis helyre kell ezt a v�ltoz�t dobni, vagy fogja mag�t �s ki�rogatja az eddigieket
			elozoszovege = i;
		}
	}

	std::cout << szoveg;
}