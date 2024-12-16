#include<iostream>
using namespace std;

void add(int a, int b){
    // int a =10, b= 20, c= a+b;
    cout<<"Addition is "<<a+b<<endl;
}

void sub(int a, int b){
    // int a = 20, b =10;
    cout << "Substraction is: "<< a-b<<endl;
}
int main(){
    char ch;
    int k, a,b;
    cout<<"Select something :\n1. Addition \n2.Substraction"<<endl;
    cin>>k;
    switch(k){
        case 1: {
            cout<<"Enter num 1"<<endl;
            cin>>a;
            cout<<"Enter num 2"<<endl;
            cin>>b;
            add(a,b);
            }

    }
    return 0;
}