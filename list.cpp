#include<iostream>
#include<list>
using namespace std;
int main()
{
    list<int>mylist;
    mylist.push_back(10);
    mylist.push_back(20);
    mylist.push_back(30);
    mylist.push_front(5);
    cout<<"list element: ";
    for (int val:mylist){
        cout<<val<<" ";
    }
    cout<<endl;
    mylist.pop_front();
    mylist.pop_back();


    cout<<"Size after poping: "<<mylist.size()<<endl;
 

    return 0;
}    