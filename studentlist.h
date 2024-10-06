#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "student.h"
#include "iomanager.h"
#include <vector>
#include <string>

using namespace std;

class StudentList {
private:
    vector<Student> students;

public:
    void loadFromFile(const string& filename);
    void saveToFile(const string& filename) const;

    void insertStudent(IOManager& ioManager, const string& filename);
    void searchStudent(IOManager& ioManager) const;
    void setSortOption(IOManager& ioManager);
    
    void printAllStudents() const;
};

#endif