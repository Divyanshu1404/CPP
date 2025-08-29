#include<iostream>
using namespace std;
 
 int SumOfN(int n)
 {
    int sum=0;
    for(int i=0;i<=n;i++){
        sum +=i;
    }    
    return sum;
 }
 int main()
 {
    cout<<"sum : "<<SumOfN(5)<<endl;
    return 0;
 }