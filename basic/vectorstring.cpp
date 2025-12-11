#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    vector<string>words={"apple","banana","cherry"};
    for(auto&word: words){
        
        word+="!";
    }
    for(const auto&word:words){
        cout<<word<<" ";
    }
    return 0;
}