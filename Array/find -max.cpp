#include <iostream>
#include <climits>
using namespace std;

// Function to find largest element in array
int findMax(int arr[], int n) {
    int largest = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {   // corrected condition
            largest = arr[i];
        } 
    }
    return largest;
}

int main() {
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    int marks[size];  

    cout << "Enter the values of array: ";
    for (int i = 0; i < size; i++) {
        cin >> marks[i];
    }

    int largest = findMax(marks, size);

    cout << "Largest : " << largest << endl;
    return 0;
}
