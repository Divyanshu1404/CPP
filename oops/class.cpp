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
    cout<<"hi"<<endl;
    hero ramesh(10);
    cout<<"address of ramesh : "<<&ramesh<<endl;
    // hero *h=new hero(11);
    cout<<"hello"<<endl;
//        hero a;
//    a.sethealth(80);
//    a.setlevel('B');
//    cout<<"level is : "<<a.level<<endl;
//    cout<<"health is :"<<a.gethealth()<<endl;

// dynamic allocation

//    hero *b=new hero;

//    b->sethealth(70);
//    b->setlevel('A');
//    cout<<"level is : "<<(*b).level<<endl;
//    cout<<"health is :"<<(*b).gethealth()<<endl;

//    cout<<"level is : "<<b->level<<endl;
//    cout<<"health is :"<<b->gethealth()<<endl;

//    return 0;

   //  hero h1;
   //  h1.sethealth(100);
   //  h1.level = 'A';

   //  cout <<"size of hero : "<<sizeof(h1)<<endl;

   //  cout<<"health is : "<<h1.gethealth()<<endl;
   //  cout<<"level is : "<<h1.level<<endl;

   //  return 0;
   
   // static allocation


}