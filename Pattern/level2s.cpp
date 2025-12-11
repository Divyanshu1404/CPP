#include<iostream>
using namespace std;
int main(){
    int n; 
    cout<<"Enter the number : ";
    cin>>n;
     
    for (int i=0;i<(n/2)+1;i++){
        for(int j=0;j<n-i;j++){
            cout<<" ";
        }
        for (int j=0;j<(2*i)+1;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout<<" ";
        }
        for(int j=0;j<1;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    for (int i=0;i<n;i++){
        for(int j=0;j<n/2;j++){
            cout<<" ";
        }
        for(int j=0;j<n+2;j++){
          if(i==0||j==0||j==n+1){
            cout<<"*";
          }
          else{
            cout<<" ";
          }
          cout<<endl;
        }
    }
    //  for (int i=0;i<5;i++){
    //         for (int j=0;j<2*n+1;j++){
    //             if(j==(n/2)-1||j==2*n-(n/2+1)||i==0 && j>=n/2&&j<2*n-n/2){
    //                 cout<<"*";

    //             }
    //             else{
    //                 cout<<" ";
    //             }
    //         }
    //         cout<<endl;
    //     }
} 
