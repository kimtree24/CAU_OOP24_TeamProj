#ifndef IOMANAGER_H
#define IOMANAGER_H

#include "student.h"
#include <string>
#include <unordered_set>
#include <unordered_map>

class IOManager {
public:
    int showMainMenu() const;
    int showSearchMenu() const;
    int showSortMenu() const;

    Student getStudentInfo() const;
    std::string getSearchInput() const;

    void displayMessage(const std::string& message) const;
};

#endif