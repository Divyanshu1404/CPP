#include<iostream>
using namespace std;
 int main(){
    char ch;
    cout<<"enter the charter :";
    cin>>ch;

    if(ch>='a' && ch<='z'){
        cout<<"lower case";
    }
    else {
        cout<<"upper case";
    }
 }