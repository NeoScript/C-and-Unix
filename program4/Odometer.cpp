/*	Filename: 	Odometer.cpp
	Author: 		Erick Narvaez/Hameed Hakimi
	Procedures:	1) Odometer(): Constructor for FuelGauge class.
					2) incrementMileage(FuelGauge &gauge): Increments the milage by 1.
					3) getMileage(): Returns milage attribute.
*/
#include "Odometer.h"
#include <iostream>

using namespace std;
/*	Name: 		Odometer
	Author:		Erick Narvaez
	Summary: 	Default constructor for Odometer class that initializes the value of
					milage to zero.
	Arguments: 	None
*/
Odometer::Odometer() {
	mileage = 0;
}
/*	Name: 		incrementMileage
	Author:		Hameed Hakimi
	Summary: 	Checks that milage is not above the max, and will increment it by 1.
					Also takes a FuelGauge object and decrements its fuel every time
					it travels the milage of the car.
	Arguments:
		1) Name:				gauge
			Direction: 		I/O
			Type:				FuelGauge
			Description:	Passes a FuelGauge object so that it can decrement its fuel
								as the milage increases.
*/
void Odometer::incrementMileage(FuelGauge &gauge) {
	if (mileage == maxMileage) {
		mileage = 0;
	} else {
		mileage++;
	}

	if (mileage % mpg == 0) {
		gauge.decrementFuel();
	}

}

/*	Name: 		getMilage
	Author:		Hameed Hakimi
	Summary: 	Getter method for the milage attribute. Returns an integer.
	Arguments: 	None
*/
int Odometer::getMileage() {
	return mileage;
}
