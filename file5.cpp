#include <iostream>
#include <fstream>

using namespace std;

class Student {
    char name[50];
    int roll;
    float marks;

    Student(name, roll, marks){
        this->name = name;
        this->roll = roll;
        this->marks = marks;
    }
};

void writeToFile(const char* filename, Student s) {
    ofstream outFile(filename, ios::binary);
    outFile.write(reinterpret_cast<char*>(&s), sizeof(Student));
    outFile.close();
}

void readFromFile(const char* filename) {
    ifstream inFile(filename, ios::binary);
    Student s;
    while (inFile.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        cout << "Name: " << s.name << "\nRoll: " << s.roll << "\nMarks: " << s.marks << "\n";
    }
    inFile.close();
}

int main() {
    Student s;
    char name[50];
    cout << "Enter name: "; cin.getline(s.name, 50);
    cout << "Enter roll: "; cin >> s.roll;
    cout << "Enter marks: "; cin >> s.marks;

    writeToFile("student.dat", s);
    cout << "\nReading from file:\n";
    readFromFile("student.dat");

    return 0;
}
