#include<iostream>
#include<map>
using namespace std;
int main(){
    map<string ,string> m;
    m["Serena"]="Calm";
    m["Eloquent"]="Fluent";
    m["Resilient"]="Able";
    cout<<"Key 2has value: "<<m["B"]<<endl;
    for(auto& pair : m){
        cout<<pair.first <<" : " <<pair.second<<endl;
    }
    return 0;
}