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
    void loadFromFile(string& filename);
    void saveToFile(string& filename);

    void insertStudent(IOManager& ioManager, string& filename);
    void searchStudent(IOManager& ioManager);
    void setSortOption(IOManager& ioManager);
    void modifyStudent(IOManager& ioManager, string& filename); //추가
    
    void printAllStudents();
};

#endif