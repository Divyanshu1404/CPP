#include<iostream>
using namespace std;

class a{
    void fun(){
        cout<<"fun of class a"<<endl;
    }
    class b : public a{
        void run(){
            cout<<"run of class b"<<endl;   
        }
    } 
}
int main(){
    b obj;
    return 0; 
}