//
// Created by nasir on 2/11/16.
//

#ifndef PROGRAM3_PHARMACY_H
#define PROGRAM3_PHARMACY_H


#include "Charge.h"
#include "PatientAccount.h"
#include <vector>
#include <iostream>

using namespace std;

class Pharmacy {

public:
    static const Charge ADVIL;
    static const Charge TYLENOL;
    static const Charge TUMS;
    static const Charge MUCINEX;
    static const Charge VITAMIN_D_SUPPLEMENT;
    static const vector<Charge> medicineList;

    static void prescribeMedicine(Charge c, PatientAccount &p){
        p.charge(c);
    }

    static void listMedicines(){
        int currNum = 1;
        for(const Charge &currCharge:medicineList){
            cout << currNum++ <<". "<<currCharge.toString()<<endl;
        }
    }
};

const Charge Pharmacy::ADVIL("Advil", 10);
const Charge Pharmacy::TYLENOL("Tylenol", 15);
const Charge Pharmacy::TUMS("Tums", 8);
const Charge Pharmacy::MUCINEX("Mucinex", 25);
const Charge Pharmacy::VITAMIN_D_SUPPLEMENT("Vitamin D Supplement", 17);

const vector<Charge> Pharmacy::medicineList = {ADVIL, TYLENOL, TUMS, MUCINEX, VITAMIN_D_SUPPLEMENT};


#endif //PROGRAM3_PHARMACY_H
