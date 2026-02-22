#include<iostream>
#include<string>
using namespace std;

class teacher{
    //properties
private:
    double salary;
public:
    string name;
    string dept;
    string subject;
    
    
    //methods
    void changedept(string newdept){
        dept = newdept;
    }
    // setter 
    void setSalary(double a){
        salary = a;
    }
    //getter
    double getSalary(){
        return salary;
    }
};

int main(){
    teacher t1;
    t1.name="aman";
    t1.dept="computer application";
    t1.subject="oop";
    t1.salary=50000;
    cout<<t1.name<<endl;
    cout<<t1.dept<<endl;
    cout<<t1.subject<<endl;
    cout<<t1.salary<<endl;

    return 0;  
}
 