#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <random>

enum class Ako { becsi, budai, pesti };

class FunctionExcersises {
public:
	void		verses(int verse_num);
	void		poem(int verses_num, int versszaksorszam);
	void		swapppp(int& a, int& b);

	double		akochange(double liter);
	std::string monogram(std::string vezeteknev, std::string keresztnev);
	double		akochange2(double liter, Ako tipus);
	std::string verse();
	unsigned	fibonacci(const unsigned N);
	int			comparison(const int a, const int b);
	bool		is_divisor(int a, int b);
	bool		isPrime(int num);
	double		absValue(double num);
	bool		isEmpty(int num);
	bool		perfect(int szam);
	int			fakt(int n);

private:
};