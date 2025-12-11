#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    unordered_map<string, int>umap;

    umap["cat"]=5;
    umap["dog"]=3;
    umap["bird"]=7;
    for (auto& pair : umap){
        cout<<pair.first<<" : "<<pair.second<<endl;
    }


    return 0;
}