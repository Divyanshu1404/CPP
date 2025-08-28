#include<iostream>
using namespace std;
 int main(){
    char ch;
    cout<<"enter the charter :";
    cin>>ch;
//if(ch>='A' && ch<='B')
    if(ch>=65 && ch<=90){ /// ascii value A - Z lies between 65 to 90
        cout<<"upper case\n";
    }
    else {
        cout<<"lower case\n";
    }
 }