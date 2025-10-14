#include<iostream>
#include <climits>

// Program to find the smallest element in an array and its index
// Uses a simple linear search to find the minimum value

using namespace std;

int main()
{
    int size; // Size of the array

    // Input: size of the array
    cout << "enter the size of array : ";
    cin >> size;

    int marks[size]; // Array to store values

    // Input: values of the array
    cout << "enter the values of array : ";
    for (int i = 0; i < size; i++) {
        cin >> marks[i];
    }

    int smallest = INT_MAX; // Initialize smallest to maximum possible int
    int index = -1;         // Index of the smallest element

    // Find the smallest element and its index
    for (int i = 0; i < size; i++) {
        if (marks[i] < smallest) {
            smallest = marks[i];
            index = i;
        }
    }

    // Output the smallest value and its index
    cout << "Smallest : " << smallest << endl;
    cout << "index : " << index << endl;
    return 0;
}


// #include <iostream>
// #include <climits>
// using namespace std;

// // Function to find smallest element in array
// int findMin(int arr[], int n) {
//     int smallest = INT_MAX;
//     for (int i = 0; i < n; i++) {
//         if (arr[i] < smallest) {
//             smallest = arr[i];
//         }
//     }
//     return smallest;
// }

// int main() {
//     int size;
//     cout << "Enter the size of array: ";
//     cin >> size;

//     int marks[size];   // works in GCC/Clang (Variable Length Array), 
//                        // not standard C++ but supported by many compilers

//     cout << "Enter the values of array: ";
//     for (int i = 0; i < size; i++) {
//         cin >> marks[i];
//     }

//     int smallest = findMin(marks, size);

//     cout << "Smallest: " << smallest << endl;
//     return 0;
// }
