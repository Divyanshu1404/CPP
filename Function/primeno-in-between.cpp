#include<iostream>
using namespace std;

bool isPrime(int num){
    if(num<2){
    return false;
    }
    for(int i=2;i*i<=num;i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}
void printPrime(int n){
    for(int i =2;i<=n;i++){
        if(isPrime(i))
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;
}
int main()
{
    int n;
    cout<<"enter the value of :"; 
    cin>>n;
    printPrime(n);
    return 0;
}