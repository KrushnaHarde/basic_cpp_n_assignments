#include <iostream>
#include <fstream>  
#include <string>

using namespace std;

int main() {
    
    string s = "opt.txt";
    
    ofstream optFile(s);
    
    if (!optFile) {
        cerr << "Error!" << endl;
        return 1;
    }

    optFile << "It is a test file!" << endl;
    optFile << "Write data into the file." << endl;
    optFile << "End of the file." << endl;
 
    optFile.close();

    ifstream inFile(s);
 
    if (!inFile) {
        cerr << "Error!" << endl;
        return 1;
    }

    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
  
    inFile.close();
    
    return 0;
}