#include<iostream>
using namespace std;
int main(){
    int n;
    cout <<"enter the number :";
    cin>>n;
  //using for loop
    // for(int i=1;i<=n;i++){
    //     cout<<i;
    //     cout<<"\n";
    // }
    //using while loop
    int count=1; 
    while (count<=n){
        cout<<count;
        cout<<"\n";
        count++;
    }
}