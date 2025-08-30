#include<iostream>
using namespace std;
 
int binary2decimal(int binary){
    int ans=0;
    int pow=1;
    while(binary>0){
        int rem=binary%10;
        ans=ans+(binary * pow);
        binary=binary/10;
        pow=pow*2;
    }
    return ans;
}
int main()
{
    cout<<binary2decimal(101)<<endl;   
    return 0;
}