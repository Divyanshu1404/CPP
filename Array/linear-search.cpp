#include<iostream>

// Linear Search Algorithm Implementation
// This program finds the index of a target value in an array using linear search.
// If the target is not found, it returns -1.

using namespace std;

// Function to perform linear search
// arr: input array
// size: number of elements in the array
// target: value to search for
// Returns the index of target if found, otherwise -1
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Target found, return index
        }
    }
    return -1; // Target not found
}

int main() {
    int size; // Size of the array

    // Input: size of the array
    cout << "enter the size of array : ";
    cin >> size;

    int arr[size]; // Array to store values

    // Input: values of the array
    cout << "enter the values of array : ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int target; // Value to search for
    cin >> target;

    // Output the index of the target value (or -1 if not found)
    cout << "Index : " << linearSearch(arr, size, target) << endl;

    return 0;
}