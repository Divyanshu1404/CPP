#include<iostream>
using namespace std;
 void changeArr(int arr[],int size){
    cout<<"In function\n";
    for(int i=0;i<size;i++){
        arr[i]=2*arr[i];

    }
 }

int main()
{
    int arr[]={2,5,8};
    changeArr(arr,3);


     for(int i=0;i<3;i++){
        arr[i]=2*arr[i];
        cout<<"changed arr : "<<arr[i];
    }
    cout<<endl;
    
    return 0;
}