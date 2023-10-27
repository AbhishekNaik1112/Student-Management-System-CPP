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
    cout << "\t ENTER YOUR CAMPUS NAME: ";
    cin.ignore();
    getline(cin, campus_name);
    cout << "\t ENTER YOUR COURSE NAME: ";
    cin.ignore();
    getline(cin, course_name);
    cout << "\t ENTER YOUR DATE OF BIRTH(XX Month Name XXXX): ";
    getline(cin, dob);
    cout << "\n\n\n\t REGISTRATION SUCCESSFUL & WELCOME TO OUR INSTITUTION..:)\n\n\n";
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
