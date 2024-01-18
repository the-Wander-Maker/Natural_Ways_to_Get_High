#include "HeronFormula.h"

void HeronFormula::heron_formula_process(){
	std::cout << std::endl << "----------------- Heron Forumla task ------------------" << std::endl;

	double a = 0, b = 0, c = 0;

	std::cout << std::endl << "Please give me the triangles three sides in cm: " << std::endl;
	std::cin >> a >> b >> c;

	double perimeter_half = (a + b + c) / 2;
	double perimeter = a + b + c;
	double area = sqrt(perimeter_half * ((perimeter_half - a) * (perimeter_half - b) * (perimeter_half - c)));

	std::cout << "Area of the triangle: " << area << " cm" << std::endl;
	std::cout << "The perimeter of the triangle: " << perimeter << " cm" << std::endl;
}