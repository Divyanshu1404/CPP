#include<iostream>
#include<vector>
using namespace std;
// Binary Search Algorithm Implementation
// This program finds the index of a target value in a sorted array using binary search
int BinarySearch(vector<int>&arr, int st, int target, int end){
    if(st<=end){
        int mid=st+(end-st)/2;
        if(target>arr[mid]){
            return BinarySearch(arr, mid+1, target, end);
        }
        else if(target< arr[mid]){
            return BinarySearch(arr, st, target, mid-1);
        }
        else{
            return mid;
        }
    }
    return -1;
}
int main(){
    vector<int>arr={1,2,3,4,5,6,7,8,9,10};
    int target;
    cin>>target;
    cout << "Index : " << BinarySearch(arr, 0, target, arr.size()-1) << endl;
    return 0;
}