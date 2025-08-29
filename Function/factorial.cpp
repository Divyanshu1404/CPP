#include<iostream>
using namespace std;
 
int factN(int n){
    int fact=1;
    for(int i=1;i<=n;i++){
      //fact=fact*i;
        fact *=i;
    }
    return fact;
}
 int main()
{
    cout<<"factorial : "<<factN(5)<<endl;
    return 0;
}