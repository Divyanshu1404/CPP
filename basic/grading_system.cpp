#include<iostream>
using namespace std;
int main()
{
    int marks;
    cout<<"enter the marks :";
    cin>>marks;
    if(marks>=90){
        cout<<"A\n";
    }
    else if(marks>=80){
        cout<<"B\n";
    }
    else if(marks>=70){
        cout<<"C\n";
    }
    else if(marks>=60){
        cout<<"D\n";
    }
    else if(marks>=50){
        cout<<"E\n";
    }
    if(marks>=40){
        cout<<"F\n";
    }

    else {
        cout<<"Fail\n";
    }
}