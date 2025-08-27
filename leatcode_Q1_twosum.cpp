// Leatcode Q1 Two Sum

#include<iostream>
#include<vector>
#include<unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int,int>numToIndexMap;

        for(int i=0;i<nums.size();i++){
            int diff=target-nums[i];

            if(numToIndexMap.find(diff) !=numToIndexMap.end()){
                return{i,numToIndexMap[diff]};
            }

            numToIndexMap[nums[i]]=i;
        }
        return {};
        
    }
};
int main(){
    Solution sol;
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> result = sol.twoSum(nums, target);
    
    std::cout << "Indices: [" << result[0] << ", " << result[1] << "]" << std::endl;
    return 0;
}