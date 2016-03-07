#ifndef ODOMETER_H
#define ODOMETER_H

#include "FuelGauge.h"

class Odometer {
private:
	int mileage;
	const static int maxMilege = 999999;
	const static int mpg = 24;
public:
	Odometer();
	void incrementMileage(FuelGauge &gauge);
	int getMileage();
};

#endif