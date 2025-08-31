#include<iostream>
#include <climits>
using namespace std;
 
// int findMin(int smallest){
//     smallest=INT_MAX;
//     for
// }
int main()
{
    int size;

    int marks[size];
    
    for (int i=0; i<size;i++){
        cin>>marks[i];
    }
    for(int i= 0 ; i<size ; i++){
        cout<<marks[i];
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