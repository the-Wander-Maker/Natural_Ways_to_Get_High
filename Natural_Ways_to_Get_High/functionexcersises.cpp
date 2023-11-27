#include "FunctionExcersises.h"

/*1. Write a function, that can change liter into pesti akó.
pesti, pozsonyi akó: 53,72 liter (According to Pallas Lexicon 50,8 l)*/
double FunctionExcersises::akochange(double liter) {
	return liter * 53.72;
}


//2. Write a function, which getting a name as paramater returns its monogram!
std::string FunctionExcersises::monogram(std::string vezeteknev, std::string keresztnev) {
	return std::string() + vezeteknev.front() + keresztnev.front();
}


/*3. Wrinte a function, that can change into budai or pesti or bécsi akó, the caller of the function decide,
data can be found here: https://hu.wikipedia.org/wiki/Ak%C3%B3
If possible use enum.*/

double FunctionExcersises::akochange2(double liter, Ako tipus) {
	if (tipus == Ako::becsi) {
		return liter * 56.589;
	}
	else if (tipus == Ako::budai) {
		return liter * 58.6;
	}
	else {
		return liter * 53.72;
	}
}


/*4. On Vogon poetry from one of literature's now classic science fiction novels,
The Hitchhiker's Guide to the Galaxy.
If we want to delve into it, let's do so, but for now, that's all we need to know,
is that it's terrible. We'll be producing equally horrific poems with our next programme.
The lines of the poems always consist of an adjective, an object, a predicate,
and a punctuation mark at the end of a sentence ("We throw squeaky windows!", "We eat spherical well coffee?!")

a. Write a function called verse() without parameters,
that returns a line of verses, with the four parts of the sentence randomly chosen from four lists.

b. This function is called by another function called verse(). The parameter of verse() is a number,
which specifies the number of lines in the stanza. This function returns the entire stanza.

c. Our last function is called : verse(). Its first parameter is a number giving the number of verses,
the second is the number of lines per verse, returning the total verse.

d. Our poems show overflowing emotion, at least as indicated by the punctuation.
How can we very simply make the end of sentences end more often with a full stop ?

e. Challenging exercise : rewrite the function poem() to expect only a list as a parameter.
If the list is [2, 2, 4], then return a poem that consists of three stanzas, each stanza being 2, 2 and 4 lines long !*/

std::string FunctionExcersises::verse() {
	std::vector<std::string> adjective = { "Bubajos" , "Pompas", "Tragikus", "Kegyetlen", "Cuksi", "Omladozo", "Viragzo", "Sejtelmes", "Rettegett", "Szepseges" };
	std::vector<std::string> object = { "tanyert" , "teascseszet" , "kaparofat" , "mobiltokot" , "rozsalevelet" , "koralkotetet" , "fenykardot" , "cickafarkot" , "droidot" , "mokust" };
	std::vector<std::string> statement = { "eszunk", "dobalunk", "ragunk" , "olelunk" , "hoztal" , "elengedtem" , "mondom" , "lazitunk" , "kaparunk" , "festunk" };
	std::vector<std::string> punctuation = { "?", "." , "!!!" , " - ", ":", "!", "...", "--", "???", "....." };

	std::random_device r;

	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist(0, 9);
	std::string adjectiveword = adjective[uniform_dist(e1)];
	std::string objectword = object[uniform_dist(e1)];
	std::string statementword = statement[uniform_dist(e1)];
	std::string punctuationword = punctuation[uniform_dist(e1)];

	return adjectiveword + std::string(" ") + objectword + std::string(" ") + statementword + std::string(" ") + punctuationword;
}

void FunctionExcersises::verses(int verse_num) {
	for (int i = 0; i < verse_num; i++) {
		std::cout << verse();
		std::cout << std::endl;
	}
}

void FunctionExcersises::poem(int verses_num, int versszaksorszam) {
	for (int i = 0; i < verses_num; ++i) {
		for (int k = 0; k < versszaksorszam; ++k) {
			std::cout << verse();
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
}


//5. Prepare a procedure that swaps two int values!
void FunctionExcersises::swapppp(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}


/*6. Write a program to find the first n elements of a Fibonacci sequence (F1 : = 1; F2: = 1;
Fn: = Fn - 1)*/
unsigned FunctionExcersises::fibonacci(const unsigned N) {
	if (N == 1) {
		return 0;
	}
	else if (N == 2) {
		return 1;
	}
	else {
		return fibonacci(N - 1) + fibonacci(N - 2);
	}
}
/*Fibonacci(1) = 0
Fibonacci(2) = 1
Fibonacci(n) = Fibonacci(n-1) + Fibonacci(n-2)
i.e. the function Fibonacci(n) is sufficient if it calls itself for n-1 and n-2 and adds the two values returned
DE needs the stopping condition
and since both n-1 and n-2 are called at the same time, it can be seen that 2 conditions will be needed */


//7. Construct a function that returns the larger of two signed integers.
int FunctionExcersises::comparison(const int a, const int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}


//8. Write a function that checks whether the first parameter is the divisor of the second parameter.
bool FunctionExcersises::is_divisor(int a, int b) {
	if (a % b == 0) {
		return true;
	}
	else {
		return false;
	}
}


//9. Write a function that decides whether a number is prime or not. (It is enough to check up to the root of the number)
bool FunctionExcersises::isPrime(int num) {
	bool flag = true;
	for (int i = 2; i <= num / 2; i++) {
		if (num % i == 0) {
			flag = false;
			break;
		}
	}
	return flag;
}


//10. Write a function that returns the absolute value of a number.
double FunctionExcersises::absValue(double num) {
	if (num < 0) {
		return num * -1;
	}
	else {
		return num;
	}
}


/*11. Construct a function that determines whether a number is an incomplete number.
(It is incomplete if it is greater than the sum of its divisors. Divisor: 1 inclusive, excluding the number itself.)*/
bool FunctionExcersises::isEmpty(int num) {
	int divisor = 0;
	for (unsigned i = 1; i <= num / 2; i++) {
		if (num % i == 0) {
			divisor += i;
			/*std::cout << divisor;
			std::cout << " ";
			std::cout << num;*/
		}
	}
	return divisor < num;
}


/*12. Create a function that decides whether a number is a perfect number.
(It is perfect if it is exactly the sum of its divisors. Divisor: 1 inclusive, excluding the number itself.)*/
bool FunctionExcersises::perfect(int szam) {
	int divisor = 0;
	for (unsigned i = 1; i <= szam / 2; i++) {
		if (szam % i == 0) {
			divisor += i;
			/*std::cout << oszto;
			std::cout << " ";
			std::cout << szam;*/
		}
	}
	return divisor == szam;
}


//13. Create a function that calculates the factorial of a number.
int FunctionExcersises::fakt(int n) {
	int fakt = 1;

	for (unsigned i = 1; i <= n; i++) {
		fakt *= i;
	}
	return fakt;
}