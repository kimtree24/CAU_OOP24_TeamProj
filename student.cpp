#include "student.h"
#include <iostream>
#include <iomanip>

using namespace std;

Student::Student() {}

Student::Student(string &name, string &id, string &birthYear, string &department, string &phone) {
    this-> name = name;
    this-> id = id;
    this-> birthYear = birthYear;
    this-> department = department;
    this-> phone = phone;
}

string Student::getName() {
    return name;
}

string Student::getId() {
    return id;
}

string Student::getBirthYear() {
    return birthYear;
}

string Student::getDepartment() {
    return department;
}

string Student::getPhone() {
    return phone;
}

void Student::printStudentInfo() {
    cout << left << setw(15) << name 
         << setw(15) << id 
         << setw(30) << department 
         << setw(15) << birthYear 
         << setw(12) << phone 
         << endl;
}


// 추가
void Student::setName(const string& newName) {
    this->name = newName;
}

void Student::setBirthYear(const string& newBirtYear) {
    this->birthYear = newBirtYear;
}

void Student::setDepartment(const string& newDepartment) {
    this->department = newDepartment;
}

void Student::setPhone(const string& newPhone) {
    this->phone = newPhone;
}
