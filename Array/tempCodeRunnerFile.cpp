
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
