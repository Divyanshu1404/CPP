
#include <iostream>
#include <vector>

// Kadane's Algorithm Implementation
// This program finds the maximum sum of a contiguous subarray in a given array.
// It uses Kadane's algorithm, which runs in O(n) time.

using namespace std;

// Class implementing Kadane's algorithm
class kadans {
public:
    // Function to find the maximum subarray sum
    // nums: input vector of integers
    // Returns the maximum sum of any contiguous subarray
    int maxSubArray(vector<int>& nums) {
        int sum = 0;           // Current subarray sum
        int maxi = nums[0];    // Maximum subarray sum found so far
        for (int i = 0; i < nums.size(); i++) {
            sum = sum + nums[i];       // Add current element to sum
            maxi = max(maxi, sum);     // Update maximum if needed

            if (sum < 0)
                sum = 0;               // Reset sum if it becomes negative
        }
        return maxi;
    }
};

int main() {
    kadans sol; // Create an instance of the kadans class
    // Example input array
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    // Find the maximum subarray sum
    int result = sol.maxSubArray(nums);

    // Output the result
    cout << "Maximum Subarray Sum = " << result << endl;

    return 0;
}
