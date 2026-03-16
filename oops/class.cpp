#include<iostream>
using namespace std;

// creation of class
class hero{
private:
    int health;

public:
    char level;

    void print(){
        cout<<level<<endl;
    }

    int gethealth(){
        return health;
    }

    char getlevel(){
        return level;
    }

    void sethealth(int h){
        health = h;
    }

    void setlevel(char ch){
        level = ch;
    }
};

int main(){
    hero h1;

    h1.sethealth(100);
    h1.level = 'A';

    cout<<"health is : "<<h1.gethealth()<<endl;
    cout<<"level is : "<<h1.level<<endl;

    return 0;
}