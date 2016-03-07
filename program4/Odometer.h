#ifndef ODOMETER_H
#define ODOMETER_H

#include "FuelGauge.h"

class Odometer {
private:
	int mileage;
public:
	Odometer();
	void incrementMileage(FuelGauge &gauge);
	int getMileage();
};

#endif