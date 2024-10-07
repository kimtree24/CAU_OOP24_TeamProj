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
    cout << name << "/" << id << "/" << birthYear << "/" << department << "/" << phone << endl;
}