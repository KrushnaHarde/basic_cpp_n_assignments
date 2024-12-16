#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void writeToFile(const string& filename, const string& name, int roll, float marks) {
    ofstream outFile(filename);
    outFile << name << "\n" << roll << "\n" << marks << "\n";
    outFile.close();
}

void readFromFile(const string& filename) {
    ifstream inFile(filename);
    string name;
    int roll;
    float marks;
    while (inFile >> name >> roll >> marks) {
        cout << "Name: " << name << "\nRoll: " << roll << "\nMarks: " << marks << "\n";
    }
    inFile.close();
}

int main() {
    string name;
    int roll;
    float marks;
    cout << "Enter name: "; cin >> name;
    cout << "Enter roll: "; cin >> roll;
    cout << "Enter marks: "; cin >> marks;

    writeToFile("student.txt", name, roll, marks);
    cout << "\nReading from file:\n";
    readFromFile("student.txt");

    return 0;
}
