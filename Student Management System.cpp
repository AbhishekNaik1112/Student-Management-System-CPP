#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <string>  // Added for the string class

using namespace std;

class student {
    string full_name;
    int campus_id;
    string campus_name;
    string dob;

public:
    void new_registration();
    void show_details();
};

void student::new_registration() {
    system("cls");
    cout << "\t ENTER YOUR FULL NAME: " << endl;
    cin.ignore();
    getline(cin, full_name);
    full_name = toupper(full_name);
    cout << "\t ENTER A NEW CAMPUS ID: " << endl;
    cin >> campus_id;
    cout << "\t ENTER YOUR CAMPUS NAME: " << endl;
    cin.ignore();
    getline(cin, campus_name);
    campus_name = toupper(campus_name);
    cout << "\t ENTER YOUR DATE OF BIRTH(XX Month Name XXXX): " << endl;
    getline(cin, dob);
    dob = toupper(dob);
    cout << "\t REGISTRATION SUCCESSFUL & WELCOME TO OUR INSTITUTION..:)" << endl;
}

void student::show_details() {
    cout << "\t FULL NAME: " << full_name << endl;
    cout << "\t CAMPUS ID: " << campus_id << endl;
    cout << "\t CAMPUS NAME: " << campus_name << endl;
    cout << "\t DATE OF BIRTH: " << dob << endl;
}

int main() {
    student S;
    S.new_registration();
    S.show_details();
}
