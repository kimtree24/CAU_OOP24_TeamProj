#include "student.h"
#include <iostream>
#include <iomanip>

using namespace std;

Student::Student() {}

Student::Student(const string &name, const string &id, const string &birthYear, const string &department, const string &phone) {
    this-> name = name;
    this-> id = id;
    this-> birthYear = birthYear;
    this-> department = department;
    this-> phone = phone;
}

string Student::getName() const {
    return name;
}

string Student::getId() const {
    return id;
}

string Student::getBirthYear() const {
    return birthYear;
}

string Student::getDepartment() const {
    return department;
}

string Student::getPhone() const {
    return phone;
}

void Student::printStudentInfo() const {
    cout << name << "/" << id << "/" << birthYear << "/" << department << "/" << phone << endl;
}

// operator== 구현 (학생 ID를 비교하는 함수)
bool Student::operator==(const string& otherId) const {
    return this->id == otherId;
}