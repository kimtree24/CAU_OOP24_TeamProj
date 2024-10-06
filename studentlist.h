#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "student.h"
#include "iomanager.h"
#include <vector>
#include <string>

class StudentList {
private:
    std::vector<Student> students;

public:
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename) const;

    void insertStudent(IOManager& ioManager, const std::string& filename);
    void searchStudent(IOManager& ioManager) const;
    void setSortOption(IOManager& ioManager);
    
    void printAllStudents() const;
};

#endif