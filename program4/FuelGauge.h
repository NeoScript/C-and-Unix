#ifndef FUELGAUGE_H
#define FUELGAUGE_H

class FuelGauge {
private:
	int fuel;
public:
	FuelGauge();
	int getFuel();
	void incrementFuel();
	void decrementFuel();
};

#endif