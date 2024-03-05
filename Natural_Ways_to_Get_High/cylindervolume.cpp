#include "CylinderVolume.h"



void Cylinder::cylinderExec(){
	double volume = 0.0;
	double radius = 0.0;
	double altitude = 0.0;

	std::cout << "The diameter gives the radius and volume of the cylinder: " << std::endl;
	std::cin >> radius;
	std::cin >> altitude;

	volume = M_PI * (involving(radius, 2) * altitude);
	std::cout << "Volume of the cylinder: " << volume;
}