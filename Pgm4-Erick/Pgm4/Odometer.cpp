#include "stdafx.h"
#include "Odometer.h"
#include "FuelGauge.h"
#include <iostream>

using namespace std;
Odometer::Odometer()
{
	milage = 0;
}

void Odometer::incrementMilage(FuelGauge &gauge) {
	milage++;
	if (milage % 24 == 0)
		gauge.decrementFuel();
	cout << "Milage: " << milage << " miles\n" << "Fuel: " << gauge.getFuel() << "Gallons\n\n";
}

int Odometer::getMilage() {
	return milage;
}