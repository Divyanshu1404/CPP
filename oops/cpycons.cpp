#include<iostream>
#include<cstring>
using namespace std;

// creation of class
class hero{
private:
    int health;

public:
    char *name;
    char level;

    hero(){

        cout<<"default constructor"<<endl;
        name =new char[100];
    }

    hero(int health){
        cout<<"this -> "<<this<<endl;
        this->health = health;
         name =new char[100];
        // cout<<"constructor called :"<<endl;
    }
    hero(int health ,char level){
        this -> level=level;
        this -> health=health;

         name =new char[100];
    }

    //copy constructor

    hero(hero &temp){
        cout<<"copy constructor called"<<endl;
        this->name=temp.name;
        this->health=temp.health;
        this->level=temp.level;
    }

    void print(){
        cout<<endl;
        cout<<"Name: "<<this->name<<" ,";
        cout<<"health : "<<this->health<<" ,";
        cout<<"level : "<<this->level<<endl;
        cout<<endl;
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
    void setname(char name[]){
        strcpy(this->name,name);
    }
};

int main(){
    hero ramesh;

    ramesh.sethealth(10);
    ramesh.setlevel('A');
    char name [7]="Aman";
    ramesh.setname(name);

    ramesh.print();

    return 0;

    // hero s(70,'C');

    // s.print();

    // //copy constructor

    // hero r(s);
    // r.print();


    return 0;
}
