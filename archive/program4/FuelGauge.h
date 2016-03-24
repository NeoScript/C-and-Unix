/*	Filename: 	FileGauge.h
	Author: 		Erick Narvaez
	Procedures:	1) FuelGauge(): Constructor for FuelGauge class.
					2) getFuel(): Getter method for fuel.
					3) decrementFuel(): Decreaments the fuel variable.
					4) incrementFuel(): Increments the fuel variable.
*/
#ifndef FUELGAUGE_H
#define FUELGAUGE_H

class FuelGauge {  
private:
	int fuel;
	const static int maxCapacity = 15;
public:
	FuelGauge();
	int getFuel();
	void incrementFuel();
	void decrementFuel();
};

#endif
