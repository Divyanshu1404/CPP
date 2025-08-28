#include<iostream>
using namespace std;
 int main(){
    int n;
    cout <<"enter the number :";
    cin>>n;
    bool isPrime=true;
  //for (int i=2;i<=n-1;i++)
    for (int i=2;i*i<=n-1;i++){
        if(n%i ==0){
            isPrime=false;
            break;
        }
    }
    // if(n<=1){
    //     isPrime=false;
    // }
    // else{

    //      for (int i=2;i<=n;i++){
    //     if(n % 2==0){
    //        isPrime=false; 
    //        break;
    //     }
    // }
    if(isPrime){
        cout<<"prime number";

    }
    else{
        cout<<"not prime";
    }
     return 0;

 }
