#ifndef IOMANAGER_H
#define IOMANAGER_H

#include "student.h"
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;
class IOManager {
public:
    int showMainMenu();
    int showSearchMenu();
    int showSortMenu();

    Student getStudentInfo();
    string getSearchInput();

    void displayMessage(string &message);
};

#endif