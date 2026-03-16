#include<iostream>
#include<string>
using namespace std;

class teacher{
private:
    double salary;   // private

public:
teacher(){
    cout<<"hey i am constructor"<<endl;
}
    string name;
    string dept;
    string subject;

    // Method
    void changedept(string newdept){
        dept = newdept;
    }

    // Setter
    void setSalary(double a){
        salary = a;
    }

    // Getter
    double getSalary(){
        return salary;
    }
};

int main(){
    teacher t1;

    t1.name = "aman";
    t1.dept = "computer application";
    t1.subject = "oop";

    // Set salary using setter
    t1.setSalary(50000);

    cout << t1.name << endl;
    cout << t1.dept << endl;
    cout << t1.subject << endl;

    // Get salary using getter
    cout << t1.getSalary() << endl;

    return 0;
}