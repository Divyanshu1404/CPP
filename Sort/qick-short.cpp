#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>&arr, int st, int end){
    int pivIdx=arr[end];
    int idx=st - 1;
    for (int j=st;j<end;j++){
        if(arr[j] <= pivIdx){
            idx++;
            swap(arr[j],arr[idx]);
        }
    }
    idx++;
    swap(arr[end],arr[idx]);
    return idx;
}

void QuickSort(vector<int>&arr ,int st,int end){
    if(st < end){
        int pivIdx = partition(arr ,st ,end);
        QuickSort(arr,st,pivIdx-1);
        QuickSort(arr,pivIdx+1,end);
    }
}

 int main()
 {
    vector<int>arr ={2,1,3,4,5,6};
    QuickSort(arr,0,arr.size()-1);
    for (int val :arr){
        cout<<val<<" "; 
    }
    cout<<endl;
    return 0;
}