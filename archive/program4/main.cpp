/*	Filename: 	main.cpp
	Author: 		Nasir Ratnani
	Procedures:	1) main: Main method of the program that simulates a car
						getting fuled and driving.
*/
#include <iostream>
#include "FuelGauge.h"
#include "Odometer.h"

using namespace std;

/*	Name: 		main
	Author:		Nasir Ratnani
	Summary: 	Main method of the program. Creates an instance of an Odometer and
					a FuelGauge and uses them to simulate a car getting its fuel tank filled
					and then running until the tank is empty.
	Arguments: 	None
*/
int main() {
	//Create instances of both classes using default constructors.
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
