#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

class student {
    string full_name;
    long long campus_id;
    string course_name;
    string campus_name;
    string dob;
    string batch;
    string blood_group;
    long long contact_number;
    string perm_address;

public:
    void new_registration();
    void show_details();
};

void student::new_registration() {
    cout << "\t\t ENTER YOUR FULL NAME: ";
    cin.ignore(); // Move cin.ignore here to clear the newline character from the previous input
    getline(cin, full_name);
    cout << "\t\t ENTER A NEW CAMPUS ID: ";
    cin >> campus_id;
    cin.ignore();
    cout << "\t\t ENTER YOUR CAMPUS NAME: ";
    getline(cin, campus_name);
    cout << "\t\t ENTER YOUR COURSE NAME: ";
    getline(cin, course_name);
    cout << "\t\t ENTER YOUR DATE OF BIRTH(XX Month Name XXXX): ";
    getline(cin, dob);
    cout << "\t\t ENTER YOUR BATCH YEAR: ";
    getline(cin, batch);
    cout << "\t\t ENTER YOUR BLOOD GROUP: ";
    getline(cin, blood_group);
    cout << "\t\t ENTER YOUR CONTACT NUMBER: ";
    cin >> contact_number;
    cin.ignore();
    cout << "\t\t ENTER YOUR PERMANENT ADDRESS: ";
    cin.ignore(); 
    getline(cin, perm_address);
    cout << "\n\n\n\t REGISTRATION SUCCESSFUL & WELCOME TO OUR INSTITUTION..:)\n\n\n";
}

void student::show_details() {
    cout << "\t\t FULL NAME: " << full_name << endl;
    cout << "\t\t CAMPUS ID: " << campus_id << endl;
    cout << "\t\t CAMPUS NAME: " << campus_name << endl;
    cout << "\t\t COURSE NAME: " << course_name << endl;
    cout << "\t\t DATE OF BIRTH: " << dob << endl;
    cout << "\t\t BATCH: " << batch << endl;
    cout << "\t\t BLOOD GROUP: " << blood_group << endl;
    cout << "\t\t CONTACT NUMBER: " << contact_number << endl;
    cout << "\t\t PERMANENT ADDRESS: " << perm_address << endl;
}

int main() {
    char c;

    cout << "\t\t\t----------------------------------------" << endl;
    cout << "\t\t\t| WELCOME TO STUDENT MANAGEMENT SYSTEM |" << endl;
    cout << "\t\t\t----------------------------------------" << endl;
    cout << endl;

    cout << "\t\t\t\t ------MAIN MENU------" << endl;
    cout << endl;
    cout << "\t\t1. NEW REGISTRATION" << endl;
    cout << endl;
    cout << "\t\t2. UPDATE STUDENT INFORMATION" << endl;
    cout << endl;
    cout << "\t\t3. LIST OF ALL STUDENTS" << endl;
    cout << endl;
    cout << "\t\t4. ADD CREDITS" << endl;
    cout << endl;
    cout << "\t\t5. CREDITS DETAILS" << endl;
    cout << endl;
    cout << "\t\t6. EXIT" << endl;
    cout << endl;

    cout << "\t\tENTER YOUR CHOICE(1-6): ";
    cin >> c;
    cout << "\n";

    student S;

    switch (c) {
    case '1':
        S.new_registration();
        S.show_details();
        break;
    case '6':
        return 0;
    default:
        cout << "Invalid choice. Exiting..." << endl;
        break;
    }

    return 0;
}
