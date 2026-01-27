#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=i+1;j>0;j--){
            cout<<"*";
            
        }
        cout<<"\n";
    }
    for (int i=n;i>0;i--){
        for(int j=i-1;j>0;j--){
            cout<<"*";
        }
        cout<<"\n";
    }
}