#include<iostream>
using namespace std;
class complex{
    int r,im;
    public:
    complex(){
        r = im = 0;
    }
    void input(){
        cout << "enter the real and imaginary parts" << endl;
        cin >> r >> im;

    }
    void add_complex(complex s, complex s1){
        r = s.r + s1.r;
        im = s.im
         + s1.im;
        cout << " the new complex no is " << r << "+i" << im << endl;
    }
};

int main(){
    complex c,c1;
    c.input();
    c1.input();
    c.add_complex(c,c1);

    return 0;
}