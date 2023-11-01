#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>

class student {
    std::string full_name;
    long long campus_id;
    std::string campus_name;
    std::string course_name;
    std::string dob;
    std::string batch;
    std::string blood_group;
    std::string contact_number;
    std::string perm_address;

public:
    student() : campus_id(0), contact_number("0") {}
    void new_registration();
    void show_details() const;
    long long getCampusId() const;
    void modify();
};

void write_registration();
void show_details(long long n);
void modify_details(long long n);

void student::new_registration() {
    std::cout << "\t\t ENTER YOUR FULL NAME: ";
    std::cin.ignore();
    std::getline(std::cin, full_name);
    std::cout << "\t\t ENTER A NEW CAMPUS ID: ";
    std::cin >> campus_id;
    std::cin.ignore();
    std::cout << "\t\t ENTER YOUR CAMPUS NAME: ";
    std::getline(std::cin, campus_name);
    std::cout << "\t\t ENTER YOUR COURSE NAME: ";
    std::getline(std::cin, course_name);
    std::cout << "\t\t ENTER YOUR DATE OF BIRTH(XX Month Name XXXX): ";
    std::getline(std::cin, dob);
    std::cout << "\t\t ENTER YOUR BATCH YEAR: ";
    std::getline(std::cin, batch);
    std::cout << "\t\t ENTER YOUR BLOOD GROUP: ";
    std::getline(std::cin, blood_group);
    std::cout << "\t\t ENTER YOUR CONTACT NUMBER: ";
    std::getline(std::cin, contact_number);
    std::cout << "\t\t ENTER YOUR PERMANENT ADDRESS: ";
    std::getline(std::cin, perm_address);
    std::cout << "\n\n\n\t REGISTRATION SUCCESSFUL & WELCOME TO OUR INSTITUTION..:)\n\n\n";
}

void student::show_details() const {
    std::cout << "\t\t FULL NAME: " << full_name << std::endl;
    std::cout << "\t\t CAMPUS ID: " << campus_id << std::endl;
    std::cout << "\t\t CAMPUS NAME: " << campus_name << std::endl;
    std::cout << "\t\t COURSE NAME: " << course_name << std::endl;
    std::cout << "\t\t DATE OF BIRTH: " << dob << std::endl;
    std::cout << "\t\t BATCH: " << batch << std::endl;
    std::cout << "\t\t BLOOD GROUP: " << blood_group << std::endl;
    std::cout << "\t\t CONTACT NUMBER: " << contact_number << std::endl;
    std::cout << "\t\t PERMANENT ADDRESS: " << perm_address << std::endl;
}

long long student::getCampusId() const {
    return campus_id;
}

void student::modify() {
    std::cout << "\t\t MODIFY STUDENT DETAILS\n";
    std::cin.ignore();

    std::cout << "\t\t ENTER YOUR FULL NAME: ";
    std::getline(std::cin, full_name);

    std::cout << "\t\t ENTER YOUR CAMPUS NAME: ";
    std::getline(std::cin, campus_name);

    std::cout << "\t\t ENTER YOUR COURSE NAME: ";
    std::getline(std::cin, course_name);

    std::cout << "\t\t ENTER YOUR DATE OF BIRTH(XX Month Name XXXX): ";
    std::getline(std::cin, dob);

    std::cout << "\t\t ENTER YOUR BATCH YEAR: ";
    std::getline(std::cin, batch);

    std::cout << "\t\t ENTER YOUR BLOOD GROUP: ";
    std::getline(std::cin, blood_group);

    std::cout << "\t\t ENTER YOUR CONTACT NUMBER: ";
    std::getline(std::cin, contact_number);

    std::cout << "\t\t ENTER YOUR PERMANENT ADDRESS: ";
    std::getline(std::cin, perm_address);

    std::cout << "\n\n\t\t DETAILS UPDATED SUCCESSFULLY\n\n";
}

void write_registration() {
    student reg;
    std::ofstream outFile;
    outFile.open("registration.dat", std::ios::binary | std::ios::app);

    if (!outFile) {
        std::cout << "Error opening file for writing. Registration failed." << std::endl;
        return;
    }

    reg.new_registration();
    outFile.write(reinterpret_cast<char*>(&reg), sizeof(student));
    outFile.close();
}

void show_details(long long n) {
    student reg;
    bool found = false;
    std::ifstream inFile;
    inFile.open("registration.dat", std::ios::binary);

    if (!inFile) {
        std::cout << "Details could not be opened! Press any key..." << std::endl;
        return;
    }

    std::cout << "\n\t\t\tSTUDENT DETAILS\n";
    while (inFile.read(reinterpret_cast<char*>(&reg), sizeof(student))) {
        if (reg.getCampusId() == n) {
            reg.show_details();
            found = true;
        }
    }

    inFile.close();

    if (!found)
        std::cout << "\n\n\t\tCampus ID does not exist" << std::endl;
}

void modify_details(long long n) {
    student reg;
    bool found = false;
    std::fstream File;
    File.open("registration.dat", std::ios::binary | std::ios::in | std::ios::out);

    if (!File) {
        std::cout << "Details could not be opened! Press any key..." << std::endl;
        return;
    }

    while (File.read(reinterpret_cast<char*>(&reg), sizeof(student))) {
        if (reg.getCampusId() == n) {
            reg.show_details();
            std::cout << "\n\n\t\tEnter The New Details\n";
            reg.modify();

            int pos = (-1) * static_cast<int>(sizeof(student));
            File.seekp(pos, std::ios::cur);
            File.write(reinterpret_cast<char*>(&reg), sizeof(student));
            found = true;
            break;
        }
    }

    File.close();

    if (!found)
        std::cout << "\n\n\t\tCampus ID Not Found" << std::endl;
}

int main() {
    char c;
    long long n;

    std::cout << "\t\t\t----------------------------------------" << std::endl;
    std::cout << "\t\t\t| WELCOME TO STUDENT MANAGEMENT SYSTEM |" << std::endl;
    std::cout << "\t\t\t----------------------------------------" << std::endl;
    std::cout << std::endl;

    while (true) {
        std::cout << "\t\t\t\t ------MAIN MENU------" << std::endl;
        std::cout << "\t\t\t\t 1. NEW REGISTRATION" << std::endl;
        std::cout << "\t\t\t\t 2. SHOW DETAILS" << std::endl;
        std::cout << "\t\t\t\t 3. MODIFY DETAILS" << std::endl;
        std::cout << "\t\t\t\t 4. EXIT" << std::endl;

        std::cout << "\t\t\t Enter Your Choice: ";
        std::cin >> c;

        switch (c) {
        case '1':
            write_registration();
            break;

        case '2':
            std::cout << "\t\t\t Enter Your Campus ID: ";
            std::cin >> n;
            show_details(n);
            char ch;
            std::cout << "Enter any key and Enter to return to Main Menu.";
            std::cin >> ch;
            //std::this_thread::sleep_for(std::chrono::seconds(5));
            system("cls");
            return main();

        case '3':
            std::cout << "\t\t\t Enter Your Campus ID: ";
            std::cin >> n;
            modify_details(n);
            system("cls");
            return main();

        case '4':
            exit(0);
            break;

        default:
            std::cout << "\a"; 
        }
    }

    return 0;
}
