#include<iostream>
using namespace std;

int linearSearch(int arr[],int size,int target){
    for (int i=0;i<size;i++){
        if (arr[i]==target){
            return i;
        }
    }
    return -1;
}

int main()
{
    int size;
     cout<<"enter the size of array : ";
    cin>>size;
    
    int arr[size];    
    cout<<"enter the values of array : ";
    for (int i=0; i<size;i++){
        cin>>arr[i];
    }

    int target;
    cin>>target;

    cout<<linearSearch(arr,size,target)<endl;

    return 0;
}