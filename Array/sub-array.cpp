#include<iostream>
#include<vector>

// Program to print all possible subarrays of a fixed array
// Each subarray is printed in order, separated by spaces

using namespace std;

int main()
{
    int n = 5; // Size of the array
    int arr[5] = {1, 2, 3, 4, 5}; // Array elements

    // Outer loop: starting index of subarray
    for (int st = 0; st < n; st++) {
        // Middle loop: ending index of subarray
        for (int end = st; end < n; end++) {
            // Inner loop: print elements from st to end
            for (int i = st; i <= end; i++) {
                cout << arr[i];
            }
            cout << " "; // Separate subarrays by space
        }
        cout << endl; // Newline after all subarrays starting at st
    }
    return 0;
}

// #include <iostream>
// #include <vector>
// using namespace std;

// // Function to find the maximum sum subarray using DP (Kadane's algorithm)
// int maxSubArraySum(const vector<int>& arr) {
//     int n = arr.size();
//     int max_sum = arr[0];
//     int current_sum = arr[0];

//     for (int i = 1; i < n; i++) {
//         // DP relation: current_sum = max(arr[i], current_sum + arr[i])
//         current_sum = max(arr[i], current_sum + arr[i]);
//         max_sum = max(max_sum, current_sum);
//     }
//     return max_sum;
// }

// int main() {
//     vector<int> arr = {1, 2, 3, 4, 5}; // You can change the array as needed
//     int result = maxSubArraySum(arr);
//     cout << "Maximum subarray sum: " << result << endl;
//     return 0;
// }