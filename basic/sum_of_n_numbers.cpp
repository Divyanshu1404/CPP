#include<iostream>
using namespace std;
void main(){
    int n; 
    cout<<"enter the value :";
    cin>>n;
    int sum=0;
   
    for (int i=1;i<=n;i++){  ///using for loop
        sum=sum+i;

    }
    // int count=1;       /// using while loop 
    // while(count<=n){
    //     sum=sum+count;
    //     count=count +1;
    // }
    cout<<"Sum :"<<sum<<endl;
}

