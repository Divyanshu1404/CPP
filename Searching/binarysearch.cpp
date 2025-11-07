#include<iostream>
#include<vector>
using namespace std;
// Binary Search Algorithm Implementation
// This program finds the index of a target value in a sorted array using binary search.    
// If the target is not found, it returns -1.   
 int binarySearch(vector<int>&arr,int target){
    int st=0, end=arr.size()-1;
    while(st <= end){
       int mid=st+(end-st)/2;
        // int mid=(st+end)/2;
        if(target>arr[mid]){
            st=mid+1;
        }
        else if(target<arr[mid]){
            end=mid-1;
        }
        else{
            return mid;
        }
    }
        return -1;
    
 }
int main()
{
    vector<int>arr={1,2,3,4,5,6,7,8,9,10};
    int target;
    cin>>target;
    // cout<<binarySearch(arr,target)<<endl;
    cout << "Index : " << binarySearch(arr, target) << endl;
    return 0;
}