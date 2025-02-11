//passing a vector using call by reference
#include<iostream>
#include<vector>
using namespace std;
void printVector(const vector<int>&vec){
  for(int val : vec){
    cout << val <<" ";
  }
  cout<<endl;
}
int main(){
    vector<int> vec ={1,2,3,4,5,6,7,8,9,0};
    printVector(vec);
    return 0;

}

