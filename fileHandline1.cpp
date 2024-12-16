#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string name;
    int roll;
    float marks;

    // Taking input from the user
    cout << "Enter student name: ";
    getline(cin, name);
    cout << "Enter roll number: ";
    cin >> roll;
    cout << "Enter marks: ";
    cin >> marks;

    // Writing to file using insertion operator (<<)
    ofstream outFile("student.txt");
    if (outFile.is_open()) {
        outFile << name << "\n";
        outFile << roll << "\n";
        outFile << marks << "\n";
        outFile.close();
    } else {
        cerr << "Error opening file for writing!\n";
    }

    // Reading from file using extraction operator (>>)
    ifstream inFile("student.txt");
    if (inFile.is_open()) {
        string readName;
        int readRoll;
        float readMarks;


        getline(inFile, readName);  // Reading string
        inFile >> readRoll >> readMarks; // Reading int and float

        inFile.close();

        cout << "\nStudent Name: " << readName << "\n";
        cout << "Roll Number: " << readRoll << "\n";
        cout << "Marks: " << readMarks << "\n";
    } else {
        cerr << "Error opening file for reading!\n";
    }

    return 0;
}
