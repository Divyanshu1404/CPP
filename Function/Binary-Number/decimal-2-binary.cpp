#include<iostream>
using namespace std;
 
int dec2binary(int n){
    int ans=0; 
    int pow=1;
    while(decNum > 0){
        int rem=decNum %2;
        int decNum =decNum/2;
        int rem=rem+(rem*pow);
        pow=pow*10;
    }
    return ans;
}
int main()
{
    int decNum;
    dec2binary(decNum);
    cout<<"binary number : "<<dec2binary<<endl;
    return 0;
}