#include <iostream>
using namespace std;

class Complex
{
    int a, b, c, d; // instance variable, or data members
public:             // contructor
    Complex()
    {
        cout << "Enter a real part of complex no.: " << endl;
        cin >> a;
        cout << "Enter a img part of complex no.: " << endl;
        cin >> b;
        cout << "Enter a real part of complex no.: " << endl;
        cin >> c;
        cout << "Enter a img part of complex no.: " << endl;
        cin >> d;
        cout << "The first complex no is " << a << " + " << b << "i" << endl;
        cout << "The second complex no is " << c << " + " << d << "i" << endl;
    }

    void add()
    {
        cout << "Addition of complex no. is" << endl;
        cout << a + c << " + " << b + d << "i" << endl;
    }

    // This is a destructor

    ~Complex()
    {
        // calls automatically no need to call it
        cout << "object destructed";
    }
};

int main()
{
    Complex C1;
    C1.add();
}