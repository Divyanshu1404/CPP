#include<iostream>
using namespace std;

int arrReverse(int arr[],int size){
    int start0;
    int end=size-1;
       for (int i=0; i<size;i++){
       
    }
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

    cout<<"Reverse Array : "<<arrReverse()<<endl;

    return 0;
}