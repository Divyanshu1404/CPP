#include<iostream>
using namespace std;
 int main()
 {
    int n;
    cout<<"enter the value of n :";
    cin>>n;
    int m;
    cout <<"enter the value of m :";

    for(int i=1;i<=n;i++){
        for ( int j=n;j>=-n-1;j--){
             cout<<"*";
        }
    }
    
 } 