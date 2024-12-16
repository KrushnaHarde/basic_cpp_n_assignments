#include <iostream>
using namespace std;

class Complex{
    int real, img;

public:
    Complex(){
        real = 0;
        img = 0;
    }
    Complex(int real, int img){
        this->real = real;
        this->img = img;
    }
    Complex operator+(Complex& obj){
        Complex temp;
        temp.real = this->real + obj.real;
        temp.img = this->img + obj.img;
        return temp; 
    }
    friend istream& operator>>(istream&, Complex& obj){
        cin>>obj.real;
        cin>>obj.img;
        return cin;
    }
    friend ostream& operator<<(ostream&, Complex& obj){
        cout<<obj.real<<"+"<<obj.img<<"i"<<endl;
        return cout;
    }
};
int main(){
    Complex c1;
    Complex c2(10, 5);
    cin>>c1;
    Complex c3 ;
    c3 = c1 + c2;
    cout<<c3;
}