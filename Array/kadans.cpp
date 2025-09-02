
#include <iostream>
#include <vector>
using namespace std;

class kadans {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            sum = sum + nums[i];
            maxi = max(maxi, sum);

            if (sum < 0)
                sum = 0;
        }
        return maxi;
    }
};

int main() {
    kadans sol;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int result = sol.maxSubArray(nums);
    cout << "Maximum Subarray Sum = " << result << endl;

    return 0;
}
