#include "stdafx.h"
#include "FuelGauge.h"
#include <iostream>

FuelGauge::FuelGauge(){
	fuel = 0;
}

int FuelGauge::getFuel() {
	return fuel;
}

void FuelGauge::decrementFuel() {
	if (fuel > 0)
		fuel--;
	else
		std::cout << "Out of fuel! Please fill tank to continue driving." << std::endl;
}

void FuelGauge::incrementFuel() {
	if (fuel < 15)
		fuel++;
	else
		std::cout << "Tank is full! Cannot put any more fuel in car." << std::endl;
}

