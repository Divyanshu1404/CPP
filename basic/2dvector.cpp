#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<vector<int>>vec={{1,2,3},{4,5,6},{7,8,9}};
    vec.push_back({10,11,13});
    for(const auto&row:vec){
        for (int val:row){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    for( auto&row:vec){
        for (int val:row){
            val=val+2;
            cout<<val<<" ";
        }
        cout<<endl;
    }
 return 0;
}
///k k   