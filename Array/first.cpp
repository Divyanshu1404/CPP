#include<iostream>
using namespace std;
 
int main()
{
    int size;
    cout<<"enter the size of array : ";
    cin>>size;
    int marks[size];
    cout<<"enter the values of array : ";
    for (int i=0; i<size;i++){
        cin>>marks[i];
    }
    cout <<"the array is  : "<<endl;;
    for(int i= 0 ; i<size ; i++){
        cout<<marks[i]<<"\n";
    }


    return 0;
}