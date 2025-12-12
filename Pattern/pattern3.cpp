#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the value : ";
    cin>>n;
// First Part 
    for (int i=0;i<n;i++){
        for (int j=0;j<(n/2);j++){
            cout<<" ";
        }
        for (int j=0;j<(n+2);j++){
            if(i==0||j==0||j==n+1||i==n-1){
            cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }

    // Second Part
    for(int i=0;i<n;i++){
        for(int j=0;j<(n/2);j++){
            cout<<" ";
        }
        for(int j=0;j<(n+2);j++){
            if(j==0||j==n+1){
                cout<<"@";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    //Third Part
    for (int i=0;i<n/2+1;i++){
        for (int j=0;j<n*2+1;j++){
            if(j>=i && j<=n-1-i||j>=n+1+i && j<=n*2-i){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
     cout<<endl;
    }

}