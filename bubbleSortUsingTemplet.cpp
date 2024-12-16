#include <iostream>
using namespace std;

template <typename T>
void bubbleSort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main(){

    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    float arr2[] = {3.14, 2.718, 1.414, 1.618, 2.72};

    bubbleSort(arr1, 7);
    bubbleSort(arr2, 5);

    cout << "Sorted integer array: ";
    for (int i = 0; i < 7; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    cout << "Sorted float array: ";
    for (int i = 0; i < 5; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
}