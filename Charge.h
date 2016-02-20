//
// Created by nasir on 2/11/16.
//



#ifndef PROGRAM3_CHARGE_H
#define PROGRAM3_CHARGE_H

#include <string>
#include <sstream>

class Charge{
private:
    std::string name;
    double cost;
public:
    Charge(double c){
        cost = c;
        name = "un-named cost";
    }
    Charge (std::string n, double c){
        name = n;
        cost = c;
    }
    double getCost() const{
        return cost;
    };

    std::string getName() const{
        return name;
    }

    std::string toString() const{
        std::stringstream ss;
        ss << "Name: " << getName() << " Cost: "<<getCost();

        return ss.str();
    }
};
#endif //PROGRAM3_CHARGE_H