#include<iostream>
using namespace std;
 
void change(int x){
    x=2*x;
    cout<<"changed value : "<<x<<endl;
}
 int main(){
    int x=6;
    change(x);
    cout<<"change value : "<< x<<endl;
    return 0;
}
