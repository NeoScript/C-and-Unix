// Pgm4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Odometer.h"
#include "FuelGauge.h"

int main()
{
	Odometer dometer;
	FuelGauge fuelG;
	
	//Fill up Tank
	for (int i = 0; i < 15; i++)
		fuelG.incrementFuel();

	//Loop for Miles
	while (fuelG.getFuel() != 0) {
		dometer.incrementMilage(fuelG);
	}

    return 0;
}

