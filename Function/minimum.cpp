#include<iostream>
using namespace std;
  
int MinOfTwo(int a, int b){
    if(a<b){
        return a;
    }
    else{
         return b;
    }
}
 int main()
 {
    int min=MinOfTwo(5,6);
    
    cout<<"min : "<<MinOfTwo(5,6)<<endl;
    
    return 0;
 }