#include <iostream>
#include "FuelGauge.h"
#include "Odometer.h"

using namespace std;

int main() {
	FuelGauge gauge;
	Odometer odometer;

	//Filling up car with fuel
	for (int i=0; i<15; i++){
		gauge.incrementFuel();
	}

	//Running car until out of fuel
	while(gauge.getFuel()>0){
		odometer.incrementMileage(gauge);
		cout << "Mileage: " << odometer.getMileage() << " miles\n" << "Fuel: " << gauge.getFuel() << " gallons\n\n";
	}

	return 0;
}