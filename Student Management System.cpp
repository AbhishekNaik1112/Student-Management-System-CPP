#include<iostream>
#include<iomanip>
#include<fstream>
#include<cctype>

using namespace	std;

class student {
	string full_name;
	int campus_id;
	string campus_name;
	string dob;

public:
	void new_registration();
	void display_registration();
};

void student::new_registration() {
	system("cls");
	cout << "\t ENTER YOUR FULL NAME: " << endl;
	getline(cin, full_name);
	cout << "\t ENTER A NEW CAMPUS ID: " << endl;
	cin >> campus_id;
	cout << "\t ENTER YOUR CAMPUS NAME: " << endl;
	getline(cin, campus_name);
	cout << "\t ENTER YOUR DATE OF BIRTH(XX Month Name XXXX): " << endl;
	getline(cin, dob);
}