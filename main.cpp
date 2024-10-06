#include <iostream>
#include <fstream>
#include <string>
#include "studentlist.h"
#include "iomanager.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " file1.txt" << endl;
        return 1;
    }

    string filename = argv[1];
    ifstream file(filename);
    if (!file) {
        cout << "No file. Create new file " << filename << endl;
        ofstream newfile(filename);  // 파일이 없으면 생성
        newfile.close();
    } else{
        cout << "Success open " << filename << endl;
        file.close();
    }

    StudentList studentList;
    IOManager ioManager;

    studentList.loadFromFile(filename);  // 파일에서 학생 정보 로드

    while(true){
        int choice = ioManager.showMainMenu();

        if (choice == 1){
            studentList.insertStudent(ioManager, filename);
        } else if (choice == 2){
            studentList.searchStudent(ioManager);
        } else if (choice == 3){
            studentList.setSortOption(ioManager);
        } else if (choice == 4){
            cout << "End" << endl;
            break;
        } else {
            cerr << "Wrong input. Try agin." << endl;
        }
    }
    return 0;
}