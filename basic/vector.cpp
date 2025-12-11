#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int>number={1,2,3,4};
    number.push_back(5);
    number.push_back(6);
    
    for (int num:number){
        cout<<num<<endl;
   }
   cout<<"size:"<<number.size()<<endl;
   number.pop_back();
   for(int num:number){
    cout<<num<<"";
   }
   return 0;

}