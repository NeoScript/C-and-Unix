#include <iostream>
#include <vector>
#include <limits>
#include <sstream>
#include <fstream>

using namespace std;

const string fileName = "info.txt";

/**
 * This is the struct which will hold all the information for each customer within the following fields
 */
struct CustomerInfo {
    string name;
    string address;
    string cityStateZip;
    string telephoneNum;
    double accountBalance;
    string dateLastPaid;
};

//This vector will be used to store all the customer entries in memory so we don't have to access the disk drive and slow down operations
vector<CustomerInfo> customers;

/**
 * This method asks for information from the user regarding a new entry to the records
 * It makes sure the Account balance is a non-negative numeric input
 */
void addRecord() {
    CustomerInfo temp;

    cout << "You have chosen to add a new record to the file." << endl;
    cout << "Please enter information into the following prompts." << endl;

    cout << "Name: ";
    string tempName;
    getline(cin, tempName);
    for(CustomerInfo i:customers){
        if (i.name==tempName){
            cout << "This customer already exists! If you would like to makes changes to it, choose option 3 at the next menu." << endl;
            return;
        }
    }
    temp.name = tempName;

    cout << "Address: ";
    getline(cin, temp.address);

    cout << "City, State, and Zip Code: ";
    getline(cin, temp.cityStateZip);

    cout << "Telephone number: ";
    getline(cin, temp.telephoneNum);

    cout << "Account Balance: ";
    double tempBalance = -1;
    while (true) {
        cin >> tempBalance;

        if (cin.fail()) {
            cerr << "Input invalid, please enter a valid balance using only digits." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignores the rest of the current line
            continue; //restart at the top of the while loop
        }

        if (tempBalance < 0) {
            cerr << "Input invalid - Please enter a balance >= 0 " << endl;
            continue; //restart at the top of the while loop
        }
        break;
    }

    temp.accountBalance = tempBalance;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');//This clears out the <enter> key input from the previous cin
    cout << "Date of last payment: ";
    getline(cin, temp.dateLastPaid);

    customers.push_back(temp);
};

/**
 * This method is a helper method which turns CustomerInfo structures into strings for easy printing using std::cout
 */
string infoToString(CustomerInfo obj) {
    ostringstream oss;
    oss << obj.accountBalance; //stores account balance in oss so that is correctly formatted for output later

    string returnString = "";
    returnString += obj.name;
    returnString += "\n";
    returnString += obj.address;
    returnString += "\n";
    returnString += obj.cityStateZip;
    returnString += "\n";
    returnString += obj.telephoneNum;
    returnString += "\n";
    returnString += oss.str(); //this is the accountBalance taken from the oss so it is correctly formatted to two decimal places
    returnString += "\n";
    returnString += obj.dateLastPaid;
    returnString += "\n";

    return returnString;
}

/**
 * This method prints out the record for a single record
 * It asks the user for an input, which will then be used to search through the vector storing the records and find a match
 * if a match is found it prints out the info, else it states no record has been found
 */
void showRecord() {
    string name = "";
    cout << "Who's record would you like to display? (Enter full name): ";
    getline(cin, name);

    for (CustomerInfo i: customers) {
        if (i.name == name) {
            cout << infoToString(i);
            return;
        }
    }
    cout << "Record information not found." << endl;
};

/**
 * This method prints out all the records
 */
void displayAllRecords(){
    for(CustomerInfo i: customers){
        cout << infoToString(i) << endl;
    }
}

void changeRecord(){
    string name = "";
    cout << "Who's record would you like to alter? (Enter full name): ";
    getline(cin, name);

    for(CustomerInfo& i: customers){
        if(i.name == name){
            CustomerInfo temp;

            cout << "Please enter information into the following prompts." << endl;

            cout << "Name: ";
            getline(cin, temp.name);

            cout << "Address: ";
            getline(cin, temp.address);

            cout << "City, State, and Zip Code: ";
            getline(cin, temp.cityStateZip);

            cout << "Telephone number: ";
            getline(cin, temp.telephoneNum);

            cout << "Account Balance: ";
            double tempBalance = -1;
            while (true) {
                cin >> tempBalance;

                if (cin.fail()) {
                    cerr << "Input invalid, please enter a valid balance using only digits." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignores the rest of the current line
                    continue; //restart at the top of the while loop
                }

                if (tempBalance < 0) {
                    cerr << "Input invalid - Please enter a balance >= 0 " << endl;
                    continue; //restart at the top of the while loop
                }
                break;
            }

            temp.accountBalance = tempBalance;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');//This clears out the <enter> key input from the previous cin
            cout << "Date of last payment: ";
            getline(cin, temp.dateLastPaid);

            i=temp;
            return;
        }
    }

    cout << "Record information not found." << endl;
}

/**
 * Deletes the record that is specified by the user
 */
void deleteRecord(){
    string name;

    cout << "Who's record would you like to remove? (Enter full name)" << endl;
    getline(cin, name);

    for(int i = 0; i<customers.size(); i++){
        if(customers.at(i).name == name){
            customers.erase(customers.begin()+i);
        }
    }
}

/**
 * This method will update the storage file with the new information
 * It will overwrite any previous information stored in the file
 *
 * This method is called at the end of the application, when the user chooses to no longer perform operations
 * on the records rather than constantly updating in an effort to minimize I/O
 */
void updateFile(){
    fstream file;
    file.open(fileName, ios::out | ios::trunc);
    for(CustomerInfo i: customers){
        file << i.name << endl;
        file << i.address << endl;
        file << i.cityStateZip << endl;
        file << i.telephoneNum << endl;
        file << i.accountBalance << endl;
        file << i.dateLastPaid << endl;
        file << endl;
    }

    file.close();
}

/**
 * This method will read information from the save file and then update the customers vector with the appropriate entries
 */
void updateFromFile(){
    fstream file;
    file.open(fileName, ios::in);
    vector<CustomerInfo> tempStorage;

    CustomerInfo temp;
    string currLine;
    int linenum = 1;
    while(getline(file, currLine)){
        switch (linenum) {
            case 1:
                temp.name = currLine;
                linenum++;
                break;
            case 2:
                temp.address = currLine;
                linenum++;
                break;
            case 3:
                temp.cityStateZip = currLine;
                linenum++;
                break;
            case 4:
                temp.telephoneNum = currLine;
                linenum++;
                break;
            case 5:
                temp.accountBalance = atof(currLine.c_str());
                linenum++;
                break;
            case 6:
                temp.dateLastPaid = currLine;
                linenum++;
                break;
            case 7: //empty line
                linenum = 1; //reset for the next set of inputs
                tempStorage.push_back(temp);
                break;

        }
    }
    customers = tempStorage;

    file.close();
}

/**
 * This is the main function, it runs a loop that will show a numbered menu from which a user can choose from the available
 * record operations. Once an operation is chosen it is sent through the switch selection process to be forwarded to the appropriate
 * method. At the start of this function information is read from the save file, and at the end the save file is overwritten with
 * the new information.
 */
int main() {
    updateFromFile();

    string input = "y";
    int option = 0;

    while (tolower(input.at(0)) == 'y') {
        cout << "   Customer Account Records Interface   " << endl;
        cout << "----------------------------------------" << endl;
        cout << "1. Enter new information into the records." << endl;
        cout << "2. Search for record by name and display it." << endl;
        cout << "3. Search for record by name and change it." << endl;
        cout << "4. Search for record by name and delete it." << endl;
        cout << "5. Display entire list of records." << endl;
        cout << "Please choose an option: ";
        cin >> option;
        cin.ignore(); //clears out std::cin

        cout<<endl;

        switch (option) {
            case 1:
                addRecord();
                break;
            case 2:
                showRecord();
                break;
            case 3:
                changeRecord();
                break;
            case 4:
                deleteRecord();
                break;
            case 5:
                displayAllRecords();
                break;
            default:
                cout << "Option not supported, try again." << endl;
                continue;
        }

        //saveInfoToFile();
        cout << "Would you like to apply another operation to the records? (Y/n)" << endl;
        cin >> (input = ""); //resets the input to "" before taking a new input from std::cin
        cout << endl;
    }

    cout << "Good-bye!" << endl;
    updateFile();
    return 0;
}
