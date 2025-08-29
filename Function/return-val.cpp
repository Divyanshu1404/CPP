#include<iostream>
using namespace std;
 
int printhello(){
    cout<<"returned value";
    return 4;
}
int main()
{
    int val=printhello();
    cout<<"val ; "<<val<<endl;
    return 0;
}