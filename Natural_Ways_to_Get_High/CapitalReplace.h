#pragma once

#include <iostream>
#include <string>


class CapitalReplace {
public:
	bool isCapital(const char karakter);
	bool isWhitespace(const char karakter);
	void swapper(std::string& szoveg, const int mettol, const int meddig);

	void capital_replace_process();

private:
};