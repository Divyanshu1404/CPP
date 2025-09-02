#include<iostream>
#include<vector>

using namespace std;

vector<int> pairSum(vector<int>nums,int target){
    vector<int>ans;
    int n=nums.size();
    // for (int i=0;i<n;i++){
    //     for(int j=i;j<n;j++){
    //         if(nums[i]+nums[j]==target){
    //             ans.push_back(i);
    //             ans.push_back(j);
    //             return ans;

    //         }
    //     } 
    // }


    //Using while loop and more optimised ans
    // this is only applicable when the array is in shorted form

    int i=0;
    int j=n-1;

    while(i<j){
        int pairSum=nums[i]+nums[j];
        if(pairSum > target){
            j--;
        }
        else if(pairSum < target){
            i++;
        }
        else{
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }
    return ans;
}
int main()
{
    vector<int>nums={1,2,3,4,8,9,10};
    int target=7;


    vector<int>ans =pairSum(nums ,target);
    cout<<ans[0]<<" , "<<ans[1]<<endl;
    return 0;
}