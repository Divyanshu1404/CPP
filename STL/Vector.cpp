#include<iostream>
#include<vector>

using namespace std;
 
int main()
{
    vector<int>v;

    v.push_back(5);
    v.push_back(6);
    v.push_back(1);
    v.push_back(4);
    v.push_back(9);
    v.push_back(3);
    v.push_back(2);
    for(int x:v){
        cout<<x<<" ";
    }
    cout<<v.size()<<endl;
   
    return 0;
}