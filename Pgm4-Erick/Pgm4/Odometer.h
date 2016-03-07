#pragma once
#include "FuelGauge.h"
class Odometer
{
private:
	int milage;
public:
	Odometer();
	void incrementMilage(FuelGauge &gauge);
	int getMilage();
};

