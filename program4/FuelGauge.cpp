#include <iostream>
using namespace std;
#include "FuelGauge.h"

void FuelGauge::printGallonsOfFuel()
{
    cout << "Gallons of fuel: " << gallonsOfFuel << endl;
}

void FuelGauge::addFuel()
{
    //  fuel tank is already full
    if (gallonsOfFuel == 15)
    {
        cout << "Fuel Tank is full, cannot add more. " << endl;
        return;
    }
    
    //  adding a gallon of fuel fills up the tank
    if (gallonsOfFuel + 1 == 15)
    {
        cout << "Adding one gallon to the tank. The tank is now full." << endl;
        gallonsOfFuel++;
        return;
    }
    
    //  adding a gallon of fuel
    else
    {
        cout << "Adding one gallon to the tank. ";
        gallonsOfFuel++;
        printGallonsOfFuel();   //  used for debugging, can be removed
    }
}

void FuelGauge::removeFuel()
{
    //  fuel tank is already empty
    if (gallonsOfFuel == 0)
    {
        cout << "Fuel Tank is empty. Cannot remove any more. " << endl;
        return;
    }
    
    //  removing a gallon of fuel depletes the tank
    if (gallonsOfFuel - 1 == 0)
    {
        cout << "Removing one gallon from the tank. The tank is now empty." << endl;
        gallonsOfFuel--;
        return;
    }
    
    //  removing a gallon of fuel
    else
    {
        cout << "Removing one gallon from the tank.";
        gallonsOfFuel--;
        printGallonsOfFuel();   //  used for debugging, can be removed
    }
}
