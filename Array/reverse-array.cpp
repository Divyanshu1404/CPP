#include<iostream>
using namespace std;

void arrReverse(int arr[],int size){
    int start=0;
    int end=size-1;
    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
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
    arrReverse(arr,size);

    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;

}
