#pragma once
class FuelGauge
{
private: 
	int fuel; 
public:
	FuelGauge();
	int getFuel();
	void incrementFuel();
	void decrementFuel();
};

