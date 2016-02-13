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
class Surgery {

public:
    const Charge KIDNEY_TRANSPLANT = Charge("Kidney Transplant", 2500);
    const Charge HEART_BYPASS = Charge("Heart Bypass", 6000);
    const Charge LASIK = Charge("Lasik", 1200);
    const Charge HIP_REPLACEMENT = Charge("Hip Replacement", 1500);
    const Charge PLASTIC_SURGERY = Charge("Plastic Surgery", 800);
    static const vector<Charge> surgeryList = {KIDNEY_TRANSPLANT, HEART_BYPASS, LASIK, HIP_REPLACEMENT, PLASTIC_SURGERY};

    static void performOperation(Charge c, PatientAccount &p) {
        p.charge(c);
    }

    static std::string listOfSurgeries() {
        using namespace std;

        int curr = 1;
        for(const Charge &c:surgeryList){
            cout << curr++ << ". " << c.toString() << endl;
        }
    }
};


#endif //PROGRAM3_SURGERY_H
