#include "Odometer.h"
#include <iostream>

using namespace std;

Odometer::Odometer() {
	mileage = 0;
}

void Odometer::incrementMileage(FuelGauge &gauge) {
	if (mileage == 999999) {
		mileage = 0;
	} else {
		mileage++;
	}

	if (mileage % 24 == 0) {
		gauge.decrementFuel();
	}

}

int Odometer::getMileage() {
	return mileage;
}