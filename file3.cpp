#include <iostream>
#include <fstream>
using namespace std;

class Person{
    char name[8];
    int age;
public:
    Person(){
        age = 0;
        name[0] = '\0';
    }
    void input() {
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter age: ";
        cin>>age;
    }

    void display() {
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age<<endl;
    }
    
    void write_data() {
        ofstream ofs("Person_binaryIO.txt", ios::binary | ios::app);
        ofs.write(reinterpret_cast<char*>(this), sizeof(*this));
        ofs.close();
    }

    void read_data() { 
        ifstream ifs("Person_binaryIO.txt", ios::binary);
        
        while(!ifs.eof()){
            ifs.read(reinterpret_cast<char*>(this), sizeof(*this));
            if(ifs.eof())break;
            this->display();
        }
        ifs.close();
    }
};

int main() {
    Person p;
    char ch = 'y';
    cout << "Enter details: " << endl;
    do {
        p.input();
        p.write_data();

        cout << "Add other person ? (y/n): ";
        cin >> ch;
    } while (ch == 'y');
    
    cout<<"\nDetails in File: "<<endl;
    p.read_data();
    cout<<endl;
    
    return 0;
}