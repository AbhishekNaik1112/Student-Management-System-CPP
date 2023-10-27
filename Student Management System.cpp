#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <string>  // Added for the string class

using namespace std;

class student {
    string full_name;
    int campus_id;
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
    system("cls");
    cout << "\t\t\t\t\t\t-----STUDENT MANAGEMENT SYSTEM-----" << endl;
    cout << "\t ENTER YOUR FULL NAME: ";
    getline(cin, full_name);
    cout << "\t ENTER A NEW CAMPUS ID: ";
    cin >> campus_id;
    cin.ignore(); 
    cout << "\t ENTER YOUR CAMPUS NAME: ";
    getline(cin, campus_name);
    cout << "\t ENTER YOUR COURSE NAME: ";
    getline(cin, course_name);
    cout << "\t ENTER YOUR DATE OF BIRTH(XX Month Name XXXX): ";
    getline(cin, dob);
    cout << "\t ENTER YOUR BATCH YEAR: ";
    getline(cin, batch);
    cout << "\t ENTER YOUR BLOOD GROUP: ";
    getline(cin, blood_group);
    cout << "\t ENTER YOUR CONTACT NUMBER: ";
    cin >> contact_number;
    cin.ignore(); 
    cout << "\t ENTER YOUR PERMANENT ADDRESS: ";
    getline(cin, perm_address);
    cout << "\n\n\n\t REGISTRATION SUCCESSFUL & WELCOME TO OUR INSTITUTION..:)\n\n\n";
}


void student::show_details() {
    cout << "\t FULL NAME: " << full_name << endl;
    cout << "\t CAMPUS ID: " << campus_id << endl;
    cout << "\t CAMPUS NAME: " << campus_name << endl;
    cout << "\t COURSE NAME: " << course_name << endl;
    cout << "\t DATE OF BIRTH: " << dob << endl;
    cout << "\t BATCH: " << batch << endl;
    cout << "\t BLOOD GROUP: " << blood_group << endl;
    cout << "\t CONTACT NUMBER: " << contact_number << endl;
    cout << "\t PERMANENT ADDRESS: " << perm_address << endl;
}

int main() {
    student S;
    S.new_registration();
    S.show_details();
   
}
