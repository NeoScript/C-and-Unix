/**
 * Created by Nasir Ratnani on 2/11/16.
 *
 *     – The PatientAccount class will keep a total of the patient’s charges. It will also keep track of the number of days
 *     spent in the hospital. The group must decide on the hospital’s daily rate.
**/

#ifndef PROGRAM3_PATIENTACCOUNT_H
#define PROGRAM3_PATIENTACCOUNT_H


#include "Charge.h"

using namespace std;

class PatientAccount {
    private:
        string name;
        double totalCharges;
        int daysInHospital;
    public:
        PatientAccount(string n);
        void charge(Charge s);
        string getName();
        double getTotalChargse();
        int getDaysInHospital();
        void incrementStay(int days);
        string toString();
};


#endif //PROGRAM3_PATIENTACCOUNT_H