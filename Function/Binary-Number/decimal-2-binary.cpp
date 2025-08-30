#include<iostream>
using namespace std;
 
int dec2binary(int decNum){
    int ans=0; 
    int pow=1;
    while(decNum > 0){
        int rem=decNum %2;
        decNum =decNum/2;
        ans=rem+(rem*pow);
        pow=pow*10;
    }l
    return ans;
}
int main()
{
     int decNum;
     cout<<"enter the number : ";
     cin>>decNum; 
    // dec2binary(decNum);
    cout<<"binary number : "<<dec2binary(decNum)<<endl;
    return 0;
}