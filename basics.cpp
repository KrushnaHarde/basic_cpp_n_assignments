#include<iostream>
using namespace std;

void fibonacci(int n){
    int first = 0, second = 1;
    if(n < 0){
        cout<<"Enter number greater than 0";
    }
    for(int i=0; i<n; i++){
        cout<<first<<", ";
        int temp = second;
        second += first;
        first = temp; 
    }
}
int main(){
    // dataType     size        range
    // int	    4 bytes	    -2^31 to 2^31-1
    // float	4 bytes	    N/A
    // double	8 bytes	    N/A
    // char	    1 byte	    -128 to 127
    // bool	    1 byte	    true / false
    // void	    N/A	        N/A
    // wchar_t	2 or 4 bytes	1 wide character

    wchar_t any = 'A';
    cout<<"Wide character Value : "<<any<<endl;
    cout<<"Size if wide char is : "<<sizeof(any)<<" Bytes"<<endl;

    fibonacci(10);

    // Just like pass by Refernce

    int i = 1;
    int& ri = i; // ri is a reference to i
    // int& is used to pass bhy reference, if doen't use it will be pass by value

    ri = 2; // i is now changed to 2
    cout << "\ni=" << i<<endl;

    i = 3;   // i is now changed to 3
    cout << "ri=" << ri<<endl;

    // tirnary operator

    int x = 3, y = 5, max;
    max = (x > y) ? x : y;

    // Outputs: 5
    std::cout << max << std::endl;

    // ARRAY'S IN CPP


    int marks[5] = {10,12,19,28,35};
    cout<< marks[2]<<endl;
    marks[1] = 39;
    cout<< marks[1]<<endl;


    char ref[5] = {'R', 'e', 'f'};

    // Range based for loop    for each loop
    // for each loop generally passes by value
    
    for (const char &n : ref) {     // &n or char& n will create a reference to the array ref
    // this loop will ilterate over an array

        //std::string(1, n): This constructor creates a std::string object with a single character n
        // 1: This is the number of times to repeat the character n. In this case, it is 1, so the string will contain exactly one occurrence of the character n.
        // n: This is the character to be repeated in the string. It is taken from the current element in the ref array during each iteration of the loop.

        std::cout << std::string(1, n);     //Ref
    }

    return 0;
}