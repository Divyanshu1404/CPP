#include<iostream>
#include<set>
using namespace std;
int main()
{
    set<int>myset;
    myset.insert(10);
    myset.insert(2);
    myset.insert(4);
    myset.insert(11);

    cout<<"element are"<<endl;
    for(int num:myset){
        cout<<num<<",";
    }
    cout<<endl;
    myset.erase(2);
 
    return 0;
}