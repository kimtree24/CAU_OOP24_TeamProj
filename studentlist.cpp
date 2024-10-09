 #include "studentlist.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

// 학생 이름을 기준으로 정렬하는 함수
bool compareByName(Student &a, Student &b) {
    return a.getName() < b.getName();
}

// 학생 ID를 기준으로 정렬하는 함수
bool compareById(Student &a, Student &b) {
    return a.getId() < b.getId();
}

// 출생 연도를 기준으로 정렬하는 함수
bool compareByBirthYear(Student &a, Student &b) {
    return a.getBirthYear() < b.getBirthYear();
}

// 학과를 기준으로 정렬하는 함수
bool compareByDepartment(Student &a, Student &b) {
    return a.getDepartment() < b.getDepartment();
}

// 파일에서 학생 목록을 불러오는 함수
void StudentList::loadFromFile(string &filename) {
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error: Cannot open file " << filename << endl;
        return;
    }

    string line;
    while (getline(infile, line)) {  // 한 줄씩 읽음
        stringstream ss(line);       // 줄을 스트림으로 변환

        string name, id, birthYear, department, phone;
        getline(ss, name, '/');      // '/'를 기준으로 데이터 분리
        getline(ss, id, '/');
        getline(ss, birthYear, '/');
        getline(ss, department, '/');
        getline(ss, phone, '/');

        students.push_back(Student(name, id, birthYear, department, phone));
    }
    infile.close();

    sort(students.begin(), students.end(), compareByName);  // 정렬
}

// 파일에 학생 목록을 저장하는 함수
void StudentList::saveToFile(string &filename) {
    ofstream outfile(filename);
    if (!outfile) {
        cerr << "Error: Cannot open file " << filename << endl;
        return;
    }

    for (size_t i = 0; i < students.size(); ++i) {
        Student &student = students[i];
        outfile << student.getName() << "/" 
                << student.getId() << "/" 
                << student.getBirthYear() << "/" 
                << student.getDepartment() << "/" 
                << student.getPhone() << endl;
    }
    outfile.close();
}

// 학생을 삽입하는 함수
void StudentList::insertStudent(IOManager &ioManager,string &filename) {
    Student newStudent = ioManager.getStudentInfo();

    // 중복된 학생 ID 체크
    for (size_t i = 0; i < students.size(); ++i) {
        Student &student = students[i];
        if (student.getId() == newStudent.getId()) {
            cout << "Error: already exist" << endl;
            //ioManager.displayMessage("Error: already exist");
            return;
        }
    }

    students.push_back(newStudent);
    saveToFile(filename);  // 삽입 후 파일에 저장
    cout << "insert complete" << endl;
    //ioManager.displayMessage("학생 정보가 삽입되었습니다.");
}

// 학생을 검색하는 함수
void StudentList::searchStudent(IOManager &ioManager) {
    int searchOption = ioManager.showSearchMenu();
    string searchInput;
    bool found = false; // 결과를 찾았는지 확인하기 위한 플래그

    if (searchOption == 1) {
        cout << "Input name" << endl;
        searchInput = ioManager.getSearchInput();
        cout << left << setw(15) << "Name" 
         << setw(15) << "StudentID" 
         << setw(30) << "Dept" 
         << setw(15) << "Birth Year" 
         << setw(12) << "Tel"
         << endl;

    cout << string(90, '-') << endl;
        for (size_t i = 0; i < students.size(); ++i) {
            Student &student = students[i];
            if (student.getName() == searchInput) {
                student.printStudentInfo();
                found = true;
            }
        }
    } else if (searchOption == 2) {
        cout << "Input Student ID" << endl;
        searchInput = ioManager.getSearchInput();
        cout << left << setw(15) << "Name" 
         << setw(15) << "StudentID" 
         << setw(30) << "Dept" 
         << setw(15) << "Birth Year" 
         << setw(12) << "Tel"
         << endl;

    cout << string(90, '-') << endl;
        for (size_t i = 0; i < students.size(); ++i) {
            Student &student = students[i];
            if (student.getId() == searchInput) {
                student.printStudentInfo();
                found = true;
            }
        }
    } else if (searchOption == 3) {
        cout << "Input AdmissionYear" << endl;
        searchInput = ioManager.getSearchInput();
        cout << left << setw(15) << "Name" 
         << setw(15) << "StudentID" 
         << setw(30) << "Dept" 
         << setw(15) << "Birth Year" 
         << setw(12) << "Tel"
         << endl;

    cout << string(90, '-') << endl;
        for (size_t i = 0; i < students.size(); ++i) {
            Student &student = students[i];
            string AdmissionYear = student.getId().substr(0, 4);
            if (AdmissionYear == searchInput) {
                student.printStudentInfo();
                found = true;
            }
        }
    } else if (searchOption == 4) {
        cout << "Input Birth Year" << endl;
        searchInput = ioManager.getSearchInput();
        cout << left << setw(15) << "Name" 
         << setw(15) << "StudentID" 
         << setw(30) << "Dept" 
         << setw(15) << "Birth Year" 
         << setw(12) << "Tel"
         << endl;

    cout << string(90, '-') << endl;
        for (size_t i = 0; i < students.size(); ++i) {
            Student &student = students[i];
            if (student.getBirthYear() == searchInput) {
                student.printStudentInfo();
                found = true;
            }
        }
    } else if (searchOption == 5) {
        cout << "Input Department name keyword" << endl;
        searchInput = ioManager.getSearchInput();
        cout << left << setw(15) << "Name" 
         << setw(15) << "StudentID" 
         << setw(30) << "Dept" 
         << setw(15) << "Birth Year" 
         << setw(12) << "Tel"
         << endl;

    cout << string(90, '-') << endl;
        for (size_t i = 0; i < students.size(); ++i) {
            Student &student = students[i];
            if (student.getDepartment() == searchInput) {
                student.printStudentInfo();
                found = true;
            }
        }
    } else if (searchOption == 6) {
        if (students.empty()) {
            cout << "No students." << endl;
            //ioManager.displayMessage("No students.");
        } else {
            printAllStudents();
            found = true;
        }
    } else {
        cout << "Wrong Input." << endl;
        //ioManager.displayMessage("Wrong Input.");
    }

    if (!found) {
        cout << "Nothing" << endl;
        //ioManager.displayMessage("Nothing"); // 검색 결과가 없을 때 출력
    }
}

// 정렬 옵션을 설정하는 함수
void StudentList::setSortOption(IOManager &ioManager) {
    int sortOption = ioManager.showSortMenu();
    switch (sortOption) {
        case 1:
            sort(students.begin(), students.end(), compareByName);
            break;
        case 2:
            sort(students.begin(), students.end(), compareById);
            break;
        case 3:
            sort(students.begin(), students.end(), compareByBirthYear);
            break;
        case 4:
            sort(students.begin(), students.end(), compareByDepartment);
            break;
        default:
            cout << "Wrong Input" << endl;
            //ioManager.displayMessage("Wrong Input");
            return;
    }
    cout << "Sorting option has been set." << endl;
    //ioManager.displayMessage("Sorting option has been set.");
}

// 모든 학생 정보를 출력하는 함수
void StudentList::printAllStudents() {
    cout << left << setw(15) << "Name" 
         << setw(15) << "StudentID" 
         << setw(30) << "Dept" 
         << setw(15) << "Birth Year" 
         << setw(12) << "Tel"
         << endl;

    cout << string(90, '-') << endl;

    for (size_t i = 0; i < students.size(); ++i) {
        students[i].printStudentInfo();
    }
}


// 추가
// 학생 정보 수정하는 함수
void StudentList::modifyStudent(IOManager& ioManager, string& filename) {
    cout << "Student ID: ";
    string studentId = ioManager.getSearchInput();

    int idx = 0;
    // 학생 검색
    for (size_t i = 0; i < students.size(); ++i) {
        Student& student = students[i];
        idx += 1;
        if (student.getId() == studentId) {
            cout << "Find student. Enter New Info" << endl;
            // 이름
            cout << "Name: ";
            string newName;
            getline(cin, newName);
            if (!newName.empty()) {
                student.setName(newName);
            }
            // 생년
            cout << "Birth Year (4 digits): ";
            string newBirthYear;
            getline(cin, newBirthYear);
            if (!newBirthYear.empty()) {
                student.setBirthYear(newBirthYear);
            }
            // 학과
            cout << "Department: ";
            string newDepartment;
            getline(cin, newDepartment);
            if (!newDepartment.empty()) {
                student.setDepartment(newDepartment);
            }
            // 전화번호
            cout << "Tel: ";
            string newPhone;
            getline(cin, newPhone);
            if (!newPhone.empty()) {
                student.setPhone(newPhone);
            }
            
            cout << "Updated successfully." << endl;
            saveToFile(filename);
            break;
        }
        else if(idx == students.size()) {
            cout << "Error: Student ID not found." << endl;
        }
    }
}