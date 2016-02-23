//
// Created by nasir on 2/11/16.
//

#include "PatientAccount.h"
#include <sstream>
/**
 * The patient account class holds information about the individual patient
 * It allows for encapuslation of data, so that it is correctly interacted with through methods
 * */
 
PatientAccount::PatientAccount(string n) {
    name = n;
    totalCharges = 0;
    daysInHospital = 0;
}

string PatientAccount::getName(){
    return name;
}
void PatientAccount::charge(Charge s) {
    double cost = s.getCost();

    if(cost>0){
        totalCharges+=cost;
    }
}

double PatientAccount::getTotalCharges() {
    return totalCharges;
}

int PatientAccount::getDaysInHospital() {
    return daysInHospital;
}

void PatientAccount::incrementStay(int days) {

    if (daysInHospital + days > 0) {
        daysInHospital += days;

        totalCharges += (dailyRate * days);
    }
}


string PatientAccount::toString() {
    stringstream ss;

    ss << "Name: " << getName() << "\nDays Stayed: " << getDaysInHospital() << "\nTotal Charges: " << getTotalCharges();
    return ss.str();
}
