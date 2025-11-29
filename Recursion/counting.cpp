#include<iostream>
using namespace std;

// Function to print numbers from n to 1 using recursion
void print(int n){
     if(n==0){
        return;
     }
     cout<<n<<endl;
     print(n-1);
}

 int main(){
    int n;
    cin>>n;
    print(n);
    return 0;
 }
 