#include <iostream>
using namespace std;

int main() {
    int n = 5;
    for (int i=n/2;i>=0;i--) {
        for (int j=0;j<i+n/2;j++) {
            cout<<" ";
        }
        for (int j=n-(2*i);j>0;j--) {
            cout << "*";
        }
        cout << endl;
    }
        
        for (int i=0;i<n;i++){
            for (int j=1;j<2*n+1;j++){
                if(j==n){
                    cout<<"*";
                }
                else{
                    cout<<" ";
                }
            }
            cout<<endl;
        }
        for (int i=0;i<5;i++){
            for (int j=0;j<2*n+1;j++){
                if(j==(n/2)-1||j==2*n-(n/2+1)||i==0 && j>=n/2&&j<2*n-n/2){
                    cout<<"*";

                }
                else{
                    cout<<" ";
                }
            }
            cout<<endl;
        }
         for (int i=0;i<=n/2;i++){
            for (int j=0;j<i+n;j++){
                cout<<" ";
        }
         for(int j=n-(2*i);j>0;j--){
            cout<<"*";
        }
        cout<<endl;
        }
    }


