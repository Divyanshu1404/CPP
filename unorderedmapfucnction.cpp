#include<iostream>
#include<unordered_map>
using namespace std;
void unorderedmap(unordered_map<string,int>um)
for (auto& pair : umap){
    cout<<pair.first<<" : "<<pair.second<<endl;
}
int main()
{
    unordered_map<string, int>umap;

    umap["cat"]=5;
    umap["dog"]=3;
    umap["bird"]=7;
    
    return 0;
}