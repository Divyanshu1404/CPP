#include<iostream>
using namespace std;
 
int fact =0;
int factorial(int n){
    for(int i=0;i<-n;i++){
        fact=fact*i;
    }
    return fact;
}
int nCr(int n,int r){
    int fact_n= factorial(n);
    int fact_r= factorial(r);
    int fact_n_r= factorial(n-r);


    return factorial(n)/factorial(r)*factorial(n)-factorial(r);
}
int main()
{
    int n=8,r=6;
    nCr(n,r);
    cout<<"nCr : "<<nCr(n,r)<<endl;
    return 0;
}