#include<iostream>
using namespace std;
 
int binary2decimal(int binary){
    int ans=0;
    int pow=1;
    while(binary>0){
        int rem=binary%10;
        ans=ans+(binary * pow);        
        pow=pow*2;
    }
    return ans;
}
int main()
{
    
    return 0;
}