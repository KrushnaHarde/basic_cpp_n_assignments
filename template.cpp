#include<iostream>
using namespace std;
template <typename T>
void selection_sort(T arr[], int n){
    for(int i=0; i<n-1; i++){
        int index = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[index]){
                index = j;
            }
        }
        swap(arr[i],arr[index]);
    }
}

template <typename T>
void print_array(T arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    const int max=100;
    int intArray[max];
    float floatArray[max];

    int intn;
    cout<<"Enter the no. of elements in integer array: "<<endl;
    cin>>intn;

    cout<<"Enter the "<<intn<<" integer elements: "<<endl;
    for(int i=0; i<intn; i++){
        cin>>intArray[i];
    }

    cout<<"Original array: "<<endl;
    print_array(intArray, intn);
    selection_sort(intArray, intn);
    cout<<"Sorted array: "<<endl;
    print_array(intArray, intn);

    float floatn;
    cout<<"Enter the no. of elements in float array: "<<endl;
    cin>>floatn;

    cout<<"Enter the "<<floatn<<" float elements: "<<endl;
    for(int i=0; i<floatn; i++){
        cin>>floatArray[i];
    }

    cout<<"Original array: "<<endl;
    print_array(floatArray, floatn);
    selection_sort(floatArray, floatn);
    cout<<"Sorted array: "<<endl;
    print_array(floatArray, floatn);

    return 0;

}