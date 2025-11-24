#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;        // Current subarray sum
        int maxi = nums[0]; // Maximum sum found so far

        for (int i = 0; i < nums.size(); i++) {
            sum = sum + nums[i];           // Add current element to running sum
            maxi = max(maxi, sum);         // Update max if current sum is larger

            // If sum becomes negative, it's better to start fresh from next element
            if (sum < 0)
                sum = 0;
        }
        return maxi;
    }
};
