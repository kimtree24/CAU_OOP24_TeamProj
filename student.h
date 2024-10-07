#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;

class Student {
private:
    string name;
    string id;
    string birthYear;
    string department;
    string phone;

public:
    Student();
    Student(string &name, string &id, string &birthYear, string &department, string &phone);

    string getName();
    string getId();
    string getBirthYear();
    string getDepartment();
    string getPhone();

    void printStudentInfo();
};

#endif