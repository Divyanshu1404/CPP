#include<iostream>
#include <climits>
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
    int smallest=INT_MAX;
    for(int i=0;i<size;i++){
        if(marks[i]<smallest){
            smallest=marks[i];
        }
    }
    cout<<"Smallest : "<<smallest<<endl;
    return 0;
}
