#include <iostream>
#include <vector>
#include "PatientAccount.h"
#include "Surgery.h"
#include "Pharmacy.h"
#include <string>

/**
 * TODO: Group Project
20. Patient Fees

2. You are to write a program that computes a patient’s bill for a hospital stay. The different components of the program are
                    The PatientAccount class
                    The Surgery class
                    The Pharmacy class
                    The main program

    – The PatientAccount class will keep a total of the patient’s charges. It will also keep track of the number of days
    spent in the hospital. The group must decide on the hospital’s daily rate.

    – The Surgery class will have stored within it the charges for at least five types of surgery. It can update the
    charges variable of the PatientAccount class.

    – The Pharmacy class will have stored within it the price of at least five types of medication. It can update the
    charges variable of the PatientAccount class.

    – The student who designs the main program will design a menu that allows the user to enter a type of surgery and
    a type of medication, and check the patient out of the hospital. When the patient checks out, the total charges
    should be displayed.
 */

using namespace std;

//this vector holds all our patient information

vector<PatientAccount> patientDataBase;

/**
 * This method allows for a new Patient to be added to the database
 * It asks the user for a name,
 * checks to make sure the patient does not already exist,
 * and then adds it to the data-base
 */
void checkInPatient() {
    string name;

    cout << endl;
    cout << "   Patient Check-in   " << endl;
    cout << "----------------------" << endl;
    cout << "Name: ";
    cin.ignore();
    getline(cin, name);

    for (PatientAccount &i:patientDataBase) {
        if (i.getName() == name) {
            cout << "This patient already exists!";
            return;
        }
    }

    PatientAccount newPatient(name);

    patientDataBase.push_back(newPatient);
    cout << endl;
}

/**
 * Prints out all of the patients that are held in the database
 */
void listPatients() {
    cout << endl;
    for (PatientAccount &i:patientDataBase) {
        cout << i.toString() << endl;
        cout << endl;
    }
}

//This includes the interface for working with a patient account, gives options and asks user for what they would like to do before guiding them through the options

void workWithPatient() {

    string inputName;
    cout << endl;
    cin.ignore();

    cout << "Select a Patient: ";
    getline(cin, inputName);

    for(PatientAccount &currPatient:patientDataBase){
        if(currPatient.getName() == inputName){

            int selection = 0;
            while(selection != 6){
                cout << endl;
                cout << "   Patient Services   " << endl;
                cout << "----------------------" << endl;
                cout << "1. Add Surgery Bill" << endl;
                cout << "2. Add Pharmacy Bill" << endl;
                cout << "3. Add Days to Hospital Stay" <<endl;
                cout << "4. Print current Info" <<endl;
                cout << "5. Check-out" <<endl;
                cout << "6. Exit Patient menu" <<endl;
                cout << "Selection: ";
                cin >> selection;

                switch (selection){
                    case 1:
                        Surgery::listSurgeries();
                        cin.ignore();

                        cout << "Choose one: ";
                        int surgeryChoice;
                        cin >> surgeryChoice;

                        Surgery::performOperation(Surgery::surgeryList.at(surgeryChoice - 1), currPatient);
                        break;
                    case 2:
                        Pharmacy::listMedicines();
                        cin.ignore();

                        cout <<"Chose one: ";
                        int medChoice;
                        cin >>medChoice;

                        Pharmacy::prescribeMedicine(Pharmacy::medicineList.at(medChoice-1), currPatient);
                        break;
                    case 3:
                        cout << "Current Days: " << currPatient.getDaysInHospital() << endl;
                        cout << "Days to increment (negative numbers remove days): ";
                        int days;

                        cin>> days;

                        currPatient.incrementStay(days);
                        break;
                    case 4:
                        cout << currPatient.toString() << endl;
                        break;
                    case 5:{
                        cout << "Are you sure you would like to check out -> " << currPatient.getName() << endl;
                        cout << "Y/n :";
                        string checkoutChoice;

                        cin.ignore();
                        getline (cin, checkoutChoice);

                        if(tolower(checkoutChoice.at(0)) == 'y'){
                            cout << currPatient.toString() << endl;
                            for(int i = 0; i<patientDataBase.size(); i++){
                                if(patientDataBase.at(i).getName() == currPatient.getName()){
                                    patientDataBase.erase(patientDataBase.begin()+i);
                                }
                            }

                            return;
                        }
                        break;
                    }
                    case 6:
                        break;
                    default:
                        cout << "Selection invalid. Try again..." << endl;
                        break;

                }
            }
            return;//done working with patient here, so we leave the method without continuing through the rest of the list for no reason

        }
    }

    cout << "No patient with that name exists" <<endl;
    cout << endl;
    //select patient to work with
    //give options to choose (surgeries, medications, checkout)
    //perform operation
}

int main() {

    int selection = 0;
    while (selection != 4) {
        cout << "   Hospital Interface   " << endl;
        cout << "------------------------" << endl;
        cout << "1. Patient Check-in" << endl;
        cout << "2. List of Patients" << endl;
        cout << "3. Select Patient" << endl;
        cout << "4. Exit program" << endl;
        cout << "Selection: ";
        cin >> selection;

        switch (selection) {
            case 1:
                checkInPatient();
                break;
            case 2:
                listPatients();
                break;
            case 3:
                workWithPatient();
                break;
            case 4:
                cout << "Good-bye!" << endl;
                return 0;
            default:
                cout << "Invalid selection" << endl;
                selection = 4;
                break;
        }
    }
    return 0;
}
