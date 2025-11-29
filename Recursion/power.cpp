#include<iostream>
using namespace std;
// Function to calculate power using recursion
int power(int n){
    //base case
    if(n==0)
    return 1;
    //recursive relation

    return 2*power(n-1);
    // int smallerProblem=power(n-1);
    // int biggerProblem=2*smallerProblem;
    // return biggerProblem;
}
// base: the base number

int main(){
    int n;
    cin>>n;
    int ans=power(n);
    cout<<ans<<endl;
    return 0;   
}