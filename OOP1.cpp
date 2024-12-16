#include<iostream>
using namespace std;

class Student{
    int a,b,c;      // instance variable, or data members
    public:     // contructor
        Student(){
            a = 5;
            b = 6;
        }

    void input(){
        cout<<"Enter no: ";
        cin>>a>>b;
    } 
    // these(above and below both) are memeber functions of class 
    // constuctor is also member function of class 

    void add(){
        cout<<a+b<<endl;
    }

    // This is a destructor

    ~Student(){
        // calls automatically no need to call it
        cout<<"object destructed";
    }
};


int main(){
    Student S1;
    S1.input();
    S1.add();
}