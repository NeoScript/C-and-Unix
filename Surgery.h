//
// Created by nasir on 2/11/16.
//

#ifndef PROGRAM3_SURGERY_H
#define PROGRAM3_SURGERY_H


#include "Charge.h"
#include "PatientAccount.h"
#include <sstream>
#include <vector>
#include <iostream>

/**
 * This is the surgery class
 * It holds an enum named SurgeryCharge which contains 5 common surgeries that can be added to a PatientAccount along with their costs
 *
 */
using namespace std;

class Surgery {
public:
    static const Charge KIDNEY_TRANSPLANT;
    static const Charge HEART_BYPASS;
    static const Charge LASIK;
    static const Charge HIP_REPLACEMENT;
    static const Charge PLASTIC_SURGERY;
    static const vector<Charge> surgeryList;

    static void performOperation(Charge c, PatientAccount &p){
        p.charge(c);
    }

    static void listSurgeries(){

        int curr = 1;
        for(const Charge &i: surgeryList){
            cout << curr++ << ". " << i.toString() << endl;
        }
    }
};

const Charge Surgery::KIDNEY_TRANSPLANT("Kidney Transplant", 2500);
const Charge Surgery::HEART_BYPASS("Heart Bypass", 6000);
const Charge Surgery::LASIK("Lasik", 1200);
const Charge Surgery::HIP_REPLACEMENT("Hip Replacement", 1200);
const Charge Surgery::PLASTIC_SURGERY("Plastic Surgery", 800);

const vector<Charge> Surgery::surgeryList = {KIDNEY_TRANSPLANT, HEART_BYPASS, LASIK, HIP_REPLACEMENT, PLASTIC_SURGERY};

#endif //PROGRAM3_SURGERY_H
