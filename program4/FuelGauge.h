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