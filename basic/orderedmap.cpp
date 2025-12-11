#include<iostream>
#include<map>
using namespace std;
int main(){
    //orderedmap = om

    map<string ,int> om;
    om["Apple"]=1;
    om["Mango"]=2;
    om["Cherry"]=3;
    for(auto& pair :om){
        cout<<pair.first<<" : "<<pair.second<<endl;
    }
return 0;
}