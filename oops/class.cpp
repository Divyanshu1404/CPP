#include<iostream>
#include "hero.cpp"
using namespace std;

// creation of class
class  hero{
   char name;
   int health;
   
};
int main(){
    // creation of object
    hero h1;

    cout<<"size : "<<sizeof(h1)<<endl;
    return 0;
}