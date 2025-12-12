#include<iostream>
using namespace std;

int main(){
     int n;
     cout<<"Enter the number : ";
     cin>>n;
/// First Part.
        for (int i=0;i<n/2+1;i++){
            for (int j=0;j<2*n+1-i;j++){
                cout<<" ";
            }
            for (int j=0;j<2*i+1;j++){
                cout<<"*";
            }
            cout<<endl;
        }
    // Second Part.
        for (int i=0;i<n-1;i++){
            for (int j=0;j<2*n+1;j++){
                cout<<" ";
            }
            for (int j=0;j<1;j++){
                cout<<"*";
            }
            cout<<endl;
        }
        //Third Part
        for (int i=0;i<n/2;i++){
            for (int j=0;j<n+2;j++){
                cout<<" ";
            }
            for (int j=0;j<n;j++){
                if(i==0||j==0){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
            }
            cout<<endl;
        }
//Fourth Part
        for (int i=0;i<n;i++){
            for (int j=0;j<n/2+1;j++){
                if(j>=n/2-i && j>=i-n/2){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
            }
            for (int j=0;j<n/2+2;j++){
                if(i==n/2){
                    cout<<"*";
                }
                else
                 cout<<" ";
            }
            for (int j=0;j<1;j++){
                if(i<n-1){
                cout<<"*";
                }
            }
            cout<<endl;
            }
}