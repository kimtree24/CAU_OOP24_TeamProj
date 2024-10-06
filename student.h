#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <unordered_map>

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
    Student(const string &name, const string &id, const string &birthYear, const string &department, const string &phone);

    string getName() const;
    string getId() const;
    string getBirthYear() const;
    string getDepartment() const;
    string getPhone() const;

    void printStudentInfo() const;

    bool operator<(const Student& other) const;
    bool operator==(const string& otherId) const;
    bool operator==(const Student& other) const;
};

#endif