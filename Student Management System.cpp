#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class student {
	string full_name;
	long long campus_id; // Changed the type to long long
	string campus_name;
	string course_name;
	string dob;
	string batch;
	string blood_group;
	string contact_number;
	string perm_address;

public:
	student() : campus_id(0), contact_number("0") {} // Corrected the initialization

	void new_registration();
	void show_details();
	long long getCampusId() const; // Corrected the return type to long long
};

void write_registration();
void show_details(long long n);

void student::new_registration() {
	system("cls");
	cout << "\t\t ENTER YOUR FULL NAME: ";
	cin.ignore();
	getline(cin, full_name);
	cout << "\t\t ENTER A NEW CAMPUS ID: ";
	cin >> campus_id; // Read as long long
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
	getline(cin, contact_number);
	cout << "\t\t ENTER YOUR PERMANENT ADDRESS: ";
	// cin.ignore(); // Remove this line
	getline(cin, perm_address);
	cout << "\n\n\n\t REGISTRATION SUCCESSFUL & WELCOME TO OUR INSTITUTION..:)\n\n\n";
}

void student::show_details() {
	system("cls");
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

long long student::getCampusId() const {
	return campus_id;
}

void write_registration() {
	student reg;
	ofstream outFile;
	outFile.open("registration.dat", ios::binary | ios::app);
	reg.new_registration();
	outFile.write(reinterpret_cast<char*>(&reg), sizeof(student));
	outFile.close();
}

void show_details(long long n) {
	student reg;
	bool flag = false;
	ifstream inFile;
	inFile.open("registration.dat", ios::binary);
	if (!inFile) {
		cout << "Details could not be opened !! Press any Key...";
		return;
	}
	cout << "\n\t\t\tSTUDENT DETAILS\n";
	while (inFile.read(reinterpret_cast<char*>(&reg), sizeof(student))) {
		if (reg.getCampusId() == n) {
			reg.show_details();
			flag = true;
		}
	}
	inFile.close();
	if (flag == false)
		cout << "\n\n\t\tCampus ID does not exist";
}

int main() {
	char c;
	long long n;

	system("cls");
	cout << "\t\t\t----------------------------------------" << endl;
	cout << "\t\t\t| WELCOME TO STUDENT MANAGEMENT SYSTEM |" << endl;
	cout << "\t\t\t----------------------------------------" << endl;
	cout << endl;

	cout << "\t\t\t\t ------MAIN MENU------" << endl;
	cout << endl;
	cout << "\t\t1. NEW REGISTRATION" << endl;
	cout << endl;
	cout << "\t\t2. SHOW STUDENT INFORMATION" << endl;
	cout << endl;
	cout << "\t\t3. UPDATE STUDENT INFORMATION" << endl;
	cout << endl;
	cout << "\t\t4. LIST OF ALL STUDENTS" << endl;
	cout << endl;
	cout << "\t\t5. ADD CREDITS" << endl;
	cout << endl;
	cout << "\t\t6. CREDITS DETAILS" << endl;
	cout << endl;
	cout << "\t\t7. EXIT" << endl;
	cout << endl;

	cout << "\t\tENTER YOUR CHOICE(1-7): ";
	cin >> c;
	cout << "\n";

	switch (c) {
	case '1':
		write_registration();
		break;
	case '2':
		system("cls");
		cout << "\t\tENTER THE CAMPUS ID: " << endl;
		cin >> n;
		// cin.ignore(); // Remove this line
		show_details(n);
		break;
	case '3':
		// update student information here
		break;
	case '4':
		// list of all students here
		break;
	case '5':
		// add credits here
		break;
	case '6':
		// credits details here
		break;
	case '7':
		system("cls");
		return 0;
	default:
		cout << "Invalid choice. Exiting..." << endl;
		break;
	}

	return 0;
}
