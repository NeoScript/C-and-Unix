/*	Filename: 	Odometer.h
	Author: 		Erick Narvaez
	Procedures:	1) Odometer(): Constructor for FuelGauge class.
					2) incrementMileage(FuelGauge &gauge): Increments the milage by 1.
					3) getMileage(): Returns milage attribute.
*/
#ifndef ODOMETER_H
#define ODOMETER_H

#include "FuelGauge.h"

class Odometer {
private:
	int mileage;
	const static int maxMileage = 999999; //For variable max milage
	const static int mpg = 24; //For variable mpg

public:
	Odometer();
	void incrementMileage(FuelGauge &gauge);
	int getMileage();
};

#endif
