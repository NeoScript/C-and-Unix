
#ifndef FuelGauge_h
#define FuelGauge_h
class FuelGauge{
private:
    int gallonsOfFuel;
    
public:
    FuelGauge()
    { gallonsOfFuel = 0;}
    
    FuelGauge(int gal)
    { gallonsOfFuel = gal;}
    void printGallonsOfFuel();
    void addFuel();
    void removeFuel();
};

#endif /* FuelGauge_h */
