#include "studentlist.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

// 학생 이름을 기준으로 정렬하는 함수
bool compareByName(const Student& a, const Student& b) {
    return a.getName() < b.getName();
}

// 학생 ID를 기준으로 정렬하는 함수
bool compareById(const Student& a, const Student& b) {
    return a.getId() < b.getId();
}

// 출생 연도를 기준으로 정렬하는 함수
bool compareByBirthYear(const Student& a, const Student& b) {
    return a.getBirthYear() < b.getBirthYear();
}

// 학과를 기준으로 정렬하는 함수
bool compareByDepartment(const Student& a, const Student& b) {
    return a.getDepartment() < b.getDepartment();
}

// 파일에서 학생 목록을 불러오는 함수
void StudentList::loadFromFile(const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(infile, line)) {  // 한 줄씩 읽음
        std::stringstream ss(line);       // 줄을 스트림으로 변환

        std::string name, id, birthYear, department, phone;
        std::getline(ss, name, '/');      // '/'를 기준으로 데이터 분리
        std::getline(ss, id, '/');
        std::getline(ss, birthYear, '/');
        std::getline(ss, department, '/');
        std::getline(ss, phone, '/');

        students.push_back(Student(name, id, birthYear, department, phone));
    }
    infile.close();

    sort(students.begin(), students.end(), compareByName);  // 정렬
}

// 파일에 학생 목록을 저장하는 함수
void StudentList::saveToFile(const std::string& filename) const {
    std::ofstream outfile(filename);
    if (!outfile) {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        return;
    }

    for (std::vector<Student>::const_iterator it = students.begin(); it != students.end(); ++it) {
        const Student& student = *it;
        outfile << student.getName() << "/" 
                << student.getId() << "/" 
                << student.getBirthYear() << "/" 
                << student.getDepartment() << "/" 
                << student.getPhone() << std::endl;
    }
    outfile.close();
}

// 학생을 삽입하는 함수
void StudentList::insertStudent(IOManager& ioManager, const std::string& filename) {
    Student newStudent = ioManager.getStudentInfo();

    // 중복된 학생 ID 체크
    for (std::vector<Student>::const_iterator it = students.begin(); it != students.end(); ++it) {
        const Student& student = *it;
        if (student == newStudent.getId()) {
            ioManager.displayMessage("Error: 이미 삽입됨");
            return;
        }
    }

    students.push_back(newStudent);
    saveToFile(filename);  // 삽입 후 파일에 저장
    ioManager.displayMessage("학생 정보가 삽입되었습니다.");
}

// 학생을 검색하는 함수
void StudentList::searchStudent(IOManager &ioManager) const {
    int searchOption = ioManager.showSearchMenu();
    std::string searchInput;
    searchInput = ioManager.getSearchInput();

    while(true){
        if (searchOption == 1){
        for (std::size_t i = 0; i < students.size(); ++i) {
            const Student& student = students[i];
            if (student.getName() == searchInput) {
                student.printStudentInfo();
            }
        }
        ioManager.showMainMenu();
        break;
    } else if (searchOption == 2){
        for (std::size_t i = 0; i < students.size(); ++i) {
            const Student& student = students[i];
            if (student.getId() == searchInput) {
                student.printStudentInfo();
            }
        }
        ioManager.showMainMenu();
        break;
    } else if (searchOption == 3){
        for (std::size_t i = 0; i < students.size(); ++i) {
            const Student& student = students[i];
            std::string AdmissionYear = student.getId().substr(0, 4);
            if (AdmissionYear == searchInput) {
                student.printStudentInfo();
            }
        }
        ioManager.showMainMenu();
        break;
    } else if (searchOption == 4){
        for (std::size_t i = 0; i < students.size(); ++i) {
            const Student& student = students[i];
            if (student.getBirthYear() == searchInput) {
                student.printStudentInfo();
            }
        }
        ioManager.showMainMenu();
        break;
    } else if (searchOption == 5){
        for (std::size_t i = 0; i < students.size(); ++i) {
            const Student& student = students[i];
            if (student.getDepartment() == searchInput) {
                student.printStudentInfo();
            }
        }
        ioManager.showMainMenu();
        break;
    } else if (searchOption == 6){
        printAllStudents();
        ioManager.showMainMenu();
        break;
    } else {
        ioManager.displayMessage("Wrong Input.");
    }
    }
}

// 정렬 옵션을 설정하는 함수
void StudentList::setSortOption(IOManager& ioManager) {
    int sortOption = ioManager.showSortMenu();
    switch (sortOption) {
        case 1:
            std::sort(students.begin(), students.end(), compareByName);
            break;
        case 2:
            std::sort(students.begin(), students.end(), compareById);
            break;
        case 3:
            std::sort(students.begin(), students.end(), compareByBirthYear);
            break;
        case 4:
            std::sort(students.begin(), students.end(), compareByDepartment);
            break;
        default:
            ioManager.displayMessage("Wrong Input");
    }
    ioManager.displayMessage("Change SortOption");
    ioManager.showMainMenu();
}

// 모든 학생 정보를 출력하는 함수
void StudentList::printAllStudents() const {
    for (std::size_t i = 0; i < students.size(); ++i) {
        students[i].printStudentInfo();
    }
}