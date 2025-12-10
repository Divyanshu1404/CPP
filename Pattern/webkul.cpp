#include<iostream>
using namespace std;


int main(){
    int n=5;
    for (int i=0;i<=n/2;i++){
        for (int j=0;j<i+n/2;j++){
            cout<<" ";
        }
         for(int j=n-(2*i);j>0;j--){
            cout<<"@";
        }
        cout<<endl;
        }

        for(int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if(i==0||j==0||j==n-1){
                    cout<<"*";
                }
                else{
                    cout<<" ";
                }

            }
            cout<<endl;
        }
}
        
    