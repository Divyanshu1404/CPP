#include<iostream>
using namespace std;

void PrintNums(int n){
    // Base case:
    if(n==1){
        cout<<"1\n";
        return;
    }
    // Recursive case:
    cout<<n<<" ";
    PrintNums(n-1);
}
int main(){
    PrintNums(5);
    return 0;
}