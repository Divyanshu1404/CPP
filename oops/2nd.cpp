#include<iostream>
using namespace std;

// creation of class
class hero{
private:
    int health;

public:
    char level;

    hero(int health){
        cout<<"this -> "<<this<<endl;
        this->health = health;
        // cout<<"constructor called :"<<endl;
    }
    hero(int health ,char level){
        this -> level=level;
        this -> health=health;

    }

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
    hero ramesh(10);
    

    cout<<"address of ramesh : "<<&ramesh<<endl;
    ramesh.gethealth();
    

    // hero *h=new hero(11);
    hero temp(11,'B');
    return 0;
}
