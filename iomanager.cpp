#include "iomanager.h"
#include <iostream>
#include <limits>

using namespace std;

int IOManager::showMainMenu() {
    int choice;
    cout << "1. Insertion\n";
    cout << "2. Search\n";
    cout << "3. Sorting Option\n";
    cout << "4. Exit\n";
    cout << "5. Modify\n"; // 추가
    cout << "> ";
    cin >> choice;
    return choice;
}

int IOManager::showSearchMenu() {
    int choice;
    cout << "\n- Search -\n";
    cout << "1. Search by Name\n";
    cout << "2. Search by Student ID (10 digits)\n";
    cout << "3. Search by Admission Year (4 digits)\n";
    cout << "4. Search by Birth Year (4 digits)\n";
    cout << "5. Search by Department Name\n";
    cout << "6. List All\n";
    cout << "> ";
    cin >> choice;
    return choice;
}

int IOManager::showSortMenu() {
    int choice;
    cout << "\n- Sorting Option -\n";
    cout << "1. Sort by Name\n";
    cout << "2. Sort by Student ID\n";
    cout << "3. Sort by Birth Year\n";
    cout << "4. Sort by Department name\n";
    cout << "> ";
    cin >> choice;
    return choice;
}

Student IOManager::getStudentInfo(){
    string name, id, birthYear, department, phone;

    cout << "Name? ";
    cin.ignore();
    getline(cin, name);

    cout << "Student ID (10 digits) ? ";
    getline(cin, id);

    cout << "Birth Year (4 digits)? ";
    getline(cin, birthYear);

    cout << "Department? ";
    getline(cin, department);

    cout << "Tel? ";
    getline(cin, phone);

    return Student(name, id, birthYear, department, phone);
}

string IOManager::getSearchInput() {
    string input;
    cin.ignore();
    getline(cin, input);
    return input;
}

// void IOManager::displayMessage(string& message) {
//     cout << message << endl;
// }