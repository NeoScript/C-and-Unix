/*	Filename: 	FileGauge.cpp
	Author: 		Chris Rodriguez/Erick Narvaez
	Procedures:	1) FuelGauge(): Constructor for FuelGauge class.
					2) getFuel(): Getter method for fuel.
					3) decrementFuel(): Decreaments the fuel variable.
					4) incrementFuel(): Increments the fuel variable.
*/
#include "FuelGauge.h"
#include <iostream>
/*	Name: 		FuelGauge
	Author:		Erick Narvaez
	Summary: 	Default constructor for FuelGauge class that initializes the value of
					fuel to zero.
	Arguments: 	None
*/
FuelGauge::FuelGauge() {
	fuel = 0;
}

/*	Name: 		getFuel
	Author:		Erick Narvaez
	Summary: 	Getter method for fuel attribute. Returns an int.
	Arguments: 	None
*/
int FuelGauge::getFuel() {
	return fuel;
}

/*	Name: 		decrementFuel
	Author:		Chris Rodriguez
	Summary: 	Decreases the value of fuel by 1 every time it is called. Will print
					out a warning to the console if the fuel will drop below zero.
	Arguments: 	None
*/
void FuelGauge::decrementFuel() {
	if (fuel > 0) {
		fuel--;
	} else {
		std::cout << "Out of fuel! Please fill tank to continue driving." << std::endl;
	}
}

/*	Name: 		incrementFuel
	Author:		Chris Rodriguez
	Summary: 	Increases the value of fuel by 1 every time it is called. Will print
					out a warning to the console if the fuel will go above the maximum
					size of the fuel tank.
	Arguments: 	None
*/
void FuelGauge::incrementFuel() {
	if (fuel < maxCapacity) {
		fuel++;
	} else {
		std::cout << "Tank is full! Cannot put any more fuel in car." << std::endl;
	}
}
